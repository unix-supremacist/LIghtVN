cmake_minimum_required(VERSION 3.10)

# set the project name
project(2DL)

# add the executable
add_library(${PROJECT_NAME} graphics.c)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "../external/raylib/src"
    "../chelp"
)