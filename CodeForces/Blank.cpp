#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// 在固定长度 len 的前提下回溯生成和为 rem 的序列，当前位置是 pos（0-index）
void dfs_fixed_len(int pos, int len, int rem) {
    if (pos == len) {
        if (rem == 0) {
            // 输出当前序列
            for (int i = 0; i < len; ++i) {
                if (i) cout << ' ';
                cout << a[i];
            }
            cout << '\n';
        }
        return;
    }
    // 剩余位置 count
    int remain_pos = len - pos;
    // 当前值至少为1，最大值为 rem - (remain_pos-1)*1
    int maxv = rem - (remain_pos - 1);
    for (int v = 1; v <= maxv; ++v) {
        a[pos] = v;
        dfs_fixed_len(pos + 1, len, rem - v);
    }
}

int main() {
    if (!(cin >> n)) return 0;
    a.assign(n, 0);
    // 按长度从1到n枚举
    for (int len = 1; len <= n; ++len) {
        dfs_fixed_len(0, len, n);
    }
    return 0;
}
