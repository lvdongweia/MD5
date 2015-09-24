md5_example : example.o md5_lib.o md5.o hash.o
	gcc -o md5_example example.o md5_lib.o md5.o hash.o
example.o : example.c md5_lib.h
	gcc -c example.c
md5_lib.o : md5_lib.c md5_lib.h md5.h
	gcc -c md5_lib.c
md5.o : md5.c md5.h md5_types.h hash.h
	gcc -c md5.c
hash.o : hash.c hash.h md5_types.h
	gcc -c hash.c
clean:
	-rm -rf *.o
