#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 2;
    while (n != 0)
    {
        size_t j = 2;
        for (; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }

        if (j == i)
        {
            cout << j << '\n';
            n -= 1;
        }
        i += 1;
    }
    
    return 0;
}