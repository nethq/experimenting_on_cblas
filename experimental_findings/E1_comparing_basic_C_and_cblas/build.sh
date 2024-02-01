
gcc -c *.c &&(libtool --mode=link --tag=CC gcc -o result.out ref/libgslcblas.a *.o -o result.out)
