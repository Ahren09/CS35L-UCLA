#!/usr/bin/python
a=[1,2,3,4,5]
if __name__ == "__main__":
	print a[0] #output 1
	print a[1] #output 2
	a[1] = 5   #a = [1, 5, 3, 4, 5]
	print a[1] #output 5
	print a # output [1, 5, 3, 4, 5]

	b = [4, 5, 6]
	i,j,k = b # i = 4, j = 5, k = 6
	print "i = " + str(i)
	print "j = " + str(j)
	print "k = " + str(k)

	c = [1, 3, 5, 2, 4]
	c.sort()
	print c #1, 2, 3, 4, 5
	
	for i in c:
		print i #print 1,2,3,4,5
