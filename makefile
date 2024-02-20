objects=main.o paillierPubkey.o paillierPrivkey.o paillierCiphertext.o paillierUtils.o
main:$(objects)
	g++ -o main main.o paillierPubkey.o paillierPrivkey.o paillierCiphertext.o paillierUtils.o -lgmp -lgmpxx

paillierPubkey.o:paillierPubkey.cpp
	g++ -c paillierPubkey.cpp
paillierPrivkey.o:paillierPrivkey.cpp
	g++ -c paillierPrivkey.cpp
paillierCiphertext.o:paillierCiphertext.cpp
	g++ -c paillierCiphertext.cpp
paillierUtils.o:paillierUtils.cpp
	g++ -c paillierUtils.cpp
main.o:main.cpp
	g++ -c main.cpp
clean:
	rm -f *o