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
-- File Name: wxPixelMatrix.cpp
-- Description: Pixel Matrix widget
--
-- Last update: 2023-06-01
--
-------------------------------------------------------------------------------*/

#include "wxPixelMatrix.h"

/**
 * @file wxPixelMatrix.h
 * @name wxPixelMatrix
 */
wxPixelMatrix::wxPixelMatrix(wxWindow *parent, unsigned int matrix_width, unsigned int matrix_height, wxPoint matrix_pos, wxSize pixel_size) :
    matrix_width(matrix_width),
    matrix_height(matrix_height) {
  for (auto x=0; x<matrix_width; x++) {
    for (auto y=0; y<matrix_height; y++) {
      wxPoint pixel_loc(matrix_pos.x + x*21, matrix_pos.y + y*21);
      
      this->pixels[x][y] = new wxPanel(parent, wxID_ANY, pixel_loc, pixel_size);
      this->pixels[x][y]->SetBackgroundColour(this->deselect_colour);
      this->pixels[x][y]->Bind(wxEVT_LEFT_DOWN, &wxPixelMatrix::OnPixelClick, this);
    }
  }
}

/**
 * @file wxPixelMatrix.h
 * @name OnPixelClick
 */
void wxPixelMatrix::OnPixelClick(wxMouseEvent& event) {
  // Get pixel coordinates from item ID
  wxPanel *pixel = static_cast<wxPanel*>(event.GetEventObject());
  assert(pixel);

  if (pixel->GetBackgroundColour() == this->deselect_colour) {
    pixel->SetBackgroundColour(this->select_colour);
  }
  else {
    pixel->SetBackgroundColour(this->deselect_colour);
  }
  pixel->Refresh();
  pixel->Update();
}

/**
 * @file wxPixelMatrix.h
 * @name GetPixel
 */
wxPanel * wxPixelMatrix::GetPixel(unsigned int x, unsigned int y) {
  if ((x > this->matrix_width) || (y > this->matrix_height)) { return nullptr; }

  return this->pixels[x][y];
}

/**
 * @file wxPixelMatrix.h
 * @name IsPixelSelected
 */
bool wxPixelMatrix::IsPixelSelected(unsigned int x, unsigned int y) {
  if ((x > this->matrix_width) || (y > this->matrix_height)) { return false; }

  if (this->pixels[x][y]->GetBackgroundColour() == this->select_colour) { return true; }

  return false;
}

/**
 * @file wxPixelMatrix.h
 * @name Clear
 */
void wxPixelMatrix::Clear(void) {
  for (auto x=0; x<this->matrix_width; x++) {
    for (auto y=0; y<this->matrix_height; y++) {
      this->pixels[x][y]->SetBackgroundColour(this->deselect_colour);
      this->pixels[x][y]->Refresh();
      this->pixels[x][y]->Update();
    }
  }
}
