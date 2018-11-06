#!/bin/sh

echo "Building zobdisp...";

make -s -C src;

echo "Moving zoblock script and zobdisp in /usr/bin..."

sudo cp src/zobdisp /usr/bin;
sudo cp src/zoblock /usr/bin;

make fclean -s -C src;

echo "Done ! Launch zoblock and enjoy the phallus power :D"
