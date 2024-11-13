
# Look for headers in the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(main_zipfs_containers SHARED main_zipfs_containers.cpp)
add_library(main_zipfs_algorithms SHARED main_zipfs_algorithms.cpp)

# You can also add any stand alone executables
# add_executable(example main.cpp) # Will make a binary called "example" inside build/bin using main.cpp
