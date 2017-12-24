#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct STATION // STATION이라는 구조체를 선언
{
	char name[20];
	struct STATION *next;
	struct STATION *prev;
}station; // typedef으로 바꿀 이름

// int *p = (int*)malloc(sizeof(int)) // 동적할당 선언방법

station *first; // 출발역 선언
station *last; // 종착역 선언
station *add; // 역을 추가하는 변수 선언

void init() // 출발역과 종착역 초기화 함수
{

	first = (station*)malloc(sizeof(station)); //출발역 메모리 할당
	last = (station*)malloc(sizeof(station)); // 종착역 메모리 할당


	first->next = last; // 출발역의 다음역을 종착역으로 지정
	last->prev = first; // 종착역의 이전역을 출발역으로 지정
	first->prev = NULL; // 출발역의 이전역은 없으므로 NULL
	last->next = NULL;  // 종착역의 다음역은 없으므로 NULL
	strcpy(first->name,"");
	strcpy(last->name,"");

}
void add_station(station *add)
{

    add = (station*)malloc(sizeof(station));

    printf("추가할 역을 입력하세요 : ");
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
    printf("삭제 완료\n");
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
