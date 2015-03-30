#include "PoliceTreeOps.h"


static inline int getMaxamount(PoliceTree root)
{
		PoliceTree p=root;
		if(p == NULL)
				return 0;

		if(p->right  == NULL)
				return p->amount;
		while(p->right !=NULL)
		{
			p=p->right;
		}
		return p->amount;
}

void printBonusPolicemen(PoliceTree root)
{

}
