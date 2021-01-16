# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
# set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
# CACHE STRING "Vcpkg toolchain file")
set(CMAKE_TOOLCHAIN_FILE /Users/zhangqilong/Desktop/git/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")
project(test)


############################################################
# Create a library
############################################################
#库的源文件Hello.c生成静态库hello_library
add_library(hello_library STATIC src/hello.c)
#根据Hello.cpp生成动态库
add_library(frist_library SHARED src/frist.c)
#给动态库frist_library起一个别的名字frist::library
add_library(frist::library ALIAS frist_library)
# 创建一个变量，名字叫SOURCE。它包含了所有的cpp文件。
set(SOURCES src/main.c)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
 
add_executable(${PROJECT_NAME} ${SOURCES})
#这个目录是库所包含的头文件的目录，并设置库属性为PUBLIC。
target_include_directories(hello_library PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(frist_library PUBLIC ${PROJECT_SOURCE_DIR}/include)
#设置这个可执行文件headers需要包含的库的路径
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
#链接可执行文件和静态库
target_link_libraries(${PROJECT_NAME} PRIVATE unofficial::sqlite3::sqlite3)
#自定义静态库链接到主项目中
target_link_libraries(${PROJECT_NAME} PRIVATE hello_library)
target_link_libraries(${PROJECT_NAME} PRIVATE frist::library) 