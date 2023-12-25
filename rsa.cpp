#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>
// #include<math.h>


// using namespace std;
struct Primes
{
    /* data */
    int p, q;
    int num()
    {
        return p * q;
    }
    int phi()
    {
        return (p - 1) * (q - 1);
    }
};

struct PublicKey
{
    unsigned int n;
    unsigned int e;
};

struct PrivateKey
{
    unsigned int n;
    unsigned int d;
};

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

unsigned int generatePrime()
{
    srand(time(0));
    unsigned  prime;
    prime = rand();
    while (isPrime(prime))
    {
        prime = rand();
    }
    
    return prime;
}
void displayMessageIntValues(std::string msg)
{
    for (char c : msg)
    {
        std::cout << static_cast<int>(c) << " ";
    }
    std::cout << std::endl;
}

std::vector<unsigned int> convertMessageToString(std::string text)
{   
    std::vector<unsigned int> message_ascii_values;
    for (char c : text) {
        message_ascii_values.push_back(static_cast<int>(c));
        std::cout << static_cast<int>(c) << " ";
        // msg
    }
    return message_ascii_values;
}

std::vector<unsigned int> encryption(PublicKey pubKey, std::vector<unsigned int> msg_integers)
{
    unsigned int n = pubKey.n;
    unsigned int e = pubKey.e;
    std::vector<unsigned int> encryptedValues;
    for (unsigned int value : msg_integers)
    {
        unsigned int myvalue = pow(value, e);
        myvalue = myvalue % n;
        encryptedValues.push_back(myvalue);
    }
    return encryptedValues;
}

std::vector<unsigned int> decryption(std::vector<unsigned int> ciphertext, PrivateKey privateKey)
{
    unsigned int n = privateKey.n;
    unsigned int d = privateKey.d;
    std::vector<unsigned int> decryptedValues;
    for(unsigned int cipher: ciphertext)
    {
        unsigned int msgValue = pow(cipher, d);
        msgValue = msgValue % n;
        decryptedValues.push_back(msgValue);

    }
    return decryptedValues;

}


int main(){
    // Primes primes;
    // primes.p = generatePrime();
    // primes.q = generatePrime();
    // int num = primes.num();
    // std::cout << primes.phi() << std::endl;
    PublicKey key;
    key.e = 3;
    key.n = 33;
    PrivateKey privateky;
    privateky.n = 33;
    privateky.d = 7;
    
    displayMessageIntValues("hello");
    std::vector<unsigned int> values = encryption(key, convertMessageToString("hello"));
    for( unsigned int value : values){
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::vector<unsigned int> decryptValues = decryption(values, privateky);
    for(unsigned int dValue: decryptValues){
        std::cout << dValue << " ";
    }
    return 0;
}