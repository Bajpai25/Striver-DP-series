Problem : https://bit.ly/3F4yl8z


#include <bits/stdc++.h> 


long long solve(vector<long long>&nums){
    long long n=nums.size();

    long long prev1=nums[0];
    long long prev2=0;

    for(long long i=1;i<n;i++){
        long long rob=nums[i];
        if(i>1){
            rob+=prev2;
        }
        long long notrob=0+prev1;
        long long curr=max(rob,notrob);
        prev2=prev1;
        prev1=curr;
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    long long n=valueInHouse.size();
    if(n==1) return valueInHouse[0];

    vector<long long>v1,v2;
    for(long long i=0;i<n;i++){
        if(i!=0){
            v1.push_back(valueInHouse[i]);
        }
        if(i!=n-1){
            v2.push_back(valueInHouse[i]);
        }
    }

    long long ans=max(solve(v1),solve(v2));
    return ans;
}