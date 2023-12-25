#include<string>
#include<bitset>
#include<iostream>
#include<vector>

using namespace std;

string cars[10];

int main(){
    string greetings = "hello world";
    std::bitset<8> b3{"00110101"};
    cout << "key: " << b3 <<endl;
    for(std::size_t i=0; i < greetings.size(); ++i){
        // cout << bitset<8> (greetings[i]) << " ";
        // bits[i] = bitset<8> (greetings[i]).to_string() ;
        bitset<8> b = (greetings[i]);
        cout <<"orig " << b << " " << b.to_ulong() << " "; 
        b = b ^ b3;
        cout << "enc " << b.to_ulong() << " ";
        b = b ^ b3;
        cout << "decr " << b.to_ulong() << endl;
        cars[i] = b.to_string();
    }
    
    cout << "string bits " << cars[0] << endl;
    cout << b3.to_string() <<endl;

    return 0;
}