cmake_minimum_required(VERSION 3.10)
include(CMakePrintHelpers)

set(TARGET PC)

if(${TARGET} STREQUAL "PSV")
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

# set the project name
project(LightVN VERSION 0.1)

if(${TARGET} STREQUAL "PSV")
  include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")
  include_directories(../common)
  link_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

# add the executable
add_executable(${PROJECT_NAME} main.c)

# configure file
configure_file(config.h.in config.h)

add_subdirectory(external/lua)

if(${TARGET} STREQUAL "PC")
  add_subdirectory(external/raylib)
  add_subdirectory(2DL-PC)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/2DL-PC"
)

if(${TARGET} STREQUAL "PC")
  target_link_libraries(${PROJECT_NAME} PRIVATE m lua::lib raylib 2DL)
endif()

if(${TARGET} STREQUAL "PSV")
  target_link_libraries(${PROJECT_NAME} SceLibKernel_stub m lua::lib)
  vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
endif()
message(STATUS $ENV{VITASDK})
cmake_print_variables(TARGET)