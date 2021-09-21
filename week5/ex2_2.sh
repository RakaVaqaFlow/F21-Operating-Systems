#!/bin/bash
n=10
file='ex2_2.txt'
filelock='file.lock'
ln $file $filelock
for ((i=0; i<n; i++))
do
  num=0
  num=$(tail -n 1 $file)
  let num++
  echo $num >> ${file}
done