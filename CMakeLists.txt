cmake_minimum_required(VERSION 3.10)
project(Cobrinha)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        C:/libs/glfw/include
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/class
        ${PROJECT_SOURCE_DIR}/include/utils
)

link_directories(
        C:/libs/glfw/lib
)

add_executable(cobrinha
    src/main.cpp
    src/snake.cpp
    src/food.cpp
    utils/keycallback.cpp
    utils/draw.cpp

)

target_link_libraries(
    cobrinha
    glfw3
    opengl32
)