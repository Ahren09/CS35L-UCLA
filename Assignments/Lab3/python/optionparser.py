#!/usr/local/cs/bin/python
from optparse import OptionParser
import sys

if __name__ == "__main__":
	parser = OptionParser()

	parser.add_option("-f", "--fields", action="store", dest="fields")
	
	parser.add_option("-d", action="store", dest="delim")
	
	parser.add_option("-n", action="store_true", dest="nosplit")
	#option is the result after parsing 
	#args is the remaining command line arguments	
        options, args = parser.parse_args(sys.argv)
        print "options:"
	print options
	print "args:"
	print args
	
	#arg after -f
	print "options.fields"
	print options.fields
	#arg after -d
	print "options.delim"
	print options.delim
	#arg -n
	print "options.nosplit"
	print options.delim
	print options.nosplit

