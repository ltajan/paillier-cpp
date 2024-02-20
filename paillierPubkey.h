#include"includes.h"

#ifndef __paillierPubkey__
#define __paillierPubkey__


class paillierPubkey{

private:

public:
    int size;
    mpz_class n;
    mpz_class n_square;
    mpz_class g;

    paillierPubkey(int size, mpz_class n);
    paillierCiphertext encrypt(long plaintext);
};

#endif