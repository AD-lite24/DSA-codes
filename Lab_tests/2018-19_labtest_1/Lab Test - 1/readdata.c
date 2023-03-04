
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Locality *createLocalityNode()
{
	Locality *node = malloc(sizeof(Locality));
	node->count = 0;
	node->first = NULL;
	node->next = NULL;
	return node;
}

Member *createMemberNode()
{
	Member *node = malloc(sizeof(Member));
	node->id = 0;
	node->next = NULL;
	return node;
}

Locality *ReadFileintoLists(char *filename)
{
	FILE *fptr;
	fptr = fopen(filename, "r+");

	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}

	Locality *head = createLocalityNode();

	Locality *temp1 = head;

	for (int i = 0; i < N; i++)
	{
		int count;
		fscanf(fptr, "%d", &count);

		if (i == 0)
		{

			head->count = count;
			head->next = createLocalityNode();
			head->first = createMemberNode();
			Member* temp2 = head->first;

			for (int j = 0; j < count; j++)
			{
				int dummy;
				fscanf(fptr, ",%d", &(temp2->id));
				temp2->next = createMemberNode();
				temp2 = temp2->next;
			}
			fscanf(fptr, "\n");
			
		}

		else{

			temp1->next = createLocalityNode();
			temp1 = temp1->next;
			temp1->count = count;

			temp1->first = createMemberNode();

			Member *temp2 = temp1->first;
			for (int j = 0; j < count; j++){

				fscanf(fptr, ",%d", &temp2->id);
				temp2->next = createMemberNode();

				temp2 = temp2->next;		
			}
			
		}
	}
	return head;
}

// int main()
// {
// 	char *filename = "file.txt";
// 	Locality *stuff;
// 	stuff = ReadFileintoLists(filename);
// 	PrintLists(stuff);
// }

void PrintLists(Locality* start)
{
	Locality* temp = start;
	for (int i = 0; i < N; i++){

		printf("count: %d\n", temp->count);
		Member* mem = temp->first;
		for (int j = 0; j < temp->count; j++){
			printf("id: %d\n", mem->id);
		}
		temp = temp->next;
	}
}
