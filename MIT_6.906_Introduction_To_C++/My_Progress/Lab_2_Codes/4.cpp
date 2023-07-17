#include <iostream>

using namespace std;

int sum(const int, const int);
double sum(const double, const double);
double sum(const double, const double, const double);
double sum(const double, const double, const double, const double);
int sum(const int[], const int);

int main()
{
    // cout << sum(1, 10.0); // Ex2
    // cout << sum(3, 5, 7); // Ex4
    int nums[] = {1, 2, 3, 4, 5};
    cout << sum(nums, 5);
    return 0;
}

// Ex1
/*
int sum(const int a, const int b)
{
    return a + b;
}

double sum(const double a, const double b)
{
    return a + b;
}
*/

// Ex3
/*
double sum(const double a, const double b, const double c)
{
    return a + b + c;
}

double sum(const double a, const double b, const double c, const double d)
{
    return a + b + c + d;
}
*/

// Ex4
/*
double sum(const double a, const double b, const double c=0, const double d=0)
{
    return a + b + c + d;
}
*/

// Ex5
/*
int sum(const int nums[], const int length)
{
    int sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += nums[i];
    }
    return sum;
}
*/

// Ex6
/*
int sum(const int nums[], const int length)
{
    if (length == 1)
    {
        return nums[0];
    }
    else
    {
        return nums[0] + sum(nums+1, length-1);
    }
}
*/