#ifndef TR_LOG_CPP
#define TR_LOG_CPP

#include "Log.hpp"

namespace tr
{
    Log::Log()
    {
        m_fout.open("log.txt");
        if (m_fout.fail())
        {
            m_fout.close();
            throw std::runtime_error(
                to_string(
                    TR_DEBUG,
                    "Unable to open file: \"log. txt\""));
        }
    }

    Log::~Log()
    {
        m_fout.close();
    }

    std::ostream &Log::get()
    {
        if (m_target == FILE)
            return m_fout;
        else
            return std::cout;
    }

    const std::ostream &Log::get() const
    {
        if (m_target == FILE)
            return m_fout;
        else
            return std::cout;
    }

    Log::operator std::ostream &()
    {
        return get();
    }

    Log::operator const std::ostream &() const
    {
        return get();
    }

    void Log::set_target(Target target)
    {
        m_target = target;
    }

    void Log::flush()
    {
        get().flush();
    }

} // namespace tr

#endif
