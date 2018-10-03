#pragma once

#include "Shape.hpp"

class alignas(2) Circle final : public Shape
{
public:
    Circle() = delete; // doesn't allow to call default constructor
    Circle(double r);
    Circle(double r, Color color);
    Circle(const Circle & other) = default;
    Circle(const Circle && other) noexcept;
    Circle& operator = (const Circle && other) noexcept;
    Circle& operator = (const Circle & other) = default;
    ~Circle() = default;

    double getArea() const noexcept override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;
    [[deprecated]]
    double getPi() const;

private:
    double r_;
};
