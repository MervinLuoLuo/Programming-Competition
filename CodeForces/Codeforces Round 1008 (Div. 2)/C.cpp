/*https://codeforces.com/contest/2078/problem/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    map<int,int> cnt;//表存是否出现
    vector<int> b(2 * n + 5);
    for(int i = 1; i <= 2 * n; i++){
        cin >> b[i];
        cnt[b[i]]++;
    }
    sort(b.begin() + 1,b.begin() + (2 * n + 1));//排序
    int sum = 0;
    for(int i = 1; i <= n; i++) sum -= b[i];
    for(int i = n + 1; i <= n * 2; i++) sum += b[i];
    cout << sum << " ";//先单走一个sum,因为如果sum出现在b中就得换策略
    if(!cnt[sum]){
        for(int i = 1; i <= n; i++) cout << b[i + n] << " " << b[i] << " ";//这里我们得输出间隔式的
        cout << endl;
    }
    else {//当sum在b中时
        vector<int> c;
        int res = 0;//记录
        for(int i = 1; i <= n * 2; i++) if(b[i] != sum) c.push_back(b[i]);//把不是sum的都放到一起
        for(int i = 0; i < 2 * n - 2; i+= 2){//两个两个操作得+=2
            res += c[i + 1] - c[i];//让大的减小的,保证结果都是正数
            cout << c[i + 1] << " " << c[i] << " ";
        }
        cout << c[2 * n -2] + sum - res << " " << c[2 * n - 2] << endl;//用最后两个数字补差价
    }

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}