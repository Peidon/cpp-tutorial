#pragma once
enum class shape_type
{
    circle,
    triangle,
    rectangle
};

class shape
{
public:
    shape();
    virtual ~shape();
};

class circle : public shape
{
public:
    circle();
    ~circle() override;
};

class triangle : public shape
{
public:
    triangle();
    ~triangle() override;
};

class rectangle : public shape
{
public:
    rectangle();
    ~rectangle() override;
};

shape *create_shape(shape_type type);

class shape_wrapper
{
public:
    explicit shape_wrapper(shape *ptr = nullptr);
    ~shape_wrapper();

    shape *get() const;

private:
    shape *ptr_;
};