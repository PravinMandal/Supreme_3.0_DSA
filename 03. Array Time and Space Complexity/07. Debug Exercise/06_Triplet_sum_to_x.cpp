// //code to be debug
// int tripletSumToX(int input[], int size, int x){
// 	int triplets = 0;
// 	for(int i=0; i<size; i++){
// 		for(int j=i; j<size; j++){
// 			for(int k=j; k<size; k++){
// 				if(input[i] + input[j] + input[k] == x) triplets++;
// 			}
// 		}
// 	}
// 	return triplets;
// }



#include<iostream>
using namespace std;

int tripletSumToX(int input[], int size, int x){
	int triplets = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			for(int k=j+1; k<size; k++){
				if(input[i] + input[j] + input[k] == x){
                 triplets++;
                cout<<input[i] <<" "<< input[j] <<" "<< input[k];
                cout<<endl;
                }
			}
		}
	}
	return triplets;
}



int main(){

    int arr[]={2,1,4,3,7,5};
    int n=6;
    int targetsum=12;

    int ans=tripletSumToX(arr,n,targetsum);

    cout<<"number of pairs: "<<ans<<endl;

    
    return 0;

}