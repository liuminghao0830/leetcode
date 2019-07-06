#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    double x_;
    double y_;
    double r_;
public:
    Solution(double radius, double x_center, double y_center) 
    : x_(x_center), y_(y_center), r_(radius) {}
    
    vector<double> randPoint() {
        double theta = 2 * M_PI * ((double)rand() / RAND_MAX);
        double r = sqrt((double)rand() / RAND_MAX) * r_;
        return {x_ + r * cos(theta), y_ + r * sin(theta)};
    }
};


int main(){
    Solution* rand_circle = new Solution({1.0, 0.0, 0.0});
    auto rand_points = rand_circle->randPoint();

    for (auto x : rand_points) cout << x << " ";
    cout << "\n";
    return 0;
}
