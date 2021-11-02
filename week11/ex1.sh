#!/bin/bash
img=lofs.img
dd if=/dev/zero of=$img bs=1M count=55
sudo losetup -fP $img
mkfs.ext4 ./$img
disk=lofsdisk
mkdir $disk
sudo mount -o loop $img $disk
df -hP $disk