# Only the root CMake file must start with a version declaration
cmake_minimum_required(VERSION 3.7)
# Name of project (executable)
project(EmbedPy)
set(headerfiles
  ${PROJECT_SOURCE_DIR}/include/dummy.h
)
set(sourcefiles
      ${PROJECT_SOURCE_DIR}/src/Main.cpp
    )
set(CMAKE_SUPPRESS_REGENERATION true)
set(pybind11_DIR "C:\\vcpkg\\packages\\pybind11_x86-windows\\share\\cmake\\pybind11")

find_package(pybind11 CONFIG REQUIRED)

set(CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/cmake_modules"
     ${CMAKE_MODULE_PATH})

add_executable(EmbedPy ${sourcefiles} ${headerfiles})
target_compile_features(EmbedPy
                        PRIVATE
                        cxx_std_17)
target_link_libraries(EmbedPy PRIVATE pybind11::embed)
cmake_minimum_required(VERSION 3.8)


