#!/usr/bin/python

"""
Output lines selected randomly from a file

Copyright 2005, 2007 Paul Eggert.
Copyright 2010 Darrell Benjamin Carbajal.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Please see <http://www.gnu.org/licenses/> for a copy of the license.

$Id: randline.py,v 1.4 2010/04/05 20:04:43 eggert Exp $
"""

import random, sys, string
from optparse import OptionParser

class randline:
    def __init__(self, filename,lo_hi,range,stdin_lines):
        #if input is a number range 
        if lo_hi:
            self.lines=range
        
        #if input is "-" or none, read from stdin
        elif filename =="no_file":
            self.lines=stdin_lines
            if(len(self.lines)<=0):
                return 0
        #Open file
        else:
            f = open(filename, 'r')
            self.lines = f.readlines()
            f.close()
    def chooseline(self):
        return random.choice(self.lines)
    def chooselineThenRemove(self):
        word=random.choice(self.lines)
        self.lines.remove(word)
        return word

def main():
    version_msg = "%prog 2.0"
    usage_msg = """%prog [OPTION]... FILE

Output randomly selected lines from FILE."""

    parser = OptionParser(version=version_msg,
                          usage=usage_msg)
    parser.add_option("-i","--input-range",action="store",default=False,help="treat each number LO through HI as an input line",dest="lo_hi")

    parser.add_option("-n","--head-count",action="store",dest="count",default=sys.maxsize,help="output at most COUNT number of lines")

    parser.add_option("-r","--repeat",action="store_true",default=False,dest="Repeat",help="output lines can be repeated")

    options, args = parser.parse_args(sys.argv[1:])
    # count
    try:
        count = int(options.count)
    except:
        parser.error("invalid count:'{0}'".
                     format(options.count))
    if count < 0:
        parser.error("invalid line count:'{0}'".
                     format(count))
 
# option is -i, analyze the number range
    if options.lo_hi:
        try:
            bounds=options.lo_hi.split("-")

            #Now low and high are of type str, so
            #We MUST cast them to int
            low=int(bounds[0])
            high=int(bounds[1])
        except:
            parser.error("Invalid input range '{0}'".format(options.lo_hi))
        if low>high:
            parser.error("Invalid input range '{0}'".format(options.lo_hi))
    stdin_lines=[]
    range=[]

    if options.lo_hi:
        input_file=""
        while low<=high:
            range.append(str(low)+'\n')
            low += 1
    if len(args)>1 and not options.lo_hi:
        parser.error("Wrong number of operands")
    
# Read from stdin when args is "-" or does not exist
    try:
        input_file=args[0]
    except:
        input_file="no_file"
    
    if input_file == "-":
        input_file="no_file"


#Count number of lines
#"count" stores number of iterations
#"iter" 
    if options.lo_hi:
        iter=len(range)
    elif input_file != "no_file":
        with open(input_file,'r') as f:
            for line in f:
                iter+=1  #python DOES NOT support i++

    else:
        stdin_lines=sys.stdin.readlines()
        for line in stdin_lines:
            iter+=1
    # if -n NOT selected, print at most as many lines as input
    if iter<count and not options.Repeat:
        count=iter

    try:
        generator = randline(input_file,options.lo_hi,range,stdin_lines)
        i=0
        if options.Repeat:
            while i<count:
                sys.stdout.write(generator.chooseline())
                i+=1
        else: 
            while i<count:
                sys.stdout.write(generator.chooselineThenRemove())
                i+=1
    
    except IOError as err:
        parser.error("I/O error({0}): {1}".
                 format(errno, strerror))

if __name__ == "__main__":
    main()
