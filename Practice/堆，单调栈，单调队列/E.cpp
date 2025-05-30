#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int K,D,M,F;cin >> K >> D >> M >> F;
    priority_queue<int> k,d,m,f;
    for(int i = 0; i < K; i++){
        int x;cin >> x;
        k.push(x);
    }
    for(int i = 0; i < D; i++){
        int x;cin >> x;
        d.push(x);
    }
    for(int i = 0; i < M; i++){
        int x;cin >> x;
        m.push(x);
    }
    for(int i = 0; i < F; i ++){
        int x;cin >> x;
        f.push(x);
    }
    int q;cin >> q;
    for(int i = 0; i < q; i++){
        int  a , b ,c;
        double ans = 0;
        cin >> a >> b >> c;
        for(int j = 0; j < a; j++){
            ans += d.top();
            d.pop();
        }
        for(int j = 0; j < b; j++){
            ans+= m.top();
            m.pop();
        }
        for(int j = 0; j < c; j++){
            ans+= f.top();
            f.pop();
        }
        ans += k.top();
        k.pop();
        printf("%.2f\n", double(ans / 11));
    }
    return 0;
}