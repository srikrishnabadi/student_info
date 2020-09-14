#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct subject
{
     char subId[15];
     char subName[15];
     int subCredits;
};
struct subjectList
{
    struct subject subjectSub;
    struct subjectList *subjectList;
};
int validsem(int sem)
{
    if(sem<1 || sem>8)
    return 1;
    else
    return 0;
}
struct subjectList *createNode(struct subject s)
{
    struct subjectList *nn;
    nn=(struct subjectList*)malloc(sizeof(struct subjectList));
    nn->subjectSub=s;
    nn->subjectList=NULL;
    return nn;
}
void insert(struct subjectList**h,struct subject s)
{
    struct subjectList *nn,*temp;
    temp=*h;
    nn=createNode(s);
    if(*h== NULL)
    {
        *h=nn;
    }
    else
    {
        while(temp->subjectList!=NULL)
        temp=temp->subjectList;
        temp->subjectList=nn;
    }
}
void display(struct subjectList *s)
{

    struct subjectList *temp=s;
    if(temp==NULL)
    {
        printf("----Not Entered Yet----\n");
        return;
    }
    else
    {
       printf("Sub Id Sub Name Sub Credits\n");
       while(temp!=NULL)
       {
       printf("%s %s %-10d",temp->subjectSub.subId,temp->subjectSub.subName,temp->subjectSub.subCredits);
       temp=temp->subjectList;
       }

    }
}
int main()
{
    int sem,i;
    struct subjectList *b[8];
    char a;
    struct subject s;
    for(i=0;i<8;i++)
    {
        b[i]=NULL;
    }
    do
    {
        do
        {
            printf("Enter the Semester for which you want to insert the subjects\n");
            scanf("%d",&sem);
            if(validsem(sem))
            {
                printf("Please Enter Sem No b/w 1 - 8\n");
            }
        } while(validsem(sem));
            for(i=0;i<7;i++)
            {
                printf("Enter the Subject %d Details\n",i+1);
                printf("Enter Subject Id,Name,Credits\n");
                scanf("%s %s %d",s.subId,s.subName,&s.subCredits);
                insert(&b[sem-1],s);
            }
            printf("Do you want to insert one more Sem subject details?(y/n)\n");
            scanf(" %c",&a);
    }while(a=='y');
    printf("Display the Entered Sem Details\n");
    for(i=0;i<8;i++)
    {
        printf("\nSemester %d Details\n",i+1);
        display(b[i]);
    }

    return 0;
}
