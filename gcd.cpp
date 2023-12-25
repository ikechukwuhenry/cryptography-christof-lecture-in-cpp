#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int coprime(int a, int b)
{
    return (gcd(a, b) == 1);
}


int main(){
    std::cout << "gcd" << endl;
    std::cout << gcd(13,7) << endl;
    std::cout << "coprimes" << endl;
    std::cout << coprime(3,7) << endl;
    return 0;
}