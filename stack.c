#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct STATION // STATION�̶�� ����ü�� ����
{
	char name[20];
	struct STATION *next;
	struct STATION *prev;
}station; // typedef���� �ٲ� �̸�

// int *p = (int*)malloc(sizeof(int)) // �����Ҵ� ������

station *first; // ��߿� ����
station *last; // ������ ����
station *add; // ���� �߰��ϴ� ���� ����

void init() // ��߿��� ������ �ʱ�ȭ �Լ�
{

	first = (station*)malloc(sizeof(station)); //��߿� �޸� �Ҵ�
	last = (station*)malloc(sizeof(station)); // ������ �޸� �Ҵ�


	first->next = last; // ��߿��� �������� ���������� ����
	last->prev = first; // �������� �������� ��߿����� ����
	first->prev = NULL; // ��߿��� �������� �����Ƿ� NULL
	last->next = NULL;  // �������� �������� �����Ƿ� NULL
	strcpy(first->name,"");
	strcpy(last->name,"");

}
void add_station(station *add)
{

    add = (station*)malloc(sizeof(station));

    printf("�߰��� ���� �Է��ϼ��� : ");
    scanf("%s",add->name);
    last->prev->next = add;
    add->prev = last->prev;
    add->next = last;
    last->prev = add;
}
void del_station()
{
    station *del;
    del = last->prev;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
    printf("���� �Ϸ�\n");
}
void print()
{
    station *all_prt;
    all_prt = last;
    while(all_prt != NULL)
    {
        printf("%s -> ", all_prt->name);
        all_prt = all_prt->prev;
    }

}
int main()
{
    init();
    int select;
    char name[20];
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
    return 0;
}
