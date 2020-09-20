cmake_minimum_required (VERSION 3.0)
project (NO)
 
set(Eigen3_DIR "../eigen-3.3.7/build")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(./ ../headers)
 
add_executable (TR Alogrithm4_1.cpp)
target_link_libraries (TR Eigen3::Eigen)