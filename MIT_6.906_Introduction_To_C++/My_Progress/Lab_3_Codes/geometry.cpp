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
