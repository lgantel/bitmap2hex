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
-- File Name: BM2H_Frame.h
-- Description: Main frame of the application
--
-- Last update: 2023-06-01
--
-------------------------------------------------------------------------------*/

#ifndef BM2H_FRAME_H
#define BM2H_FRAME_H

#include <wx/wx.h>
#include <cstring>
#include <sstream>
#include <iomanip>

#include "wxPixelMatrix.h"

/**
 * @brief Frame for the BM2H application containing a pixel matrix,
 *        a console and two buttons to generate the hex value and 
 *        clear both the matrix and the console.
 */
class BM2H_Frame : public wxFrame {
public:
  /** @brief Class constructor */
  BM2H_Frame();

protected:
  /** @brief A matrix of pixels */
  wxPixelMatrix *pixel_matrix;
  /** @brief The console displaying the generated hex value */
  wxTextCtrl *console;
  /** @brief A button to generate the hex value from the pixel matrix content */
  wxButton *gen_button;
  /** @brief A button to clear both the matrix and the console */
  wxButton *clear_button;

private:
  void SetupWidgets(void);

  void OnHello(wxCommandEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);

  void OnColorPanelClick(wxCommandEvent& event);

  void OnGenButtonClick(wxCommandEvent& event);
  void OnClearButtonClick(wxCommandEvent& event);
};

#endif // BM2H_FRAME_H
