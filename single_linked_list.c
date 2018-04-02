#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

void add(NODE **p,int v)
{
    NODE *newnode;

    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=v;
    newnode->next=NULL;

    if(*p==NULL)
    {
        *p=newnode;
    }
    else
    {
        NODE *temp;
        temp=*p;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }

}

int count(NODE *p)

{

    int count=0;

    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;

}

void display(NODE *p)

{

    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }

    printf("\n");

}
void displayrec(NODE *p)
{
    if(p==NULL)
        return;
    else
    {
        printf("%d\t",p->data);
        displayrec(p->next);
    }
}

void displayrevrec(NODE*p)
{
    if(p==NULL)
        return;
    else
    {
        displayrevrec(p->next);
        printf("%d\t",p->data);
    }
}

void sort(NODE *p)

{

    int n=count(p);
    int i;
    NODE *temp;

    for(i=0;i<n-1;i++)
    {
        for(temp=p;temp->next!=NULL;temp=temp->next)
        {
            if(temp->data>temp->next->data)
            {
                int t=temp->data;
                temp->data=temp->next->data;
                temp->next->data=t;
            }
        }
    }

}

int max(NODE *p)
{
    int large;
    large=p->data;

    while(p->next!=NULL)
    {
        if(p->next->data>large)
        {
            large=p->next->data;
        }
        p=p->next;
    }

    return large;
}

void reverse(NODE**p)

{

	NODE*temp,*prev;

	prev=NULL;

	while(*p!=NULL)

	{

		temp=(*p)->next;

		(*p)->next=prev;

		prev=*p;

		*p=temp;

	}

	*p=prev;

}

int del(NODE** p, int v)
{
    NODE *temp,*prev;
    temp=*p;
    prev=NULL;

    while(temp!=NULL)
    {
        if(temp->data==v)
            break;
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        return 0;
    }

    if(temp==*p)
    {
        *p=temp->next;
    }

    else
    {
        prev->next=temp->next;
    }

    free(temp);

    return 1;

}

int insertafter(NODE *p, int after, int v)
{
    NODE *temp, *newnode;

    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=v;
    newnode->next=NULL;
    temp=p;

    while(temp!=NULL)
    {
        if(temp->data==after)
        {
            break;
        }
        temp=temp->next;
    }

    if(temp==NULL)
    {
        return 0;
    }

    else
    {
        newnode->next=temp->next;
        temp->next=newnode;
        return 1;
    }

}

int insertpos(NODE **p, int pos, int v)
{
    NODE *temp, *newnode, *prev;
    temp= *p;

    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=v;
    newnode->next=NULL;

    int i=1;

    while(temp!=NULL)
    {
        if(i==pos)
        {
            break;
        }
        prev=temp;
        temp=temp->next;
        i++;
    }

    int c=count(*p);

    if(pos==c+1)
    {
        prev->next=newnode;
        return 1;
    }

    if(temp==NULL)
    {
        return 0;
    }

    if(i==1)
    {
        newnode->next=temp;
        *p=newnode;
        return 1;
    }

    else
    {
        newnode->next=prev->next;
        prev->next=newnode;
        return 1;

    }


}

int ol(NODE **p,int v)

{

    NODE *newnode,*temp,*prev;

    temp=*p;
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=v;
    newnode->next=NULL;

    while(temp!=NULL)

    {
        if(v<temp->data)
        {
            break;
        }
        prev=temp;
        temp=temp->next;
    }

    if(temp==*p)

    {
        newnode->next=*p;
        *p=newnode;
        return 1;
    }

    else

    {
        newnode->next=prev->next;
        prev->next=newnode;
        return 1;
    }

    if(temp==NULL)

    {
        return 0;
    }
}

NODE* intersection(NODE *p1,NODE *p2)
{
    NODE *p3,*t;

    p3=NULL;

    while(p1!=NULL)

    {
        t=p2;

        while(t!=NULL)

        {
            if(p1->data==t->data)

            {
                add(&p3,p1->data);
                break;
            }

            t=t->next;
        }

        p1=p1->next;
    }

    return p3;
}

NODE* nion(NODE *p1,NODE *p2)
{
    NODE *p3,*t;

    p3=NULL;
    t=p1;

    while(p1!=NULL)
	{
		add(&p3,p1->data);
		p1=p1->next;
	}

	while(p2!=NULL)
	{

		p1=t;

		while(p1!=NULL)
		{
			if(p1->data==p2->data)
			{
				break;
			}
			p1=p1->next;
		}

		if(p1==NULL)
        {
			add(&p3,p2->data);
        }

		p2=p2->next;
    }
	return p3;

}


int main()
{
    NODE *first=NULL,*second=NULL;

    add(&first,40);
    add(&first,30);
    add(&first,20);
    add(&first,10);

    add(&second,10);
    add(&second,30);
    add(&second,50);
    add(&second,70);


    display(first);

    display(second);

    printf("\n\n");

    displayrec(first);

    printf("\n");

    displayrec(second);


    printf("\n\n");

    displayrevrec(first);

    printf("\n");

    displayrevrec(second);

    printf("\n");

/*
    NODE*inter=intersection(first,second);

    display(inter);

    NODE* unin=nion(first,second);

    display(unin);
*/
/*
    sort(first);

    display(first);

    int c=count(first);
    printf("number of nodes in linked list is %d\n",c);

    int m=max(first);
    printf("Max value is %d\n",m);

    reverse(&first);
    display(first);

    int d=del(&first,40);
    printf("Result is %d\n",d);
    display(first);

    int ia=insertafter(first, 20, 25);
    printf("Result is %d\n",ia);
    display(first);

    int ip=insertpos(&first,1,35);
    printf("Result is %d\n",ip);
    display(first);

    ip=insertpos(&first,3,55);
    printf("Result is %d\n",ip);
    display(first);

    ip=insertpos(&first,7,75);
    printf("Result is %d\n",ip);
    display(first);

    ip=insertpos(&first,8,95);
    printf("Result is %d\n",ip);
    display(first);

    ip=insertpos(&first,10,115);
    printf("Result is %d\n",ip);
    display(first);

    int o=ol(&first,50);
    printf("Result is %d\n",o);
    display(first);

    o=ol(&first,30);
    printf("Result is %d\n",o);
    display(first);

    o=ol(&first,100);
    printf("Result is %d\n",o);
    display(first);
*/
    return 0;
}
