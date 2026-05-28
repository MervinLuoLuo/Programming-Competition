#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using tiii = tuple<int,int,int>;
constexpr int INF = 1e18;
#define debug(x) cerr<<#x<<":"<<x<<endl;

void solve(){
    int n;cin>>n;
    vector<int> a(n+1);
    // debug(n)
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    sort(a.begin()+1,a.end());
    // cerr<<a[ceil((1+n)/2)]<<endl;
    vector<tuple<int,int,int>> d;
    unordered_map<int,int> mp;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(d.empty()){
            d.push_back({a[i],i,i});
            mp[a[i]] = cnt++;
            continue;
        }
        auto& [v,l,r] = d.back();
        if(a[i]==v){
            r ++;
        }else{
            d.push_back({a[i],i,i});
            mp[a[i]] = cnt++;
        }
    }
    int res = 1;
    // for(auto x:a){cerr<<x<<" ";}
    // cerr<<endl;
    // int now = 0;
    // for(auto [tv,tl,tr]:d){
    //     cerr<<now++<<":"<<"["<<tv<<","<<tl<<","<<tr<<"]"<<endl;
    // }
    // cerr<<"====================="<<endl;
    // for(auto [x,y]:mp){
    //     cerr<<"key:"<<x<<" "<<"val:"<<y<<endl;
    // }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            int lv = a[i];
            int rv = a[j];
            if(((lv+rv)%2)!=0) continue;

            int mid = (lv+rv)/2;
            if(mp.count(mid)==0) continue;
            int tar = mp[mid];
            auto [tv,tl,tr] = d[tar];
            int cnt1 = tl-i-1;
            int cnt2 = j-tr-1;
          
            res = max(res,min(cnt1,cnt2)*2 + tr - tl + 3L);
            

            // debug(i);debug(j);
            // debug(lv);debug(rv);
            // debug(tl);debug(tr);
            // debug(need);
            // cerr<<"======"<<endl;
            
        }
    }
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}