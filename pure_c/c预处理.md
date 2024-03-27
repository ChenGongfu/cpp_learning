参考资料：

[C 预处理器 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cprogramming/c-preprocessors.html)



| #define  | 定义宏                                                      |
| -------- | ----------------------------------------------------------- |
| #include | 包含一个源代码文件                                          |
| #undef   | 取消已定义的宏                                              |
| #ifdef   | 如果宏已经定义，则返回真                                    |
| #ifndef  | 如果宏没有定义，则返回真                                    |
| #if      | 如果给定条件为真，则编译下面代码                            |
| #else    | #if 的替代方案                                              |
| #elif    | 如果前面的 #if 给定条件不为真，当前条件为真，则编译下面代码 |
| #endif   | 结束一个 #if……#else 条件编译块                              |
| #error   | 当遇到标准错误时，输出错误消息                              |
| #pragma  | 使用标准化方法，向编译器发布特殊的命令到编译器中            |





```cmake
// CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(atest LANGUAGES C)
add_compile_definitions(DEBUG)
add_executable(atest atest.c)
```



```c++
// message.c
#define MESSAGE "Hello World! from message.c"
```



```c++
// atest.c
#include <stdio.h>
#include "message.c"

#undef MESSAGE

#ifndef MESSAGE
   #define MESSAGE "Hello, World! from atest.c"
#endif

#ifdef DEBUG
    printf("DEBUG");
#endif

int main()
{   
    printf("Message :%s\n", MESSAGE );
    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    return 0;
}
```

