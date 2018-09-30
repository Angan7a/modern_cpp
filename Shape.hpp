#pragma once

enum class Color
{
    red,
    blue,
    green
};

class Shape
{
protected:
    Color color;
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
