#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fpr;
	FILE *fpw;

	fpr = fopen("some.txt", "r");
	fpw = fopen("someother.txt", "w");

	char c;
	while(!feof(fpr)) {
		fscanf(fpr, "%c", &c);
		if(c>='A' && c<='Z')
			fprintf(fpw, "%c", c-'A'+'a');
		else if((c>='a' && c<='z') || (c==' '))
			fprintf(fpw, "%c", c);
	}

	fclose(fpr);	
	fclose(fpw);

	FILE *fp;
	fp = fopen("someother.txt", "r");

	trie_t trie;
	initialize(&trie);

	char keys[][100];
	int i=0;

	while(!feof(fp)) {
		fscanf(fp, "%s", keys[i++][])

	fclose(fp);

	int size = sizeof(keys)/sizeof(keys[0]);

	for(i=0; i<size; i++) {
		insert(&trie, keys[i]);
	}

	return 0;
}
