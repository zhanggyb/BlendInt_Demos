# CMake file for blendint project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND fontviewer_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND fontviewer_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND fontviewer_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND fontviewer_SRC ${headerfiles})

add_executable(fontviewer ${fontviewer_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(fontviewer blendint ${LIBS})

