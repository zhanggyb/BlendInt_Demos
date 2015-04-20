# CMake file for blendint project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND gallery_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND gallery_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND gallery_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND gallery_SRC ${headerfiles})

add_executable(gallery ${gallery_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(gallery blendint ${LIBS})

