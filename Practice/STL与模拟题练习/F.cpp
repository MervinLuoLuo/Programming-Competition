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
    int n,r;
    while(cin >> n >> r){
        bool neg = (n < 0);
        n = abs(n);
        if(n < r) {
            if(n < 10) cout << n << endl;
            else{
                char a = n - 10 + 'A';
                cout << a << endl;
            }
            continue;
        }
        deque<int> dq;
        while(n){
            dq.push_front((n % r));
            n /= r;
        }
        if(neg) cout << '-';
        while(!dq.empty()){
            if(dq.front() >= 10){
                int dis = dq.front() - 10;
                char a = 'A' + dis;
                cout << a;
            }
            else {cout << dq.front();}
            dq.pop_front();
        }
        cout << endl;
    }
    return 0;
}