# Magic Enum C++11

![ascii-text-art](img/ascii-text-art.png)

[![C++11](https://img.shields.io/badge/c++-11-orange.svg)](https://en.cppreference.com/w/cpp/11) [![License](https://img.shields.io/badge/license-MIT-green)](https://github.com/vistar-terry/magic_enum/blob/main/LICENSE) [![Header-only](https://img.shields.io/badge/header--only-yes-yellowgreen)](#) [![README](https://img.shields.io/badge/README-Chinese-red)](https://github.com/vistar-terry/magic_enum/blob/main/README_ZH.md) [![README](https://img.shields.io/badge/README-English-blue)](https://github.com/vistar-terry/magic_enum/blob/main/README.md)


用于枚举反射的仅需包含头文件的C++11库，支持枚举和枚举类。

Neargye’s [magic_enum](https://github.com/Neargye/magic_enum) 最低支持 C++17，但有时我们的代码是基于c++11的，所以有了这个项目。

由于c++11 不支持反射机制，仍然需要事先注册枚举，不能像Neargye的magic_enumyiy 一样直接使用。

仓库链接: [https://github.com/vistar-terry/magic_enum](https://github.com/vistar-terry/magic_enum)

issues: [https://github.com/vistar-terry/magic_enum/issues](https://github.com/vistar-terry/magic_enum/issues)

如果对你有帮助，欢迎Star，有任何问题可以在issues页面交流。



## 特点

- 支持 C++11
- 支持 `enum` 和 `enum class`
- 支持多作用域 `class` `namespace`
- 使用宏注册枚举
- 仅需包含头文件，没有其他依赖



## 限制

由于使用了模板特化，需要在全局作用域下注册枚举



## 示例

### 1. 基础使用方法

```cpp
#include "magic_enum.hpp"
#include <iostream>

using namespace magic_enum;

enum class Status {
    Idle,
    Running,
    Success,
    Failure
};

REGISTER_ENUM(Status, 
              Idle, Running, Success, Failure);

int main() {
    std::cout << enum_names(Status::Running); // Running
}
```

### 2. 枚举值转字符串

```cpp
Status status = Status::Running;
auto status_name = magic_enum::enum_name(status);
// status_name -> "Running"
```

### 3. 字符串转枚举值

```cpp
Status status_value = enum_cast<Status>("Success");
std::cout << "Status::Success Value: " << static_cast<int>(status_value) << std::endl;
// status_value -> 2
```

### 4. 获取枚举值列表

```cpp
auto statuses = magic_enum::enum_values<Status>();
// statuses -> {Status::Idle, Status::Running, Status::Success, Status::Failure}
// statuses[2] -> Status::Success
```

### 5. 获取枚举字符串列表

```cpp
auto es = magic_enum::enum_names<Status>();
// statuses -> {"Idle", "Running", "Success", "Failure"}
// statuses[2] -> "Success"
```

### 6. 获取枚举字典

```cpp
auto status_entries = magic_enum::enum_entries<Color>();
// status_entries -> {{Status::Idle, "Idle"}, {Status::Running, "Running"}, {Status::Success, "Success"}, {Status::Failure, "Failure"}}
// status_entries[0].first -> Status::Idle
// status_entries[0].second -> "Idle"
```



## 作用域

支持不同作用域的枚举

### 1. 全局

```cpp
enum class Status
{
    Idle,
    Running,
    Success,
    Failure = 6
};
REGISTER_ENUM(Status, Idle, Running, Success, Failure);
```

### 2. 类

```cpp
class Foo
{
public:
    enum class Status
    {
        Idle,
        Running,
        Success,
        Failure = 6
    };

public:
    Foo() {}
    ~Foo() {}
};
// 在类外的全局作用域注册枚举
REGISTER_ENUM(Foo::Status, Idle, Running, Success, Failure);
```

### 2. 名空间

```cpp
namespace ns
{
    enum class Status
    {
        Idle,
        Running,
        Success,
        Failure = 6
    };
}
// 在名空间作用域外的全局作用域注册枚举
REGISTER_ENUM(ns::Status, Idle, Running, Success, Failure);
```



## 构建示例

```bash
mkdir build && cd build
cmake ..
make
./magic_enum_example
```

