#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

float min(float a, float b, float c, float d){
    float minVal = a;
    if (b < minVal) minVal = b;
    if (c < minVal) minVal = c;
    if (d < minVal) minVal = d;

    return minVal;
}

float max(float a, float b, float c, float d){
    float maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    if (d > maxVal) maxVal = d;

    return maxVal;
}

int main() {

    ifstream inputFile("in.dat");
    int a1, a2, b1, b2, c1, c2, d1, d2;
    float dist_a, dist_b, dist_c, dist_d;
    float max_dist, min_dist = 0;

    inputFile >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
    dist_a = pow((a1*a1 + a2*a2), 0.5);
    dist_b = pow((b1*b1 + b2*b2), 0.5);
    dist_c = pow((c1*c1 + c2*c2), 0.5);
    dist_d = pow((d1*d1 + d2*d2), 0.5);
    
    max_dist = max(dist_a, dist_b, dist_c, dist_d);
    min_dist = min(dist_a, dist_b, dist_c, dist_d);

    cout << min_dist << ' ' << max_dist;
    
    return 0;
}
