#include"includes.h"

#ifndef __paillierPrivkey__
#define __paillierPrivkey__

class paillierPrivkey{

private:
    paillierPubkey* pubkey;
    mpz_class p;
    mpz_class q;
    mpz_class psi;
    mpz_class mu;
    
public:
    paillierPrivkey(paillierPubkey* pubkey, mpz_class p, mpz_class q);
    long decrypt(paillierCiphertext& ct);
};

#endif