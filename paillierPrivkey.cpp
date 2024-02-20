#include"paillierPrivkey.h"


paillierPrivkey::paillierPrivkey(paillierPubkey* pubkey, mpz_class p, mpz_class q)
{
    if (p * q != pubkey->n)
        throw std::runtime_error("Wrong public key");

    this->pubkey = pubkey;
    this->p = p;
    this->q = q;
    this->psi = (p - 1) * (q - 1);

    mpz_class temp;
    mpz_invert(temp.get_mpz_t(), this->psi.get_mpz_t(), this->pubkey->n.get_mpz_t());
    this->mu = temp;
}

long paillierPrivkey::decrypt(paillierCiphertext& ct){

    mpz_class ciphertext = ct.getValue();
    mpz_class x, Lx, temp;

    mpz_powm_sec(x.get_mpz_t(), ciphertext.get_mpz_t(), this->psi.get_mpz_t(), this->pubkey->n_square.get_mpz_t());
    mpz_sub_ui(x.get_mpz_t(), x.get_mpz_t(), 1);
    mpz_fdiv_q(Lx.get_mpz_t(), x.get_mpz_t(), this->pubkey->n.get_mpz_t()); 
    mpz_mul(temp.get_mpz_t(), Lx.get_mpz_t(), this->mu.get_mpz_t());
    mpz_mod(temp.get_mpz_t(), temp.get_mpz_t(), this->pubkey->n.get_mpz_t());

    long message = mpz_get_ui(temp.get_mpz_t());

    return message;
}

