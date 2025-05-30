/*https://codeforces.com/contest/2084/problem/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<pii> s(n);
    for(int i = 0; i < n;i++){
        s[i] = {a[i],b[i]};//方便同步
    }
    vector<pii> ans;
    map<pii,int> pos;//记录位置
    for(int i = 0; i < n; i++){
        if(s[i].first == s[i].second and i != (n - 1) / 2){
            swap(s[i],s[(n - 1) / 2]);
            ans.push_back({i,(n - 1) / 2});
            break;//只走一次,方便后面判断
        }
    }
    for(int i = 0; i < n; i++) pos[s[i]] = i;//初始化位置
    for(int i =0; i < n / 2; i++){
        auto[x,y] = s[i];
        if(pos.find({y,x}) == pos.end() or x == y){
            no;return;
        }
        //如果没有对称序列或者发现第二个 x == y ,就无法构造
        int sp = n - i - 1;
        int cur = pos[{y,x}];
        if(cur != sp){
            swap(s[sp], s[cur]);
            ans.push_back({cur,sp});
            pos[s[sp]] = sp;
            pos[s[cur]] = cur;
        }
        //找对称点位置并操作,注意我这里是 0-based
    }
    cout << ans.size() << endl;
    for(auto it : ans){cout << it.first + 1 << " " << it.second + 1 << endl;}
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}