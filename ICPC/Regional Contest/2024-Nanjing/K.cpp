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

void solve(){
    int n,m,k,w;cin >> n >> m >> k >> w;
    vector<int> a(n + 1, 0),b(m + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    b.push_back(w + 1);
    m++;

    vector<int> ans;
    //红色下标
    int cur = 1;


    //遍历 黑 区间 ( b[i - 1], b[i] )
    for(int i = 1; i <= m; i++){
        //左右界
        int L = b[i - 1] + 1, R = b[i] - 1;
        //如果区间内没有红,就直接走到下一个黑区间
        if(L > R) continue;

        vector<int> seg;//存这个区间内的红色纸条
       while(cur <= n && a[cur] <= R){
            if(a[cur] >= L ) seg.push_back(a[cur]);//存纸条左界
            cur++;
       }
       if(seg.empty()) continue;//没有红色块就到下一个黑区间

       vector<int> lefts;
       int cur_cover = L - 1;//记录现在被覆盖的右端
       for(int x : seg){
            if(x > cur_cover){
                lefts.push_back(x);
                cur_cover = x + k - 1;//更新右端点
            }
        }

        //本来长度就不够放所有纸条的情况
        if(lefts.size() * k > R - L + 1){cout << -1 << endl;return;}

        //调整最后一张纸条
        if(lefts.back() + k - 1 > R){
            lefts.back() = R - k + 1;//对齐边界
            for(int j = lefts.size() - 2; j >= 0; j--){
                if(lefts[j] + k - 1 >= lefts[j + 1]){//如果重叠就往左走
                    //直接让他们右界对齐后一个纸条左界就行,不需要考虑重叠了多少
                    lefts[j] = lefts[j + 1] - k;
                }
            }
        }

        //左边界越界
        if(lefts.front() < L) {cout << -1 << endl;return;}

        //存入答案
        for(int x : lefts) ans.push_back(x);
    }
    //还有纸条没存下
    if(cur <= n) {cout << -1 << endl;return;}

    cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
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