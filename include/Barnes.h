#ifndef BARNES_H
#define BARNES_H


#include <iostream>
#include <vector>

#include "Star.h"
#include "Tools.h"

using namespace std;
using std::vector;

const double Gr = 0.00000000006674;

class Node {
public:
    // number of stars in the node
    int n = 0;
    // stars in the node
    Star existingStar;
    // sons
    vector<Node*> quadrants = {NULL, NULL, NULL, NULL};
    // center of node
    vector<double> origin {0, 0}; // top left corner
    // Size of node
    double d = 0;
    // Mass related
    vector<double> centerOfMass = {0, 0};
    double mass = 0;
    // deepness
    int deepness = 0;

    // Constructor
    Node(vector<double> origin, double d, int deepness=0);


    // Add a star in the node
    void insertToNode(Star &s, int test=0);

    // Get quad for a star
    int getQuad(Star s);

    // Create a new subnode
    void createSubNode(int i);

    // Compute the mass distrib
    void computeMassDistrib();

    // Compute forces
    vector<double> computeForces(Star &target);

};

class Tree {
public:
    // node 0
    Node *initialNode;
    int mapSize; // 1000 => [-1000; 1000]
    vector<Star> stars;

    Tree(vector<Star> &stars);

};


#endif