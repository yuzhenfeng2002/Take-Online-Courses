#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        // Ex1: cout << ((n >= 0 && n % 5 == 0)? n/5 : -1);
        if (!(n >= 0 && n % 5 == 0))
        {
            if (n == -1)
            {
                cout << "Good bye!";
                break;
            }
            continue;
        }        
        cout << n/5;
    }
    
    return 0;
}