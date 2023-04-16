#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int min, max, sum;
    cin >> min;
    max = min;
    sum = min;
    if (n > 1)
    {
        for (size_t i = 1; i < n; i++)
        {
            int num;
            cin >> num;
            sum += num;
            if (num < min)
            {
                min = num;
            }
            if (num > max)
            {
                max = num;
            }
        }
    }
    cout << "Mean: " << sum * 1.0 / n << '\n';
    cout << "Max: " << max << '\n';
    cout << "Min: " << min << '\n';
    cout << "Range: " << max - min << '\n';

    return 0;
}