// Problem Link : https://bit.ly/3q5sqfu

// approach 1 : Top down approach using memoization and recursion 

#include <bits/stdc++.h> 

int solve(int i,int j , vector<vector<int>>&grid , vector<vector<int>>&dp){
            if(i==0 && j==0){
                return grid[i][j];
            }

            if(i<0 || j<0){
                return 1e9;
            }

            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            int left=grid[i][j]+solve(i,j-1,grid,dp);
            int up=grid[i][j] +solve(i-1,j,grid,dp);

            dp[i][j]=min(left,up);

            return dp[i][j];
}



int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    
    return solve(n-1,m-1,grid,dp);
}

// Approach 2 : Bottom up approach using dynamic programming using tabulation 

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,1e9));
    dp[0][0]=grid[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+grid[i][j]);
            }
            if(j>0){
                dp[i][j]=min(dp[i][j],dp[i][j-1]+grid[i][j]);
            }
        }
    }
    return dp[n-1][m-1];
}

// approach 3 : Bottom up approach using dynamic programming using tabulation with space optimization

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<int>dp(m,1e9);
    dp[0]=grid[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0){
                dp[j]=min(dp[j],dp[j]+grid[i][j]);
            }
            if(j>0){
                dp[j]=min(dp[j],dp[j-1]+grid[i][j]);
            }
        }
    }
    return dp[m-1];
}