#ifndef PHYSICS_H
#define PHYSICS_H


#include <iostream>
#include <vector>

#include "Star.h"
#include "Tools.h" 
#include "Barnes.h"

using namespace std;
using std::vector;

const double G = 0.00000000006674;

// apply phisics on a star field
void apply_physics(vector<Star> &stars);

// apply gravity to a star
vector<double> gravity(vector<Star> stars, int index);


#endif