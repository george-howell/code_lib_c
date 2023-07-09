all:
	make static_lib
	make shared_lib
	doxygen Doxyfile

docs:
	doxygen Doxyfile

static_lib:
	# create object file
	gcc -c *.c
	# invoke the archiver to create static library	
	ar rcs libdataio.a *.o
	# remove object files
	rm *.o

shared_lib:
	# create object file
	gcc -c -fPIC *.c
	# create the shared library
	gcc -shared -o libdataio.so *.o
	# remove object files
	rm *.o

clean:
	rm -fr *.a
	rm -fr *.so
	rm -fr ./docs