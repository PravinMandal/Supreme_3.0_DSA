#include<iostream>
#include<vector>
using namespace std;

int garbageCollection(vector<string> &garbage , vector<int> &travel ){
    //P(plastic) truck
    int pickP=0;
    int travelP=0;
    int lasthouseP=0;

    //M(metal) truck
    int pickM=0;
    int travelM=0;
    int lasthouseM=0;

    //G(glass) truck
    int pickG=0;
    int travelG=0;
    int lasthouseG=0;


    //saare ghar mai enter maar rhe h
    for(int i=0 ; i<garbage.size() ; i++){
        string currHouse=garbage[i];

        //ghar ke andar dekh rhe h ki ek perticular ghar mai konsa konsa kachra h
        for(int j=0 ; j<currHouse.length() ; j++){
            char garbagetype=currHouse[j];
            if(garbagetype=='P')
            {
                pickP++;
                lasthouseP=i;
            }
            if(garbagetype=='M')
            {
                pickM++;
                lasthouseM=i;
            }
            if(garbagetype=='G')
            {
                pickG++;
                lasthouseG=i;
            }

        }
        
    }
        for(int i=0; i<lasthouseP ; i++)
        {
            travelP=travelP+travel[i];    
        }
        for(int i=0; i<lasthouseM ; i++)
        {
            travelM=travelM+travel[i];
        }
        for(int i=0; i<lasthouseG ; i++)
        {
            travelG=travelG+travel[i];
        }

        int totalTraveltime=travelP+travelM+travelG;
        int totalPicktime=pickP+pickM+pickG;

        int totaltime=totalTraveltime+totalPicktime;
        
        
        return totaltime;
}


int main(){
    vector<string> garbage;
    vector<int> travel;
    garbage = {"G","P","GP","GG"};
    travel = {2,4,3};
    int ans=garbageCollection(garbage,travel);
    cout<<"Total time to collect garbage is: "<<ans;




    return 0;
}
