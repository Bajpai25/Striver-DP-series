Problem : https://bit.ly/3F4yl8z 

// Approach 1 : Memoization : TopDown


int solve(int index , vector<vector<int>>&points , int last, vector<vector<int>>&dp ){

    if(index==0){
        int maxi=0;

        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[index][last]!=-1){
        return dp[index][last];
    }
    int ans=0;

    for(int i=0;i<3;i++){
        if(i!=last){
            int point=points[index][i] +solve(index-1,points,i,dp);
            ans=max(ans,point);
        }
    }
    return dp[index][last]= ans;
}



int ninjaTraining(int n, vector<vector<int>> &points)
{
   vector<vector<int>>dp(n+1 ,  vector<int>(4,-1)); 

    return solve(n-1,points,3,dp);
}


// Approach 2 : Tabulation : BottomUp

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n+1 , vector<int>(4,-1));

    dp[0][0]=max(points[0][1] ,points[0][2]);
    dp[0][1]=max(points[0][0] ,points[0][2]);
    dp[0][2]=max(points[0][0] , points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

   
    for(int days=1;days<n;days++){

        for(int last=0;last<4;last++){
            dp[days][last]=0;

            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[days][task] +dp[days-1][task];
                    dp[days][last]=max(dp[days][last],point);
                    }
            }
        }
    }

    return dp[n-1][3];
}

// Approach 3 : Space optimisation Intuition : 

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>prev(4,0);

    prev[0]=max(points[0][1] ,points[0][2]);
    prev[1]=max(points[0][0] ,points[0][2]);
    prev[2]=max(points[0][0] , points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

   
    for(int days=1;days<n;days++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;

            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[days][task] +prev[task];
                    temp[last]=max(temp[last],point);
                    }
            }
        }
        prev=temp;
    }

    return prev[3];
}