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
#include <cassert>

using namespace magic_enum;

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
REGISTER_ENUM(Fruit, Apple, Banana, Blueberry, Cherry,
                        Grape, Lemon, Orange, Tomato);

int main()
{
    assert(enum_name(Fruit::Apple) == "Apple");
    assert(enum_cast<Fruit>("Apple") == Fruit::Apple);
    assert(enum_name(Fruit::Banana) == "Banana");
    assert(enum_cast<Fruit>("Orange") == Fruit::Orange);
    assert(enum_name(Fruit::Grape) == "Grape");
    assert(enum_cast<Fruit>("Tomato") == Fruit::Tomato);

    return 0;
}
