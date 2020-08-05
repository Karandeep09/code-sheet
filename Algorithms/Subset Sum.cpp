bool is_subset_sum(vector<int>& v,int sum)
{
    int n=v.size();
    vector<int>dp(sum+1,0);
    dp[0]=1; //sum =0 is always attainable.

for(int i=0;i<n;i++)
    for(int j=sum;j>=v[i];j--)
        dp[j]|=dp[j-v[i]];

return dp[sum];

}