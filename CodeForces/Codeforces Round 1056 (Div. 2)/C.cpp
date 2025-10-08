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
constexpr int MOD = 676767677;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 2, 0),stat(n + 2,0);
    int flag = 0;//记录是否存在断层
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    //从左往右走一遍
    for(int i = 1; i < n; i++){
        if(a[i] - a[i + 1] == 1){//少了一个人 -> i + 1看不见 -> i + 1也是向左
            if(stat[i] == -1) {cout << 0 << endl;return;}
            stat[i] = stat[i + 1] = 1;
            flag = 1;
        }

        else if(a[i] - a[i + 1] == -1){//多了一个人 -> i + 1能被看见
            if(stat[i] == 1){cout << 0 << endl;return;}

            stat[i] = stat[i + 1] = -1;
            flag = 1;
        }

        else if(a[i + 1] == a[i]){//看的人数不变 一左一右配对抵消
            stat[i + 1] = -stat[i]; 
        }

        else {//差值超过 1 , WA掉
            cout << 0 << endl;return;
        }
    }

    //从左往右看一遍,找没被放置过的位置
    for(int i = 1; i <= n; i++){
        if(stat[i] == 0){
            if(stat[i - 1] != stat[i + 1] && stat[i - 1] && stat[i + 1]){
                cout << 0 << endl;return;
            }

            if(stat[i + 1] != 0) stat[i] = -stat[i + 1];
            else if(stat[i - 1] != 0) stat[i] = -stat[i - 1];
        }
    }

    //从右往左看,找没放置的位置
    for(int i = n; i >= 1; i--){
        if(stat[i] == 0){
            if(stat[i - 1] != stat[i + 1] && stat[i - 1] && stat[i + 1]){
                cout << 0 << endl;return;
            }
            if(stat[i + 1] != 0) stat[i] = -stat[i + 1];
            else if(stat[i - 1] != 0) stat[i] = -stat[i - 1];
        }
    }
    
    //如果不是都一样
    if(flag != 0){
        int sum = 1;
        for(int i = 2; i <= n; i++) sum += (stat[i] == 1);
        if(sum != a[1]) {cout << 0 << endl;return;}

        sum = 1;
        for(int i = n - 1;i >= 1; i--) sum += (stat[i] == -1);
        if(sum != a[n]){cout << 0 << endl;return;}
        
        cout << 1 << endl;
    }

    else{
        if((n & 1) == 0 && (a[1] == ((n + 1) >> 1) || a[1] == ((n + 2) >> 1)))
            cout << 1 <<endl;
        else if((n & 1)&& a[1] == ((n + 1) >> 1))
            cout << 2 << endl;
        else cout << 0 << endl; 
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}