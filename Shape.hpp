#pragma once
#include <memory>

enum class Color
{
    red,
    blue,
    green
};

class Shape
{
protected:
    Color color_;
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    virtual Color getColor() const { return color_;}
};

template<class DerivedType, class... Arguments> 
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return std::make_shared<DerivedType>(args...);
}
