#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << "Print using for-loop:\n";
    for (size_t i = 0; i < n; i++)
    {
        cout << "Hello, World!\n";
    }

    size_t i;
    cout << "Print using while-loop:\n";
    i = 0;
    while (i < n)
    {
        cout << "Hello, World!\n";
        i++;
    }

    cout << "Print using do-while-loop:\n";
    i = 0;
    do
    {
        cout << "Hello, World!\n";
        i++;
    } while (i < n);
    
    return 0;
}