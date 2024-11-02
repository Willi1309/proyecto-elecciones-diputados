#include "Nodo.h"

template<class Tipo>
void Nodo<Tipo>::AsigInfo(Tipo in) {
	info = in;
}

template<class T>
T Nodo<T>::ObtInfo() {
	return info;
}

template<class Tipo>
void Nodo<Tipo>::AsigSig(Nodo<Tipo> *p) {
	sig = p;
}

template<class Tipo>
Nodo<Tipo>* Nodo<Tipo>::ObtSig() {
	return sig;
}