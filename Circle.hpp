#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle() = delete; // doesn't allow to call default constructor
    Circle(double r);
    Circle(const Circle & other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;
    [[deprecated]]
    double getPi() const;

private:
    double r_;
};
