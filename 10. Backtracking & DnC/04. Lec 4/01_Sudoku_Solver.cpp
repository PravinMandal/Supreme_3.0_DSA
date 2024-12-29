//leetcode:- 37. Sudoku Solver
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(char digit,int row, int col, vector<vector<char>>& board){
    int n=board.size();
    //3 condition
    //rowcheck
    for(int k=0; k<n; k++){
        if(board[row][k]==digit){
            //digit pehle se h mtlb nhi h safe nhi daal skte
            return false;
        }
    }

    //colcheck
    for(int k=0; k<n; k++){
        if(board[k][col]==digit){
            //digit pehle se h uss column mai, wapas nhi daal skte
            return false;
        }
    }

    //3x3 mai hai wo number ki nhi
    //iska formula h, samjhaya h
    for(int k=0; k<n; k++){
        if(board[3*(row/3)+(k/3)] [3*(col/3)+(k%3)] == digit){
            return false;
        }
    }

    //yaha tk aa gya mtlb teeno ke andar nhi jaa paaya and safe h 
    return true;
}

bool solve(vector<vector<char>>& board){
    //base case-?

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]=='.'){
                for(char digit='1'; digit<='9'; digit++){
                    if(isSafe(digit,i,j,board)){
                        board[i][j]=digit;
                        bool aageSolveHoGya=solve(board);
                        if(aageSolveHoGya==true){
                            return true;
                        }
                        else{
                            //backtracking
                            //jo change kiye tha wapas pehle jaisa krdo
                            board[i][j]='.';
                        }
                    }
                }
                //yaha pr aa gya mtlb poore digit try kr liye and solve nhi ho paaya
                return false;
                //false hone ke baad wo else condition mai jaake backtrack krega
            }
        }
    }
    //yaha last tak aa gya mtlb poora sudoku solve ho gya kyuki nhi hota toh yaha tk pohoch hi nhi paata
    return true;

}

void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

int main(){

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}