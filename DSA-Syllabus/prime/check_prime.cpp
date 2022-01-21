#include <iostream>
using namespace std;

bool isPrime(int n)   
{
    if(n<=1)
      return false;
     for (int i = 2; i*i <= n; i++) //O(sqrt(n))
        if (n % i == 0)
            return false;
    return true;
}


int main()
{
    int n, f = 0;
    cout << "Enter a number to check prime no.";
    cin >> n;
    isPrime(n) ? cout<<"number is prime" : cout<<"not a prime";
    return 0;
}