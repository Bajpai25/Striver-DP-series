// Approach Top-down Memoization 

# include <bits/stdc++.h> 

int jump(int ind,vector<int>&heights,vector<int>&dp){

    // memoization  top-down approach
    
    if(ind==0) return 0;
    // after base case check whether that case is computed before or  not
   //step 2
    if(dp[ind]!=-1){
        return dp[ind];
    }

    int left=jump(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);

    int right=INT_MAX;

    if(ind>1){
        right=jump(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
    }
    // step 3 store the result in the dp vector and return dp vector
    return dp[ind]=min(left,right);
}


int frogJump(int n, vector<int> &heights)
{
    // step1 intialise a dp vector (n+1)
    vector<int>dp(n+1,-1);

    return jump(n-1,heights,dp);
}


// Approach Bottom-Up Tabulation

int frogJump(int n, vector<int> &heights)
{
    // step1 intialise a dp vector (n+1)
    vector<int>dp(n+1,-1);

    dp[0]=0; // base case 
    int left=0;
    int right=INT_MAX;

    for(int i=1;i<=n-1;i--){
        left= dp[i-1] +abs(heights[i]-heights[i-1]);
         // at the index= 1 we cant jump 2 steps 
        if (i > 1) {
          right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i]=min(left,right);
    }

    return dp[n-1];

}

// third space optimised approach constant space O(1)

int frogJump(int n, vector<int> &heights)
{
    
    int prev1=0;
    int prev2=0;

    int first=0;
    int second=INT_MAX;

    for(int i=1;i<=n-1;i++){
        first=prev1+abs(heights[i]-heights[i-1]);

        if(i>1){
            second=prev2 +abs(heights[i]-heights[i-2]);
        }

        int curr=min(first,second);

        prev2=prev1;
        prev1=curr;

    }

    return prev1;
}

