//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

void merge(int left, int mid, int right, vector<int>& a){
    vector<int> tmp;
    for(int i=left; i<=right; i++){
        tmp.push_back(a[i]);
    }

    for(int i=left, j=mid+1, k=left; k<=right; k++){
        if(i > mid){
            a[k] = tmp[j-left];
            j++;
        }else if(j > right){
            a[k] = tmp[i-left];
            i++;
        }else if(tmp[i-left] < tmp[j-left]){
            a[k] = tmp[i-left];
            i++;
        }else{
            a[k] = tmp[j-left];
            j++;
        }
    }
}

void myMergeSort(int left, int right, vector<int>& arr){
    if(left >= right){
        return;
    }
    int mid = left + ((right-left)/2);
    myMergeSort(left, mid, arr);
    myMergeSort(mid, right, arr);
    merge(left, mid, right, arr);
}

// 将给定数组a升序排序
// n：数组大小
// a：所给数组，大小为n
// 返回值：排序后的数组
vector<int> getAnswer(int n, vector<int> a) {
    /* 请在这里设计你的算法 */
    vector<int> arr;
    for(int i=0; i<n; i++){
        arr.push_back(a[i]);
    }
    myMergeSort(0, n-1, arr);
    return arr;
}

// ================= 代码实现结束 =================

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    a = getAnswer(n, a);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
    return 0;
}
