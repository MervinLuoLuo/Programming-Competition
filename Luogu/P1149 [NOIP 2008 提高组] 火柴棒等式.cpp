/*https://www.luogu.com.cn/problem/P1149*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n;
int ans = 0;
vector<int> num = {6,2,5,5,4,5,6,3,7,6};
vector<int> cur;

/*int add(int x){
    if(x < 10) return num[x];
    int sum = 0;
    while(x){
        sum += num[x % 10];
        x /= 10;
    }
    return sum;
}*/
void dfs(int pos,int cnt){
    if(cnt > n) return;
    if(pos > 3){
        if(cur[0] + cur[1] == cur[2] and cnt == n){
            ans++;
        }
        return;
    }

    for(int i = 0; i <= 1001; i++){
        cur.push_back(i);
        dfs(pos + 1, cnt + num[i]);
        cur.pop_back();
    }
}
void solve(){
    cin >> n;
    n -= 4;
    for(int i = 10; i <= 1001; i++){
        int count = num[i % 10] + num[i / 10];
        num.push_back(count);        
    }//记录查表
    dfs(1,0);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}