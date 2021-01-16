<!--
 * @Author: q1lon<keyron.zhang@gmail.com>
 * @Date: 2021-01-16 15:12:29
 * @LastEditTime: 2021-01-16 15:23:00
 * @FilePath: /sqlite-test/README.md
-->
### 使用cmake构建
~~~
>mkdir build &&cd build
>cmake .. "-DCMAKE_TOOLCHAIN_FILE=D:\src\vcpkg\scripts\buildsystems\vcpkg.cmake"
 // omitted CMake output here //
- Build files have been written to: /Users/zhangqilong/Desktop/git/C/sqlite-test

>cmake --build .

>./main 'database/test-db' 'select * from main.m_user'  
~~~

