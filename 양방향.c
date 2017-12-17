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
	strcpy(first->name,"출발역");
	strcpy(last->name,"종착역");
	
}

void add_station(station *add) // 역을 추가하는 함수 
{
	
	add = (station*)malloc(sizeof(station)); //추가할 역 메모리 할당
	
	printf("추가할 역을 입력하세요 : ");
	scanf("%s",add->name);
	
	// 종착역이 가리키는 이전역의 다음역을 추가하는 역으로 지정 
	last->prev->next = add; 
	// 추가되는 역의 이전역을 종착역의 이전역으로 지정 
	add->prev = last->prev;
	
	add->next = last; // 추가되는 역의 다음역을 종착역으로 지정 
	last->prev = add; // 종착역의 이전역을 추가되는 역으로 지정 
}

void del_station(char *name) // 역을 삭제하는 함수  
{
	station *del; // 출발역부터 종착역까지 갈 변수 
	del = first; // del을 출발역으로 지정한다. 
	while(del != NULL) // 종착역의 다음역까지 반복 
	{
		if(strcmp(name,del->name)==0) // 이름이 같은지 비교 
		{
			del->prev->next = del->next;
			del->next->prev = del->prev;
			free(del); // 이름이 같다면 삭제 
			printf("삭제 완료\n");
		}
		del = del->next; // 다음역으로 넘어간다. 
	}
	
}

// 검색하는 것은 삭제하는 것과 구조가 같다.
// 단지 삭제가 아니라 출력일 뿐 
void search_station(char *name) // 역을 검색하는 함수 
{
	station *search; // 출발역부터 종착역까지 나아갈 변수 
	search = first; // search를 출발역으로 지정 
	while(search != NULL) // 종착역의 다음역까지 반복 
	{
		if(strcmp(name,search->name)==0) // 이름이 같은지 비교 
		{
			printf("%s\n", search->name); // 이름이 같다면 출력 
		}
		search = search->next; // 다음역으로 넘어간다. 
	}	
	
}

void print() // 전체노선 출력 함수 
{
	station *all_prt; // 출발역부터 종착역까지 나아갈 변수 
	all_prt = first; // 출발역으로 지정 
	while(all_prt != NULL) // 최종역의 다음역까지 반복 
	{
		printf("%s -> ", all_prt->name); // 역이름 출력 
		all_prt = all_prt->next; // 다음역으로 간다. 
	}
}

int main()
{
	init();
	int select; // 메뉴 선택을 위한 변수 
	char name[20]; // 삭제, 검색을 위한 변수 
	
	while(select != 5)
	{
		
	printf("\n 1. 추가 2. 삭제 3. 검색 4. 전체노선 5. 종료\n");
	printf("메뉴 선택 : ");
	scanf("%d", &select);
	
	switch(select)
	{
		case 1:
			add_station(&add);
			break;
			
		case 2:
			printf("삭제할 역을 입력하세요 : ");
			scanf("%s", &name);
			del_station(&name);
			break;
			
		case 3:
			printf("검색할 역을 입력하세요 : ");
			scanf("%s", &name);
			search_station(&name); // 이름 전달 
			
		case 4:
			print();
			break; 
			
	}
		}
	
	return 0;
}
