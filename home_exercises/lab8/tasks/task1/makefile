runTask1: hashtable.o task1_driver.o
	gcc -o runTask1 hashtable.o task1_driver.o
	./runTask1

task1.o: task1_driver.c 
	gcc -c task1_driver.c

hashtable.o: hashtable.c
	gcc -c hashtable.c

clean:
	rm -f *.o runTask1