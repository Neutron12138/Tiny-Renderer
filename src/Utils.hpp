#ifndef TR_UTILS_HPP
#define TR_UTILS_HPP

#include <string>
#include <sstream>
#include <ctime>

#define TR_DEBUG                        \
    tr::to_string(                      \
        "[at file: \"", __FILE__,       \
        "\", line: ", __LINE__,         \
        ", function: \"", __FUNCTION__, \
        "\"]\n")

namespace tr
{
    std::string to_string();

    template <typename T>
    std::string to_string(const T &value);

    template <typename T, typename... ArgsT>
    std::string to_string(const T &value, const ArgsT &...args);

    float get_current_clocks();

} // namespace tr

#endif
