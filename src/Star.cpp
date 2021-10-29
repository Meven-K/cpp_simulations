#include "Star.h"

Star::Star() {
    this->pos = {0, 0, 0};
}

Star::Star(double x, double y, double z) {
    this->pos = {x, y, z};
}

Star::Star(vector<double> pos) {
    this->pos = pos;
}

vector<double> Star::getPos() {
    return this->pos;
}

void Star::setPos(vector<double> pos) {
    this->pos = pos;
}

void Star::setPos(double x, double y, double z) {
    this->pos = {x, y, z};
}

ostream& operator<<(ostream& os, Star& star) {
    vector<double> pos = star.getPos();
    os << "Pos : {" << pos[0] << ", " << pos[1] << ", " << pos[2] << "}";
    return os;
}