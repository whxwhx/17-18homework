from random import randint as rd
import os
for t in xrange(1, 30 + 1):
	f = open(str(t) + ".in", 'w')
	n = 10 ** 5
	w = 10 ** 9
	f.write(str(n) + '\n')
	for i in xrange(n):
		f.write(str(rd(-w, w)) + ' ')
	f.write('\n')
	m = 10 ** 5
	k = rd(1, 10 ** 18)
	f.write(str(m) + ' ' + str(k) + '\n')
	for i in xrange(m):
		f.write(str(rd(2, n - 1)) + ' ')
	f.write('\n')
	f.close()
	os.system('../whx < ' + str(t) + '.in>' + str(t) + '.out')
