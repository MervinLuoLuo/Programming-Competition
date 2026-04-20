#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int MAXN = 1e9;
constexpr int INF = 1e18;
string s = "";

void op1(){
    // cerr << 1 << endl;
    int l1;cin >> l1;
    string tar = "";
    for(int i = 1; i <= l1; i++){
        int x;cin >> x;
        x--;
        tar += ('a' + x);
    }
    int l2;cin >> l2;
    string rep = "";
    for(int i = 1; i <= l2; i++){
        int x;cin >> x;
        x--;
        rep += ('a' + x);
    }
    // for(char c : rep) cerr << c - 'a' << " ";
    // cerr << endl;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == tar[0]){
            bool flag = 1;
            for(int j = 1; j < tar.size(); j++){
                if(s[i + j] != tar[j]) {flag = 0;break;}
            }
            if(flag){
                string s1 = s.substr(0,i);
                string s2 = s.substr(i + tar.size());
                s = s1 + rep + s2;
                return;
            }
        }
    }
}

void op2(){
    for(int i = s.size() - 1; i > 0; i--){
        int cur  = ((s[i] - 'a') + (s[i - 1] - 'a')) + 2;
        if(cur % 2 == 0){
            char ave = ((cur / 2) - 1) + 'a';
            s.insert(i,1,ave);
        }
    }
}

void op3(){
    int l,r;cin >> l >> r;
    l--,r--;
    string s1 = s.substr(0,l);
    string s2 = s.substr(l,(r - l + 1));
    string s3 = s.substr(r + 1);
    // cerr << s1 << endl << s2 << endl << s3 << endl;
    reverse(s2.begin(),s2.end());
    s = s1 + s2 + s3;
}

void solve(){
    int n,m;cin >> n >> m;
    for(int i = 1; i <= n;i ++){
        int x;cin >> x;
        x--;
        s += ('a' + x);
    }
    while(m--){
        int op;cin >> op;
        if(op == 1){
            op1();
        }
        else if(op == 2){
            op2();
        }
        else{
            op3();
        }
    }
    for(int i = 0; i < s.size() - 1; i++){
        int res = s[i] - 'a' + 1;
        cout << res << " ";
    }
    cout << s[s.size() - 1] - 'a' + 1;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}