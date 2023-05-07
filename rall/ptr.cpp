template <typename T>
class smart_ptr
{
public:
    explicit smart_ptr(T *ptr = nullptr)
        : ptr_(ptr) {}
    
    ~smart_ptr()
    {
        delete ptr_;
    }

    T *get() const { return ptr_; }

    T &operator*() const { return *ptr_; }
    T *operator->() const { return ptr_; }
    operator bool() const { return ptr_; }

private:
    T *ptr_;
};

/*
没有实现拷贝构造

此时
smart_ptr<shape> ptr1{create_shape(shape_type::circle)};
smart_ptr<shape> ptr2{ptr1};
在编译时不会出错，但在运行时却会有未定义行为——由于会对同一内存释放两次，通常情况下会导致程序崩溃
*/