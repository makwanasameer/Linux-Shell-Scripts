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





cmp $1 $2 > temp
i=0;
exec < temp
while read line
do
        i=`expr $i + 1`
done
if [ $i -eq 0 ]
then
        rm $2;
        echo "FIle $2 deleted";
fi
if [ $i -gt 0 ]
then
        echo " two files are not same";
fi
