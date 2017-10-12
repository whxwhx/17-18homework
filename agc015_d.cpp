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
int main() {
	LL a, b; cin >>a>>b;
	dep(i,60,0) if ((a >> i & 1) != (b >> i & 1)) {
		LL t1 = a & ((1LL << i) - 1), t2 = b & ((1LL << i) - 1);
		if (t2 >= t1) { cout <<(b | ((1LL << i) - 1)) - a + 1<<endl; }
		else {
			LL ans = b - a + 1, t = t2;
			dep(j,i-1,0) if (t2 >> j & 1) {
				t |= (1LL << j) - 1; break;
			}
			ans += (min(t, t1 - 1) - t2) + (1LL << i) - t1;
			cout <<ans<<endl;
		}
		return 0;
	}
	cout <<1<<endl;
	return 0;
}