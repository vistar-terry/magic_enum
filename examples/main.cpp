//  __  __             _        ______                          _____          __ __ 
// |  \/  |           (_)      |  ____|                        / ____|_     _ /_ /_ |
// | \  / | __ _  __ _ _  ___  | |__   _ __  _   _ _ __ ___   | |   _| |_ _| |_| || |
// | |\/| |/ _` |/ _` | |/ __| |  __| | '_ \| | | | '_ ` _ \  | |  |_   _|_   _| || |
// | |  | | (_| | (_| | | (__  | |____| | | | |_| | | | | | | | |____|_|   |_| | || |
// |_|  |_|\__,_|\__, |_|\___| |______|_| |_|\__,_|_| |_| |_|  \_____|         |_||_|
//                __/ |                                                              
//               |___/        https://github.com/vistar-terry/magic_enum
//                            Magic Enum C++11 - version 0.1.0
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 <vistar-terry>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
