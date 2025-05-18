#include "magic_enum.hpp"
#include <iostream>

using namespace magic_enum;

enum Color
{
    Red = 1,
    Green,
    Blue = 5,
    Yellow,
    Grey
};
REGISTER_ENUM(Color, Red, Green, Blue, Yellow, Grey);

enum class Status
{
    Idle,
    Running,
    Success,
    Failure
};
REGISTER_ENUM(Status, Idle, Running, Success, Failure);

enum Fruit
{
    Apple = -1,
    Banana,
    Blueberry,
    Cherry = 6,
    Grape,
    Lemon,
    Orange = 11,
    Tomato
};
REGISTER_ENUM(Fruit, 
            Apple, Banana, Blueberry, Cherry,
            Grape, Lemon, Orange, Tomato);

int main()
{
    // 获取枚举值的字符串name
    std::cout << "Color::Green name: " << enum_name(Color::Green) << std::endl;
    std::cout << "Status::Running name: " << enum_name(Status::Running) << std::endl;
    std::cout << "Fruit::Blueberry name: " << enum_name(Fruit::Blueberry) << std::endl;

    // 字符串转枚举值
    Status status_value = enum_cast<Status>("Success");
    std::cout << "Status::Success value from string: " << static_cast<int>(status_value) << std::endl;

    // 通过向量索引访问枚举值
    auto statuses = enum_values<Status>();
    // statuses -> {Status::Idle, Status::Running, Status::Success, Status::Failure}
    std::cout << "Status::Success value from index: " << static_cast<int>(statuses[2]) << std::endl;

    // 获取枚举的所有成员名称
    std::cout << "Color names: ";
    for (auto v : enum_names<Color>())
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // 获取枚举的所有成员值
    std::cout << "Color values: ";
    for (auto v : enum_values<Color>())
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // 获取枚举的所有成员值
    std::cout << "Fruit values: ";
    for (auto v : enum_values<Fruit>())
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // 获取枚举的所有成员名称
    std::cout << "Fruit names: ";
    for (auto v : enum_names<Fruit>())
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // 获取枚举值字符串对
    std::cout << "Color entries: ";
    for (auto v : enum_entries<Color>())
    {
        std::cout << "{" << v.first << "::" << v.second << "}" << " ";
    }
    std::cout << std::endl;

    return 0;
}
