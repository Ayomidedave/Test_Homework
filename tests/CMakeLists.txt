include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Make all targets in this directory look for headers here
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)

# Add the library for expression
add_library(main_zipfs_containers_lib SHARED ${CMAKE_SOURCE_DIR}/src/main_zipfs_containers.cpp)
add_library(main_zipfs_algorithms_lib SHARED ${CMAKE_SOURCE_DIR}/src/main_zipfs_algorithms.cpp)
# Make all targets in this directory link against Gtest
link_libraries(GTest::gtest_main)

add_executable(test_zipfs_containers ${CMAKE_SOURCE_DIR}/tests/test_zipfs_containers.cpp)
add_executable(test_zipfs_algorithms ${CMAKE_SOURCE_DIR}/tests/test_zipfs_algorithms.cpp)
# Link against any required libraries. The library "some_library" is compiled in src/
target_link_libraries(
  test_zipfs_containers
  main_zipfs_containers_lib
  GTest::gtest_main
)

target_link_libraries(
  test_zipfs_algorithms
  main_zipfs_algorithms_lib
  GTest::gtest_main
)


# Discover the tests in both test executables            
gtest_discover_tests(test_zipfs_containers) # Register the tests to gtest
gtest_discover_tests(test_zipfs_algorithms)