gcc -c -Wall -Werror -fpic gates.c
gcc -shared -o libgates.so gates.o
sudo cp ./libgates.so /usr/local/lib/
#sudo ldconfig
