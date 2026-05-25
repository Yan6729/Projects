#!/bin/bash
if [ -n "$1" ]
then
    grep -c -i $1 Day02/students.csv
else
    wc -l Day02/students.csv
fi
