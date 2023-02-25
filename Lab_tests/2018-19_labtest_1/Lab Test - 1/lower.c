#include "node.h"
BOOL IsLower_GM(int id1, int id2)
{
	if(id1%10000<id2%10000)
		return TRUE;
	else if(id1%10000>id2%10000)
		return FALSE;
	else if(id1%10000==id2%10000)
		{
		if(id1%10000000<id2%10000000)
			return TRUE;
		else
			return FALSE;
		}
}
