#include<iostream>
using namespace std;

//inline func , func ke andar ka code utha kr just udhr paste kr deta h jaha call kiya h usse compile krne ke time
//hum isiliye use krte h kyuki agar func chhota h and baar baar func ko call kr rhe h toh baar baar stack mai wo func banta h and wind up hota h
//isse boht overhead badh jaata h toh ussi ko avoid krne ke liye inline keyword use krte h
//inline keyword generally chhote func ke liye krte h kyuki bada func rha toh utne saare code ko main func mai paste krega toh boht zyada bada code ho jayega joki aacha nhi h utna

inline void print(int a){
    cout<<a<<endl;
    cout<<a*2<<endl;
}

int main(){
    int a=5;

    print(a);
    print(a);
    print(a);
    print(a);
    print(a);

    return 0;
}