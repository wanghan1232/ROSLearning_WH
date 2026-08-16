# HelloWorldProject

一个使用 C++ 和 CMake 编写的简单示例程序。程序创建 `HelloWorld` 对象，并输出姓名和年龄信息。


## 项目结构

```text
.
├── CMakeLists.txt        # CMake 构建配置
├── main.cpp              # 程序入口
├── include/
│   └── HelloWorld.hpp    # HelloWorld 类声明
└── src/
    └── HelloWorld.cpp    # HelloWorld 类实现
```

## 修改示例信息

编辑 `main.cpp` 中的构造函数参数即可修改输出内容：

```cpp
HelloWorld hello("YourName", 20);
```
