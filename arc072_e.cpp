#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 5e5 + 10;
int n, D, q, d[N], x[N], r[N];
 
int f(int x, int d) {
	return x > d ? (x - d) : (d - x < x ? d - x : x);
}
 
int main() {
	scanf("%d%d",&n,&D);
	rep(i,1,n) scanf("%d", d + i);
	
	x[0] = D;
	rep(i,1,n) x[i] = f(x[i - 1], d[i]);
 
	r[n + 1] = 0;
	dep(i,n,1) {
		r[i] = r[i + 1];
		if (r[i] >= d[i] / 2) r[i] += d[i];
	}
 
	scanf("%d",&q);
	rep(t,1,q) {
		int i; scanf("%d",&i);
		if (x[i - 1] <= r[i + 1]) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}