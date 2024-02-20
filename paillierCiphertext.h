#include"includes.h"

#ifndef __paillierCiphertext__
#define __paillierCiphertext__

class paillierCiphertext {

    private:

        mpz_class val;
        paillierPubkey* pk;

    public:

        paillierCiphertext(paillierPubkey* pk, mpz_class ciphertext);
        paillierCiphertext operator+(paillierCiphertext& other); 
        mpz_class getValue();
};

#endif