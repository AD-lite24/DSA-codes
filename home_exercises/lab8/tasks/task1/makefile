runTask1: hashtable.o task1.o
	gcc -o runTask1 hashtable.o task1.o
	./runTask1

task1.o: task1.c 
	gcc -c task1.c

hashtable.o: hashtable.c
	gcc -c hashtable.c

clean:
	rm -f *.o runTask1