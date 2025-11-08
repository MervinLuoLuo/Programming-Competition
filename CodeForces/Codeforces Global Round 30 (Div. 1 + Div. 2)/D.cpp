#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,K;cin >> n >> K;
    string s,t;cin >> s >> t;
    vector<int> p(n + 1, 0);

    auto check = [&](int k) -> bool{
        int prev = 1;//确定上一次的位置
        for(int j = 1; j <= n; j++){
            int l = max(1LL ,j - k);
            if(l < prev) l = prev;//保证 p 非严格递增, 需要缩小左界
            int found = -1;
            for(int idx = l; idx <= j; idx++){
                if(s[idx - 1] == t[j - 1]){
                    found = idx; 
                    break;
                }
            }
            if(found == -1) return 0;//当前区间[l,j]找不到任何一个字符与 t[j]符合就绝对无法构造
            p[j] = found;
            prev = found;
        }
        return 1;
    };

    int ans = -1;
    for(int k = 0; k <= K; k++){//枚举最小可行 k
        if(check(k)){
            ans = k;
            break;
        }
    }

    if(ans == -1){cout << -1 << endl; return;} 
     
    cout << ans << endl;

    vector<int> q = p;
    string cur = s;

    for(int i = 1; i <= ans; i++){
        string nxt = cur;
        nxt[0] = cur[0];

        for(int j = 2; j <= n; j++){
            nxt[j - 1] = (q[j] == j ? cur[j - 1] : cur[j - 2]);// 0 - base
        }

        cout << nxt << endl;

        for(int j = 1; j <= n; j++){
            if(q[j] < j) q[j]++;
        }

        cur = nxt;
    }
    
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