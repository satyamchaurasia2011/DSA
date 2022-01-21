#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number for find its prime factorization - ";
    cin >> n;
    int p = 2;
    while (n > 1 && p * p <= n) ///////O(sqrt(n))
    {
        while (n % p == 0)
        {
            n /= p;
            cout << p << " ";
        }
        p++;
    }
    if (n > 1)
        cout << n << " ";
}