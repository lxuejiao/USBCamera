# cmake needs this line
cmake_minimum_required(VERSION 3.1)
 
# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Define project name
project(cv_read_save)
 
find_package(OpenCV REQUIRED) 

add_executable(run_me readAndSave.cpp)
target_link_libraries(run_me opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs)
