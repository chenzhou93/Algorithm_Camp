#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// ================= 代码实现开始 =================

// n：节点数目
// m：边数目
// k：医院数目
// A：医院数组，大小为 k
// U, V, W：分别存放各边的两端点、长度，大小为 m
// 返回值：一个数组，依次表示每个点到最近医院的最短距离
vector<int> get_answer(int n, int m, int k, vector<int> A, vector<int> U, vector<int> V, vector<int> W) {
    return vector<int>();
}

// ================= 代码实现结束 =================

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> A, U, V, W;
    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        A.push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        U.push_back(u);
        V.push_back(v);
        W.push_back(w);
    }

    vector<int> ans = get_answer(n, m, k, A, U, V, W);
    for (int i = 0; i < int(ans.size()); ++i)
        printf("%d\n", ans[i]);
    return 0;
}
