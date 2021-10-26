#!/bin/bash
touch _ex1.txt
echo "-: What is your name?
-: My name?
-: Yes, your name.
-: My name is Uvuvwevwevwe Onyetenyevwe Ugwemubwem Osas
-: Oh...." > _ex1.txt
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
touch ex1.txt
echo "i-node _ex1.txt:" >> ex1.txt
ls -i _ex1.txt >> ex1.txt
echo "i-node _ex1_1.txt:" >> ex1.txt
ls -i _ex1_1.txt >> ex1.txt
echo "i-node _ex1_2.txt:" >> ex1.txt
ls -i _ex1_2.txt >> ex1.txt
