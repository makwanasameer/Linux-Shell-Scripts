#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3

echo enter the no
read no
t1=0
t2=1
t3=0
count=0
while [ $count -lt $no ]
do
        t3=`expr $t2 + $t1`
        echo $t3
        t1=$t2
        t2=$t3
        count=`expr $count + 1`
done
