#include "paillierCiphertext.h"


paillierCiphertext::paillierCiphertext(paillierPubkey* pk, mpz_class ciphertext){

    this->pk = pk;
    this->val = ciphertext;
}

mpz_class paillierCiphertext::getValue(){

        return this->val;
}

paillierCiphertext paillierCiphertext::operator+(paillierCiphertext& other){

    if (this->pk->n != other.pk->n)
        throw std::runtime_error("Wrong public key");
    mpz_class a = this->getValue();
    mpz_class b = other.getValue();

    mpz_class temp;
    mpz_mul(temp.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
    mpz_mod(temp.get_mpz_t(), temp.get_mpz_t(), this->pk->n.get_mpz_t());

    paillierCiphertext res = paillierCiphertext(this->pk, temp);
    
    return res;
} 
