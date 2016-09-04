#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3


echo enter 1 for addition
echo enter 2 for subtraction
echo enter 3 for multiplication
echo enter 4 for division

read no

echo enter the a
read a
echo enter the b
read b

if [ $no -eq 1 ]
then
        c=`echo scale=2 ";" $a + $b |bc`
        echo add is $c

elif [ $no -eq 2 ]
then
        d=`echo scale=2 ";" $a - $b |bc`
        echo sub is $d

elif [ $no -eq 3 ]
then
        e=`echo scale=2 ";" $a \* $b |bc`
        echo mul is $e

elif [ $no -eq 4 ]
then
        f=`echo scale=2 ";" $a / $b | bc`
        echo division is $f
fi

