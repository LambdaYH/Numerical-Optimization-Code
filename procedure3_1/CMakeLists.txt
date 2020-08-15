cmake_minimum_required (VERSION 3.0)
project (NO)
 
set(Eigen3_DIR "C:/Users/cinte/OneDrive/Documents/libc++/eigen-3.3.7/build")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
 
add_executable (PD3_1 Procedure3_1.cpp)
target_link_libraries (PD3_1 Eigen3::Eigen)