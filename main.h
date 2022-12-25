#pragma once

#include <bit>
#include <array>
#include <string.h>

using namespace std;
struct uint24_t
{
  static constexpr uint32_t max = (256 * 256 * 256) - 1;
  static constexpr uint8_t hibyte = endian::native == endian::little ? 2 : 0;
  static constexpr uint8_t lobyte = endian::native == endian::little ? 0 : 2;

  constexpr uint24_t () noexcept = default;
  constexpr uint24_t (const uint24_t &) noexcept = default;
  constexpr uint24_t (uint24_t &&) noexcept = default;

  constexpr uint24_t & operator= (const uint24_t &) noexcept = default;
  constexpr uint24_t & operator= (uint24_t &&) noexcept = default;

  constexpr uint24_t (uint32_t u) noexcept:m_Data{}
  {
    uint32_t wrapped_u32 = u % (max + 1);
    m_Data[hibyte] = wrapped_u32 >> 16;
    m_Data[1] = (wrapped_u32 >> 8) & 0xFF;
    m_Data[lobyte] = wrapped_u32 & 0xFF;
  }

  constexpr auto operator+= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this + other);
  }

  constexpr auto operator++ (int) noexcept->uint24_t &
  {
    return (*this) = ((*this) + 1);
  }

  constexpr auto operator-- (int) noexcept->uint24_t &
  {
    return (*this) = ((*this) - 1);
  }

  constexpr auto operator++ () noexcept->uint24_t &
  {
    return (*this) = ((*this) + 1);
  }

  constexpr auto operator-- () noexcept->uint24_t &
  {
    return (*this) = ((*this) - 1);
  }

  constexpr auto operator-= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this - other);
  }

  constexpr auto operator*= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this * other);
  }

  constexpr auto operator/= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this / other);
  }

  constexpr auto operator%= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this % other);
  }

  constexpr auto operator&= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this & other);
  }

  constexpr auto operator|= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this | other);
  }

  constexpr auto operator^= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this ^ other);
  }

  constexpr auto operator<<= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this << other);
  }

  constexpr auto operator>>= (const uint24_t & other) noexcept->uint24_t &
  {
    return (*this) = (*this >> other);
  }

  constexpr operator uint32_t () const noexcept
  {
    return ((m_Data[hibyte] << 16) | m_Data[1] << 8 | m_Data[lobyte]);
  }
  

private:
    array < uint8_t, 3 > m_Data{};
};

uint24_t ntohu(uint24_t const net) {
    uint8_t data[3] = {};
    memcpy(&data, &net, sizeof(data));

    return ((uint24_t) data[2] << 0)
         | ((uint24_t) data[1] << 8)
         | ((uint24_t) data[0] << 16);
}
