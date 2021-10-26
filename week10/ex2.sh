#!/bin/bash
mkdir week01
cd week01
touch file.txt
echo "Vagif Khalilov" > file.txt
cd ..

mkdir week10 
cd week10
link ../week01/file.txt _ex2.txt

out="$(ls -i ../week01/file.txt)"
inodenumber=${out%% *}
cd .. 
echo "i-node number of file.txt $inodenumber "> ex2.txt
echo "files with same i-node:" >> ex2.txt
find ../ -inum $inodenumber >> ex2.txt
echo "now, let's remove them" >> ex2.txt
find ../ -inum $inodenumber -exec rm {} \;



