#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=2e5+10;
const int mod=998244353; 
void solve()
{
    string s;cin >> s;
    int ans = 0,ans1=0,ans2=0;
    map<int,int> mp;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='2')
        {
            if(i%2==0)
                ans1++;
            else
                ans2++;
            continue;
        }
        if(i%2==0)
            mp[s[i]-'0']++;
        else
            mp[s[i]-'0']--;
    }
    if(mp[0]*mp[1]>=0)
    {
        cout<<s.size()%2<<'\n';
        return;
    }
    if(mp[0]>0)
    {
        ans+=max(0ll,mp[0]-ans2);
        ans+=max(0ll,-mp[1]-ans1);
    }
    else
    {
        ans+=max(0ll,-mp[0]-ans1);
        ans+=max(0ll,mp[1]-ans2);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--)
        solve();
}