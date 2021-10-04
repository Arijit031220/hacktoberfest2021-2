#include<bits/stdc++.h>
using namespace std;
int num_fact_topdown(int dp[],int n)//top_down
{
    if(n==0||n==1||n==2)
        return 1;
    if(n==3)
        return 2;
    if(dp[n]==0)
    {
        int sub_1=num_fact_topdown(dp,n-1);
        int sub_3=num_fact_topdown(dp,n-3);
        int sub_4=num_fact_topdown(dp,n-4);
        dp[n]=sub_1+sub_3+sub_4;
    }
    return dp[n];
}
int num_fact_bottom_up(int dp[],int n) //bottom-up approach
{
    dp[0]=dp[1]=dp[2]=1;
    dp[3]=2;
    for(int i=4;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-3]+dp[i-4];
    }
    return dp[n];
}
 int main()
 {
     int a;
     cout<< "enter the number: ";
     cin>>a;
     int dp[a+1];
     memset(dp,0,sizeof(dp));
     cout<<"using top-down "<<num_fact_topdown(dp,a);
     cout<<endl<<"using bottom-up "<<num_fact_bottom_up(dp,a);

 }
