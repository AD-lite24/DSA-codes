runTask2Driver: hashtable_open.o task2_driver.o 
	gcc -o runTask2 hashtable_open.o task2_driver.o
	./runTask2

hashtable_open.o: hashtable_open.c
	gcc -c hashtable_open.c

task2_driver.o: task2_driver.c
	gcc -c task2_driver.c

clean:
	rm -f *.o runTask2