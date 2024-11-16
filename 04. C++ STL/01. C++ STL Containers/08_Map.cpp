#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    //creation

    unordered_map<string , string> table;

    //insertion

    //1
    table["in"]="India";

    //2
    table.insert(make_pair("en" , "England"));

    //3
    pair<string , string> p ;
    p.first="br";
    p.second="brazil";
    table.insert(p);

    // unordered_map<string,string>::iterator it= table.begin();

    // while(it != table.end())
    // {
    //     pair<string,string> p=*it;
    //     cout<<p.first<<" "<<p.second<<endl;
    //     it++;
    // }

    if( table.find("in") != table.end())
    {
        cout<<"Key found"<<endl;
    }
    else
    {
        cout<<"Key not found"<<endl;
    }

    if( table.count("in")==0)
    {
        cout<<"key not found"<<endl;

    }
    if( table.count("in")==1)
    {
        cout<<"key found"<<endl;
    }

    return 0;
}