# CMake file for BlendInt project
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

if(NOT WITH_BUILTIN_GLFW3)
    if(OS_APPLE)
        set(LIBS ${LIBS} glfw3)
    else()
        set(LIBS ${LIBS} glfw)
    endif()
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(gallery DemoCommon BlendInt ${LIBS})

