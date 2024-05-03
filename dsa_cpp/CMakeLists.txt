cmake_minimum_required(VERSION 3.20)

project(
  dsa_cpp
  DESCRIPTION "Data structures and algorithms implemented in C++"
  LANGUAGES CXX
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)

  enable_testing()

endif()

add_subdirectory(src)

add_subdirectory(apps)

option(BUILD_TESTING "Build tests" ON)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()