//
//  main.c
//  HashingUsingChaining
//
//  Created by Ramsai Kamavaram on 11/01/22.
//

#include <stdio.h>
#include <stdlib.h>
#define tablesize 10
struct node
{
    int data;
    struct node*next;
};
struct node*head[tablesize]={NULL},*c;
void insert(int key)
{
    int i;
    i=key%tablesize;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    
    if(head[i]==NULL)
    {
        head[i]=newnode;
        return;
    }
     newnode->next=head[i];
    head[i]=newnode;
    
}
void display(void)
{
    for(int i=0;i<tablesize;i++)
    {
        printf("keys at index %d",i);
        if(head[i]==NULL)
        {
            printf("no keys present");
            
        }
        else{
       
            for(c=head[i];c!=NULL;c=c->next)
            printf("[%d]->",c->data);
        
    }
        printf("\n");
    }
}
void countkeys(void)
{
    for(int i=0;i<tablesize;i++)
    {
        int count=0;
        printf("keys at index %d",i);
        if(head[i]==NULL)
        {
            printf("%d",count);
            
        }
        else{
       
            for(c=head[i];c!=NULL;c=c->next)
            {
                count++;
            }
        
    }
        printf("number of keys in index %d is %d",i,count);
        printf("\n");
    }
}
void search(int key)
{
    int i;
    i=key%tablesize;
    if(head[i]==NULL)
    {
        printf("key not exit");
        return;
    }
    c=head[i];
    int found=0;
    while(c!=NULL)
    {
        if(c->data==key)
        {
            printf("it is found in %d row %d col",i,found);
            return;
        }
        c=c->next;
        found++;
    }
    printf("key not found\n");
}


int main()
{
    int ch,key;
    while(1)
    {
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter key to insert");
                scanf("%d",&key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("enter key to search\n");
                scanf("%d",&key);
                search(key);
                break;
            case 4:
                countkeys();
                break;
        }
    }
    
}
