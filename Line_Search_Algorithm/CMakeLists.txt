cmake_minimum_required (VERSION 3.0)
project (NO)
 
set(Eigen3_DIR "C:/Users/cinte/OneDrive/Documents/libc++/eigen-3.3.7/build")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(./ ../headers)
 
add_executable (AG3_2 Algorithm3_2.cpp)
target_link_libraries (AG3_2 Eigen3::Eigen)