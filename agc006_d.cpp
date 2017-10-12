#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < (a); i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)//(a)!
#define dep(i,a,b) for(int i = (a); i >= (b); i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 100100;
int a[N * 2], n, b[N * 2];
 
bool check(int m) {
	rep(i,1,2 * n - 1) a[i] = (b[i] >= m);
	dep(i,n - 1,1) if (a[i] == a[i + 1] || a[2 * n - i - 1] == a[2 * n - i]){
		if (a[i] == a[i + 1]) return a[i];
		if (a[2 * n - i - 1] == a[2 * n - i]) return a[2 * n - i];
	}
	return a[1];
}
 
int main() {
	scanf("%d",&n);
	rep(i,1,2 * n - 1) scanf("%d",&b[i]);
	int l = 1, r = 2 * n;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid; else r = mid;
	}
	printf("%d\n",l);
	return 0;
}