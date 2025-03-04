#include<iostream>
using namespace std;

void KMtoMiles(float km) {
    float miles;
    miles = km * 0.621371;

    cout<<km<<" KM is "<<miles<<" Miles"<<endl;
}

int main() {

    float n;
    cout<<"Enter the distance in KM: ";
    cin>>n;

    KMtoMiles(n);


    return 0;
}