# CMake file for blendint project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND HeadPoseEstimation_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND HeadPoseEstimation_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND HeadPoseEstimation_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND HeadPoseEstimation_SRC ${headerfiles})

add_executable(HPE ${HeadPoseEstimation_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(HPE blendint ${LIBS})

