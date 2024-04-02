Problem Link: https://bit.ly/3q5rlUY

// approach 1 : Memoization : TopDown


#include <bits/stdc++.h>
using namespace std;


int solve(int i, vector<int>&nums , vector<int>&dp){

    if(i==0){
        return nums[i];
    }
    if(i<0){
        return 0;
    }

    if(dp[i]!=-1){
        return dp[i];
    }

    int pick=nums[i] +solve(i-2,nums,dp);

    int notpick= 0 + solve(i-1,nums,dp);

    dp[i]=max(pick,notpick);

    return dp[i];
}

int max_sum(vector<int>&nums){

    int n=nums.size();

    vector<int>dp(n+1,-1);

    return solve(n-1,nums);
} 


// Approach 2 : Tabulation : BottomUp

int max_sum(vector<int>&nums){

    int n=nums.size();

    vector<int>dp(n+1,-1);

    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1){
            pick+=dp[i-2];
        }
        int notpick=0+ dp[i-1];

        dp[i]=max(pick,notpick);
    }

    return dp[n-1];
} 

// Approach 3 : Space optimisation Intuition : We only need to keep track of last two elements

int max_sum(vector<int>&nums){

    int n=nums.size();

    int prev1=nums[0]; // prev for dp[i-1]

    int prev2=0;  // prev for dp[i-2]

    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1){
            pick+=prev2;
        }

        int notpick=0 +prev1;

        int curr=max(prev1,prev2);
    }

    return prev1;
} 