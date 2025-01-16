#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                //opening bracket h push krdo
                st.push(ch);
            }
            else {
                //mujhe close bracket mila h
                //close bracket ke case mai, mai stack ke top pr check krta hu
                //ki same type ka closing bracket hai ki nhi

                 if(ch==')' && !st.empty() && st.top()== '('){
                    //bracket ka correct combo 
                    st.pop();
                 }
                 else if(ch=='}' && !st.empty() && st.top()== '{'){
                    st.pop();
                 }
                 else if(ch==']' && !st.empty() && st.top()== '['){
                    st.pop();
                 }
                 else{
                    //sahi closing bracket nhi mila kuch aur mila , mtlb invalid 
                    return false;
                 }
            }
           
        }
        if(st.empty()){
            return true;
            //khali ho gya mtlb sahi parentheses hai and sab pop ho gya
        }
        else{
            return false;
        }
    }
};

int main() {
    Solution solution;

    string input="()[]{}";

    // Check if the parentheses are valid
    if (solution.isValid(input)) {
        cout << "The string has valid parentheses." << endl;
    } else {
        cout << "The string has invalid parentheses." << endl;
    }

    return 0;
}
