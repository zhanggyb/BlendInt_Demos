# CMake file for BlendInt project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND node_editor_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND node_editor_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND node_editor_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND node_editor_SRC ${headerfiles})

add_executable(node_editor ${node_editor_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(node_editor BlendInt ${LIBS})

