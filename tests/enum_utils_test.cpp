#include <gtest/gtest.h>

#include <cstdint>
#include <integra/enum_utils.hpp>
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
    EXPECT_EQ(integra::EnumValue(Command::eReset), 1U);
    EXPECT_EQ(integra::EnumValue(Command::eStart), 7U);
}

TEST(EnumUtilsTest, KeepsTheUnderlyingType)
{
    static_assert(std::is_same_v<decltype(integra::EnumValue(Command::eReset)), std::uint8_t>);
    static_assert(std::is_same_v<decltype(integra::EnumValue(Offset::eBelow)), std::int16_t>);
    EXPECT_EQ(integra::EnumValue(Offset::eBelow), -3);
}

TEST(EnumUtilsTest, WorksAtCompileTime)
{
    static_assert(integra::EnumValue(Command::eStart) == 7U);
    SUCCEED();
}

} // namespace
