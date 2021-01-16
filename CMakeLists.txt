# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
# set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
# CACHE STRING "Vcpkg toolchain file")
set(CMAKE_TOOLCHAIN_FILE /Users/zhangqilong/Desktop/git/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")
# /Users/zhangqilong/Desktop/git/vcpkg/scripts/buildsystems/vcpkg.cmake
project(test)

find_package(unofficial-sqlite3 CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE unofficial::sqlite3::sqlite3)
