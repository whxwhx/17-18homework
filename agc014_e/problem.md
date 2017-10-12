###Problem Statement

有一个$N$个节点的树，节点从$1$到$n$标号，$N-1$条边中的第$i$条边连接节点$a_i$和$b_i$。

开始的时候所有的边都是蓝色，Takahashi会通过$n - 1$步操作把这个蓝色的树变成红色。

每次操作包含以下步骤：

1.选择一个只包含蓝色的简单路径，然后移除上面的一条边。

2.在选出的蓝色简单路径的两个端点之间加一条红边。

他想把树变恰好变成一棵每条边连接$c_i$, $d_i$的红色的树。

请问他能否达成他的目标？

###Constraints

$2 \leq N \leq 10^5$

$1 \leq a_i, b_i, c_i, d_i \leq N$

$a_i \not= b_i$

$c_i \not= d_i$

保证输入的两个图都是树。

###Input

以以下格式从标准输入读入

<pre>
N
a_1  b_1
.
.
a_{N - 1} b_{N - 1}
c_1 d_1
.
.
c_{N - 1} d_{N - 1}
</pre>

###Output

如果可以达成，输出'YES'，否则输出'NO'。

###Sample Input 1

<pre>
3
1 2
2 3
1 3
3 2
</pre>

###Sample Output 1

<pre>
YES
</pre>

目标可以达成，至少：
1.选择连接节点$1$和$3$的路径，然后移除蓝边$1-2$，加入红边$1-3$。
2.选择连接节点$2$和$3$的路径，然后移除蓝边$2-3$，加入红边$2-3$

###Sample Input 2

<pre>
5
1 2
2 3
3 4
4 5
3 4
2 4
1 4
1 5
</pre>

###Sample Output 2

<pre>
YES
</pre>

###Sample Input 3

<pre>
6
1 2
3 5
4 6
1 6
5 1
5 3
1 4
2 6
4 3
5 6
</pre>

##Sample Output 3

<pre>
NO
</pre>