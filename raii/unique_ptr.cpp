#include <utility>   // std::move, std::swap
#include <cstddef>   // std::nullptr_t

template <typename T>
class unique_ptr
{
public:
    // Constructors
    constexpr unique_ptr() noexcept : ptr_(nullptr) {}
    explicit unique_ptr(T* ptr) noexcept : ptr_(ptr) {}

    // Destructor
    ~unique_ptr()
    {
        delete ptr_;
    }

    // ❌ No copying allowed
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // ✅ Move constructor
    unique_ptr(unique_ptr&& other) noexcept
        : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }

    // ✅ Move assignment
    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr_;              // clean up current resource
            ptr_ = other.ptr_;        // steal pointer
            other.ptr_ = nullptr;     // reset source
        }
        return *this;
    }

    // Observers
    T* get() const noexcept { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }
    explicit operator bool() const noexcept { return ptr_ != nullptr; }

    // Modifiers
    T* release() noexcept
    {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    void reset(T* ptr = nullptr) noexcept
    {
        delete ptr_;
        ptr_ = ptr;
    }

    void swap(unique_ptr& other) noexcept
    {
        using std::swap;
        swap(ptr_, other.ptr_);
    }

private:
    T* ptr_;
};