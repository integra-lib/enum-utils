#include <gtest/gtest.h>

#include <cstdint>
#include <hwlib/utilities/enum_utils.hpp>
#include <type_traits>

namespace
{

enum class Command : std::uint8_t
{
    eReset = 1U,
    eStart = 7U,
};

enum class Offset : std::int16_t
{
    eBelow = -3,
};

TEST(EnumUtilsTest, ReturnsTheUnderlyingValue)
{
    EXPECT_EQ(hwlib::utilities::EnumValue(Command::eReset), 1U);
    EXPECT_EQ(hwlib::utilities::EnumValue(Command::eStart), 7U);
}

TEST(EnumUtilsTest, KeepsTheUnderlyingType)
{
    static_assert(std::is_same_v<decltype(hwlib::utilities::EnumValue(Command::eReset)), std::uint8_t>);
    static_assert(std::is_same_v<decltype(hwlib::utilities::EnumValue(Offset::eBelow)), std::int16_t>);
    EXPECT_EQ(hwlib::utilities::EnumValue(Offset::eBelow), -3);
}

TEST(EnumUtilsTest, WorksAtCompileTime)
{
    static_assert(hwlib::utilities::EnumValue(Command::eStart) == 7U);
    SUCCEED();
}

} // namespace
