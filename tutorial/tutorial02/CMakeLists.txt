# CMake file for blendint project
#

file(GLOB sourcefiles "*/*.cpp")
list(APPEND tutorial02_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND tutorial02_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND tutorial02_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND tutorial02_SRC ${headerfiles})

add_executable(tutorial02 ${tutorial02_SRC})

if(NOT WITH_BUILTIN_GLFW3)
    if(OS_APPLE)
        set(LIBS ${LIBS} glfw3)
    else()
        set(LIBS ${LIBS} glfw)
    endif()
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(tutorial02 blendint ${LIBS})

