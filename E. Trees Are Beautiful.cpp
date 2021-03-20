/*
#pragma comment (linker, "/stack:200000000")
#pragma GCC optimize("O3")//using O2 isn't a bad idea.
#pragma GCC optimize("Ofast") //may result in inaccurate calculations in float.
#pragma GCC optimize ("unroll-loops") // https://code-examples.net/en/q/17133ec
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")//vectorization
//Consider using user defined function for better optimization.
*/
#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
vector<pii>adj[20004];
int dp[20005];
vector<pii>neg;
int sum,n;

void dfs(int node,int par,int cost)
{
    for(auto i:adj[node])
    {
        int son=i.first;
        int cst=i.second;
        if(son==par) continue;
        dfs(son,node,cst);
        dp[node]+=dp[son];
    }
    if(node==1) return;
    sum+=(dp[node]*(n-dp[node])*cost);
  //  cout<<cost<<" "<<n*(n-dp[node])<<endl;
    if(cost<0) neg.pb({dp[node]*(n-dp[node]),-cost});
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {

         cin>>n;
         for(int i=1; i<=n; i++)
         {
             adj[i].clear();
             dp[i]=1;
         }
         neg.clear();

         for(int i=0; i<n-1; i++)
         {
             int x,y,z;
             cin>>x>>y>>z;
             adj[x].pb({y,z});
             adj[y].pb({x,z});
         }
         sum=0;
         dfs(1,0,0);
        cout<<"Case "<<tc<<": ";
         if(sum>=0)
         {
             cout<<0<<endl;
             continue;
         }
       //  cout<<sum<<endl;
         sort(neg.rbegin(),neg.rend());
         int ans=0;
         /*
         for(auto i:neg)
         {
             cout<<i.first<<" "<<i.second<<endl;
         }
         */
         for(auto i:neg)
         {
             int add=i.first;
             int cnt=i.second;
             if(add*cnt+sum>=0)
             {
                 while(cnt--)
                 {
                     ++ans;
                     sum+=add;
                     if(sum>=0) break;
                 }
                 break;
             }
             ans+=cnt;
             sum+=add*cnt;
         }
         cout<<ans<<endl;

     }

}

