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
-- File Name: wxPixelMatrix.h
-- Description: Pixel Matrix widget
--
-- Last update: 2023-06-01
--
-------------------------------------------------------------------------------*/

#include <wx/wx.h>

class wxPixelMatrix {
public:
  /**
   * @brief Class constructor
   * @param parent The widget parent
   * @param matrix_width The matrix width, ie. the number of pixels in a row
   * @param matrix_height The matrix height, ie. the number of pixels in a column
   * @param matrix_pos The matrix position in the parent
   * @param pixel_size The size of a pixel
   */
  wxPixelMatrix(wxWindow *parent, unsigned int matrix_width, unsigned int matrix_height, wxPoint matrix_pos, wxSize pixel_size);

  /**
   * @brief Get a reference to the panel representing a pixel
   * @param x The pixel abscissa inside the matrix
   * @param y The pixel ordinate inside the matrix
   * @return wxPanel* A pointer to the pixel panel if the coordinates are valid, nullptr otherwise
   */
  wxPanel * GetPixel(unsigned int x, unsigned int y);

  /**
   * @brief Indicate if a pixel is selected
   * @param x The pixel abscissa inside the matrix
   * @param y The pixel ordinate inside the matrix
   * @return true if the pixel is selected
   * @return false if the pixel is deselected or the (x,y) coordinates are invalid
   */
  bool IsPixelSelected(unsigned int x, unsigned int y);

  /**
   * @brief Clear the matrix, deselect all pixels
   */
  void Clear(void);

protected:
  /** @brief Colour when a pixel is deselected */
  wxColour deselect_colour{*wxLIGHT_GREY};
  /** @brief Colour when a pixel is selected */
  wxColour select_colour{*wxCYAN};
  /** @brief Matrix of pixels to be displayed in the frame */
  wxPanel * pixels[8][8];

private:
  /** @brief The matrix width, ie. the number of pixels in a row */
  unsigned int matrix_width;
  /** @brief The matrix height, ie. the number of pixels in a column */
  unsigned int matrix_height;

  /**
   * @brief Handle a pressure event from the mouse on a pixel
   * @param event The event to be handled
   */
  void OnPixelClick(wxMouseEvent& event);
};
