#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
const int N = 110;
int n, a[N], mx = 0, cnt[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a + i);
	rep(i,1,n) mx = max(mx, a[i]);
	if (mx >= n) { printf("Impossible\n"); return 0; }
	else {
		rep(i,1,n) {
			if (a[i] < (mx + 1) / 2) { printf("Impossible\n"); return 0; }
			cnt[a[i]]++;
		}
		rep(i,mx / 2 + 1,mx) if (cnt[i] <= 1) { printf("Impossible\n"); return 0; }
		if (mx % 2 == 0) {
			if (cnt[mx / 2] > 1) { printf("Impossible\n"); return 0; }
		} else {
			if (cnt[(mx + 1) / 2] > 2) { printf("Impossible\n"); return 0; }
		}
	}
	printf("Possible\n"); 
	return 0;
}
