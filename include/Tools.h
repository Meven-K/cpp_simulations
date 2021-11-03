#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
using std::vector;

vector<double> addv(vector<double> a, vector<double> b);


// return dx, dy, dz, d
vector<double> dist(vector<double> a, vector<double> b);

#endif