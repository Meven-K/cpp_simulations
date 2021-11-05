#ifndef UNIVERSE_H
#define UNIVERSE_H


#include <vector>
#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <random>

#include "Tools.h"
#include "Star.h"
#include "Physics.h"

using namespace std;
using std::vector;

class Universe{
  private:
    
    // Star field
    int nStars = 0; // Default number of stars in the universe
    int size = 100; // Default size of the universe

  public:
    vector<Star> stars;
    // Contructors
    Universe();
    Universe(int n);
    Universe(int n, int size);

    // Random universe generator
    void generate(int dx=10, int dy=10);
    void generateGalaxy(int ng=1, int n=250);

    // Getter and setter
    int getNStars();
    vector<Star> getStars();
    int *getStarsPointer() { return &this->nStars;};

    // display
    void display();

    // Compute next iteration
    void compute(Uint32 delta_time=1);
};

// operators
ostream& operator<<(ostream& os, Universe& universe);


// Tools
vector<double> v3Rand(double dx, double dy);


#endif