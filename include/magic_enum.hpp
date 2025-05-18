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


#ifndef MAGIC_ENUM_HPP
#define MAGIC_ENUM_HPP

#include <string>
#include <map>
#include <vector>
#include <stdexcept>

namespace magic_enum
{

// ================================== Internal implementation ==================================
    template <typename T, typename Enable = void>
    struct EnumTraits;

    template <typename T>
    using IsEnum = typename std::enable_if<std::is_enum<T>::value>::type;

#define REGISTER_ENUM_IMPL(EnumType, ...)                                         \
    namespace magic_enum                                                          \
    {                                                                             \
        template <>                                                               \
        struct EnumTraits<EnumType, IsEnum<EnumType>>                             \
        {                                                                         \
            static const std::map<EnumType, std::string> &value_to_name_map()     \
            {                                                                     \
                static const std::map<EnumType, std::string> map = {__VA_ARGS__}; \
                return map;                                                       \
            }                                                                     \
            static const std::map<std::string, EnumType> &name_to_value_map()     \
            {                                                                     \
                static std::map<std::string, EnumType> map;                       \
                if (map.empty())                                                  \
                {                                                                 \
                    for (const auto &kv : value_to_name_map())                    \
                    {                                                             \
                        map[kv.second] = kv.first;                                \
                    }                                                             \
                }                                                                 \
                return map;                                                       \
            }                                                                     \
            static const std::vector<EnumType> &values()                          \
            {                                                                     \
                static std::vector<EnumType> vec;                                 \
                if (vec.empty())                                                  \
                {                                                                 \
                    for (const auto &kv : value_to_name_map())                    \
                    {                                                             \
                        vec.push_back(kv.first);                                  \
                    }                                                             \
                }                                                                 \
                return vec;                                                       \
            }                                                                     \
            static const std::vector<std::string> &names()                        \
            {                                                                     \
                static std::vector<std::string> vec;                              \
                if (vec.empty())                                                  \
                {                                                                 \
                    for (const auto &kv : value_to_name_map())                    \
                    {                                                             \
                        vec.push_back(kv.second);                                 \
                    }                                                             \
                }                                                                 \
                return vec;                                                       \
            }                                                                     \
        };                                                                        \
    }

// Produce enum-to-string mappings，{EnumType::Name, "Name"}
#define ENUM_REFLECT_PAIR(EnumType, Name) {EnumType::Name, #Name}

// Auto-adapts to enum member count (max 20 supported), with extensible architecture
#define EXPAND(x) x
#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, NAME, ...) NAME

#define ENUM_REFLECT_IMPL(EnumType, PAIR_MACRO, ...)                                                         \
    EXPAND(GET_MACRO(__VA_ARGS__,                                                                            \
                     ENUM_REFLECT_IMPL_20, ENUM_REFLECT_IMPL_19, ENUM_REFLECT_IMPL_18, ENUM_REFLECT_IMPL_17, \
                     ENUM_REFLECT_IMPL_16, ENUM_REFLECT_IMPL_15, ENUM_REFLECT_IMPL_14, ENUM_REFLECT_IMPL_13, \
                     ENUM_REFLECT_IMPL_12, ENUM_REFLECT_IMPL_11, ENUM_REFLECT_IMPL_10, ENUM_REFLECT_IMPL_9,  \
                     ENUM_REFLECT_IMPL_8, ENUM_REFLECT_IMPL_7, ENUM_REFLECT_IMPL_6, ENUM_REFLECT_IMPL_5,     \
                     ENUM_REFLECT_IMPL_4, ENUM_REFLECT_IMPL_3, ENUM_REFLECT_IMPL_2, ENUM_REFLECT_IMPL_1)(EnumType, PAIR_MACRO, __VA_ARGS__))

#define ENUM_REFLECT_IMPL_1(EnumType, M, A) M(EnumType, A)
#define ENUM_REFLECT_IMPL_2(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_1(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_3(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_2(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_4(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_3(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_5(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_4(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_6(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_5(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_7(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_6(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_8(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_7(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_9(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_8(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_10(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_9(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_11(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_10(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_12(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_11(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_13(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_12(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_14(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_13(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_15(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_14(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_16(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_15(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_17(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_16(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_18(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_17(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_19(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_18(EnumType, M, __VA_ARGS__)
#define ENUM_REFLECT_IMPL_20(EnumType, M, A, ...) M(EnumType, A), ENUM_REFLECT_IMPL_19(EnumType, M, __VA_ARGS__)

// ================================== Public API ==================================

// Registration Macro for External Enum Registration
#define REGISTER_ENUM(EnumType, ...) \
    REGISTER_ENUM_IMPL(EnumType, ENUM_REFLECT_IMPL(EnumType, ENUM_REFLECT_PAIR, __VA_ARGS__))

    // Enum value to string
    template <typename T>
    std::string enum_name(T value)
    {
        const auto &map = EnumTraits<T>::value_to_name_map();
        auto it = map.find(value);
        if (it != map.end())
        {
            return it->second;
        }
        return "Unknown";
    }

    // String to enum value
    template <typename T>
    T enum_cast(const std::string &name)
    {
        const auto &map = EnumTraits<T>::name_to_value_map();
        auto it = map.find(name);
        if (it != map.end())
        {
            return it->second;
        }
        throw std::runtime_error("Invalid enum name: " + name);
    }

    // Enum value sequence
    template <typename T>
    const std::vector<T> &enum_values()
    {
        return EnumTraits<T>::values();
    }

    // Enum names sequence
    template <typename T>
    const std::vector<std::string> &enum_names()
    {
        return EnumTraits<T>::names();
    }

    // Enum entries sequence
    template <typename T>
    const std::map<T, std::string> &enum_entries()
    {
        return EnumTraits<T>::value_to_name_map();
    }

} // namespace magic_enum

#endif
