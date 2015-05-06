#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "data.h"

int** dataRead(char *filename, int *numPoints, int *numCoords)
{
	//Input File Format ==>
		//First number represents Number of pointList (numPoints)
		//Second number represents Number of Dimensions (numCoords)
	//After that each numCoords numbers represent a data point.

   	PointList pointList;
	int  i, j, len;

	FILE *infile;

	if ((infile = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Error: no such file (%s)\n", filename);
		return NULL;
	}

	fscanf(infile, "%d", numPoints);
	fscanf(infile, "%d", numCoords);

	//allocate space for pointList[][] and read all points
	len = (*numPoints) * (*numCoords);
	pointList    = (int**)malloc((*numPoints) * sizeof(int*));
	assert(pointList != NULL);

	pointList[0] = (int*) malloc(len * sizeof(int));
	assert(pointList[0] != NULL);

	for (i=1; i<(*numPoints); i++)
		pointList[i] = pointList[i-1] + (*numCoords);

	i = 0;
	while(feof(infile)!= 1)
	{
		for (j=0; j<(*numCoords); j++)
		{
			fscanf(infile, "%d ", &pointList[i][j]);
			//printf("%d ", pointList[i][j]);
		}
		i++;
		//printf("\n");
	}

	fclose(infile);

	if((i) != *numPoints)
	{
		fprintf(stderr, "Error: Broken file (%s) : Have lesser number of points than claimed\n", filename);
		return NULL;
	}
    return pointList;
}

void writePartition(char *filename, int **pointList, int start, int end)
{
	FILE *outfile = fopen(filename, "w");
	assert(outfile != NULL);
	int i;
	for (i = start; i < end; i++)
		fprintf(outfile, "%d %d %d %d\n", pointList[i][0], pointList[i][1], pointList[i][2], pointList[i][3]);
	fclose(outfile);
}
void dataWrite(int **pointList, int* partitionResult, int numPoints)
{
	FILE *outfile;
	int i;
	writePartition("partition11.txt", pointList, 0, partitionResult[1]);
	writePartition("partition12.txt", pointList, partitionResult[1], partitionResult[2]);
	writePartition("partition21.txt", pointList, partitionResult[2], partitionResult[3]);
	writePartition("partition22.txt", pointList, partitionResult[3], numPoints-1);
}

int main(int *argc, char* argv[])
{
	if(argc != 4)
	{
		printf("Format: <executable> <longitude> <latitude> <sealevel>\n");
		return(1);
	}
	
	int testPoint[4];
	testPoint[0] = atoi(argv[1]);		//longitude
	testPoint[1] = atoi(argv[2]);		//latitude
	testPoint[2] = atoi(argv[3]);		//sealevel
	
	
	PointList pointList = NULL;		//list of points
	int numPoints = 0;			//number of points
	int numCoords;				//number of integer value stored in a point
	
	pointList = dataRead("inputData.txt", &numPoints, &numCoords);
	assert(pointList != NULL);
	
	int *partitionResult = partitionInto4(pointList, numPoints);
    
	int start, end;
	if(pointList[partitionResult[2]][0] > testPoint[0])				//if test point belong to P11 or P12
	{
		if(pointList[partitionResult[1]][0] > testPoint[1])			//if test point belongs to P11
		{
			start = 0;
			end = partitionResult[1] - 1;
		}
		else														//if test point belongs to P12
		{
			start = partitionResult[1];
			end = partitionResult[2] - 1;
		}
	}
	else															//if test point belong to P21 or P22
	{
		if(pointList[partitionResult[3]][0] > testPoint[1])			//if test point belongs to P21
		{
			start = partitionResult[2];
			end = partitionResult[3] - 1;
		}
		else														//if test point belongs to P22
		{
			start = partitionResult[3];
			end = numPoints;
		}
	}
	
	
	LongitudeHash H = (hData **) malloc(sizeof(hData *)*41); ;
	populateHash(H, pointList, start, end);
	
	printVicinity(H, pointList, testPoint[0], testPoint[1], testPoint[2]);  //writes output to output3.txt
	
	dataWrite(pointList, partitionResult, numPoints);
	return (0);
}
