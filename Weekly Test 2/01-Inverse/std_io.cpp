#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// ================= 代码实现开始 =================
vector<int> B;

long long merge(int l, int mid, int r){
    //cout << B[l] << B[mid] << B[mid+1] << B[r] << endl;
    // if(B[l] > B[mid]){
    //     swap(B[l], B[mid]);
    // }
    // if(B[mid+1] > B[r]){
    //     swap(B[mid+1],B[r]);
    // }
    int sum=0;
    int i = l;
    int j = mid+1;
    bool res = true;
    for(int i=l; i<=mid; i++){
        if(B[i] < B[i-l+mid+1]){
            res = false;
            break;
        }
    }
    //cout << res << endl; 
    if(res){
        for(int i=l; i<=mid; i++){
            //cout << i << B[i] << i+mid + 1 << B[i-l+mid+1] << endl;
            swap(B[i], B[i-l+mid+1]);
        }
    }
    while (i<=mid && j<=r){
        if(B[i] > B[j]){
            //temp[t++] = B[i++];
            sum+=(mid-i+1);
            j++;
        }else{
            i++;
        }
    }
    return sum;
    
    // cout << "after swap: " << endl;
    // cout << B[l] << B[mid] << B[mid+1] << B[r] << endl;
}

long long mergeSort(int l, int r){
    int count = 0, mid;
    if(l < r){
        mid = (l + r) >> 1;
        count += mergeSort(l, mid);
        count += mergeSort(mid+1, r);
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        count += merge(l, mid, r);
    }
    return count;
    
}

int merge_inversion(int left, int mid, int right){
    //int N = B.size();
    //int temp[N];
    int sum=0;
    int i = left;
    int j = mid+1;
    int t = 0;
    while (i<=mid && j<=right){
        if(B[i] > B[j]){
            //temp[t++] = B[i++];
            sum+=(mid-i+1);
            j++;
        }else{
            i++;
        }
        // }else {
        //     //temp[t++] = B[j++];
        //     //sum+=(mid-i+1);
        // }
    }
    // while(i<=mid){
    //     temp[t++] = B[i++];
    // }
    // while(j<=right){
    //     temp[t++] = B[j++];
    // }
    // t = 0;
    // //将temp中的元素全部拷贝到原数组中
    // while(left <= right){
    //     B[left++] = temp[t++];
    // }
    return sum;
}
int count_inversion(int l, int r){
    int count = 0, mid;
    if(l < r){
        mid = l + (r - l) / 2;
        count += count_inversion(l, mid);   
        count += count_inversion(mid + 1, r);    
        count_inversion(l,mid);
        count_inversion(mid+1,r);
        count += merge_inversion(l, mid, r);
    }
    return count;
}

// A：长度为n的数组，下标从0开始，为题中所给叶子序列
// 返回值：返回最少的逆序对个数
long long getAnswer(int n, vector<int> A) {
    /* 请在这里设计你的算法 */
    B = A;
    long long cnt = 0;
    int pos = 0;
    cnt = mergeSort(0, n-1);
    //cnt = count_inversion(0, n-1);
    return cnt;
}

// ================= 代码实现结束 =================

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0, x; i < n; ++i) {
        scanf("%d", &x);
        a.push_back(x);
    }
    cout << getAnswer(n, a) << '\n';
    return 0;
}
