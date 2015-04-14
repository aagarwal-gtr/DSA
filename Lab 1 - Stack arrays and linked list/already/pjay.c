#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node;
typedef struct node node;
typedef node * ptr;
struct node{
int reg;
char name[20];
};
struct parking_lot{
int top[2];
ptr id1[100000];
ptr id2[100000];
int pid[100000];
int cur_id;
};
typedef struct parking_lot plot;
typedef plot* pptr;
pptr first,sec;
int MAX=100000;
void Enter_ParkingLot(int reg,char name[],int lot){
if(first->top[lot]<MAX-1){
(first->top[lot])++;
ptr car=(ptr) malloc(sizeof(node));
car->reg=reg;
strcpy(car->name,name);
first->id[first->top[lot]]=car;
first->pid[first->top[lot]]=(++(first->cur_id));
}
else printf("Parking full:overflow");
}
void Exit_Parking(int pid){
if(first->top<0) printf("parking vacant:underflow");
else{
	int i=0,j=0,done=0;
	for(i=0;i<=first->top[1];i++){
		if(first->pid[i][1]==pid){
		done=1;
		break;
		}
	}
	if(done){
		
	}
	if(!done){
		for(i=0;i<=first->top[1];i++){
			if(first->pid[i][2]==pid){
			done=1;
			break;
			}
		}
	}
	if(!done)printf("car not in the parking");
	}
}
void Exit_ParkingLot(int i){
if(first->top[i]<0) printf("parking vacant:underflow");
else{
first->id[first->top[i]]=NULL;
first->pid[first->top[i]]=-1;
first->top[i]--;
}
}
ptr is_parked(int id){
int i=0;
for(int j=0;j<2;j++){
while(i<=first->top[j] && id!=first->pid[i]){
i++;
} 
if(i<=first->top[j]){
return first->id[i];
}
}
else return NULL;
}
void Parking_Snapshot(char* filename){
int i=0,j=0;
FILE * file;
file=fopen(filename,"w");
for(j=0;j<2;j++){
while(i<=first->top[j]){
fprintf(file,"parking id:%d	Regno:%d	Owner_Name:%s	\n",first->pid[i],first->id[i]->reg,first->id[i]->name);
i++;
}
}
fclose(file);
}
int main()
{
char filename1[]="parked.c";
char file2[]="removed3.c";
char file3[]="added2.c";
ptr head;
first = (pptr) malloc(sizeof(plot));
first->top1=-1;
first->top2=-1;
first->cur_id=0;
int j=0;
/*for(j=0;j<5;j++)
{
char name[20];
int reg;
printf("enter name and reg\n");
fflush(stdin);
scanf("%s%d",name,&reg);
Enter_ParkingLot(reg,name);
}
Parking_Snapshot(filename1);
Exit_ParkingLot();
Exit_ParkingLot();
Exit_ParkingLot();
Parking_Snapshot(file2);*/
Enter_ParkingLot(1452,"newGuy");
Enter_ParkingLot(172,"nwGirl");
Enter_ParkingLot(1121,"somebody");
Parking_Snapshot(file3);


return 0;
}
