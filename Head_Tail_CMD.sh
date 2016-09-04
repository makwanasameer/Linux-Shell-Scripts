#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3


echo " 1. enter the head"
echo " 2. enter the tail"
read n
case "$n" in
1)      exec < $1
        i=1
        while [ $i -le $2 ]
        do
                read line
                echo $line
                i=`expr $i + 2`
        done;;
2)
        exec < $1
        i=`cat $1 | wc -l`
        j=$2
        k=`expr $i - $j`
	h=0
	while [ $h -lt $k ]
	do
		read line
		h=`expr $h + 1`
	done
	k=`expr $h + 1`     
   	while [ $k -lt $i ]
        do
                read line
                echo $line
                k=`expr $k + 1`
        done;;
esac

