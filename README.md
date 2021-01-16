<!--
 * @Author: q1lon<keyron.zhang@gmail.com>
 * @Date: 2021-01-16 15:12:29
 * @LastEditTime: 2021-01-16 16:17:16
 * @FilePath: /sqlite-test/README.md
-->
### 使用cmake构建
~~~
//使用本地 CmakeLists.txt内容构建makefile
>cmake .
//make 编译
> make 
//执行结果
>./main 'database/test-db' 'select * from main.m_user'  
~~~

