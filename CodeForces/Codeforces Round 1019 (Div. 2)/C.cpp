/*https://codeforces.com/contest/2103/problem/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool check(vector<int> &a,int n, int k){
    //前缀和 + 最大前缀和(如果用后缀和写就是后缀和 + 最小后缀和)
    vector<int> prefix(n + 5), maxpre(n + 5);
    prefix[1] = maxpre[1] = a[1];
    for(int i = 2; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }

    maxpre[n + 1] = INT_MIN;
    for(int i = n; i >= 1; i--){
        maxpre[i] = max(maxpre[i + 1],prefix[i]);
    }

    for(int i = 1; i <= n - 2; i++){
        if(prefix[i] < 0) continue;
        if(maxpre[i + 1] - prefix[i] >= 0) return true;
    }
    return false;
}

void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n + 5);
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        if(x > k) a[i] = -1;
        else a[i] = 1;
    }

    //T F T情况
    int posl = n + 1, posr = -1;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        if(sum >= 0){posl = i;break;}
    }
    sum = 0;
    for(int i = n; i >= 1; i--){
        sum += a[i];
        if(sum >= 0){posr = i;break;}
    }
    if(posl + 1 < posr){yes;return;}

    //T T F情况
    if(check(a,n,k)){yes;return;}

    //F T T情况
    //因为与T T F情况对称,我们转置一下数组又可以接着用函数
    for(int i = 1; i <= n - i + 1; i++) swap(a[i],a[n - i + 1]);
    if(check(a,n,k)){yes;return;}

    //都不成立就 no
    no;
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