add_library(measurement_sets OBJECT measurement_sets.cpp)
target_include_directories(measurement_sets PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(measurement_sets PRIVATE ${CMAKE_CXX_FLAGS} -c -Wall -Werror -Wno-return-type-c-linkage)