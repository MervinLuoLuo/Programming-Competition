#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

struct Tra{
    double gain;
    int x,y;

    bool operator<(const Tra& other)const {
        return gain < other.gain;
    }
};

void solve(){
    int n,w;cin >> n >> w;
    vector<Tra> a(n + 1);
    double ans = 0;
    priority_queue<Tra> pq;
    for(int i =1 ; i <= n; i++){
        int x,y;cin >> x >> y;
        a[i].x = x,a[i].y = y;
        ans += sqrt((double)x * x + (double)y * y);
        if(y > 0){
            double num = 2.0 * y - 1.0;
            double de = sqrt(x * x + y * y) + sqrt(x * x + (y - 1.0) * (y - 1.0));

            pq.push({num/de ,x,y});
        }
    }
    double cut = 0;
    for(int k = 0; k < w; k++){
        if(pq.empty()) break;
        Tra cur = pq.top();
        pq.pop();
        cut += cur.gain;
        cur.y--;

        if(cur.y > 0){
            double num = 2.0 * cur.y - 1.0;
            double de = sqrt(cur.x * cur.x + cur.y * cur.y) + sqrt(cur.x * cur.x + (cur.y - 1.0) * (cur.y - 1.0));
            pq.push({num / de, cur.x,cur.y}); 
        }
    } 

    cout << fixed << setprecision(10) << ans - cut << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}