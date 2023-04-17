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