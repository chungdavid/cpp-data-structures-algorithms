set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/algorithms/MergeSort.cpp
)

add_library(dsa_cpp STATIC ${SOURCES})
target_include_directories(dsa_cpp PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(dsa_cpp PUBLIC cxx_std_11)