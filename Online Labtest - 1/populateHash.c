#include "data.h"
#include <stdlib.h>
#include <stddef.h>

extern void populateHash(LongitudeHash H, PointList plist, int start, int end)
{
	int i, hashval;
	for(i=0; i<41; i++) {
		H[i] = NULL;	
	}
	for(i=start; i<=end; i++) {
		hData *hd = (hData *)malloc(sizeof(hData));
		hData *temp = (hData *)malloc(sizeof(hData));
		hd->longi = plist[i][0];
		hd->idx = i;
		hd->next = null;
		hashval = hd->longi % 41;
		temp = H[hashval];
		if(H[hashval] == NULL) {
			H[hashval] = hd;		
		}
		else {
			while(H[hashval]->next != NULL) {
				H[hashval] = H[hashval]->next;		
			}
			H[hashval]->next = hd;
			H[hashval] = temp;
		}
	}
}
