#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : Circle(r, Color::red)
{}

Circle::Circle(double r, Color color)
    : r_(r)
{
    color_ = color;
}

Circle::Circle(Circle && other) noexcept 
    : r_(std::move(other.r_))
{
    std::cout << "Move constructor " << std::endl;
}

Circle& Circle::operator = (Circle && other) noexcept
{
    std::cout << "Move assignment operator" << std::endl;
    r_ = std::move(other.r_);
    return *this;
}

double Circle::getArea() const noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}

double Circle::getPi() const
{
    return M_PI;
}
