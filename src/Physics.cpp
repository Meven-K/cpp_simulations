#include "Physics.h"


// apply phisics on a star field
void apply_physics(vector<Star> &stars) {

    Tree tree = Tree(stars);

    // Change speed of all stars accordingly to all energy that applies to it
    // for (int i=0; i<(int) stars.size(); i++) {
        
    //     vector<double> acceleration = {0, 0};
    //     acceleration = addv(acceleration, gravity(stars, i));

    //     stars[i].setSpeed(addv(stars[i].getSpeed(), acceleration));
    // }
}

// apply gravity to a star
vector<double> gravity(vector<Star> stars, int index) {
    
    double gx = 0;
    double gy = 0;

    for (int i=0; i<(int) stars.size(); i++) {

        if (i != index) {
            vector<double> d = dist(stars[i].getPos(), stars[index].getPos());
            double gravity = G * 1 * 1 / (d[2] * d[2]);

            gx += gravity * d[0] * 100000000000;
            gy += gravity * d[1] * 100000000000;

        }
    }

    return vector<double> {gx, gy};
}