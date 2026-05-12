#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

struct Point{
    int x,y;
    
    // 求向量
    Point operator-(const Point &a) const{
        int nx = x - a.x,ny = y - a.y;
        return {nx,ny};
    }

    // 重载运算符 用 ^ 表示叉乘
    int operator^(const Point &a) const{
        int res = x * a.y - y * a.x;
        return res;
    }

    int operator*(const Point &a) const{
        int res = x * a.x + y * a.y;
        return res;
    }

    // 求向量模的平方
    int len2() const{
        int res = (*this) * (*this);
        return res;
    }

    // 要求圆心都在弦的同一侧
    int toleft(const Point &a) const{
        auto t = (*this) ^ a;
        if(t > 0) return 1;
        else if(t < 0) return 0;
        else return -1;
    }
};

int n,R;
Point c;
vector<Point> p;

bool check(int l,int r){ 
    if(r >= l + n) return false;
    Point v = p[r] - p[l];
    Point w = c - p[l];

    // 要求圆心必须在弦的右侧 否则不合法
    if(v.toleft(w) < 0) return false;

    // 判断点到圆心的距离是否合法
    i128 num = v ^ w;
    num *= num;
    i128 den = v.len2();

    return num >= (i128)R * R * den;
}

void solve(){
    cin >> n;
    cin >> c.x >> c.y >> R;
    p.clear();p.resize(n * 2);
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        p[i + n] = p[i];
    }

    int ans = 0,cur = 0;
    int r = 0;
    for(int l = 0; l < n; l++){
        if(r <= l){
            r = l + 1;
            cur = 0;
        }

        // r + 1 满足了才可以递增 r 并加上多的这一块三角形的面积
        while(check(l,r + 1)){
            int res = abs((p[r] - p[l]) ^ (p[r + 1] - p[l]));
            cur += res;
            r++;
        }

        ans = max(ans,cur);
        if(r > l + 1){
            cur -= abs((p[l + 1] - p[r]) ^ (p[l] - p[r]));
        }
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}