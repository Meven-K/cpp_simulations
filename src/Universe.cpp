#include "Universe.h"


// Contructors
Universe::Universe() {
    // by default, n_stars = 10;
    this->nStars = 0;
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


void generateGalaxyFrom(vector<Star> &stars, int x=0, int y=0, int taille=1000, int n=250, vector<double> color={1, 1, 1}) {
    default_random_engine generator;
    normal_distribution<double> distribution(taille,taille);

    // generate a random galaxy
    for (int j=0; j<n; j++) {
        // generate a star from galaxy
        Star s = Star();
        vector<double> randomVectorPos = v3Rand(distribution(generator), distribution(generator));
        
        // Generate speed
        vector<double> speed = {0, 0};
        vector<double> d = dist(randomVectorPos, vector<double> {0, 0});
        speed[0] = 1.5 * d[1] / d[2];
        speed[1] = -1.5 * d[0] / d[2];
        
        s.setSpeed(speed);
        
        // set pos
        randomVectorPos[0] += x;
        randomVectorPos[1] += y;
        s.setPos(randomVectorPos);

        // set color
        s.color = color;

        stars.push_back(s);        
    }

}

void Universe::generateGalaxy(int ng, int n) {
    this->size = 5000;
    this->nStars = n;
    
    if (ng==1) generateGalaxyFrom(this->stars, 0, 0, 500, n, vector<double> {0,1,1});


    if (ng==2) {
        generateGalaxyFrom(this->stars, -1500, 1500, 500, n/2, vector<double> {0,1,1});
        generateGalaxyFrom(this->stars, 1500, -1500, 500, n/2, vector<double> {1,1,1});
    }
    if (ng==3) {
        generateGalaxyFrom(this->stars, -1500, 1500, 500, n/3, vector<double> {0,1,1});
        generateGalaxyFrom(this->stars, 1500, -1500, 500, n/3, vector<double> {1,1,1});
        generateGalaxyFrom(this->stars, 1500, 1500, 500, n/3, vector<double> {1,1,0});
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
        Star s = this->stars[i];

        vector<double> pos = s.getPos();
        double relative_x = pos[0] / this->size;
        double relative_y = pos[1] / this->size;

        glColor3f(s.color[0], s.color[1], s.color[2]); glVertex3d(relative_x, relative_y, 0); 
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
