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
-- File Name: BM2H_App.cpp
-- Description: Main application
--
-- Last update: 2023-06-01
--
-------------------------------------------------------------------------------*/

#include "BM2H_App.h"

// Implementation
bool BM2H_App::OnInit() {
  BM2H_Frame * frame = new BM2H_Frame();
  frame->Show();
  return true;
}
