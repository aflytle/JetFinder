#!/bin/bash


#calculate static meanvals
#?meanvals= python3 mean_only.py
#erase old files, must take out of non-test mode
#/bin/bash CleanTexts.bash

E=120
dir1="TEST_FILES/"

#generate a test collision
./rips_from_pythia $E $dir1



#run ripser on test collision

newdir="TEST_OUTPUTS/"
filetype=".txt"
if [ ! -d $newdir ]
then
   mkdir $newdir
fi
filename="testfile"

file="TEST_FILES/"
#add line to check for arguments




if [ ! -f  $newdir$filename$filetype ]
then
   ../Ripser/ripser/ripser $file/*.txt --format point-cloud --dim 0 > $newdir$filename$filetype
fi




#pull top five lifetimes from that collison
#thesevals= python3 five_point_puller.py $E $newdir$filename$filetype

#compare the means from the test runs with the values from the five_point_puller script
#result= python3 Fuzzy_Boolean.py $meanvals $thesevals

#echo $result
