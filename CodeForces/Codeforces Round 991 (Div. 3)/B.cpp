#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        if(n == 1){cout << "Yes" << endl;continue;}
        vector<int> a(n + 5);
        int sum1 = 0,sum2 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i & 1){sum1 += a[i];cnt1++;}
            else {sum2 += a[i];cnt2++;}
        }
        if(sum1 % cnt1 or sum2 % cnt2 or sum1 / cnt1 != sum2 / cnt2) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
/*
长度为 n 的数组
找一个 i 操作:
a[i-1] - 1 然后 a[i + 1] + 1
或者 a[i - 1] + 1 然后 a[i + 1] - 1
每次操作后 所有值都得为非负
问最后能否使所有元素相等
Input: 
t cases
n
a[0] ~ a[n - 1]
2*1e5
Output: 
Yes or No
*/