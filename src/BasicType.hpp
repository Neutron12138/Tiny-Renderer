#ifndef TR_BASICTYPE_HPP
#define TR_BASICTYPE_HPP

#include <cstdint>

namespace tr
{
    using Int8 = std::int8_t;
    using Int16 = std::int16_t;
    using Int32 = std::int32_t;
    using Int64 = std::int64_t;

    using UInt8 = std::uint8_t;
    using UInt16 = std::uint16_t;
    using UInt32 = std::uint32_t;
    using UInt64 = std::uint64_t;

    using Char = char;

    using SizeT = std::size_t;
    using EnumT = UInt32;

} // namespace tr

#endif
