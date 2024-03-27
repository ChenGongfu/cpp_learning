# cpp20 语法

简单小例子

```c++
// ex1.cpp
import <iostream>;

int main()
{
    std::cout << "Hello World!\n"
              << 42 << std::endl;
    return 0;
}

```

## 1. MSVC 编译

coming soon

## 2. msys2 g++ 编译

```bash
g++ -std=c++20 -fmodules-ts -x c++-system-header iostream

g++ -std=c++20 -fmodules-ts -c ex1.cpp

g++ -std=c++20 ex1.o -o ex1.exe
```

```bash
./ex1.exe
```

![image-20231228211115846](./cpp20语法.assets/image-20231228211115846.png)