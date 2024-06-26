 // Problem link : https://bit.ly/3JMHc2l

// Approach : Top down DP (Memoization)

int mod=(int)1e9+7;
int solve(int i,int j, vector<vector<int>>&mat,vector<vector<int>>&dp){
  
  if (i >= 0 && j >= 0 && mat[i][j] == -1) {
    return 0;
  }

        if(i<0 || j<0){
        return 0;
    }

    if(i==0 && j==0){
        return 1;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int up=solve(i-1,j,mat,dp);
    int left=solve(i,j-1,mat,dp);

    return dp[i][j]=(up+left)%mod;
    
}





int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>>dp(n,vector<int>(m,-1));

    return   solve(n-1,m-1,mat,dp);
}


// Approach 2 : Bottom up DP Tabulation

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int mod=(int)1e9+7;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(mat[i][j]==-1) dp[i][j]=0;
            else if(i==0 && j==0) dp[i][j]=1;
            else{
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0)  left=dp[i][j-1];
                dp[i][j]=(left+up)%mod;
            }
            
        }
        
    }

    return dp[n-1][m-1];
}

// Approach 3 : Space optimistaion (Bottom up DP Tabulation)

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<int>prev(m,0);
    int mod=(int)1e9+7;

    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) curr[j]=0;
            else if(i==0 && j==0) curr[j]=1;
            else{
                int left=0,up=0;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];
                curr[j]=(up+left)%mod;
            }
        }
        prev=curr;
    }

    return prev[m-1];

}

