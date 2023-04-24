# 6.096 - Introduction To C++ - Lab 3

## Catch that bug

1. `const` object calls non-`const` functions in Line 21 and 22.
- [ ] Line 20 misses a `;`.
2. `const` function cannot modify the member `x` in Line 11.
3. `private` variables cannot be accessed directly in Line 16.
4. `Point::setX(...)`
5. `delete[] nums`
6. `new` should be paired with `delete`.

## `Point`

See code in Appendix.

## `PointArray`

See code in Appendix.

4.5.1 Non-`const` version is used when we need to modify the returned `Point`; `const` version is used when we defined a `const` `PointArray` and we need to get its `Point` somewhere.

## `Polygon`

### Constructors/Destructors

If we try to copy a `Polygon` and don’t define our own copy constructor, i.e.,
```c++
Polygon pl2 = pl1;
```
the default copy constructor will be called to copy each non-static data member by their copy constructors.

Reference: https://en.cppreference.com/w/cpp/language/copy_constructor

### Questions

1. Then we are unable to call `Point(...)` to construct an instance.
2. Firstly, call `~Polygon()` where `numOfPoly` is substracted by one. Secondly, `pointArray` is automatically destroyed, which means `~~PointArray()` is called.
3. Make the members accessible by its subclass.
4. `Polygon` version. But if we define the function as virtual in `Polygon`, it will be the subclass versions.

- [ ] Bugs and improvements shown in the code.

## Strings

```c++
string pigLatinify(string str) {
    if (VOWELS.find(str[0]) == string::npos)
    {
        if (str[0] == 'q')
        {
            if (str[1] == 'u')
            {
                return str.substr(2) + "-quay";
            }
        }
        return str.substr(1) + '-' + str[0] + "ay";
    } else return str + "-way";
}
```

## Appendix

```c++
// geometry.h
class Point {
private:
    int x, y;
public:
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {};

    int getX() const { return x; };

    int getY() const { return y; };

    void setX(const int new_x) { x = new_x; };

    void setY(const int new_y) { y = new_y; };
};

class PointArray {
private:
    Point *begin;
    int size;

    void resize(int n);

public:
    PointArray();

    PointArray(const Point points[], const int size);

    PointArray(const PointArray &pv);

    void push_back(const Point &p);

    void insert(const int position, const Point &p);

    void remove(const int pos);

    const int getSize() const { return size; };

    void clear() { resize(0); };

    Point *get(const int position);

    const Point *get(const int position) const;

    ~PointArray();
};

class Polygon {
protected:
    PointArray pointArray;
    static int numOfPoly;
public:
    Polygon(const Point points[], const int len) : pointArray(points, len) { numOfPoly++; };

    Polygon(const PointArray &pa) : pointArray(pa) { numOfPoly++; };

    ~Polygon() { numOfPoly--; };

    virtual double area() = 0; // improve: declared as const function

    static int getNumPolygons() { return numOfPoly; };

    int getNumSides() { return pointArray.getSize() - 1; }; // bug: remove '-1'; improve: declared as const function

    const PointArray getPoints() { return pointArray; };
};

Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3,
                               const Point &p4 = Point(0, 0));

const int RECTANGLE_POINT_NUM = 4;

class Rectangle : public Polygon {
public:
    Rectangle(Point low_left, Point top_right) : Polygon(
            updateConstructorPoints(
                    low_left, Point(low_left.getX(), top_right.getY()),
                    top_right, Point(low_left.getY(), top_right.getX())
            ), RECTANGLE_POINT_NUM
    ) {};

    Rectangle(int low_left_x, int low_left_y, int top_right_x, int top_right_y) : Rectangle(
            Point(low_left_x, low_left_y), Point(top_right_x, top_right_y)
    ) {};

    double area() override;
};

const int TRIANGLE_POINT_NUM = 3;

class Triangle : public Polygon {
public:
    Triangle(Point a, Point b, Point c) : Polygon(
            updateConstructorPoints(
                    a, b, c
            ), TRIANGLE_POINT_NUM
    ) {};

    double area() override;
};
```

```c++
// geometry.cpp
#include "geometry.h"
#include "cmath"

PointArray::PointArray() {
    size = 0;
    begin = new Point[size];
}

PointArray::PointArray(const Point points[], const int size) {
    this->size = size;
    begin = new Point[size];
    for (int i = 0; i < size; i++) {
        *(begin + i) = Point(points[i].getX(), points[i].getY());
    }
}

PointArray::PointArray(const PointArray &pv) {
    size = pv.size;
    begin = new Point[size];
    for (int i = 0; i < size; i++) {
        *(begin + i) = Point((pv.begin + i)->getX(), (pv.begin + i)->getY());
    }
}

PointArray::~PointArray() {
    delete[] begin;
}

void PointArray::resize(int n) {
    auto *new_begin = new Point[n];
    for (int i = 0; i < n && i < size; ++i) {
        *(new_begin + i) = *(begin + i);
    }
    delete[] begin;
    begin = new_begin;
    size = n;
}

void PointArray::push_back(const Point &p) {
    resize(size + 1);
    *(begin + size - 1) = p;
}

void PointArray::insert(const int position, const Point &p) {
    resize(size + 1);
    for (int i = size - 1; i > position; --i) {
        *(begin + i) = *(begin + i - 1);
    }
    *(begin + position) = p;
}

void PointArray::remove(const int pos) {
    for (int i = pos; i < size; ++i) {
        *(begin + i) = *(begin + i + 1);
    }
    resize(size - 1);
}

Point *PointArray::get(const int position) {
    if (position < size) {
        return begin + position;
    }
    return nullptr;
}

const Point *PointArray::get(const int position) const {
    if (position < size) {
        return begin + position;
    }
    return nullptr;
}

int Polygon::numOfPoly = 0;
Point constructorPoints[4];

Point *updateConstructorPoints(const Point &p1, const Point &p2,
                               const Point &p3, const Point &p4) {
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

double Rectangle::area() {
    Point low_left = *this->pointArray.get(0);
    Point top_right = *this->pointArray.get(RECTANGLE_POINT_NUM / 2);
    int a = abs(low_left.getX() - top_right.getX());
    int b = abs(low_left.getY() - top_right.getY());
    return a * b;
}

double Triangle::area() {
    Point p1 = *this->pointArray.get(0);
    Point p2 = *this->pointArray.get(1);
    Point p3 = *this->pointArray.get(2);

    double a = sqrt(pow((p1.getX() - p2.getX()), 2) +
                    pow((p1.getY() - p2.getY()), 2));
    double b = sqrt(pow((p2.getX() - p3.getX()), 2) +
                    pow((p2.getY() - p3.getY()), 2));
    double c = sqrt(pow((p1.getX() - p3.getX()), 2) +
                    pow((p1.getY() - p3.getY()), 2));
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
```

```c++
#include <iostream>
#include "geometry.h"

using namespace std;

void printAttributes(Polygon *);

int main() {
    // test for the exercises
    /*
    Point p;
    cout << p.getX() << ' ' << p.getY() << endl;

    PointArray pa;
    Point pb[] = {Point(), Point(1, 1), Point(1, 0), Point()};
    PointArray pc = PointArray(pb, 4);
    PointArray pd = PointArray(pc);

    cout << pc.get(1)->getX() << endl;
    pc.push_back(Point(3, 6));
    cout << pc.get(4)->getX() << endl;
    pc.remove(3);
    cout << pc.get(3)->getX() << endl;
    pc.insert(1, Point(2, 2));
    cout << pc.get(1)->getX() << ' ' << pc.get(3)->getX() << endl;
    pc.clear();
    cout << pc.getSize() << endl;
    if (pc.get(0) == nullptr) {
        cout << "nullptr" << endl;
    }
    */

    int low_left_x, low_left_y, top_right_x, top_right_y;
    cout << "Input the lower-left position of a Rectangle: ";
    cin >> low_left_x >> low_left_y;
    cout << "Input the upper-right position of a Rectangle: ";
    cin >> top_right_x >> top_right_y;
    Rectangle pl1(low_left_x, low_left_y, top_right_x, top_right_y);
    // cout << pl1.area() << endl;

    int x1, x2, x3, y1, y2, y3;
    cout << "Input the three point positions of a Triangle: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Triangle pl2(Point(x1, y1),
                 Point(x2, y2),
                 Point(x3, y3));
    // cout << pl2.area() << endl;

    printAttributes(&pl1);
    printAttributes(&pl2);

    return 0;
}

void printAttributes(Polygon *pl) {
    cout << "Area:\t" << pl->area() << endl;
    PointArray pa = pl->getPoints();
    cout << "Points:\t";
    for (int i = 0; i < pa.getSize(); ++i) {
        Point p = *pa.get(i);
        cout << '(' << p.getX() << ", " << p.getY() << ")\t";
    }
    cout << endl;
}
```