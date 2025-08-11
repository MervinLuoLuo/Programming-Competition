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
using i128 = __int128_t;

void read(i128 &x){
    x = 0;
    int sign = 1;
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    if (c == '-'){
        sign = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9'){
        x = x * 10 + (c - '0');
        c = getchar();
    }
    x *= sign;
}

void print(i128 x){
    if(x == 0){ putchar('0');return;}
    if(x < 0){putchar('-');x = -x;}
    string s;
    while(x > 0){
        s.push_back('0' + (int)(x % 10));
        x /= 10;
    }
    reverse(s.begin(),s.end());
    fputs(s.c_str(), stdout);
}

i128 calc(i128 r,i128 c ,i128 cnt){
    if(cnt <= 0) return (i128)0;
    i128 sum1 = cnt * r + c * (cnt * (cnt - 1) / 2);
    i128 sum_j = cnt * (cnt - 1) / 2;
    i128 sum_j2 = cnt * (cnt - 1) * (2 * cnt - 1) / 6;
    i128 sum2 = cnt * r * r + 2 * r * c * sum_j + c * c * sum_j2;
    return (sum2 + sum1) / 2;
}

void solve(){
    i128 n,w; read(n);read(w);
    i128 ans = 0,r = 0, tim = n;
    i128 sum = (n + 1) * n / 2;
    while(tim >= w){
        i128 c = tim / w;
        i128 cnt = (tim - w * c) / c + 1;
        ans += cnt * sum - calc(r,c,cnt);
        r += cnt * c;
        tim -= cnt * c;
    }
    ans += sum - (1 + r) * r / 2;
    print(ans);
    putchar(endl);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    i128 t;
    read(t);
    while(t--){
        solve();
    }
    return 0;
}