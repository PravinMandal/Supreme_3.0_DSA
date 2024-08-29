#include<iostream>
#include<list>
using namespace std;

int main()
{
   //creation
   list<int> mylist;
   mylist.push_back(10);
   mylist.push_back(20);
   mylist.push_back(30);
   mylist.push_back(40);
   mylist.push_back(50);

   list<int>::iterator it= mylist.begin();

   while( it != mylist.end())
   {
    cout<<*it<<" ";

    it++;

   }




    return 0;
}