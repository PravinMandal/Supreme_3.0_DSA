// //code to be debug
// #include<iostream>
// using namespace std;

// int main(){
//     int n, sum;
//     cin >> n;
//     int input[n];
//     for(int i=0;i<n;i++){
//         cin >> input[0];
//     }
//      for(int i=0; i<n; i++){
//          sum = sum + input[i];
//      }
//     cout << sum << endl;
//     return 0;
// }



#include<iostream>
using namespace std;

int main(){
    int n;
    int sum=0; //sum ko 0 se initialize krna tha warna usme garbage value stored rhta h
    cin >> n;
    int* input=new int [n]; //aise hum dynamic array banate h
    for(int i=0;i<n;i++){
        cin >> input[i]; //input cin krne ke liye for loop lagaye the toh i daalna h 0 likha tha pehle 
    }
     for(int i=0; i<n; i++){
         sum = sum + input[i];
     }
    cout << sum << endl;
    return 0;
}