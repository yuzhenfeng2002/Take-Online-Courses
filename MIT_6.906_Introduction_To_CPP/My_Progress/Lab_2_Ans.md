# 6.096 - Introduction To C++ - Lab 2

## A Simple Function

```
2
246
6
8
10
```

## Fix the Function

### [N/A]

1. Move the 8th line before the 3nd line.
2. Add `void printNum(int)` before the 3nd line.

### [N/A]

1. `void printNum(int number)`
2. Define `number` globally before the 3nd line and call `printNum()`.

The 1st way is preferred. We should avoid defining global variables as far as possible.

### [N/A]

```c++
void doubleNumber(int &num) {num = num * 2;}
```

### [N/A]

Add `return diff` in the function.

### [N/A]

```c++
std::cout << sum(sum(1, 2), 3);
```

### [N/A]

```c++
std::cout << &xPtr << ’ ’ << &yPtr;
```

- [] Wrong! Define `int *xPtr = arr, *yPtr = arr + ARRAY_LEN - 1;`.

## Sums

```c++
// Ex1
int sum(const int a, const int b)
{
    return a + b;
}

double sum(const double a, const double b)
{
    return a + b;
}

// Ex3
double sum(const double a, const double b, const double c)
{
    return a + b + c;
}

double sum(const double a, const double b, const double c, const double d)
{
    return a + b + c + d;
}

// Ex4
double sum(const double a, const double b, const double c=0, const double d=0)
{
    return a + b + c + d;
}

// Ex5
int sum(const int nums[], const int length)
{
    int sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += nums[i];
    }
    return sum;
}

// Ex6
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
```

2. `sum(1, 10.0)`: more than one instance of overloaded function "sum" matches the argument list
4. `sum(3, 5, 7)`: more than one instance of overloaded function "sum" matches the argument list

## Calculating $\pi$

```c++
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double pi(int);

int main()
{
    srand(time(0));
    int n = 5000000;
    cout << pi(n);
}

double pi(int n)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        double x = rand() * 1.0 / RAND_MAX;
        double y = rand() * 1.0 / RAND_MAX;
        double d = sqrt(x*x + y*y);
        if (d <= 1)
        {
            count ++;
        }
    }

    return 4 * count * 1.0 / n;
}
```

## Array Operations

4. The array will be cleared when exiting.

```c++
void printArray(const int nums[], const int length)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << nums[i];
        if (i != length - 1)
        {
            cout << ", ";
        }
    }
}

void reverse(int nums[], int length)
{
    for (size_t i = 0; i < length / 2; i++)
    {
        int tmp = nums[i];
        nums[i] = nums[length - 1 - i];
        nums[length - 1 - i] = tmp;
    }
}

void reverse2(int *nums, int length)
{
    for (size_t i = 0; i < length / 2; i++)
    {
        int tmp = *(nums + i);
        *(nums + i) = *(nums + (length - 1 - i));
        *(nums + (length - 1 - i)) = tmp;
    }
}

void transpose(const int input[][LENGTH], int output[][WIDTH])
{
    for (size_t i = 0; i < LENGTH; i++)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            output[i][j] = input[j][i];
        }
    }
}
```

## Pointers and Strings

```c++
#include <iostream>

using namespace std;

int lengthStr(const char*);
void swapTwoNums(int&, int&);
void swapTwoNums2(int*, int*);
void swapTwoNums3(int**, int**);

int main()
{
    char a[] = "123";
    cout << lengthStr(a) << endl;

    int b = 1, c = 2;
    swapTwoNums(c, b);
    cout << b << ' ' << c << endl;
    
    swapTwoNums2(&c, &b);
    cout << b << ' ' << c << endl;

    int x = 5, y = 6;
    int *ptr1 = &x, *ptr2 = &y;
    swapTwoNums3(&ptr1, &ptr2);
    cout << *ptr1 << ' ' << *ptr2 << endl;

    char *oddOrEven = "Never odd or even";
    char *nthCharPtr = oddOrEven + 6 - 1;
    nthCharPtr -= 2;
    cout << *nthCharPtr << endl;
    char **pointerPtr = &nthCharPtr;
    cout << pointerPtr << endl;
    cout << **pointerPtr << endl;
    nthCharPtr += 1;
    cout << nthCharPtr - oddOrEven << endl;
    return 0;
}

int lengthStr(const char *a)
{
    int i = 0;
    char ch;
    do
    {
        ch = *(a + i);
        i++;
    } while (ch != '\0');
    return i;
}

void swapTwoNums(int &a, int &b)
{
    int tmp = b; b = a; a = tmp;
}

void swapTwoNums2(int *a, int *b)
{
    int tmp = *a; *a = *b; *b = tmp;
}

void swapTwoNums3(int **a, int **b)
{
    int *tmp = *a; *a = *b; *b = tmp;
}
```