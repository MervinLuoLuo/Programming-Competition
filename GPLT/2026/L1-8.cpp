#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
string s;
int n;

void op1(){
    string ss;cin >> ss;
    int m = ss.size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(s[i] == ss[0]){
            string tmp = s.substr(i,m);
            if(tmp == ss) ans.push_back(i);
        }
        if(ans.size() == 3) break;
    }
    if(ans.size() == 0) cout << -1;
    else{
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i != ans.size() - 1) cout << " ";
        }
    }

}

void op2(){
    int p;cin >> p;
    string ss;cin >> ss;
    s.insert(p,ss);
    cout << s;
}

void op3(){
    int l,r;cin >> l >> r;
    string s1 = s.substr(0,l);
    string s2 = s.substr(l,r - l + 1);
    string s3 = s.substr(r + 1);
    // cerr << s1 << endl << s2 << endl << s3;
    reverse(s2.begin(),s2.end());
    s = s1 + s2 + s3;
    cout << s;
}

void solve(){
    int q;cin >> q;
    cin >> s;
    n = s.size();
    while(q--){
        int op;cin >> op;
        if(op == 1) op1();
        else if(op == 2) op2();
        else op3();
        if(q != 0) cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/*
3 2 6

XaabaMbaY
*/

/*
XabMabaY

XaabaMbY
*/