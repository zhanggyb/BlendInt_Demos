# CMake file for BlendInt project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND tutorial01_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND tutorial01_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND tutorial01_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND tutorial01_SRC ${headerfiles})

add_executable(tutorial01 ${tutorial01_SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(tutorial01 BlendInt ${LIBS})

