#include <iostream>

using namespace std;

int main()
{
    short number;
    cout << "Enter a number: ";
    cin >> number;

    while (number < 0)
    {
        cout << "The number is negative and has no factorial.\n";
        cout << "Enter a number (again): ";
        cin >> number;
    }

    cout << "The factorial of " << number << " is ";
    long accumulator = 1;
    for(; number > 0; accumulator *= number--);
    cout << accumulator << ".\n";
    return 0;
}