#include<bits/stdc++.h>
using namespace std;
int knapSack(int wt[],int val[],int w,int n)
{
	int dp[n+1][w+1];
	for(int i = 0;i <= n;i++)
	{
		dp[i][0] = 0;
	}
	for(int i = 0;i <= w;i++)
	{
		dp[0][i] = 0;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=w;j++)
		{
			if(wt[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
			}
		}
	}
	return dp[n][w];
}
int main()
{
	int val[] = {10, 15, 40};
	int wt[] = {1, 2, 3};
	int W = 6;
	int n = sizeof(val)/sizeof(val[0]);
	int output = knapSack(wt,val,W,n);
	cout<<output;
	return 0;
}
