#include "Star.h"


// Contructors
Star::Star() {
    this->pos = {0, 0};
}

Star::Star(double x, double y) {
    this->pos = {x, y};
}

Star::Star(vector<double> pos) {
    this->pos = pos;
}


// Physics related
void Star::move(Uint32 delta_time) {
    this->pos[0] += this->speed[0] * delta_time * 0.05;
    this->pos[1] += this->speed[1] * delta_time * 0.05;
}


// Getter and setter
vector<double> Star::getPos() {
    return this->pos;
}

void Star::setPos(vector<double> pos) {
    this->pos = pos;
}

void Star::setPos(double x, double y) {
    this->pos = {x, y};
}

vector<double> Star::getSpeed() {
    return this->speed;
}

void Star::setSpeed(vector<double> speed) {
    this->speed = speed;
}

void Star::setSpeed(double vx, double vy){
    this->speed = {vx, vy};
}

double Star::getMass() {
    return this->mass;
}


// Operators
ostream& operator<<(ostream& os, Star& star) {
    vector<double> pos = star.getPos();
    os << "Pos : {" << pos[0] << ", " << pos[1] << "}";
    return os;
}

bool operator!=(Star& star1, Star& star2) {
    if (star1.getPos()[0] == star2.getPos()[0] && star1.getPos()[1] == star2.getPos()[1]) return false;
    return true;
}