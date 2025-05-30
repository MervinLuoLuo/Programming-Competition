#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;cin >> n >> m;
    vector<int> a(n + 5), t(n +5);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        t[i] = i;
    }
    cout << 0 << endl;
    deque<int> q;
    for(int i = 1; i < n; i++){
        int j;
        while(!q.empty()){
            j = q.back();
            if(t[j] < i + 1 - m) q.pop_back();
            else if(a[i] < a[j]) q.pop_back();
            else {
                q.push_back(i);
                break;
            }
        }
        while(!q.empty() and t[q.front()] < i + 1 - m) q.pop_front();
        if(q.empty()){
            q.push_back(i);
            cout << a[i] << endl;
        }
        else cout << a[q.front()] << endl;
    }
    return 0;
}
    /*int n, m;cin >> n >> m;
    vector<int> a(n + 5), q(n + 5);
    for(int i  = 1; i <=n; i++) cin >> a[i];
    int l = 1, r = 0;
    for(int i  = 1; i <= n; i++){
        cout << a[q[l]] << endl;
        if(i - q[l] + 1 > m and l <= r) l++;
        while(a[i] < a[q[r]] and l <= r) r--;
        q[++r] = i;
    }
    */