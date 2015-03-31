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
	FILE *fp;
	int i;
	PoliceTree curr;
	fp=fopen("bonus.txt", "w+");
	if(fp == NULL)
	{
			fprintf(stderr, "\nCannot open bonus file for writing\n");
			exit(-1);
	}
	i = 0.9 * getMaxamount(root);
	curr = root;
	while(curr!=NULL)
	{
		if(curr->amount >= i) {
			fprintf(fp,"%d %d\n",curr->id, curr->amount);
		}
		curr = curr->succ;
	}

	fclose(fp);

}
