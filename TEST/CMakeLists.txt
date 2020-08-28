cmake_minimum_required (VERSION 3.0)
project (TEST)
 
set(Eigen3_DIR "C:/Users/cinte/OneDrive/Documents/libc++/eigen-3.3.7/build")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(./ ../headers)
 
add_executable (test test.cpp)
target_link_libraries (test Eigen3::Eigen)