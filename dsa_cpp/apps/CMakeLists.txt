add_executable(demo demo.cpp)
target_link_libraries(demo PRIVATE dsa_cpp)

target_compile_features(demo PRIVATE cxx_std_17)