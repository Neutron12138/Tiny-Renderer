#ifndef TR_LOG_HPP
#define TR_LOG_HPP

#include <iostream>
#include <fstream>
#include <variant>
#include "Utils.hpp"

namespace tr
{
    class Log
    {
    public:
        enum Target
        {
            STDOUT,
            FILE,
        };

    private:
        std::ofstream m_fout;
        Target m_target = STDOUT;

    public:
        Log();
        ~Log();

    public:
        std::ostream &get();
        const std::ostream &get() const;
        operator std::ostream &();
        operator const std::ostream &() const;

    public:
        void set_target(Target target);
        void flush();
    };

    static Log log;

} // namespace tr

#endif
