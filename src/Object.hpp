#ifndef TR_OBJECT_HPP
#define TR_OBJECT_HPP

#define TR_ALIGN alignas(1)

namespace tr
{
    class TR_ALIGN Object
    {
    };

    class NonCopyable : public Object
    {
    public:
        NonCopyable() = default;
        NonCopyable(const NonCopyable &) = delete;
        NonCopyable &operator=(const NonCopyable &) = delete;
    };

} // namespace tr

#endif
