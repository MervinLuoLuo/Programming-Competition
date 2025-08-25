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

vector<int> p3;

void solve(){
    int n,k;cin >> n >> k;
    vector<int> tr;
    int minc = 0;
    while(n){
        tr.push_back(n % 3);
        minc += n % 3;
        n /= 3;
    }

    if(minc > k) {cout << -1 << endl;return;}
    
    //保证k前提下把大的拆成小的
    k -= minc;
    k /= 2;
    for(int i = tr.size() - 1; i >= 1; i--){
        if(tr[i] <= k){
            tr[i - 1] += 3 * tr[i];
            k -= tr[i];
            tr[i] = 0;
        }
        //拆不完就拆一部分
        else{
            tr[i - 1] += k * 3;
            tr[i] -= k;
            break;
        }
    }

    int ans = 0;
    for(int i = tr.size() - 1; i >= 0; i--){
        ans += p3[i] * tr[i];
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    int c = 3,cnt = 1;
    for(int i = 0; i < 21; i++){
        p3.push_back(c);
        c = 3 * c + cnt;
        cnt *= 3;
    }
    

    while(t--){
        solve();
    }
    return 0;
}