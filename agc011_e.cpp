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
const int N = 500010;
char s[N];
int n, a[N];
bool check(int mx) {
	int l = n;
	rep(i,1,l) a[i] = s[i] - '0', a[i] *= 9;
	a[1] += 9 * mx;
	int j = 0;
	rep(i,1,l) a[i] = a[i] + j, j = a[i] / 10, a[i] %= 10;
	while (j) a[++l] = j % 10, j /= 10;
 
	int s = 0;
	rep(i,1,l) s += a[i];
	return s <= 9 * mx;
}
 
int main() {
	scanf("%s",s + 1); n = strlen(s + 1);
	int l = 0, r = n;
	reverse(s + 1, s + n + 1);
	while (l + 1 < r) {
		int mid = (l + r) >> 1; 
		if (check(mid)) r = mid; else l = mid;
	}
	cout <<r<<endl;
	return 0;
}