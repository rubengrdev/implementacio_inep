#include "passarelaConte.h"

passarelaConte::passarelaConte(string v, string p) {
	videojoc = v;
	paquet = p;
}

passarelaConte::~passarelaConte() {

}

string passarelaConte::getVideojoc() {
	return videojoc;
}

string passarelaConte::getPaquet() {
	return paquet;
}
