    /*https://codeforces.com/contest/2043/problem/B*/
    #include <bits/stdc++.h>
    #define int long long
    #define endl '\n'
    using namespace std;
    const int INF = 1e18;
    const int maxn = 1e9;

    signed main(){
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int t; cin >> t;
        while(t--){
            int n, d; cin>> n >> d;
            if (n <= 2) {
                int v = n == 1 ? d : d * 10 + d;
                for (int i = 1; i <= 9; i += 2) {
                    if (v % i == 0) cout << i << ' ';
                }
            }    
            else {
                cout << 1 << ' ' << 3 << ' ';
                if (d == 5) cout << 5 << ' ';
                cout << 7 << ' ';
                if (n >= 6 || d % 3 == 0) cout << 9;
            }
            cout << endl;
        }
        return 0;
    }
    /*
    写 d 这个数 n! 次 得到数字 ddddddddddd...d (n!个 d )
    求 1 3 5 7 9 哪些可以整除这个数字
    Input: 
    t cases
    n d
    Output: 
    1/3/5/7/9

    Idea: 
    1必有
    各个数位数字之和能被 3 整除 -> 能被3整除
    最后一位由 5 / 0 -> 能被 5 整除

    各个数位数字之和能被 9 整除 -> 能被 9 整除
    */