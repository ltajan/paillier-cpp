#include"includes.h"

#ifndef __paillierUtils__
#define __paillierUtils__

typedef struct {
    paillierPubkey* pub_key;
    paillierPrivkey* priv_key;
} keypair;


keypair paillierGenkey(int size);
mpz_class getPrime(int size);
mpz_class getRandom(int size);
bool testPrime(int size, mpz_class n);
bool testMillerRabin(mpz_class test, mpz_class n);

#endif