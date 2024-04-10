Problem link :  https://bit.ly/34uoYCG

// Approach 1: Memoization (Top-Down)

#include <bits/stdc++.h> 
using namespace std;

int solve(int i,int j , vector<vector<int>>&dp){
	// base case

	if(i==0 && j==0){
		return 1;
	}
	if(i<0 || j<0){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	int up=solve(i,j-1,dp);
	int left=solve(i-1,j,dp);

	return dp[i][j]=up+left;
}

int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,-1));

	return solve(m-1,n-1,dp);
}


// Approach 2: Tabulation (Bottom-Up)

/*
    Time Complexity  : O(M * N) 
    Space Complexity : O(M * N)
    
    Where 'M' is the number of rows and 'N' is the number of columns of the matrix.   
*/

int uniquePaths(int m,int n)
{
    // Reference table to store subproblems.
	int dp[m][n];                   

    // Paths to reach a cell in column 1.
	for (int i = 0; i < m; i++) 
    {   
        dp[i][0] = 1; 
    }

    // Paths to reach a cell in row 1.
    for (int j = 0; j < n; j++) 
    {   
        dp[0][j] = 1; 
    }       

    // Bottom up approach.
    for (int i = 1; i < m; i++) 
    {   
        for (int j = 1; j < n; j++) 
        { 
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  
        }
    } 

    // Returning answer.
    return dp[m - 1][n - 1];        
}

// Approach 3 : Space optimise solution

/*
    Time Complexity  : O(M * N) 
    Space Complexity : O(N)
    
    Where 'M' is the number of rows and 'N' is the number of columns of the matrix.  
*/

int uniquePaths(int m,int n)
{
    // Reference array to store subproblems.
	int dp[n] = {1};                   

    // Bottom up approach.
    dp[0] = 1;

    for (int i = 0; i < m; i++) 
    {      
        for (int j = 1; j < n; j++) 
        { 
            dp[j] += dp[j - 1];  
        }
    } 
    
    //Returning answer. 
    return dp[n - 1];                  
}




