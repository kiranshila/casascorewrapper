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

# Turn on the errors Michael warned us about
# We'd worry about  warning: 'get_cell_scalar_complex' has C-linkage specified, but returns user-defined type 'cmplx' (aka 'complex<float>') which is incompatible with C
# But somehow it doesn't matter

# Add subdirectories
add_subdirectory(measurement_sets)
add_subdirectory(measures)
add_subdirectory(tables)

# Add our library
add_library(casacorewrapper SHARED
  $<TARGET_OBJECTS:measures>
  $<TARGET_OBJECTS:tables>
  $<TARGET_OBJECTS:measurement_sets>)

# Install
install(
  TARGETS casacorewrapper
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION lib
)
