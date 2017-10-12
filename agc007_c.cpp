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
int n, d1, x;
int main() {
	int n, d1, x; scanf("%d%d%d",&n,&d1,&x);
	double ans = 0; double D1 = d1, d = x;
	rep(i,1,n) {
		int c = 2 * (n - i + 1);
		ans += (D1 * 2 + d * (c - 1)) / 2;
		D1 = D1 * (c - 2) / c + (D1 * 4 + d * 5) / c;
		d *= (1 + double(2.0) / (n - i + 1));
	}
	printf("%.15lf\n",ans);
	return 0;
}