add_library(tables OBJECT
    cells.cpp
    columns.cpp
    keywords.cpp
    rows.cpp
    tables.cpp
    util.cpp)

target_include_directories(tables PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})