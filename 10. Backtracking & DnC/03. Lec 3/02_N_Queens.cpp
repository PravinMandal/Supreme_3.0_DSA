//leetcode:- 51. N-Queens
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

unordered_map<int,bool>rowCheck;
unordered_map<int,bool>lowerDiagonalCheck;
unordered_map<int,bool>upperDiagonalCheck;


void storeSolution(vector<vector<string>>&ans,vector<vector<char>>&board,int n){
    vector<string> temp;
    for(int i=0 ; i<n ; i++){
        string output="";
        for(int j=0 ; j<n ; j++){
            output.push_back(board[i][j]);
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
}

bool isSafe(int row , int col , vector<vector<char>>&board){
    if(rowCheck[row]==true){
        return false;
    }
    if(lowerDiagonalCheck[row+col]==true){
        return false;
    }
    if(upperDiagonalCheck[row-col]==true){
        return false;
    }
    //else
    return true;
    
}

void solve(vector<vector<string>>&ans,vector<vector<char>>&board,int n,int col){
    //base case
    if(col>=n){
        //all queens are placed
        //ab hume uss arrangement ko store krna h ans mai
        storeSolution(ans,board,n);
        return;
    }

    for(int row=0 ; row<n ;row++){

        if(isSafe(row,col,board)){
            board[row][col]='Q';
            rowCheck[row]=true;
            lowerDiagonalCheck[row+col]=true;
            upperDiagonalCheck[row-col]=true;

            solve(ans,board,n,col+1);
            //backtracking
            board[row][col]='.';
            rowCheck[row]=false;
            lowerDiagonalCheck[row+col]=false;
            upperDiagonalCheck[row-col]=false;
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<vector<char>> board(n,vector<char>(n,'.'));
    int col=0;
    solve(ans,board,n,col);
    return ans;
}

int main(){

    int n=4;
    vector<vector<string>> ans=solveNQueens(n);

    for (const auto &path : ans) {
        for (const string &row : path) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}