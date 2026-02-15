#include <stdio.h>

enum class shape_type
{
    circle,
    triangle,
    rectangle
};

class shape
{
public:
    shape() { puts("shape"); }
    ~shape() { puts("~shape"); }
};

class circle : public shape
{
public:
    circle() { puts("circle"); }
    ~circle() { puts("~circle"); }
};

class triangle : public shape
{
public:
    triangle() { puts("triangle"); }
    ~triangle() { puts("~triangle"); }
};

class rectangle : public shape
{
public:
    rectangle() { puts("rectangle"); }
    ~rectangle() { puts("~rectangle"); }
};

// 此方法编译期不会报错
// 这种现象为对象切片: 值赋值而不是基类指针引用赋值
shape* create_shape(shape_type type)
{
    switch (type)
    {
    case shape_type::circle:
        return new circle();
    case shape_type::triangle:
        return new triangle();
    case shape_type::rectangle:
        return new rectangle();
    }
}

class shape_wrapper
{
public:
    explicit shape_wrapper(
        shape *ptr = nullptr)
        : ptr_(ptr) {}
    ~shape_wrapper()
    {
        delete ptr_;
    }
    shape *get() const { return ptr_; }

private:
    shape *ptr_;
};

int main()
{
    shape_wrapper ptr_wrap(create_shape(shape_type::circle));
}

// 引用坍缩
void foo(const shape&)
{
  puts("foo(const shape&)");
}

void foo(shape&&)
{
  puts("foo(shape&&)");
}

void bar(const shape& s)
{
  puts("bar(const shape&)");
  foo(s);
}

void bar(shape&& s)
{
  puts("bar(shape&&)");
  foo(s);
}

// 保持参数的值类别：左值的仍然是左值，右值的仍然是右值
template <typename T>
void bar(T&& s)
{
  foo(std::forward<T>(s));
}


int main()
{
  bar(circle());
}