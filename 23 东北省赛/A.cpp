#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int INF = 1e17;
const int maxn = 1e7;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x, k;cin >> x >> k;
    if (x == 1) {cout << 1;return 0;}
    int ans = k + 1;
    int root = x;
    for(int i = 1; i <= k; i++){
        x = root;
        root = sqrt(root);
        if(root * root == x){ans++;continue;}
        else{
            if(root != 1) ans += k - i + 1;
            else ans++;
        }
        if(root == 1)break;
    }
    cout << ans;
    return 0;
}
/*
x开始 往后如果root * root < x 则向下取整了
取整的数加上自己还能有 k - i + 1次变换
x == 1 的时候只会有一次变换

*/