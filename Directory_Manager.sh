#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3

echo " 1. show the current directory"
echo " 2. list all files"
echo " 3. list all files with attributes"
echo " 4. create the new directory"
echo " 5. delete the directorty"
echo " 6. change the directory"
echo " 7. rename the directory"
echo " ------------------------------------------------"
echo " enter your choice"
read ch
case "$ch" in
1) pwd ;;

2)      ls;;
3)      ls -l;;

4)
        echo "enter the name of the  directory which you want to create"
        read file1
        if [ -d "$file1" ]
        then
                echo "directory  already exists"
        else
        mkdir $file1
        fi;;
5)
        echo "enter the name of the directory which you want to delete"
        read file1
        if [ ! -d "$file1" ]
        then
                echo " directory does not exists"
        elif
                rm -r $file1 >> /dev/null
        then
                echo "directory successfully deleted"
        fi;;

6)
        cd ..
        echo "moved to parent directory"
        pwd;;

7)      echo "enter the name of directory which you want to rename"
    	read file1
        echo "enter the new file name"
        read new1
        mv $file1 $new1;;

*)      echo "invalid option"



esac
