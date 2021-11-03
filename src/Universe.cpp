#include "Universe.h"


// Contructors
Universe::Universe() {
    // by default, n_stars = 10;
    this->nStars = 10;
    this->generate();
}

Universe::Universe(int n) {
    this->nStars = n;
    this->generate();
}

Universe::Universe(int n, int size) {
    this->nStars = n;
    this->size = size;
    this->generate(size, size);
}


// Random universe generator
void Universe::generate(int dx, int dy) {
    for (int i=0; i<this->nStars; i++) {
        Star s = Star();
        vector<double> randomVectorPos = v3Rand(dx, dy);
        s.setPos(randomVectorPos);
        this->stars.push_back(s);
    }
}


// Getter and setter
int Universe::getNStars() {
    return this->nStars;
}

vector<Star> Universe::getStars() {
    return this->stars;
}


// display
void Universe::display() {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);

    glPointSize( 2 );

    glBegin(GL_POINTS);

    for (int i=0; i<this->nStars; i++) {
        
        // relative pos
        vector<double> pos = this->stars[i].getPos();
        double relative_x = pos[0] / this->size;
        double relative_y = pos[1] / this->size;

        glColor3f(1, 1, 1); glVertex3d(relative_x, relative_y, 0); 
    }

    glEnd();

    glFlush();
    SDL_GL_SwapBuffers();
}


// Compute next iteration
void Universe::compute(Uint32 delta_time) {
    
    // Apply physics to set stars speed
    apply_physics(this->stars); 

    // move all stars
    for (int i=0; i<this->nStars; i++) {

        // move
        stars[i].move(delta_time);

    }
}


// operators
ostream& operator<<(ostream& os, Universe& universe) {
    os << "This is a universe of " << universe.getNStars() << " stars." << endl;
    os << "Stars : " << endl;

    vector<Star> stars = universe.getStars();
    os << "Length : " << stars.size() << endl;
    return os;
}


// Tools
double dRand(double a, double b) {return (((double) rand() / (RAND_MAX / (a-b))) - a);}

vector<double> v3Rand(double dx, double dy) {return vector<double>{dRand(-dx, dx), dRand(-dy, dy)};}
