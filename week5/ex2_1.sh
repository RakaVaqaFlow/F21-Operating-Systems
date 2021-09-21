#!/bin/bash
n=10
for ((i=0; i<n; i++))
do
  file='ex2_1.txt'
  num=0
  num=$(tail -n 1 $file)
  let num++
  echo $num >> ${file}
done