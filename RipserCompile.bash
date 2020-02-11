#!/bin/bash

DATE=$(date '+%d-%m-%Y_%H-%M')
FILETYPE=".txt"
FILEBEGIN="persistence_vals"
DATAFILE="$FILEBEGIN$DATE$FILETYPE"
read inFile


../Ripser/ripser/ripser $inFile --format point-cloud --dim 1 >$DATAFILE
