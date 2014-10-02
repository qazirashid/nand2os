gcc -c -Wall -Werror -fpic nand.c
gcc -shared -o libnand.so nand.o
sudo cp ./libnand.so /usr/local/lib/nand2os/
sudo ldconfig
