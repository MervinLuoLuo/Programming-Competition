#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int a[25][25],b[25][25];

signed main(){
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int n,m,x,y;
   cin >> n >> m >> x >> y;
   n++;m++;x++;y++;
   b[x][y] = 1;
   b[x - 1][y + 2] = 1;
   b[x - 2][y + 1] = 1;
   b[x - 2][y - 1] = 1;
   b[x - 1][y - 2] = 1;
   b[x + 1][y + 2] = 1;
   b[x + 2][y + 1] = 1;
   b[x + 2][y - 1] = 1;
   b[x + 1][y - 2] = 1;
   a[1][1] = 1;
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
         if(i == 1 and j == 1)continue;
         if(b[i][j] == 0) a[i][j] = a[i - 1][j] + a[i][j -1];
      }
   }
   cout << a[n][m] << endl;
   return 0;
}