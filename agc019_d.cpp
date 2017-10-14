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
const int N = 2010;
int n;
char a[N], b[N], c[N];
int main() {
	scanf("%s", a); n = strlen(a);
	scanf("%s", b);

	bool a0 = true, b0 = true;
	Rep(i,n) { a0 = a0 && a[i] == '0'; b0 = b0 && b[i] == '0'; }

	if (a0 && b0) { printf("0\n"); return 0; }
	else if (b0) { printf("-1\n"); return 0; }

	int mn = 3 * n;

	static int pre[N], nxt[N];
	Rep(j,n) if (!j) {
		pre[j] = 0;
		while (b[pre[j]] != '1') pre[j] = (pre[j] - 1 + n) % n;
	} else pre[j] = b[j] == '1' ? j : pre[j - 1];
	dep(j,n - 1,0) if (j == n - 1) {
		nxt[j] = n - 1;
		while (b[nxt[j]] != '1') nxt[j] = (nxt[j] + 1) % n;
	} else nxt[j] = b[j] == '1' ? j : nxt[j + 1];

	Rep(i,n) {
		memcpy(c, b, n * sizeof(b[0]));
		rotate(c, c + (n - i) % n, c + n);
		int ans = 0;
		Rep(j,n) if (c[j] != a[j]) ans++;

		//0->i
		int tot1 = i;	
		static int mx[N]; memset(mx, 0, sizeof(mx));
		Rep(j,n) if (c[j] != a[j]) {
			int r = (j - pre[j] + n) % n, l = (j - nxt[j] + n) % n;
			if (l > i && r > i) mx[n - l - 1] = max(mx[n - l - 1], r - i);
		}
		dep(i,n - 2,0) mx[i] = max(mx[i], mx[i + 1]);
		int mnshift = 2 * n;
		Rep(i,n) mnshift = min(mnshift, mx[i] + i);
		tot1 += 2 * mnshift;

		//0->n - 1->i
		int tot2 = n - i;
		memset(mx, 0, sizeof(mx));
		Rep(j,n) if (c[j] != a[j]) {
			int r = (j - pre[j] + n) % n, l = (j - nxt[j] + n) % n;
			if (l < i && r < i && l > 0 && r > 0) mx[r - 1] = max(mx[r - 1], i - l);
		}
		dep(i,n - 2,0) mx[i] = max(mx[i], mx[i + 1]);
		mnshift = 2 * n;
		Rep(i,n) mnshift = min(mnshift, mx[i] + i);
		tot2 += 2 * mnshift;

		//hole circle
		ans += min(tot1, tot2);
		mn = min(mn, ans);
	}
	printf("%d\n",mn);
	return 0;
}
