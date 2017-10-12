#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 1000010;
char S[N], T[N];
int pre[N], d[N], q[N], l, r;
int main() {
	int n; scanf("%d",&n);
	scanf("%s",S + 1); scanf("%s",T + 1);
	bool flag = true; rep(i,1,n) if (S[i] != T[i]) flag = false; if (flag) { printf("0\n"); return 0; }
	int mn = n;
	dep(i,n,1) {
		mn = min(mn, i);
		while (mn > 0 && S[mn] != T[i]) mn--;
		if (!mn) { printf("-1\n"); return 0; } 
		pre[i] = mn;
	}
	int ans = 1;
	dep(i,n,1) if (pre[i] > pre[i - 1]) {
		while (l < r && q[l] - (r - l) >= i) l++;
		q[r++] = pre[i];
		if (pre[i] < i) ans = max(ans, r - l + 1); 	
	}
	cout <<ans<<endl;
	return 0;
}