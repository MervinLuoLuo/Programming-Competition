    /*https://www.luogu.com.cn/problem/P1055*/
    #include <bits/stdc++.h>
    #define endl '\n'
    #define yes cout << "YES" << endl
    #define no cout << "NO" << endl
    #define ll long long
    #define pii pair<int,int>
    #define vii vector<vector<int>>
    using namespace std;
    const int INF = 1e18;
    const int maxn = 1e9;
    const int MOD = 11;

    void solve(){
        string s;cin >> s;
        s = " " + s;
        int x = 0;
        int cnt = 1;
        for(int i =1; i <= 12; i++){
            if(s[i] != '-') {
                x += ((s[i] - '0') * cnt) % MOD;
                cnt++;
            }
        }
        x = x % MOD;
        char c;
        if(x == 10) c = 'X';
        else c = x + '0';
        if(c != s[13]){
            s[13] = c;
            s.erase(0,1);
            cout << s << endl;
        }
        else cout << "Right" << endl;


    }
    signed main(){
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        solve();
        return 0;
    }