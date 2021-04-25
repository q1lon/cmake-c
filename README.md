# Cmake

### 使用cmake直接构建makefile
~~~
> mkdir -p build && cd build && cmake .. //使用本地 CmakeLists.txt内容构建makefile
> make //make 编译
//执行结果
> ./main 'database/test-db' 'select * from main.m_user'  
~~~
### 使用clang编译
~~~
> sudo ./run_test.sh //执行脚本
~~~

### 参考 
https://sfumecjf.github.io/cmake-examples-Chinese/
