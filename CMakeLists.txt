# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
# set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
# CACHE STRING "Vcpkg toolchain file")
set(CMAKE_TOOLCHAIN_FILE /Users/zhangqilong/Desktop/git/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")
project(test)

#如果没有指定则设置默认编译方式
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  #在命令行中输出message里的信息
  message("Setting build type to 'RelWithDebInfo' as none was specified.")
  #不管CACHE里有没有设置过CMAKE_BUILD_TYPE这个变量，都强制赋值这个值为RelWithDebInfo
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)

  # 当使用cmake-gui的时候，设置构建级别的四个可选项
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()


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