#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    VII a(4,vector<int>(4,0));
    set<int> st;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++) cin >> a[i][j];
    }

    int sumc = a[1][1] + a[1][2] + a[1][3];
    for(int i = 2; i <= 3; i++){
        int res = 0;
        for(int j = 1; j <= 3; j++) {
            res += a[i][j];
        }
        if(res != sumc) {
            cout << "No";
            return;
        }
    }

    int suml = a[1][1] + a[2][1] + a[3][1];
    if(suml != sumc) {
        cout << "No";
        return;
    }

    for(int j = 2;j <= 3; j++){
        int res = 0;
        for(int i = 1; i <= 3; i++){
            res += a[i][j];
        }
        if(res != suml){
            cout << "No";
            return;
        }
    }

    int sum1 = a[1][1] + a[2][2] + a[3][3];
    int sum2 = a[3][1] + a[2][2] + a[1][3];
    if(sum1 != sum2 || sum1 != suml || sum1 != sumc){
        cout << "No";
        return;
    }

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            if(st.count(a[i][j]) != 0){
                cout << "No";
                return;
            }
            st.insert(a[i][j]);
        }
    }

    cout << "Yes";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}