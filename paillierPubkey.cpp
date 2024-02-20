#include"paillierPubkey.h"


paillierPubkey::paillierPubkey(int size, mpz_class n){
    
    this->size = size;
    this->n = n;
    this->n_square = n * n;
    this->g = n + 1;
}

paillierCiphertext paillierPubkey::encrypt(long plaintext){

    mpz_class temp, r;

    srand (time(NULL));
    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, rand());

    mpz_urandomm(r.get_mpz_t(),state, this->n.get_mpz_t());
    mpz_add_ui(r.get_mpz_t(), r.get_mpz_t(), 1);
    mpz_mod(r.get_mpz_t(), r.get_mpz_t(), this->n.get_mpz_t());

    mpz_powm_sec(r.get_mpz_t(), r.get_mpz_t(), this->n.get_mpz_t(), this->n_square.get_mpz_t());

    mpz_powm_ui(temp.get_mpz_t(), this->g.get_mpz_t(), plaintext, this->n_square.get_mpz_t());

    mpz_mul(temp.get_mpz_t(), temp.get_mpz_t(), r.get_mpz_t());
    mpz_mod(temp.get_mpz_t(), temp.get_mpz_t(), this->n_square.get_mpz_t());

    paillierCiphertext ct = paillierCiphertext(this, temp);

    return ct;
}
