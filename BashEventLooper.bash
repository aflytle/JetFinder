#!/bin/bash
for j in "64" "128" "256" "512" "1024" "2048" "4096" "8192"
do
    folder="CollisionDataFiles/"
    string1="GeV/"
    dir=$folder$j$string1
    mkdir $dir

    for i in {1..100}
	     do
		 ./rips_from_pythia $j $dir  
	     done
done

