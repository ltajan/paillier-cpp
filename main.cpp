#include"includes.h"
using namespace std;


int main(){

    int i = 1024;
    keypair kp = paillierGenkey(i);

    long m1 = 5;
    long m2 = 3;
    paillierCiphertext ct1 = kp.pub_key->encrypt(m1);
    paillierCiphertext ct2 = kp.pub_key->encrypt(m2);

    paillierCiphertext ct3 = ct1.operator+(ct2);

    long r1 = kp.priv_key->decrypt(ct3);
    cout << r1 << endl;
}