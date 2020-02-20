#!/bin/bash


#event energies
for j in "64" "128" "256" "512" "1024" "2048" "4096" "8192"
do

#make directories of events
    folder1="CollisionDataFiles/"
    string1="GeV"
    slash="/"
    dir1=$folder1$j$string1$slash
    mkdir $dir1



#generate datasets for each energy
    for i in {1..100}
	     do
		 ./rips_from_pythia $j $dir1  
	     done



#make directory for persistence values
    folder2="PersistenceVals/"
    dir2=$folder2$j$string1$slash
    mkdir $dir2
    FILETYPE=".txt"



#loop through newly created files for processing
    for f in $dir1/*.txt; do
	../Ripser/ripser/ripser $f --format point-cloud --dim 0 > $dir2$(date '+%F_%T%3N')$FILETYPE

    done


# Python loop for stuff
    for f in $dir2/*.txt; do
	python3 five_point_puller.py $j $f
    done
    
    
done

python3 mean_plotter.py
