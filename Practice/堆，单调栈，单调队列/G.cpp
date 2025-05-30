#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
const int N = 1e6 + 5;

struct file{
    int id, s, t;
};
bool operator < (file  a, file b) {
    return a.t < b.t;
    }
struct printer{
    int id, cur;
    bool operator < (const printer &a)const {
        return cur > a.cur or(cur == a.cur and id > a.id);
    }
};

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;cin >> n >> m;
    vector<file> f(n + 5);
    vector<printer> p(m + 5);
    for(int i = 1;i <= n; i++){
        f[i].id = i;
        cin >> f[i].s >> f[i].t;
    }
    sort(f.begin() + 1, f.begin() + 1 + n);
    //for(int i = 1; i <= n; i++) cout << f[i].id << ' ';
    priority_queue<printer> free, busy;
    for(int i = 1; i <= n; i++){
        free.push({i,0});
    }
    vector<vector<int>> ans(m + 5);
    for(int i = 1; i <= n; i++){
        if(!busy.empty()){
            vector<int> ava;
            while(!busy.empty()){
                int x = busy.top().cur;
                if(x > f[i].t) break;
                ava.push_back(busy.top().id);
                busy.pop();
            }
            for(auto it : ava) free.push({it,0});
        }
        int curid;
        if(!free.empty()){
            curid = free.top().id;
            free.pop();
            busy.push({curid,f[i].t + f[i].s});
        }
        else{
            curid = busy.top().id;
            busy.push({curid,busy.top().cur+f[i].s});
            busy.pop();
        }
        ans[curid].push_back(f[i].id); 
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i].size() << ' ';
        sort(ans[i].begin(),ans[i].end());
        for(auto it : ans[i]) cout << it << ' ';
        cout << endl;
    }
    return 0;
}