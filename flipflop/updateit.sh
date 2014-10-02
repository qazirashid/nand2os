gcc -c -Wall -Werror -fpic sbar-rbar-latch.c -lnand
gcc -shared -L/usr/local/lib/nand2os -o liblatch.so sbar-rbar-latch.o -lnand -lgates
sudo cp ./liblatch.so /usr/local/lib/nand2os/
sudo ldconfig
