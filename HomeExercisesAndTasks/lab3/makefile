runEx1: home_ex_1.o stack_array.o
	gcc -o runEx1 home_ex_1.o stack_array.o
	./runEx1

runEx4: home_ex_4.o queue_array.o
	gcc -o runEx4 home_ex_4.o queue_array.o
	./runEx4

home_ex_4.o: home_ex_4.c queue.h
	gcc -c home_ex_4.c

queue_array.o: queue_array.c 
	gcc -c queue_array.c 
	
home_ex_1.o: home_ex_1.c stack.h
	gcc -c home_ex_1.c 

stack_array.o: stack_array.c
	gcc -c stack_array.c

cleanEx1:
	rm -f *.o runEx1

cleanEx4:
	rm -f *.o runEx4