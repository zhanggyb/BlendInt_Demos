# CMake file for BlendInt project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND studio_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND studio_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND studio_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND studio_SRC ${headerfiles})

add_executable(studio ${studio_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(studio BlendInt ${LIBS})

