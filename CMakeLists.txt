#---------------------------------------------------------------------------------  
#                           _               _       _ 
#                          | |__ _ __ _ _ _| |_ ___| |
#                          | / _` / _` | ' \  _/ -_) |
#                          |_\__, \__,_|_||_\__\___|_|
#                            |___/                                        
# 
#---------------------------------------------------------------------------------
# 
#  Company: LGANTEL
#  Engineer: Laurent Gantel <laurent.gantel@gmail.com>
#  
#  Project Name: Bitmap2Hex
#  Version: 0.1.0
#  File Name: CMakeLists.txt
#  Description: CMake configuration file for Bitmap2Hex application
# 
#  Last update: 2026-10-12
# 
#--------------------------------------------------------------------------------

project(bitmap2hex)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

# Find wxWidgets package and include headers
find_package(wxWidgets COMPONENTS core base REQUIRED)
include( "${wxWidgets_USE_FILE}" )

# Include application headers
include_directories("inc")

# List application sources
set(SOURCES src/bitmap2hex.cpp
            inc/BM2H_Frame.h src/BM2H_Frame.cpp 
            inc/BM2H_App.h src/BM2H_App.cpp 
            inc/wxPixelMatrix.h src/wxPixelMatrix.cpp 
)

# Save the output binary into the bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Define the executable
add_executable(bitmap2hex ${SOURCES})

# Link with wxWidgets
target_link_libraries(bitmap2hex ${wxWidgets_LIBRARIES})
