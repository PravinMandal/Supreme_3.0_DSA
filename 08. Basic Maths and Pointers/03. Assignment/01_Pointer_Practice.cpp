#include<bits/stdc++.h>
using namespace std;


int main() {

    // 1
    {
        float f = 10.5;
        float p = 2.5;
        float* ptr = &f;

        (*ptr)++;
        *ptr = p;
        cout<<*ptr<<" "<<f<<" "<<p<<endl;
        //output: 2.5 2.5 2.5
    }


    // 2
    {
        int a = 7;
        int b = 17;
        int* c = &b;
        *c = 7;
        cout<<a<<" "<<b<<endl;
        //output: 7 7

    }
    
    // 3
    {
        int* ptr = 0; //null se initialize kr diya
        int a = 10;
        // *ptr = a; //ye bhi nhi kr skte, segmentation fault
        // cout<<*ptr<<endl;
        //output: Error
    }

    // 4 
    {
        int a = 10;
        int* c = &a;
        c = c+1;
        cout<<a<<", "<<*c<<endl;
        //output: 10, garbage value
    }

    // 5 
    {
        int a[] = {1,2,3,4,5};
        int* ptr = NULL;
        cout<<(*a)<<" "<<(*a+1)<<endl;
        //output: 1 2
    }

    // 6 
    {
        int a[] = {1,2,3,4,5};
        // int* ptr = a++; // 'a' is a const pointer wo aage move nhi ho skta
        // cout<<*ptr<<endl;
        //output: error
    }

    // 7 
    {
        char ch[] = "xyz";
        char* p = &ch[0];
        cout<<p<<endl;
        //output: xyz
    }

    // 8 
    {
        char arr[20];
        int i;
        for(i=0; i<10; i++) {
            *(arr+i) = 65 + i;
        }
        *(arr + i) = '\0';
        cout<<arr<<endl;
        //output: ABCDEFIJ
    }

    // 9 
    {
        char st[] = "ABCD";
        for(int i=0; st[i] != '\0'; i++) {
            cout<<st[i]<<" "<<*(st)+i<<" "<<*(st+i)<<" "<<i[st]<<endl;
        }
        //output: 
        // A 65 A A
        // B 66 B B
        // C 67 C C
        // D 68 D D
    }

    

    return 0;
}