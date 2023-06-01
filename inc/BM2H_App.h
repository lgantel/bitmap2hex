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
-- File Name: BM2H_App.h
-- Description: Main application
--
-- Last update: 2023-06-01
--
-------------------------------------------------------------------------------*/

#ifndef BM2H_APP_H
#define BM2H_APP_H

#include <wx/wx.h>
#include "BM2H_Frame.h"

// Application
class BM2H_App : public wxApp {
public:
  bool OnInit() override;
};

#endif // BM2H_APP_H
