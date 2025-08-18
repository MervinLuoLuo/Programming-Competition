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
const int B = 710;
int n,m;
vector<int> basea,summ,lazya,spf;

vector<pii> factor(int x){
    vector<pii> res;
        while(x > 1){
            int p = spf[x];
            int cnt = 0;
            while(x % p == 0){x /= p;cnt++;}
            res.push_back({p,cnt});
    }
    return res;
}

vector<int> div(int x){
    if(x == 0) return {};
    auto fac = factor(x);
    vector<int> divs = {1};
    for(auto [p , e] : fac){
        int sz = divs.size();
        int pw = 1;
        for(int ee = 1; ee <= e; ee++){
            pw *= p;
            for(int j = 0; j < sz; j++) divs.push_back(divs[j] * pw);
        }
    }
    sort(divs.begin(),divs.end());
    return divs;
}

void op1(int x,int k){
    if(x <= B) lazya[x] += k;
    else{
        for(int i = x; i <= n; i += x) basea[i] += k;
        for(int d = 1;d <= B; d++){
            int g = gcd(d,x);
            int lc = d * x / g;
            if(lc > n) continue;
            int cnt = n / lc;
            summ[d] += k * cnt;
        }
    }
}

void op2(int x,int k){
    auto adiv = div(x);
    for(int e : adiv) basea[e] += k;
    auto fac = factor(x);
    vector<int> sdiv;
    for(int dd : adiv) {
        if (dd <= B) sdiv.push_back(dd);
    }
    for(int sd : sdiv){
        vector<pii> exp;
        int tmp = sd;
        for(auto [p, e] : fac){
            int cnt = 0;
            while(tmp % p == 0){tmp /= p;cnt++;}
            if(cnt) exp.push_back({p,cnt});
        }
        int tau = 1;
        for(auto [p,e] : fac){
            int em = e;
            for(auto[pp,ee] : exp){
                if(pp == p){em -= ee;break;}
            }
            tau *= (em + 1);
        }
        summ[sd] += k * tau;
    }
}

int op3(int x){
    int res = 0;
    if(x <= B) res = summ[x];
    else{
        for(int i = x; i <= n; i += x) res += basea[i];
    }
    
    for(int d = 1; d <= B; d++){
        int g = gcd(d,x);
        int lc = d * x / g;
        if(lc > n) continue;
        int cnt = n / lc;
        res += lazya[d] * cnt;
    }
    return res;
}

int op4(int x){
    int res = 0;
    auto adiv = div(x);
    for(int i : adiv) res += basea[i];
    auto fac = factor(x);
    vector<int> sdiv;
    for(int dd : adiv){
        if(dd <= B)sdiv.push_back(dd);
    }
    int lazy = 0;
    for(int sd : sdiv){
        vector<pii> exp;
        int tmp = sd;
        for(auto[p , e] : fac){
            int cnt = 0;
            while(tmp % p == 0){tmp /= p;cnt++;}
            if(cnt) exp.push_back({p,cnt});
        }
        int tau = 1;
        for(auto [p,e] : fac){
            int em = e;
            for(auto[pp,ee] : exp){
                if(pp == p){em -= ee;break;}
            }
            tau *= (em + 1);
        }
        lazy += lazya[sd] * tau;
    }
    res += lazy;
    return res;
}

void solve(){
    cin >> n >> m;
    basea.assign(n + 1,0);
    for(int i = 1 ; i<= n; i++) cin >> basea[i];
    summ.assign(B + 1, 0);
    for(int d = 1; d <= B; d++){
        for(int i = d; i <= n; i += d) summ[d] += basea[i];
    }
    lazya.assign(B + 1,0);spf.assign(n + 1,0);
    for (int i = 0; i <= n; i++) spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    while(m--){
        int op,x,k;cin >> op >> x;
        if(op == 1){
            cin >> k;
            op1(x,k);
        }
        else if(op == 2){
            cin >> k;
            op2(x,k);
        }
        else if(op == 3) {
            int ans = op3(x);
            cout << ans << endl;
        }
        else {
            int ans = op4(x);
            cout << ans << endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}