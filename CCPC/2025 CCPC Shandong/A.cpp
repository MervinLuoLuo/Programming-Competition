#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
struct Node{
    int a;
    int b;
    int id;
};
int n;
vector<Node> a;
vector<int> ans,tmp;

bool check(int x){
    if(x == 0) return 1;
    int res = 0;
    tmp.clear();

    int i = 1;
    while(i <= n && res < x){

        // 取出当前职位相同的一组
        vector<Node> cur;
        int j = i;
        while(j <= n && a[j].a == a[i].a){
            cur.push_back(a[j]);
            j++;
        }
        
        // 这组选择 choose 个
        int choose = 0;
        int maxx = min((int)cur.size(),x - res);// 最多不能超过当前组员数
        for(int t = maxx; t >= 1; t--){
            int suf = max(x - res - t, 0ll); // 假设选择 t 个那么更高级别的只能选 suf 个
            if(suf <= cur[t - 1].b){// 满足当前选择的最小 b 更新
                choose = t;
                break;
            }
        }

        // 将选好的 choose 个人推入答案
        for(int k = 0; k < choose; k++) tmp.push_back(cur[k].id);
        res += choose;
        i = j;
    }
    return res == x;
}

void solve(){
    cin >> n;
    a.clear();a.resize(n + 1);
    ans.clear();
    for(int i = 1 ; i <= n; i++){
        cin >> a[i].a >> a[i].b;
        a[i].id = i;
    }
    sort(a.begin() + 1,a.end(),[](Node x,Node y){
        if(x.a == y.a) return x.b > y.b;
        return x.a < y.a;
    });

    int l = 1,r = n;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
            ans = tmp;
        }
        else r = mid - 1;
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
} 

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}