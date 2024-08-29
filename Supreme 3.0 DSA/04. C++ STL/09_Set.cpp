#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set<int> st;

    st.insert(10);
    st.insert(15);
    st.insert(8);
    st.insert(20);

    cout<<st.size()<<endl;


    if( st.find(15) != st.end())
    {
        cout<<"found"<<endl;
        //Agar end tak nhi pohcha mtlab bich mai mil gya
    }
    else
    {
        cout<<"Not found"<<endl;
        //end tak pohoch gya mtlab nhi mila
    }

    if( st.count(15) ==1)
    {
        cout<<"found"<<endl;
    }
    if( st.count(15) ==0)
    {
        cout<<"Not found"<<endl;
    }




    unordered_set<int>::iterator it= st.begin();

    while( it != st.end())
    {
        cout<<*it<<" ";
        it++;
    }

    return 0;
}