#include<bitset>
#include<iostream>
#include<string>
#define SHORT_SIZE 16

using namespace std;


unsigned short leftRotate(unsigned short n, short d)
{   
    return (n << d) | (n >> (SHORT_SIZE - d));
}
int main(){
    std::bitset<16> b{11100};
    std::bitset<16> A;
    A = (b << 2) | (b >> 6);
    // A = b << 3;
    // B = b >> 5;
    // C = A | B;
    cout << leftRotate(28, 2) << endl;
    cout << "A " << A << endl;
    // cout << "B " << B << endl;
    // cout << "C " << C << endl;
    return 0;
}
