add_library(tables OBJECT
    cells.cpp
    columns.cpp
    keywords.cpp
    rows.cpp
    tables.cpp
    util.cpp)

target_include_directories(tables PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(tables PRIVATE ${CMAKE_CXX_FLAGS} -c -Wall -Werror -Wno-return-type-c-linkage)