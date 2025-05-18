# Magic Enum C++11

A header-only C++11 library for enum reflection supporting enum and enum class.

repository url: [https://github.com/vistar-terry/magic_enum](https://github.com/vistar-terry/magic_enum)

issues: [https://github.com/vistar-terry/magic_enum/issues](https://github.com/vistar-terry/magic_enum/issues)



## Features

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



## License

MIT
