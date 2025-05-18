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
