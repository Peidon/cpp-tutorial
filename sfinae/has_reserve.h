
template <typename T>
struct has_reserve
{
    struct good
    {
        char dummy;
    };
    struct bad
    {
        char dummy[2];
    };
    
    template <class U,
              void (U::*)(size_t)>
    struct SFINAE
    {
    };

    template <class U>
    static good reserve(SFINAE<U, &U::reserve> *); // 检测 has_reserve 中是否有一个名叫 reserve、参数类型为 size_t 的成员函数

    template <class U>
    static bad reserve(SFINAE<U, &U::reserve> *);

    static const bool value = sizeof(reserve<T>(nullptr)) == sizeof(good);
};