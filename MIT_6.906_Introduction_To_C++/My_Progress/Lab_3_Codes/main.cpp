#include <iostream>
#include "geometry.h"
#include <string>

using namespace std;

void printAttributes(Polygon *);
string pigLatinify(string);

const string VOWELS = "aeiou";

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

    /*
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
    */

    cout << pigLatinify("question") << endl;
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