#!/bin/bash

for i in {1..10}
do
 dir="`pwd`/content/Week$i"
 target="`pwd`/Week$i" 
 cp `find $dir -type f` $target/.
done


