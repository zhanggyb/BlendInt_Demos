# CMake file for blendint project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND Cartoonifier_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND Cartoonifier_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND Cartoonifier_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND Cartoonifier_SRC ${headerfiles})

add_executable(Cartoonifier ${Cartoonifier_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(Cartoonifier blendint ${LIBS})

