#include "node.h"
#include <math.h>
#include <stdio.h>
BOOL IsLower_GM(int id1, int id2)
{
	int gn1 = id1 % 10000;
	int gn2 = id2 % 10000;

	printf("gn1: %d and gn2: %d\n", gn1, gn2);

	if (gn1 > gn2)
		return FALSE;
	else if (gn1 < gn2)
		return TRUE;

	else
	{
		int mn1 = (id1 % ((int)pow(10, 7)));
		int mn2 = (id2 % ((int)pow(10, 7)));

		mn1 = mn1 / ((int)pow(10, 4));
		mn2 = mn2 / ((int)pow(10, 4));

		printf("mn1: %d and mn2: %d\n", mn1, mn2);

		if (mn1 > mn2)
			return FALSE;
		else
			return TRUE;
	}
}

