//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
  public:
    //Function to find a solved Sudoku. 
    
    bool isvalid(int row,int col,int n,int (*grid)[N],int num){
        for(int i=0;i<n;i++){
            if(grid[i][col]==num) return false;
            if(grid[row][i]==num) return false;
        }
        int i=row/3,j=col/3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(grid[i*3+k][j*3+l]==num) return false;
            }
        }
        return true;
    }
    bool solve(int n,int (*grid)[N]){
        
        for(int row=0;row<N;row++){
            for(int col=0;col<N;col++){
                if(grid[row][col]==0){
                    for(int num=1;num<=9;num++){
                        if(isvalid(row,col,n,grid,num)){
                            grid[row][col]=num;
                            if(solve(n,grid)) return true;;
                            grid[row][col]=0;
                        }    
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solve(9,grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends