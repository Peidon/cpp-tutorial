#include "../include/shape.h"
#include <iostream>

shape::shape() { puts("shape"); }
shape::~shape() { puts("~shape"); }

circle::circle() { puts("circle"); }
circle::~circle() { puts("~circle"); }

triangle::triangle() { puts("triangle"); }
triangle::~triangle() { puts("~triangle"); }

rectangle::rectangle() { puts("rectangle"); }
rectangle::~rectangle() { puts("~rectangle"); }

shape *create_shape(shape_type type)
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
    return nullptr;
}

shape_wrapper::shape_wrapper(shape *ptr)
    : ptr_(ptr)
{
}

shape_wrapper::~shape_wrapper()
{
    delete ptr_;
}

shape *shape_wrapper::get() const
{
    return ptr_;
}