#include "data.h"
#include <stdio.h>
#include <assert.h>

extern void printVicinity(LongitudeHash H, PointList plist, int longi, int lati, int sealvl)
{
	int latii, longii, i;
	FILE *fp = fopen("output3.txt", "w");
	for(i=0; i<41; i++) {
		if(H[i] != NULL) {
			hData *temp = (hData *)malloc(sizeof(hData));
			temp = H[i];
			while(temp->next != NULL) {			
				latii = plist[temp->idx][0];
				longii = plist[temp->idx][1];
				if(((latii-lati <=2)&&(latii-lati >=-2))&&((longii-longi <=2)&&(longii-longi >=-2)))
					fprintf(fp, "%d %d %d %d\n", longii, latii, plist[temp->idx][2], plist[temp->idx][3]);
				temp = temp->next;			
			}
			latii = plist[temp->idx][0];
			longii = plist[temp->idx][1];
			if(((latii-lati <=2)&&(latii-lati >=-2))&&((longii-longi <=2)&&(longii-longi >=-2)))
				fprintf(fp, "%d %d %d %d\n", longii, latii, plist[temp->idx][2], plist[temp->idx][3]);
		}	
	}
}
