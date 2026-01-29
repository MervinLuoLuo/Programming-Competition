#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int x,y,p,q,dist;

void modify(int tp,int tq){
    if((tp & tq) != 0) return;

    int d = abs(x - tp) + abs(y - tq);
    if(d < dist){
        dist = d;
        p = tp;q = tq;
    }
}

void solve(){
    cin >> x >> y;
    p = x,q = y &(~x);
    dist = abs(x - p) + abs(y - q);

    for(int i = 0; i <= 30; i++){
        int up = ((x >> i) + 1) << i;
        modify(up,y & (~up));
        
        int down = (x >> i) << i;
        modify(down,y & (~down));

        if(i > 0){
            int tmp = ((x >> i) << i) - 1;
            if(tmp >= 0) modify(tmp,y & (~tmp));
        }

        up = ((y >> i) + 1) << i;
        modify(x & (~up),up);

        down = (y >> i) << i;
        modify(x & (~down),down);

        if(i > 0){
            int tmq = ((y >> i) << i) - 1;
            if(tmq >= 0) modify(y & (~tmq),tmq);
        }
    }

    cout << p << " " << q << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

// 又 JB 位运算