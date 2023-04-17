#include <iostream>

using namespace std;

const int LENGTH = 3;
const int WIDTH = 2;

void printArray(const int[], const int);
void reverse(int[], int);
void reverse2(int[], int);
void transpose(const int input[][LENGTH], int output[][WIDTH]);

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {1, 2, 3, 4, 5, 6, 7};
    printArray(a, 6);
    cout << endl;
    printArray(b, 7);
    cout << endl;

    reverse(a, 6);
    reverse2(b, 7);
    printArray(a, 6);
    cout << endl;
    printArray(b, 7);
    cout << endl;

    int m[][LENGTH] = {{1, 2, 3}, {4, 5, 6}};
    int n[][WIDTH] = {0};
    transpose(m, n);

    for (size_t i = 0; i < LENGTH; i++)
    {
        printArray(n[i], WIDTH);
        cout << endl;
    }
    
    return 0;
}

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