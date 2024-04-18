// Problem link :  https://bit.ly/3K1cvqv

// Approach: 1 Top-down memoization 

#include <bits/stdc++.h> 

int solve(int i , int j , vector<vector<int>>&triangle , vector<vector<int>>&dp, int n ){
	if(i==n-1){
		return triangle[n-1][j];
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	int down=triangle[i][j] +solve(i+1,j,triangle,dp,n);
	int diag=triangle[i][j] + solve(i+1,j+1,triangle,dp,n);

	return dp[i][j]=min(up,diag);

}



int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

	return solve(0,0,triangle,dp,n);

}

// Approach 2 : Bottom-up DP Tabulation 

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

    for(int i=0;i<n;i++){
        dp[n-1][i]=triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
    }

    return dp[0][0];

}

// Approach 3: Bottom-up DP Tabulation (Space Optimized)

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<int>dp(n+1,-1);

    for(int i=0;i<n;i++){
        dp[i]=triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
        }
    }

    return dp[0];

}

