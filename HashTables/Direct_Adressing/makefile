runHashTableDriver: hashtable_driver.o hashtable_sample.o
	gcc -o runHashTableDriver hashtable_driver.o hashtable_sample.o
	./runHashTableDriver

hashtable_driver.o: hashtable_driver.c
	gcc -c hashtable_driver.c 

hashtable_sample.o: hashtable_sample.c
	gcc -c hashtable_sample.c

clean:
	rm -f *.o runHashTableDriver
