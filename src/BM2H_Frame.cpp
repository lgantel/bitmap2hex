/*--------------------------------------------------------------------------------  
--                          _               _       _ 
--                         | |__ _ __ _ _ _| |_ ___| |
--                         | / _` / _` | ' \  _/ -_) |
--                         |_\__, \__,_|_||_\__\___|_|
--                           |___/                                        
--
----------------------------------------------------------------------------------
--
-- Company: LGANTEL
-- Engineer: Laurent Gantel <laurent.gantel@gmail.com>
--
-- Project Name: Bitmap2Hex
-- Version: 0.1.0
-- File Name: BM2H_Frame.cpp
-- Description: Main frame of the application
--
-- Last update: 2023-06-01
--
-------------------------------------------------------------------------------*/

#include "BM2H_Frame.h"

/**
 * @brief Menu and widgets identifiers
 */
enum {
  ID_BM2H = 1,      /**> Application       */
  ID_Console,       /**> Console widget    */
  ID_Gen_Button,    /**> Generation button */
  ID_Clear_Button   /**> Clear button      */
};

/**
 * @brief Helper: Return a string representing an integer in hex format
 * 
 * @tparam T The integer type
 * @param n The integer to be formatted
 * @param width The size in nibble of the integer (eg. 2 for a byte)
 * @return std::string The string representing the integer in hex format
 */
template<typename T>
std::string int_to_hex(T n, unsigned int width) {
  std::stringstream ss;
  ss << "0x"
     << std::setfill('0') << std::setw(width) 
     << std::hex << n;
  return ss.str();
}

/**
 * @file BM2H_Frame.h
 * @name OnClearButtonClick
 */
BM2H_Frame::BM2H_Frame()
  : wxFrame(nullptr, wxID_ANY, "Bitmap2Hex", wxDefaultPosition, wxSize(640,320))
{
  wxMenu * menuFile = new wxMenu;
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  SetMenuBar(menuBar);

  CreateStatusBar();
  SetStatusText("Welcome to Bitmap2Hex!");

  Bind(wxEVT_MENU, &BM2H_Frame::OnAbout, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &BM2H_Frame::OnExit, this, wxID_EXIT);

  this->SetupWidgets();
}

/**
 * @file BM2H_Frame.h
 * @name SetupWidgets
 */
void BM2H_Frame::SetupWidgets(void) {
  // Add pixels
  this->pixel_matrix = new wxPixelMatrix(this, 8, 8, wxPoint(20,20), wxSize(20,20));

  // Add text console
  this->console = new wxTextCtrl(this, ID_Console, "Loading...", wxPoint(20+9*21,20), wxSize(400,21*8), 
    wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);

  // The generate button
  this->gen_button = new wxButton(this, ID_Gen_Button, wxT("Generate"), wxPoint(20+10,20+9*21), wxSize(100,30), 0);
  this->gen_button->Bind(wxEVT_BUTTON, &BM2H_Frame::OnGenButtonClick, this);

  // The clear button
  this->clear_button = new wxButton(this, ID_Clear_Button, wxT("Clear"), wxPoint(20+140,20+9*21), wxSize(100,30), 0);
  this->clear_button->Bind(wxEVT_BUTTON, &BM2H_Frame::OnClearButtonClick, this);
}

/**
 * @file BM2H_Frame.h
 * @name OnClearButtonClick
 */
void BM2H_Frame::OnExit(wxCommandEvent& event) {
  Close(true);
}

/**
 * @file BM2H_Frame.h
 * @name OnClearButtonClick
 */
void BM2H_Frame::OnAbout(wxCommandEvent& event) {
  wxMessageBox("Application to convert a Bitmap into an hex array", "About Bitmap2Hex", wxOK | wxICON_INFORMATION);
}

/**
 * @file BM2H_Frame.h
 * @name OnClearButtonClick
 */
void BM2H_Frame::OnGenButtonClick(wxCommandEvent& event) {
  this->console->Clear();

  unsigned int pixel_hex;
  std::string pixels_hexstr = "";

  for (auto x=0; x<8; x++) {
    pixel_hex = 0x00;
    for (auto y=0; y<8; y++) {
      if (this->pixel_matrix->IsPixelSelected(x, y)) {
        pixel_hex |= (1 << y);
      }
    }
    pixels_hexstr += int_to_hex(pixel_hex, 2) + ", ";
  }

  this->console->AppendText(pixels_hexstr.c_str());
}

/**
 * @file BM2H_Frame.h
 * @name OnClearButtonClick
 */
void BM2H_Frame::OnClearButtonClick(wxCommandEvent& event) {
  // Clear the console
  this->console->Clear();

  // Clear the pixel matrix
  this->pixel_matrix->Clear();
}
