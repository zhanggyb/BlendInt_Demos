# CMake file for BIL project
#

include_directories(${BlendInt_SOURCE_DIR}/demo/opencv)

add_subdirectory(cartoonifier)
add_subdirectory(markerbasedar)
add_subdirectory(headposeestimation)
