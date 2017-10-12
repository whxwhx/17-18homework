##100分做法

###operation on itself

群$G$到置换的同态，最自然的就是他的 permutational representation 了。

考虑$G$ operate 自己的 permutational representation ，首先它的大小肯定要等于$n=|G|$,把它operate到集合${1...n}$上之后。它还是 transitive 的。

Lemma 1.1：任何一个$G$到$S_{|G|}$的大小为$|G|$的同态$\phi$，如果它在集合${1...|G|}$上transitive，那么它一定对应了一个$G$的标号方式，也就对应了一个permutation representation。

由于transitive的性质，所以$p[1]$一定两两不同。对于$p[1]=x$的置换$p$，我们给它标号为$x$。

考虑定义$({1...|G|}, \times), i \times j = p_i[j]$

可以验证它构成了一个群，封闭性$p_ip_j[1] = p_i[j]$，结合律由置换复合的结合律得到，幺元即为单位置换，逆元由置换群的逆得到。

我们定义在$\phi : g \rightarrow p_i$基础上，定义$\phi ' : g \rightarrow i$的映射，容易验证这是一个同构。

证完。

Proposition 1.2: $G$到$S_{|G|}$，transmitive的同态有$(|G| - 1)!$种。

在$(1.1)$中，不选择$g \rightarrow p[1]$转而选择$g \rightarrow p[x]$同样可以得到一个对$G$的标号方式，并且一个标号方式显然只对应了一个同态，又因为它是置换群，不同的$p[x]$一定对应了不同的标号。所以每种同态恰好对应了$|G|$种标号。

同时因为它transmitive的性质，所以不同的$g$对应的一定是不同置换，从而一定是一个单同态。

所以一共有$(|G| - 1)!$种同态。

###operation on coset

接下来让$G$ operate 他的一个子群$H$对应的 cosets的集合$T$，通过上面的讨论，我们已经知道了要点在于对于任意的permutational represention找出一个标号方式，证明这个标号方式和这个representation一致。同时我们往往直接随意定一个对应右乘的单位元即可，(1.2)中说明了无论定哪一个都是合法的。

$G$在$T$上的operation提供了它到$S_{|G|/|H|}$的同态，$imG$对${1...|G|/|H|}$的operation也是transitive的。

Lemma 1.3: $G$在$T$上每个transitive的同态都对应了一个$T$的标号方式，也就对应了一个permutational representation。

考虑我们先给$H$标号为$1$，那么$Stab 1$就是$H$了。

接下来我们想要找出$aH$，其实就是$\phi(a)[1]$。考虑$a = bh$的时候$\phi(a)[1] = \phi(bh)[1] = \phi(b)[\phi(h)[1]] = \phi(b)[1]$，所以每个coset一定有唯一的标号，又因为transitive，所以每个coset之间标号一定不同。

接下来考虑$\phi(a)$是否会把$bH$变成$abH$了，事实上这直接由$\phi(ab)[1] = \phi(a)[\phi(b)[1]]$得到($\phi(b)[1]$即为$bH$的标号)。

证完。

Proposition 1.4: $G$在$T$上transmitive的同态一共有$count(H) * (|G|/|H| - 1)!$个。

因为(1.3)里我们构造的时候直接给$H$编号为$1$，而每个同态只对应一个这样的编号，同时每个同态+标号又唯一对应了一个$H$。

###homomorphism to arbitrary S_n

接下来我们考虑对于任意的$n$，$G$到$S_n$的同态。首先我们还是把它operate到${1...n}$的集合上。

此时$imG$在1的Orbit上是transitive的，取$r = |Orbit_1|$之后，考虑把置换中这$r$个位置拿出来得到一个$G$到$S_r$的同态。

直接选择Orbit，得到dp表达式$h_n = \sum_{k=1}^n C(n - 1, k - 1) h_{n - k} + count(H, |H| = k) * (|G|/k-1)!$

这里算出来的同态不一定是单同态（kernel不一定为${1}$），中间$G$在有的$T$上的operation是faithful的（从而是单同态），有的可能不是。

为了把它容斥成单同态，我们枚举他的kernel，也就是枚举$G$的每个normal subgroup $N$，然后对$G/N$再算同态的个数，做一个容斥。

###Time Complexity

$h_n$的递推式计算可以$O(n^2)$暴力，但是我们还要搜索$G$的所有子群和正规子群。

考虑我们每次求出一个封闭的集合$A$之后，再加入一个元素$b \not\in A$。那么$bA \join A = \emptyset, |bA| = |A|$。从而我们的结合每次会扩大至少两倍。

这道题中$m \leq 30$，从而搜索子群和正规子群的复杂度远小于$O(m^{\log m}) \leq 24300000$。