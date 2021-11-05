#ifndef STAR_H
#define STAR_H


#include <vector>
#include <iostream>
#include <SDL/SDL.h>


using namespace std;
using std::vector;

class Star{
  private:
    
    vector<double> pos;
    vector<double> speed = {0, 0};

  public:
    double mass = 1000000000;

    vector<double> color = {1, 1, 1};

    // Contructors
    Star();
    Star(double x, double y);
    Star(vector<double> pos);

    // Physics related
    void move(Uint32 delta_time);

    // get / set
    vector<double> getPos();
    void setPos(vector<double> pos);
    void setPos(double x, double y);
    vector<double> getSpeed();
    void setSpeed(vector<double> speed);
    void setSpeed(double vx, double vy);
    double getMass();
    
};

// operators
ostream& operator<<(ostream& os, Star& star);
bool operator!=(Star& star1, Star& star2);


#endif