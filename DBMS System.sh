#!/bin/bash
#Roll no:09bce026
#Author: Sameer Makwana
#Licence: GPLv3

echo " The database management system is "
echo " 1. For inserting data into the file "
echo " 2. For searching the data from the file "
echo " 3. For sorting the data "
echo " 4. To deleting the data from the file "
echo " 5. To modify the data of the file "
echo " 6. To create a view of the given in the file "
echo " Enter your choice : "
read choice
case $choice in
          1)echo " Enter the data you want to enter in the file "
          echo " Enter the roll no "
          read rno
          similar=`grep -c "$rno" dbms`
          if [ $similar -eq 1 ]
          then
          echo " The entered roll no. violates the primary key constraint on roll no "
          while [ $similar -eq 1 ]
          do
                echo " Enter the roll no "
                read rno
                similar=`grep -c "$rno" dbms`
          done
          fi
          echo " Enter the name "
          read name
          echo " Enter the branch "
          read branch
          echo " $rno | $name | $branch " | cat >> dbms
          echo " The contents of the file after addition of data are : "
          cat dbms
          ;;
        2)echo " Enter the record you want to search from the file : "
          read rno
          search=`grep -c -i "$rno" dbms`
          if [ $search -eq 0 ]
          then
          echo " No such record exists in the file "
          else
          grep -i "$rno" dbms
          fi
          ;;
        3)echo " Enter the technique by which you want to sort "
          echo " 1.Sort by rno. "
          echo " 2.Sort by name "
          echo " 3.Sort by branch "
          read choice
          sort -t "|" -k $choice dbms
          ;;
        4)echo " Enter the rno of the record you want to delete : "
          read rno
          similar=`grep -c "$rno" dbms`
          if [ $similar -eq 0 ]
          then
                echo " No such record exist "
          else
          echo " Are you sure you want to delete the record : (y/n) "
          read choice
          if [ $choice = 'y' ]
          then
                grep -v "$rno" dbms > temp
                cp temp dbms
                rm temp
                cat dbms
          else
                exit
          fi
          fi;;
        5)echo " Enter the roll no whose contents you want to modify : "
          read rno
          similar=`grep -c "$rno" dbms`
          if [ $similar -eq 0 ]
          then
                echo " No such record exists "
          else
          echo " Are you sure you want to modify : (y/n) "
          read choice
          if [ $choice = 'y' ]
          then
                echo " Now change the contents : "
                echo " Enter the roll no : "
                read rno
                similar=`grep -c "$rno" dbms`
                if [ $similar -eq 1 ]
                then
                        echo " This roll no already exists..You will have to give another roll no "
                while [ $similar -eq 1 ]
                do
                        echo " Enter another roll no : "
                        read rno
                        similar=`grep -c "$rno" dbms`
                done
                fi
                echo " Enter the name : "
                read name
                echo " Enter the branch : "
                read branch
                grep -v "$rno" dbms > temp
                echo " $rno | $name | $branch " | cat >> temp
                cp temp dbms
                rm temp
                cat dbms
          else
                exit
          fi
          fi;;
        6)echo " The file created is : "
                cat dbms;;
        *);;
esac
