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