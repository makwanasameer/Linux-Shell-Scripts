#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3


echo "enter the number n upto which you want addition"
read n
i=0
sum=0
temp=0
while [ $n -gt 0 ]
do
        temp=`expr $n % 10`
        sum=`expr $sum + $temp`
        n=`expr $n / 10`
done
echo "The sum of given number is $sum"

