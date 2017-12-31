#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
typedef struct STATION
{
    char name[20];
    struct STATION *next;
    struct STATION *prev;
}station;
station *first;
station *last;
station *add;
void init()
{
    first = (station*)malloc(sizeof(station));
	last = (station*)malloc(sizeof(station));


	first->next = last;
	last->prev = first;
	first->prev = NULL;
	last->next = NULL;
	strcpy(first->name,"");
	strcpy(last->name,"");
}
void add_station(station *add)
{
    add=(station*)malloc(sizeof(station));

    printf("please enter the name of station:");
    scanf("%s",add->name);
    first->next->prev = add;
    add->next=first->next;
    add->prev=first;
    first->next=add;
}
void del_station()
{
    station *del;
    del = last->prev;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
    printf("done\n");
}
void print()
{
    station *all_prt;
    all_prt = last->prev;
    while(all_prt != NULL)
    {
        printf("%s ", all_prt->name);
        all_prt = all_prt->prev;
    }
}
int main()
{
    init();
    int select=NULL;
    while(select!=5)
    {
        printf("\n 1.add 2.delete 3.print all 5.end\n");
        printf("select:");
        scanf("%d",&select);
        switch(select)
        {
        case 1:
            add_station(&add);
            break;
        case 2:
            del_station();
            break;
        case 3:
            print();
            break;
        }
    }
}
