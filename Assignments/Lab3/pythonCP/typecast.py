#!/usr/bin/python 
if __name__ == "__main__":
	a = "123"
#	b = a + 45 #This will fail as 
		   #string cannot add with integer

	b = int(a) + 45 #b = 168
	d = str(b) + " is the output" #168 is the output
	print b
	print d
