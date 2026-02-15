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

    // 实现移动构造
    smart_ptr(smart_ptr &&other) { ptr_ = other.release(); }
    smart_ptr &operator=(smart_ptr rhs)
    {
        rhs.swap(*this);
        return *this;
    }
    T *release()
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }
    void swap(smart_ptr &rhs)
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

    template <typename U>
    smart_ptr(smart_ptr<U> &&other)
    {
        ptr_ = other.release();
    }

private:
    T *ptr_;
};

/*

smart_ptr<shape> ptr1{create_shape(shape_type::circle)};
smart_ptr<shape> ptr2{ptr1};             // 编译出错
smart_ptr<shape> ptr3;
ptr3 = ptr1;                             // 编译出错
ptr3 = std::move(ptr1);                  // OK，可以
smart_ptr<shape> ptr4{std::move(ptr3)};  // OK，可以



smart_ptr<shape> ptr1{new circle()};
smart_ptr<shape> ptr2 = std::move(ptr1);

std::move(ptr) 的作用是把一个左值引用强制转换成一个右值引用，而并不改变其内容
从实用的角度，在我们这儿 std::move(ptr1) 等价于 static_cast<smart_ptr<shape>&&> (ptr1)
因此 std::move(ptr1) 的结果是指向 ptr1 的一个右值引用

*/