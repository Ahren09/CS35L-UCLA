#!/usr/bin/python
def factor(n):  	
	print 'n =', n
	if n > 1:
		return n * factor(n-1)
	else:	
		print 'end of the function'
		return 1

def foo(n):
	for i in range(1, n):
		print "Hello from factor2 with iteration " + str(i)

if __name__ == "__main__":
	print factor(5)
	foo(5)	
