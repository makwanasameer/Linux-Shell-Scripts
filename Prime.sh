#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3


echo "enter first number"
read no1
echo "enter the second number"
read no2
i=`expr $no2 - $no1`
temp=$no1
while [ $i -gt 0 ]
do
        count=0
        l=1
        g=0

        while [ $l -le $temp ]
        do
                g=`expr $temp % $l`

                if [ $g -eq 0 ]
                then
                        count=`expr $count + 1`
                fi
                l=`expr $l + 1`
   done

        if [ $count -eq 2 ]
        then
                echo "no ==  $temp"
        fi

        temp=`expr $temp + 1`
        i=`expr $i - 1`
done
                           