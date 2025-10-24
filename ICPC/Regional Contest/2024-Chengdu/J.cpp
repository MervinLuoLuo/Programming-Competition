#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

struct Node{
    int id,val;
    bool operator < (const Node a) const{
        if(val == a.val) return id < a.id;
        return val > a.val; 
    }
};

void solve(){
    int n,m,q;cin >> n >> m >> q;
    //每个关卡维护两个 set, 得分的人和放弃的人 
    set<int> st_get,st_give;
    vector<int> score(m + 1, 0);
    int cur = -1;//当前关卡
    int now = m;//当前人能得到的分数

    while(q--){
        int op;cin >> op;
        if(op == 1){//换关卡
            int x;cin >> x;
            if(x <= n){
                //初始化所有状态
                st_get.clear();st_give.clear();
                cur = x;
                now = m;
            }
        }

        if(op == 2){
            int idx,x;cin >> idx >> x;
            if(x == cur){//保证关卡没错
                if(!st_get.count(idx) && !st_give.count(idx)){
                    //保证当前人没有在此关有记录
                    st_get.insert(idx);
                    score[idx] += now;
                    now--;
                }
            }    
        }

        //弃权
        if(op == 3){
            int idx,x;cin >> idx >> x;
            if(x == cur){
                if(!st_get.count(idx) && !st_give.count(idx)){
                    st_give.insert(idx);
                }
            }
        }
    }

    vector<Node> vec;
    for(int i = 1; i <= m; i++) vec.push_back({i,score[i]});

    sort(vec.begin(),vec.end());

    for(auto &[u,v] : vec) cout << u << " " << v << endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}