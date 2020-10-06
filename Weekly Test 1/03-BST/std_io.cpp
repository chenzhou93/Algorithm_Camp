#include <iostream>
#include <vector>
using namespace std;

// 二叉树的节点，包含左右孩子的编号（在数组中的下标），编号范围为 0 到 n-1，若编号为 -1，表示空
struct Node {
    int l; // 表示左节点的编号
    int r; // 表示右节点的编号
};

// ================= 代码实现开始 =================

vector<Node> treeA;
vector<Node> treeB;

// n：二叉树节点个数
// a：二叉树 a 的节点数组，大小为 n
// b：二叉树 b 的节点数组，大小为 n
// 返回值：若二叉树 a 与 b 相等，则返回真，否则返回假
// 提示：
// 解释一下节点数组的意思，由于节点的编号在 0 到 n-1 的范围内
// 因此可以将这 n 个节点存储到一个数组里，那么二叉树 a 中编号
// 为 i 的节点就是 a[i]，其左孩子编号为 a[i].l，右孩子编号为 a[i].r
// a[i] 的左孩子为 a[a[i].l]，右孩子为 a[a[i].r]
// 一定要把编号与节点区分开来，同时还要注意编号为 -1 的情况，此时该孩子
// 为空，不能用 -1 去作为数组下标噢，越界了。

bool isSameTree(Node a, Node b){
    bool res = false;
    if((a.l == -1 && b.l != -1) || ((a.r != -1 && b.r == -1))){
        res = false;
    }else if((a.l == -1 && b.l == -1) || ((a.r == -1 && b.r == -1))){
        res = true;
    }else{
        res = isSameTree(treeA[a.l], treeB[b.l]) && isSameTree(treeA[a.r], treeB[b.r]);
    }
    return res;
}

bool get_answer(int n, vector<Node> a, vector<Node> b) {
    treeA = a;
    treeB = b;
    return isSameTree(treeA[0], treeB[0]);
}

// ================= 代码实现结束 =================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        vector<Node> a, b;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            a.push_back((Node){l, r});
        }
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            b.push_back((Node){l, r});
        }

        cout << (get_answer(n, a, b) ? "yes" : "no") << '\n';
    }

    return 0;
}