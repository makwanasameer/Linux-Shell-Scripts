#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3

rev $1 > file_1;
tac file_1 > $1;
cat $1;
rm -r file_1;
~
~
