# 6.096 - Introduction To C++ - Lab 1

## “Hello, World!”

### Hello World I

```c++
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, World!";
    return 0;
}
```

### Hello World II

```c++
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
```

## More Programs

### Scope

1. `error: redefinition of 'n' with a different type: 'char' vs 'int'`
2. The program will print '`A`' instead of `1`.
3. The inner accessed name uses the inner declaration.
4. The outer accessed name uses the outer declaration.
5. By moving the 9th line to the 1st.

### Basic Statistics

```c++
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
```

### Prime Numbers

```c++
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
```

### Multiples of numbers

```c++
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
```

### What does this program do?

1. The program multiplies `bob` and `dole`. It represents `dole` as $\sum_{n=0}^N b_n 2^n$ and then calculate each item of `bob` times $b_n 2^n$.
2. The operating system will assume the execution came across an error.
3. The program is to calculte:
$$
\sum_{n=1}^N (-1)^{\frac{(N+n-2)(N-n+1)}{2}} \frac{1}{n^2}
$$

## Factorials Gone Wrong

### Writing the factorial program

It returns `1`, `1`, `2`, `362880` and `3628800`.

### Breaking the program

It returns `1`. We can add a `if` statement after user inputing `number`:
```c++
if (number < 0)
{
    cout << "The number is negative and has no factorial.";
    return 0;
}
```

### Breaking the program II

I tried `12` and `13`, where `12!` is right while `13!` goes wrong.
```
Enter a number: 12
The factorial of 12 is 479001600.

Enter a number: 13
The factorial of 13 is 1932053504.
```

The result is too large for `int` type to store.

### Rewriting Factorial

```c++
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
```

### Rewriting Factorial II

- [ ] Just hard code with `switch-case`.

### Further testing

If the input number is not a number, our program should raise an alert.