cmake_minimum_required(VERSION 3.10)

# set the project name
project(LightVN VERSION 0.1)

# add the executable
add_executable(${PROJECT_NAME} main.c)

# configure file
configure_file(config.h.in config.h)

add_subdirectory(external/lua)

target_include_directories(${PROJECT_NAME}
    PUBLIC "${PROJECT_BINARY_DIR}"
)

target_link_libraries(${PROJECT_NAME} PRIVATE m lua::lib)