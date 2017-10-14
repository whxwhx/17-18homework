#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
const int N = 1e5 + 10;
int n, m, a[N];
int main() {	
	scanf("%d%d",&n,&m); int cnt = 0;
	rep(i,1,m) {
		scanf("%d",a + i);
		if (a[i] & 1) { cnt++; swap(a[1], a[i]); }
	}
	rep(i,2,m - 1) if (a[i] & 1) swap(a[i], a[m]);
	if (m == 2) {
		rep(i,1,m) printf("%d ",a[i]); printf("\n");
		printf("%d\n",(a[1] == 1) ? m - 1 : m);
		if (a[1] - 1) printf("%d ",a[1] - 1);
		rep(i,2,m) printf("%d ",(i < m) ? a[i] : a[i] + 1); printf("\n");
	} else if (cnt > 2) printf("Impossible\n");
	else if (m == 1) {
		rep(i,1,m) printf("%d ",a[i]); printf("\n");
		if (a[1] == 1) printf("1\n1\n");
		else printf("2\n%d %d\n",a[1] - 1, 1);
	} else {
		rep(i,1,m) printf("%d ",a[i]); printf("\n");
		printf("%d\n",(a[1] == 1) ? m - 1 : m);
		if (a[1] - 1) printf("%d ",a[1] - 1);
		rep(i,2,m) printf("%d ",(i < m) ? a[i] : a[i] + 1); printf("\n");
	}
	return 0;
}
