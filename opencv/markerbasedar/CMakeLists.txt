# CMake file for blendint project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND MarkerBasedAR_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND MarkerBasedAR_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND MarkerBasedAR_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND MarkerBasedAR_SRC ${headerfiles})

add_executable(MarkerBasedAR ${MarkerBasedAR_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(MarkerBasedAR blendint ${LIBS})

