#include <iostream>

using namespace std;

int main()
{
    int n = 1;
    // int n = 2; // ans1: error: redefinition of 'n'
    // char n = 'A'; // ans1: error: redefinition of 'n' with a different type: 'char' vs 'int'
    
    /*
    {
        char n = 'A';
        cout << n; // ans2: print 'A' instead of 1
                   // ans3: inner access inner one
    }
    */
    // cout << n; // ans4: outer access outer one
    // ans5: moving the 9th line to the 1st

    return 0;
}