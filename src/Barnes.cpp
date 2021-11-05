#include "Barnes.h"


// Constructor
Node::Node(vector<double> origin, double d, int deepness) {
    this->n = 0;
    this->origin = origin;
    this->d = d;   
    this->deepness = deepness;
} 


// Add a star in the node
void Node::insertToNode(Star &s, int test) {
    if(this->n > 1) {
        int quad = this->getQuad(s);
        if (this->quadrants[quad] == NULL) {
            this->createSubNode(quad);
        }
        quadrants[quad]->insertToNode(s);
    } else if (this->n ==1) {

        int quad = this->getQuad(this->existingStar);

        if (this->quadrants[quad] == NULL) {
            this->createSubNode(quad);
        }
        

        quadrants[quad]->insertToNode(this->existingStar, 1);

        quad = this->getQuad(s);

        if (this->quadrants[quad] == NULL) {
            this->createSubNode(quad);
        }
        quadrants[quad]->insertToNode(s);

    } else {

        this->existingStar = s;
    }
    this->n +=  1;

}

// Get quad for a star
int Node::getQuad(Star s) {
    vector<double> pos = s.getPos();

    if (pos[0] <= this->origin[0] + this->d/2) {
        if (pos[1] <= this->origin[1] + this->d/2) {
            // top left
            return 0;
        } else {
            // bottom left
            return 3;
        }
    } else {
        if (pos[1] <= this->origin[1] + this->d/2) {
            // top right
            return 1;
        } else {
            // bottom right
            return 2;
        }
    }
}

// Create a new subnode
void Node::createSubNode(int i) {
    vector<double> origin = this->origin;
    if(i == 1 || i == 2) {
        origin[0] += this->d / 2;
    }
    if(i == 2 || i == 3) {
        origin[1] += this->d / 2;
    }

    this->quadrants[i] = new Node(origin, this->d/2, this->deepness + 1);
}

// Compute the mass distrib
void Node::computeMassDistrib() {
    if (this->n == 1) {
        this->centerOfMass = this->existingStar.getPos();
        this->mass = this->existingStar.getMass();
    } else {
        // Compute the center of mass based on the masses of 
        // all child quadrants and the center of mass as the 
        // center of mass of the child quadrants weightes with 
        // their mass
        for (int i=0; i<4; i++) {
            if (this->quadrants[i] != NULL) {
                this->quadrants[i]->computeMassDistrib();
                this->mass += this->quadrants[i]->mass;
                this->centerOfMass[0] += this->quadrants[i]->centerOfMass[0] * this->quadrants[i]->mass;
                this->centerOfMass[1] += this->quadrants[i]->centerOfMass[1] * this->quadrants[i]->mass;
            }
        }
        this->centerOfMass[0] /= this->mass;
        this->centerOfMass[1] /= this->mass;
    }
}

// Compute forces
vector<double> Node::computeForces(Star &target) {
    vector<double> F = {0, 0};

    if (this->n == 1) {
        if (this->existingStar != target) {
            vector<double> d = dist(this->existingStar.getPos(), target.getPos());
            double x_norm = d[0];
            double y_norm = d[1];

            double force = Gr * this->existingStar.getMass() * target.getMass() / (d[2] * d[2]);
            F[0] = force * x_norm;
            F[1] = force * y_norm;
        }
        return F;

    } else {

        vector<double> d = dist(this->centerOfMass, target.getPos());
        double r = d[2];

        if(this->d/r < 0.5) { // value of theta <1 is good

            vector<double> d = dist(this->centerOfMass, target.getPos());
            double x_norm = d[0] / d[2];
            double y_norm = d[1] / d[2];

            double force = Gr * this->mass * target.getMass() / (d[2] * d[2]);
            F[0] = force * x_norm;
            F[1] = force * y_norm;

            return F;
        } else {
            for (int i=0; i<4; i++) {
                if (this->quadrants[i] != NULL) {
                    vector<double> F2 = this->quadrants[i]->computeForces(target);
                    F[0] += F2[0];
                    F[1] += F2[1];
                }
            }
            return F;

        }
    }
    return F;
}


// Create the tree from stars
Tree::Tree(vector<Star> &stars) {

    this->stars = stars;

    vector<double> pos = stars[0].getPos();

    double xMin = pos[0] - 1;
    double yMin = pos[1] - 1;
    double xMax = pos[0] + 1; 
    double yMax = pos[1] + 1;

    for (int i=0; i<(int) stars.size(); i++) {
        // Search for max and min values
        pos = stars[i].getPos();
        if (pos[0] - 1 < xMin) xMin = pos[0] - 1;
        if (pos[1] - 1 < yMin) yMin = pos[1] - 1;
        if (pos[0] + 1 > xMax) xMax = pos[0] + 1;
        if (pos[1] + 1 > yMax) yMax = pos[1] + 1;
    }

    double dMax = xMax - xMin;
    if ((yMax - yMin) > dMax) dMax = yMax - yMin;

    this->mapSize = dMax;
    
    Node initialNode = Node(vector<double> {xMin, yMin}, dMax);
    this->initialNode = &initialNode;

    for (int i=0; i<(int) stars.size(); i++){
        this->initialNode->insertToNode(stars[i]);
    }

    this->initialNode->computeMassDistrib();

    for (int i=0; i<(int) stars.size(); i++){
        vector<double> F = this->initialNode->computeForces(stars[i]);
        F[0] /= stars[i].mass;
        F[1] /= stars[i].mass;
        stars[i].setSpeed(addv(stars[i].getSpeed(), F));
    }
}



