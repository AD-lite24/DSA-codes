
#include"node.h"
#include<stdio.h>
#include<stdlib.h>
Locality * ReadFileintoLists(char *filename)
{
	FILE *fptr;
	fptr=fopen(*filename, "r");
	if(fptr==NULL){	
		printf("Error!");	
		exit(1); 
		}

	//tn2->next addresses tail of localities
	struct node2 *tn2= (struct node2*) malloc(sizeof(struct node2));
	
	//To store initial address of localities list
	Locality *initial;

	//Localities
	for(int i=1;i<=N;i++)
	{
		//tn1->next adresses tail of members
		struct node1 *tn1=(struct node1*)malloc(sizeof(struct node1));
		

		int temp;
		fscanf(fptr,"%d", &temp);
		struct node2 *link= (struct node2*) malloc(sizeof(struct node2));
		link->count=temp;
		if(i==1)
		{	
			initial=link;
			tn2->next=link;	
		}

		//For members		
		for(int j=1;j<=temp;j++)
		{
			char c;
			fscanf(fptr,"%c", &c);//To consume comma
			struct node1 *n=(struct node1*)malloc(sizeof(struct node1));
			if(j==1)
			{
				link->first=n;
				tn1->next=n;		
			}
			int identi;
			fscanf(fptr,"%d", &identi);
			n->id=identi;
			if(j!=1)
			{	
				//Assigning this node to previous nodes next
				(tn1->next)->next=n;
				//Making this node tail node
				tn1->next=n;
			}
		}
		
		if(i!=1)
		{
				//Assigning this node to previous nodes next
				(tn2->next)->next=link;
				//Making this node tail node
				tn2->next=link;
		}
		if(i<N)		
		{//To consume new line character
			char l;
			fscanf(fptr,"%c", &l);	
		}
	}	
	fclose(fptr);
	return initial;
}

void PrintLists (Locality *start)
{
	Locality *l=start;	
	for(int i=1;i<=N;i++)
	{ 		
		int cnt= (l->count);
		Member *m=(l->first);	
		for(int i=1;i<=cnt;i++)
		{
			int ident=(m->id);
			printf("\n%d", ident);	
			if(i<cnt)	
			{m=(m->next);}
		}
		if(i<N)
		{l=(l->next);}	
	}
}
