runExternalMerge: external_merge_sort.o merge_sort.o
	gcc -o runExternalMerge external_merge_sort.o  merge_sort.o
	./runExternalMerge

external_merge_sort.o: external_merge_sort.c
	gcc -c external_merge_sort.c

merge_sort.o: merge_sort.c merge_sort.h
	gcc -c merge_sort.c