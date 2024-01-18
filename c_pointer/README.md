# 1. 变量的赋值

```c
#include <stdio.h>

int main()
{
    int a;
    a = 5;
    printf("a = %d\n", a);
    return 0;
}
```

上面的代码，`int a;` 申请了一块内存(32bit)存储a表示的值，我们暂时不知道，这块内存在哪儿。

`a = 5;` 将 5 的32位 bin steam 写入这个内存。

我们`printf`打印的时候再把这块内存的 bin steam 写入到输出流。

# 2. 获取变量存储的地址

```c
#include <stdio.h>

int main ()
{   
    // 地址与内存空间一一对应

    int a; // 声明一个变量 a ,将为它分配 int大小(32bit)的内存空间,这个空间对应一个地址
    a = 5; // 赋值时，先找到上面的地址，将值 5 存入这个地址对应的内存空间。

    // 将 a 的地址对应的内存空间中的值，读取并写入到输出流，通过 printf 打印。
    printf("a = %d\n", a); 

    int * p; // p 是一个变量，也叫指针。
             // int * 表明：p 的内存空间里面存储的是 int* 类型的地址，也是数据，也是值。
             // p 是一个变量，就需要内存来存储，内存也对应了一个地址。
             // 无限套娃 ？？？（操作系统怎么救一下？）

    // 下面获取这个存储这个指针的内存的大小：
    // sizeof(int*) = 8 bytes (因为我的机器地址总线是 64bit 的，所以 8 bytes 吗?)
    printf("sizeof(int*) = %ld bytes\n", sizeof(int*));

    // & 是取址运算符，&a 取得存储 a 变量的内存空间对应的地址，
    // p = &a, 就是将 a 的地址赋值给 p
    // 要赋值操作！找一个内存，对应一个地址，p 的值放到这个内存里，这个内存对应的地址为 &p.
    p = &a;
    
    // a 的当前地址存到 p 的内存空间啦。
    // q1: a 的地址变了咋办，p 的值不变吗？
    // q2: a 的值变了，p 存的值也跟着变，怎么处理？

    // 通过 变量 p 访问 p 的内存空间，可读可写吗？
    // 通过 变量 *p 把 p 的内存空间里面存的值当成地址，去访问这个地址对应的内存空间里面存的值，可读可写吗？

    // 既然地址都是 64bit 的，那么 double * 访问 int 值时，会咋样？

    printf("p = %p\n", p);
    printf("*p = %d\n", *p); // 读取 a 的值

    *p = 10; // 覆盖 a 的值。

    printf("a = %d\n", a);

}
```

# 3.

```c
#include <stdio.h>

int main ()
{   
    // Q1: double * 访问 int 数据 发生啥？
    int a;
    a = 0xaaaaaaaa;
    printf("a = %d\n", a);

    int * p1;
    p1 = &a;
    printf("p1 = %p\n", p1);
    printf("*p1 = %d\n", *p1);
    printf("bin data *p1 = %08x\n", *p1);
    printf(" sizeof(*p1) = %lu bytes\n", sizeof(*p1));

    double * p2;
    p2 = &a;
    printf("p2 = %p\n", p2);
    printf("*p2 = %d\n", *p2);
    printf("bin data *p2 = %08x\n", *p2);
    printf(" sizeof(*p2) = %lu bytes\n", sizeof(*p2));

}
```

结果：

```bash
cgf@ubuntupro:~/DATA/github/cpp_learning/c_pointer$ gcc test3.c -o test3.run
test3.c: In function ‘main’:
test3.c:18:8: warning: assignment to ‘double *’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
   18 |     p2 = &a;
      |        ^
test3.c:20:20: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘double’ [-Wformat=]
   20 |     printf("*p2 = %d\n", *p2);
      |                   ~^     ~~~
      |                    |     |
      |                    int   double
      |                   %f
test3.c:21:31: warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument 2 has type ‘double’ [-Wformat=]
   21 |     printf("bin data *p2 = %08x\n", *p2);
      |                            ~~~^     ~~~
      |                               |     |
      |                               |     double
      |                               unsigned int
      |                            %08f
cgf@ubuntupro:~/DATA/github/cpp_learning/c_pointer$ ./test3.run 
a = -1431655766
p1 = 0x7ffc753de5b4
*p1 = -1431655766
bin data *p1 = aaaaaaaa
 sizeof(*p1) = 4 bytes
p2 = 0x7ffc753de5b4
*p2 = -1198910816
# 跑了好些遍，只有末尾的a0一直不变
# 大小端？
bin data *p2 = b88a12a0
 sizeof(*p2) = 8 bytes
```

用 `char*` 把周围的内存都看看？

