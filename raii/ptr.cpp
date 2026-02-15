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
The copy constructor is not implemented.

smart_ptr<shape> ptr1{create_shape(shape_type::circle)};
smart_ptr<shape> ptr2{ptr1};

It will not cause errors during compilation, 
but will exhibit undefined behavior at runtime 
—- because it will free the same memory twice, which usually leads to program crashes.
*/