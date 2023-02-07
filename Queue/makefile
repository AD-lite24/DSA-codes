runQueueWithArray: queueDriver.o queue_array.o
	gcc -o runQueueWithArray queueDriver.o queue_array.o heap_usage.o
	./runQueueWithArray

runQueueWithLL: queueDriver.o queue_ll.o linked_list.o
	gcc -o runqueueWithLL queueDriver.o queue_ll.o linked_list.o
	./runqueueWithLL

queueDriver.o: queueDriver.c queue.h heap_usage.h
	gcc -c queueDriver.c
queue_ll.o: queue_ll.c queue.h linked_list.h
	gcc -c queue_ll.c
linked_list.o: linked_list.h linked_list.c
	gcc -c linked_list.c
queue_array.o: queue_array.c queue.h heap_usage.h heap_usage.o
	gcc -c queue_array.c
heap_usage.o: heap_usage.c
	gcc -c heap_usage.c
clean:
	rm -f *.o runQueueWithArray
	rm -f *.o runQueueWithLL
