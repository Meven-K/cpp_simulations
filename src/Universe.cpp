#include "Universe.h"

// Contructors
Universe::Universe() {
    // by default, n_stars = 10;
    this->nStars = 10;
}

Universe::Universe(int n) {
    this->nStars = n;
}

// Random universe generator
void Universe::generate(int dx, int dy, int dz) {
    for (int i=0; i<this->nStars; i++) {
        Star s = Star();
        this->stars.push_back(s);
    }
}

// Getter and setter
int Universe::getNStars() {
    return this->nStars;
}

vector<Star> Universe::getStars() {
    return this->stars;
}

// display
void Universe::display() {

}

// operators
ostream& operator<<(ostream& os, Universe& universe) {
    os << "This is a universe of " << universe.getNStars() << " stars." << endl;
    os << "Stars : " << endl;

    vector<Star> stars = universe.getStars();
    os << "coucou" << endl;
    for (int i=0; i<universe.getNStars(); i++) {
        os << "coucou" << endl;
        os << stars.at(i) << endl; // Non fonctionnel ? La fonction de génération marche elle ?
    }
    return os;
}

// Tools

double dRand(double a, double b) {return (((double) rand() / (RAND_MAX / (a-b))) - a);}

vector<double> v3Rand(double a, double b) {return vector<double>{dRand(a, b), dRand(a, b), dRand(a, b)};}