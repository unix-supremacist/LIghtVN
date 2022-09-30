cmake_minimum_required(VERSION 3.10)
include(CMakePrintHelpers)

set(TARGET PSV)

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
  link_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

# add the executable
add_executable(${PROJECT_NAME} main.c)

# configure file
configure_file(config.h.in config.h)

add_subdirectory(external/lua)
add_subdirectory(chelp)

if(${TARGET} STREQUAL "PC")
  add_subdirectory(external/raylib)
  add_subdirectory(2DL-PC)
  target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/chelp"
    "${PROJECT_SOURCE_DIR}/2DL-PC"
  )
  target_link_libraries(${PROJECT_NAME} PRIVATE m lua::lib raylib 2DL)
endif()

if(${TARGET} STREQUAL "PSV")
  add_subdirectory(2DL-Vita)
  target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/chelp"
    "${PROJECT_SOURCE_DIR}/2DL-Vita"
  )
  target_link_libraries(${PROJECT_NAME}
    vita2d SceDisplay_stub SceGxm_stub SceSysmodule_stub SceCtrl_stub ScePgf_stub
    ScePvf_stub SceCommonDialog_stub SceAppMgr_stub freetype png jpeg z m c lua::lib 2DL
  )
  vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
  vita_create_vpk(${PROJECT_NAME}.vpk UNIX00001 ${PROJECT_NAME}.self
    VERSION 00.01
    NAME ${PROJECT_NAME}
    FILE tatr02_l_1611.png tatr02_l_1611.png
  )
  message(STATUS $ENV{VITASDK})
endif()
cmake_print_variables(TARGET)