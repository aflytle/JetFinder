#!/bin/bash

DATE=$(date '+%d-%m-%Y_%H-%M')
FILETYPE=".txt"
FILEBEGIN="./PersistenceVals/persistence_vals_"
DATAFILE="$FILEBEGIN$DATE$FILETYPE"

#read inFile
for f in *.txt; do
    ../../Ripser/ripser/ripser $f --format point-cloud --dim 1 >$DATAFILE
done
	 
