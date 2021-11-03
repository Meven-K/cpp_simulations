#include "Tools.h"


vector<double> addv(vector<double> a, vector<double> b) {
    a[0] += b[0];
    a[1] += b[1];
    return a;
}

vector<double> dist(vector<double> a, vector<double> b) {
    double dx = a[0] - b[0];
    double dy = a[1] - b[1];
    double d = sqrt(dx*dx + dy*dy);
    return vector<double> {dx, dy, d};
}
