#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define ull unsigned long long
using namespace std;
const int INF = 1e17;
const int maxn = 1e7;

signed main(){
    int a;cin >> a;
    vector<int> n(a + 1);
    for(int i = 1; i <= a; i++){
        n[i] = i;
    }
    do{
        for(int i = 1; i <= a;i++){
            cout << "    " << n[i];
        }
        cout << endl;
    }while(next_permutation(n.begin() + 1, n.end()));
    return 0;
}