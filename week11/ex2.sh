#!/bin/bash
#Add two files
sudo touch lofsdisk/file1.txt
sudo touch lofsdisk/file2.txt
#without "change mode" command it doesn't work correctly on my laptop
sudo chmod ugo+rwx lofsdisk/file1.txt
sudo chmod ugo+rwx lofsdisk/file2.txt
sudo echo 'Vagif' > lofsdisk/file1.txt
sudo echo 'Khalilov' > lofsdisk/file2.txt

#Compile ex2.c to ex2.out
sudo gcc ex2.c -o ex2.out

#Add bash, cat, echo, ls commands to the LOFS
sudo mkdir lofsdisk/bin
sudo mkdir lofsdisk/lib
sudo mkdir lofsdisk/lib64
sudo mkdir lofsdisk/lib/x86_64-linux-gnu

sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpthread.so.0 lofsdisk/lib/x86_64-linux-gnu

sudo cp /bin/bash lofsdisk/bin
sudo cp /bin/cat lofsdisk/bin
sudo cp /bin/echo lofsdisk/bin
sudo cp /bin/ls lofsdisk/bin
#
sudo cp ex2.out lofsdisk
#Run process and chroot it 
sudo echo "without root change:">ex2.txt
sudo ./ex2.out >> ex2.txt
sudo echo >> ex2.txt
sudo echo "with root change:">> ex2.txt
sudo chroot lofsdisk /ex2.out >> ex2.txt



