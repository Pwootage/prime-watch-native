cmake_minimum_required(VERSION 3.7)
project(prime-watch-native)

set(CMAKE_CXX_STANDARD 11)


find_package(glm REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

# Libs
add_subdirectory(lib)
include_directories(lib/PrimeMemoryDumping/common)
include_directories(lib/PrimeMemoryDumping/)

add_definitions(${NANOGUI_EXTRA_DEFS})
include_directories(lib/nanogui/include ${NANOGUI_EXTRA_INCS})

set(SOURCE_FILES
        src/GameMemory.cpp
        src/main.cpp)

add_executable(primewatch ${SOURCE_FILES})

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS -static) # Should be Windows only (probably?)
endif ()

target_link_libraries(primewatch
        primememorydumping
        nanogui
        ${NANOGUI_EXTRA_LIBS}
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLFW}
        )