// Problem link : https://bit.ly/3F436dK

// approach 1 : memoization approach will give tle so its very bad 


#include <bits/stdc++.h>
using namespace std;

// Function to recursively find the maximum path sum for a given cell
int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // Base Conditions
    if (j < 0 || j >= m)
        return -1e9; // A very large negative value to represent an invalid path
    if (i == 0)
        return matrix[0][j]; // The maximum path sum for the top row is the value itself
    
    if (dp[i][j] != -1)
        return dp[i][j]; // If the result for this cell is already calculated, return it
    
    // Calculate the maximum path sum by considering three possible directions: up, left diagonal, and right diagonal
    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);
    
    // Store the maximum of the three paths in dp
    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

// Function to find the maximum path sum in the given matrix
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size(); // Number of rows in the matrix
    int m = matrix[0].size(); // Number of columns in the matrix
    
    vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization table to store computed results
    
    int maxi = INT_MIN; // Initialize the maximum path sum to a very small value
    
    // Iterate through each cell in the first row to find the maximum path sum starting from each of them
    for (int j = 0; j < m; j++) {
        int ans = getMaxUtil(n - 1, j, m, matrix, dp); // Calculate the maximum path sum for the last row
        maxi = max(maxi, ans); // Update the maximum path sum if a larger one is found
    }
    
    return maxi; // Return the maximum path sum
}

int main() {
    // Define the matrix as a 2D vector
    vector<vector<int>> matrix{{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
    
    // Call the getMaxPathSum function and print the result
    cout << getMaxPathSum(matrix);

    return 0;
}


// Approach 2 : Bottom-up DP Tabulation

#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  tabulation 
    int n=matrix.size();
    int m=matrix[0].size();


    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    // storing the values of the first row 
    for(int i=0;i<m;i++){
        dp[0][i]=matrix[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=matrix[i][j] + dp[i-1][j];
           int left=matrix[i][j] ;
            if(j-1>=0){
                 left+= dp[i-1][j-1];
            }
            else{
                left=-1e9;
            }
            int right=matrix[i][j];
             if(j+1<m){
                 right+= dp[i-1][j+1];
            }
            else{
                 right=-1e9;
            }
            dp[i][j]=max(up,max(left,right));
        }
    }

    int maxi=INT_MIN;

    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }

    return maxi;

}

// Approach 3: Bottom-up DP Tabulation (Space Optimized)

#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  tabulation 
    int n=matrix.size();
    int m=matrix[0].size();


   vector<int>prev(n+1,0);

    // storing the values of the first row 
    for(int i=0;i<m;i++){
        prev[i]=matrix[0][i];
    }

    for(int i=1;i<n;i++){
        vector<int>curr(n+1,0);
        for(int j=0;j<m;j++){
            int up=matrix[i][j] + prev[j];
           int left=matrix[i][j] ;
            if(j-1>=0){
                 left+= prev[j-1];
            }
            else{
                left=-1e9;
            }
            int right=matrix[i][j];
             if(j+1<m){
                 right+= prev[j+1];
            }
            else{
                 right=-1e9;
            }
            curr[j]=max(up,max(left,right));
        }
        prev=curr;
    }

    int maxi=INT_MIN;

    for(int j=0;j<m;j++){
        maxi=max(maxi,prev[j]);
    }

    return maxi;

}