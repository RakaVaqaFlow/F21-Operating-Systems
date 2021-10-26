#!/bin/bash
touch _ex3.txt
echo "Vagif Khalilov" >> _ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt > ex3.txt
chmod 707 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "Answers:">>ex3.txt
chmod 660 _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "    So, 660 mean that only owner and group have can read file and write to it" >> ex3.txt
echo >> ex3.txt
chmod 775 _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "    So, 775 mean that only owner and group have all permissions, others can only read and execute it." >> ex3.txt
echo >> ex3.txt
chmod 777 _ex3.txt 
ls -l _ex3.txt >> ex3.txt
echo "    So, 777 mean that everyone can read, write and execute file" >> ex3.txt