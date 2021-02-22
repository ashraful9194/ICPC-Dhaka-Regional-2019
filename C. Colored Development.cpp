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
const int p=1e9+7;
int power(int a,int b)
{
    int res=1;
    a%=p;
    while(b)
    {
        if(b&1)  res=(res*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return  res;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {
         int n,m;
         cin>>n>>m;
         int ans=((n-1)*power(n,p-2))%p;
         ans=power(ans,m);
         ans=(1-ans+p)%p;
         ans=(n*ans)%p;
         cout<<"Case "<<tc<<": ";
         cout<<ans<<endl;
     }


}




