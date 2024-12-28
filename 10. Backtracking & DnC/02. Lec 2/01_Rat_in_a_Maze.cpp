#include<iostream>
#include<vector>
#include<string>
using namespace std;


    bool isSafe(int newx,int newy,vector<vector<int>>&mat,int n,vector<vector<bool>>&visited){
        //out of bound wali condition
        if(newx<0 || newy<0){
            return false;
        }
        if(newx>=n || newy>=n){
            return false;
        }
        //visited wali condition
        if(visited[newx][newy]==true){
            return false;
        }
        //blocked path wali condition
        if(mat[newx][newy]==0){
            return false;
        }

        //agar koi bhi nhi hua then jaa skte h new position pr
        return true;
    }

    void solve(vector<vector<int>>&mat,int n ,vector<string>&ans,vector<vector<bool>>&visited,int curr_x,int curr_y,int destx,int desty,string output){
        //base case
        if(curr_x==destx && curr_y==desty){
            ans.push_back(output);
            return;
        }

        // ab humare pass 4 direction h kahin bhi jaa skte h saari possiblity check kro and store kro output mai

        // //left
        // int newx=curr_x;
        // int newy=curr_y-1;
        // if(isSafe(newx,newy,mat,n,visited)){
        //     //ab yaha aa gye then ab visited mark kro
        //     visited[newx][newy]=true;
        //     //ab recursion ko dedo aage
        //     solve(mat,n,ans,visited,newx,newy,destx,desty,output+"L");
        //     //wapas aaunga toh visited revert krna pdega
        //     //backtracking
        //     visited[newx][newy]=false;
            
        // }

        // //right
        // newx=curr_x;
        // newy=curr_y+1;
        // if(isSafe(newx,newy,mat,n,visited)){
        //     //ab yaha aa gye then ab visited mark kro
        //     visited[newx][newy]=true;
        //     //ab recursion ko dedo aage
        //     solve(mat,n,ans,visited,newx,newy,destx,desty,output+"R");
        //     //wapas aaunga toh visited revert krna pdega
        //     //backtracking
        //     visited[newx][newy]=false;
            
        // }

        // //up
        // newx=curr_x-1;
        // newy=curr_y;
        // if(isSafe(newx,newy,mat,n,visited)){
        //     //ab yaha aa gye then ab visited mark kro
        //     visited[newx][newy]=true;
        //     //ab recursion ko dedo aage
        //     solve(mat,n,ans,visited,newx,newy,destx,desty,output+"U");
        //     //wapas aaunga toh visited revert krna pdega
        //     //backtracking
        //     visited[newx][newy]=false;
            
        // }

        // //down
        // newx=curr_x+1;
        // newy=curr_y;
        // if(isSafe(newx,newy,mat,n,visited)){
        //     //ab yaha aa gye then ab visited mark kro
        //     visited[newx][newy]=true;
        //     //ab recursion ko dedo aage
        //     solve(mat,n,ans,visited,newx,newy,destx,desty,output+"D");
        //     //wapas aaunga toh visited revert krna pdega
        //     //backtracking
        //     visited[newx][newy]=false;
            
        // }


        //ye easy method same h bss for loop laga kr code chota kr diye

        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        char move[]={'L','R','U','D'};
        
        for(int i=0; i<4 ; i++){
            int newx=curr_x+dx[i];
            int newy=curr_y+dy[i];
            char movement=move[i];

            if(isSafe(newx,newy,mat,n,visited)){
            //ab yaha aa gye then ab visited mark kro
            visited[newx][newy]=true;
            //ab recursion ko dedo aage
            output.push_back(movement);
            solve(mat,n,ans,visited,newx,newy,destx,desty,output);
            //wapas aaunga toh visited revert krna pdega
            //backtracking
            output.pop_back();
            visited[newx][newy]=false;
            
           }
        }

    }

    vector<string> findpath(vector<vector<int>>&mat, int n){
        vector<string> ans;
        vector<vector<bool>> visited(n,vector<bool>(n,0)); //ye store krega kon konsi position hum visit kr chuke hai
        string output="";
        int curr_x=0;
        int curr_y=0;
        visited[0][0]=true; // humesha pehla toh visit krenge hi, so marked as visited
        int destx=n-1;
        int desty=n-1;

        //imp case
        if(mat[0][0]==0){
            return ans;
            //agar starting wala hi zero h mtlb blocked h wo path mtlb kahin aage nhi jaa skte so return empty ans
        }

        solve(mat,n,ans,visited,curr_x,curr_y,destx,desty,output);

        return ans;

    }


int main(){

    vector<vector<int>> mat= 
    {{1, 0, 0, 0},
     {1, 1, 0, 1},
     {1, 1, 0, 0}, 
     {0, 1, 1, 1}
     };
     int n=4;

    vector<string> sol=findpath(mat,n);

    for(const string &path:sol){
        cout<<path<<" ";
    }

    return 0;
}