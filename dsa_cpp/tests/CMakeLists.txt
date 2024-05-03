include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  linkedlist_tests
  LinkedList_tests.cpp
)

target_compile_features(linkedlist_tests PRIVATE cxx_std_17)

target_include_directories(
  linkedlist_tests PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
  linkedlist_tests PRIVATE
  dsa_cpp
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(linkedlist_tests)

