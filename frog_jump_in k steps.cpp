# include<bits/stdc++.h>


using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>dp(n+1,-1);

    dp[0]=0;

    int minsteps=INT_MAX;

    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int steps=dp[i-j]+abs(arr[i]-arr[i-j]);

                minsteps=min(minsteps,steps);
            }
        }
        dp[i]=minsteps;
    }

    cout<<dp[n-1]<<endl;
}