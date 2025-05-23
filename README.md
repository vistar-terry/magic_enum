# Magic Enum C++11

![ascii-text-art](img/ascii-text-art.png)

[![C++11](https://img.shields.io/badge/c++-11-orange.svg)](https://en.cppreference.com/w/cpp/11) [![License](https://img.shields.io/badge/license-MIT-green)](https://github.com/vistar-terry/magic_enum/blob/main/LICENSE) [![Header-only](https://img.shields.io/badge/header--only-yes-yellowgreen)](#) [![README](https://img.shields.io/badge/README-Chinese-red)](https://github.com/vistar-terry/magic_enum/blob/main/README_ZH.md) [![README](https://img.shields.io/badge/README-English-blue)](https://github.com/vistar-terry/magic_enum/blob/main/README.md)

A header-only C++11 library for enum reflection supporting enum and enum class.

While [magic_enum](https://github.com/Neargye/magic_enum) (by Neargye) mandates C++17, many legacy systems still rely on C++11 - hence this project was developed.

Since C++11 does not support reflection mechanisms, it is still necessary to register enums in advance and they cannot be used directly like Neargye's magic_enum.

repository url: [https://github.com/vistar-terry/magic_enum](https://github.com/vistar-terry/magic_enum)

issues: [https://github.com/vistar-terry/magic_enum/issues](https://github.com/vistar-terry/magic_enum/issues)

If this project helps you, please consider giving it a star! 

You can also communicate any issues on the issues page.



## Features

- Support for C++11
- Support for `enum` and `enum class`
- Registration with macros
- Header-only, no dependencies



## Examples

### 1. Basic

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

### 2. Enum value to string

```cpp
Status status = Status::Running;
auto status_name = magic_enum::enum_name(status);
// status_name -> "Running"
```

### 3. String to enum value

```cpp
Status status_value = enum_cast<Status>("Success");
std::cout << "Status::Success Value: " << static_cast<int>(status_value) << std::endl;
// status_value -> 2
```

### 4. Enum value sequence

```cpp
auto statuses = magic_enum::enum_values<Status>();
// statuses -> {Status::Idle, Status::Running, Status::Success, Status::Failure}
// statuses[2] -> Status::Success
```

### 5. Enum names sequence

```cpp
auto es = magic_enum::enum_names<Status>();
// statuses -> {"Idle", "Running", "Success", "Failure"}
// statuses[2] -> "Success"
```

### 6. Enum entries sequence

```cpp
auto status_entries = magic_enum::enum_entries<Color>();
// status_entries -> {{Status::Idle, "Idle"}, {Status::Running, "Running"}, {Status::Success, "Success"}, {Status::Failure, "Failure"}}
// status_entries[0].first -> Status::Idle
// status_entries[0].second -> "Idle"
```



## Build Example

```bash
mkdir build && cd build
cmake ..
make
./magic_enum_example
```


