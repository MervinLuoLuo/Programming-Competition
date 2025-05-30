#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

vector<int> prime ={2,3,5,7,11,13,17,19,23,27,31,37,41,43,47};
struct N{
    int val;
    int cnt = 1;
};
vector<N> a;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    a.resize(n + 5);
    for(int i = 0; i < n; i++){
        cin >> a[i].val;
    }
    for(int i = 0; i < n; i++){
        for(auto p : prime){
            while(a[i].val > 0 and a[i].val % p == 0){
                a[i].val /= p;
                a[i].cnt++;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i].cnt;
    }
    if(sum % 2) cout << "Nailong" << endl;
    else cout << "Belia" << endl;
    return 0;
}