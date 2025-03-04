#include<iostream>
using namespace std;

float areaofCircle(float radius) {
    float ans = 3.14 * radius * radius;
    return ans;
}

int main() {
    float radius = 5.343; //radius of circle

    float ans = areaofCircle(radius);
    cout<<"Area of circle: "<<ans;

    return 0;
}