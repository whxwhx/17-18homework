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
int n;
const int N = 1e5 + 10;
int a[N];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a; 
}
bool check() {
	int s = n&1;
	rep(i,1,n) s ^= a[i]&1;
	if (s) return true;
	int cnt = 0, t = 0;
	rep(i,1,n) if ((a[i]&1) && a[i] > 1) cnt++, t = i;
	if (cnt == 1) {
		a[t]--; int g = a[1];
		rep(i,2,n) g = gcd(g, a[i]);
		rep(i,1,n) a[i] /= g;
		return !check();
	}
	return false;
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	printf(check() ? "First\n" : "Second\n");
	return 0;
}