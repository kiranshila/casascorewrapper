project(casacorewrapper)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# We need at least C++ 11
set (CMAKE_CXX_STANDARD 11)

# Find casacore
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(Casacore REQUIRED)

# fPIC all the things
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add subdirectories
add_subdirectory(measurement_sets)
add_subdirectory(measures)
add_subdirectory(tables)
add_subdirectory(rc)

# Add our library
add_library(casacorewrapper SHARED
  $<TARGET_OBJECTS:measures>
  $<TARGET_OBJECTS:tables>
  $<TARGET_OBJECTS:measurement_sets>
  $<TARGET_OBJECTS:rc>)
target_link_libraries(casacorewrapper casa_casa casa_tables casa_ms casa_measures)

# Install
install(
  TARGETS casacorewrapper
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION lib
)
