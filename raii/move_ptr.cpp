#include <utility>
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
    explicit operator bool() const { return ptr_; }

    // Move Constructor
    smart_ptr(smart_ptr &&other) noexcept { ptr_ = other.release(); }
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
    void swap(smart_ptr &rhs) noexcept {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

    template <typename U>
    explicit smart_ptr(smart_ptr<U> &&other)
    {
        ptr_ = other.release();
    }

private:
    T *ptr_;
};

/*

smart_ptr<shape> ptr1{create_shape(shape_type::circle)};
smart_ptr<shape> ptr2{ptr1};             // It will cause errors during compilation
smart_ptr<shape> ptr3;
ptr3 = ptr1;                             // It will cause errors during compilation
ptr3 = std::move(ptr1);                  // OK
smart_ptr<shape> ptr4{std::move(ptr3)};  // OK



smart_ptr<shape> ptr1{new circle()};
smart_ptr<shape> ptr2 = std::move(ptr1);

std::move(ptr) equals static_cast<smart_ptr<shape>&&> (ptr)
*/