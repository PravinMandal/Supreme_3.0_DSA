#include<iostream>
#include<vector>
using namespace std;

vector<int>findCompliment(vector<int> binary){
    int n=binary.size();
    vector<int>twoscomp(n+1 , 0); //n+1 size ka and sbme zero
    //n+1 size ka isiliye rakhe kyuki 2's compliment krne ke liye invert krke jab 1 add krenge tab 1 carry agar bachega usse store krne ke liye 0th index pr

    //change bits , invert it
    for(int i=n-1 , j=twoscomp.size()-1 ; i>=0 ; i--,j--){
        //j bhi int bann gya kyuki , hai 
        twoscomp[j]=binary[i] ==0 ? 1:0 ;
        //zero rha toh 1 insert warna 0 insert
        //ternary operetor
    }
    // return twoscomp;

    //step 2 : add 1

    int carry=1;
    for(int i=twoscomp.size()-1 ; i>=0 ; i--){
        int sum=twoscomp[i]+ carry;
        twoscomp[i]=sum%2;
        carry=sum/2;
    }
    if(carry){
        twoscomp[0]==carry;
    }

    return twoscomp;


}

int main(){

    vector<int>binary={1,1,1,0,1,0,1,1,0};
    vector<int>twosComps=findCompliment(binary);
    for(int i=0 ; i<twosComps.size() ; i++){
        cout<<twosComps[i];
    }

    return 0;
}