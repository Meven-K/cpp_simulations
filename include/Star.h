#ifndef STAR_H
#define STAR_H


#include <vector>
#include <iostream>

using namespace std;
using std::vector;

class Star{
  private:
    
    vector<double> pos;

  public:

    // Contructors
    Star();
    Star(double x, double y, double z);
    Star(vector<double> pos);

    // get / set
    vector<double> getPos();
    void setPos(vector<double> pos);
    void setPos(double x, double y, double z);
    
};

// operators
ostream& operator<<(ostream& os, Star& star);

#endif