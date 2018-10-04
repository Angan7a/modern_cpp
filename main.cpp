#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](auto first, auto second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](auto s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
};

auto areaLessThanX = [x = 10](auto s)
{
    if(s)
    {
        return (s->getArea() < x);
    }
    return false;
};

void printCollectionElements(const Collection& collection)
{
    for(auto it : collection)
    {
        if(it != nullptr)
        {
            it->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for(auto it : collection)
    {
        if(it != nullptr)
        {
            cout << it->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main()
{
    cout << alignof(Circle) << endl;
    Collection shapes {
    make_shared<Circle>(2.0),
    make_shared<Circle>(3.0),
    nullptr,
    make_shared<Circle>(4.0),
    make_shared<Rectangle>(10.0, 5.0),
    make_shared<Square>(3.0),
    make_shared<Circle>(4.0) };

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    shared_ptr<Square> square = make_shared<Square>(4.0);
    shapes.push_back(square);

    unique_ptr<Shape> circle = make_unique<Circle>(5.0);
    shapes.push_back(move(circle));

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");
    
    Circle c1(8.0);
    Circle cc1(8.0), cc(7.0);
    cc = move(cc1);
    Circle c2(move(c1));
    auto s1 = make_shape<Circle>(5.0, Color::green);
    cout <<"Color circle is " << static_cast<int>(s1->getColor()) << endl;
//    cout <<"Color circle is " << Color[Color::red] << endl;
    return 0;
}

