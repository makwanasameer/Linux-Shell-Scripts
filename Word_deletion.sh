#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3


echo "enter the word:"
read word
grep -v "$word" $1 > reg_1;
echo "     ";
echo "     ";
cp reg_1 $1;
cat $1;