// //code to be debug
// int pairSumToX(int input[], int size, int x){
// 	int pairs = 0;
// 	for(int i=0; i<size; i++){
// 		for(int j=i; j<size; j++){
// 			if(input[i] + input[j] == x) pairs++;
// 		}
// 	}
// 	return pairs;
// }


#include<iostream>
using namespace std;

int pairSumToX(int input[], int size, int x){
	int pairs = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(input[i] + input[j] == x) pairs++;
		}
	}
	return pairs;
}


int main(){

    int arr[]={2,1,4,3,7,5,5};
    int n=7;
    int targetsum=10;

    int ans=pairSumToX(arr,n,targetsum);

    cout<<"number of pairs: "<<ans<<endl;

    
    return 0;

}