#ifndef UNIVERSE_H
#define UNIVERSE_H


#include <vector>
#include <iostream>

#include "Star.h" 

using namespace std;
using std::vector;

class Universe{
  private:
    
    // Star field
    vector<Star> stars;
    int nStars;

  public:

    // Contructors
    Universe();
    Universe(int n);

    // Random universe generator
    void generate(int dx=10, int dy=10, int dz=10);

    // Getter and setter
    int getNStars();
    vector<Star> getStars();

    // display
    void display();
    
};

// operators
ostream& operator<<(ostream& os, Universe& universe);

#endif