
/*
void insert_Hash_id(node *Hash_id[],int size,int id,char *code,int cost)
{
    int key=hash2(id,size);
    insert(&Hash_id[key],id,code,cost);

}
*/


int findEntry(Hash_item h[], int size, int cust_id, char *item_code)
{
    int key1=hash1(item_code,size);
    int key2=hash2(cust_id,5);
    //printf("%d %d\n",hash1(item_code,10),hash2(cust_id,5));

    int cost=-1;
    node *temp=h[key1].Hash_id[key2];
    while (temp!=NULL)
    {
        if (temp->cust_id==cust_id &&(strcmp(temp->item_code,item_code)==0))
        {
            cost=temp->item_cost;
            break;
        }
        temp=temp->next;
    }
    //display(h[key1].Hash_id[key2]);

   return cost;

}


int item_purchased(Hash_item h[],int size,int id)
{
    int sum=0;
    int key=hash2(id,5);
    int i;
    node *temp;
    for(i=0;i<size;i++)
    {
        temp=h[i].Hash_id[key];
        while (temp)
        {
            if (temp->cust_id==id)
            {
                sum+=temp->item_cost;
            }
            temp=temp->next;
        }
    }

    return sum;
}


int main()
{

    Hash_item h[10];
    init_Hash_item(h,10);

    FILE *fp;
    int id;
    int cost;
    char code[9];
    fp=fopen("input.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d ",&id,code,&cost);
        insert_Hash_item(h,10,id,code,cost);

    }
  /*  int pos=findEntry(h,10,5672,"DMOJEVIK");
    printf("%d\n",pos);
    int value=item_purchased(h,10,5664);
    printf("%d\n",value);
  */
   printf("\n\n\n");
  output(h,10);

    return 0;
}
