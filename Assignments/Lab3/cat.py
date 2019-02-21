#!/usr/bin/python
import sys
if __name__=="__main__":
    f=open(sys.argv[1],'r')
    lines=f.readlines()
    print lines
    f.close()
