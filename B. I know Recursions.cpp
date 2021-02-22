#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int caller,callee,n,p,k,cnt;
int dp[10005];
void solve(int n)
{
    for(int i=1; i<=p; i++)
    {
        ++cnt;
        if(cnt==k)
        {
            caller=n,callee=n-i;
            return;
        }
        if(cnt+dp[n-i]<k) cnt+=dp[n-i];
        else
        {
            solve(n-i);
            break;
        }
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {
         cin>>n>>p>>k;
         cout<<"Case "<<tc<<": ";
         if(p==1)
         {
             if(k>n)
             {
                 cout<<"Invalid"<<endl;
             }
             else
             {
                 cout<<n-k+1<<" "<<n-k<<endl;
             }
             continue;
         }
         for(int i=0; i<=n; i++)
            dp[i]=0;
         for(int i=p; i<=n; i++)
         {
             for(int j=1; j<=p; j++)
               {
                    dp[i]+=1+dp[i-j];
                    if(dp[i]>k) break;
               }
         }
         if(dp[n]<k)
         {
             cout<<"Invalid"<<endl;
             continue;
         }
         cnt=0;
         solve(n);
         cout<<caller<<" "<<callee<<endl;
     }
}
