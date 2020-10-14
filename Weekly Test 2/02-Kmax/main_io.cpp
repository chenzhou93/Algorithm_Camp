#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>

template<typename T>
inline void swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

// ================= 代码实现开始 ===================
// 在地址 [l,r) 范围内寻找 k 小值
template <typename T>
T find(T* l, T* r, int k){
    int n = r-l;
    if(n == 1){
        return *l;
    }
    bool a = 0;
    swap(*(r-1), *(l+rand()%n));

    T val = *(r-1), *pos = l;

    for(T *i = l; i<r-1; i++){
        if(*i < val){
			swap(*(pos+1), *i);
			*pos++;
        }else if(*i == val){
            a ^= 1;
            if(a){

            }
        }
    }

    swap(*pos, *(r-1));
    int cur = pos - l + 1;

    if(cur == k){

    }

    if(cur < k){

    }

    return ;


}

//	============= 代码实现结束 ==============

#define maxn 30000000

int a[maxn + 10];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int p, q, M;
	scanf("%d%d%d%d", a, &p, &q, &M);

	for (int i = 1; i < n; i++)
		a[i] = ((long long)p * a[i - 1] + q) % M;

	printf("%d\n", find(a, a + n, k));
	return 0;
}