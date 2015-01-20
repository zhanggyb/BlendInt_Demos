# build common code

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

file(GLOB sourcefiles "*/*.cpp")
list(APPEND demo_common_SRC ${sourcefiles})
file(GLOB sourcefiles "*.cpp")
list(APPEND demo_common_SRC ${sourcefiles})

file(GLOB headerfiles "*.hpp")
list(APPEND demo_common_SRC ${headerfiles})
file(GLOB headerfiles "*/*.hpp")
list(APPEND demo_common_SRC ${headerfiles})

add_library (DemoCommon ${demo_common_SRC})
target_link_libraries(DemoCommon BlendInt ${LIBS})
