#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e17;
const int maxn = 1e9;

vector<int> cnt(1005, maxn);
int c[5]= {1, 3, 6 ,10 ,15};
void dp(){
    for(int i = 0; i < 5; i++){
        int num = c[i];
        cnt[num] = 1;
        for(int j = num + 1; j < 1000; j++){
            cnt[j] = min(cnt[j],cnt[j-num] + 1);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    dp();
    while(t--){
        int n;cin >> n;
        if(n < 1000){cout << cnt[n] << endl;continue;}
        int ans = (n-500) / 15;
        int res = 500 + (n - 500) % 15;
        ans += cnt[res];
        cout << ans << endl;
    }
    return 0;
}
/*
1 3 6 10 15 种硬币
求最小的硬币数使得总金额达到n
Input: 
t cases
n
Output: 
最小硬币总数
*/