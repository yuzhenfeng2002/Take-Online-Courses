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