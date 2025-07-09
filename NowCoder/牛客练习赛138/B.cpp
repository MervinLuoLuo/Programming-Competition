#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int j=0;j<m;j++)cin>>b[j];
    sort(b.begin(),b.end());
    vector<int>s(m+1);
    for(int i=0;i<m;i++)s[i+1]=s[i]+b[i];
    int ans=0;
    for(int i=0;i<n;i++){
        int x=a[i];
        int k=upper_bound(b.begin(),b.end(),x)-b.begin();
        ans += x*k + (s[m]-s[k]);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t--){
       solve();
    }
    return 0;
}
