#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3


echo "enter the 1st number"
read l
echo "enter the second number"
read m
echo "enter the third number"
read n


for i in $l $m $n
do
        for j in $l $m $n
        do
                if [ $j -eq $i ]
                then
                        continue

                fi
                for k in $l $m $n
                do
                        if [ $k -eq $i -o $k -eq $j ]
                        then
                                continue
                        fi

                        echo "$i $j $k"

                done
        done
done
~
