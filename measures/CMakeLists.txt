add_library(measures OBJECT measures.cpp)
target_include_directories(measures PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(measures casa_measures casa_casa)