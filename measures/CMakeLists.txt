add_library(measures OBJECT measures.cpp)
target_include_directories(measures PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(measures PRIVATE ${CMAKE_CXX_FLAGS} -c -Wall -Werror -Wno-return-type-c-linkage)