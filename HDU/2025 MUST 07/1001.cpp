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
struct Point{
    int x;
    int y;
    int v;
};

void solve(){
    int n,k;cin >> n >> k;
    vector<Point> p(n);
    int maxx = 0, maxy = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y >> p[i].v;
        maxx = max(maxx,p[i].x);
        maxy = max(maxy,p[i].y);
    }
    if(maxx > maxy){
        for(int i =0; i < n; i++) swap(p[i].x,p[i].y);
        swap(maxx,maxy);
    }
    vector<vector<pii>> col(maxx + 2);
    for(int i = 0; i < n; i++){
        int x = p[i].x, y = p[i].y, v = p[i].v;
        col[x].push_back({y,v});
    }

    vector<int> colsum(maxy + 2, 0);
    int ans = 0;

    for(int L = 1; L <=maxx; L++){
        fill(colsum.begin(),colsum.end(),0LL);

        for(int R = L; R <= maxx; R++){
            int len = R - L + 1;
            if(len > k && k == 0) break;
            for(auto &p : col[R]) colsum[p.first] += p.second;
            int hmax = k / len;
            if(hmax < 0) break;
            int best = 0;
            int pre = 0;
            deque<pii> dq;
            dq.push_back({0LL,0LL});
            vector<int> prefix(maxy + 1);
            prefix[0] = 0;
            for(int i = 1; i <= maxy; i++){
                pre += colsum[i];
                prefix[i] = pre;
                int idx = i - hmax - 1;
                while(!dq.empty() && dq.front().second < i - hmax) dq.pop_front();
                if(!dq.empty()){
                    int cand = pre - dq.front().first;
                    if(cand > best) best = cand;
                }
                while(!dq.empty() && dq.back().first >= pre) dq.pop_back();
                dq.push_back({pre,i});
            }
            ans = max(best,ans);
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}