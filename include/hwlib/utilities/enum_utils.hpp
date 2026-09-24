#pragma once
#include <type_traits>

namespace hwlib::utilities
{

/// @brief Convert an enumerator to its underlying value
///
/// @param value An enumerator
/// @return underlying numerical value of the enumerator
template<typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
[[nodiscard]] constexpr auto EnumValue(Enum value) noexcept
{
    return static_cast<std::underlying_type_t<Enum>>(value);
}

} // namespace hwlib::utilities
