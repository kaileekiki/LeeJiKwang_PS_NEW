#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "classes.h"


#define SIZE 50


typedef struct {
	char title[100]; 
	int bookNum;	  
	char author[100];
  int publishedYear;
  int language; //1=korean, 2=english;
}book_st;


int main(void) {
	int no;	
	struct book_st* clist[SIZE]; 
  int menu;

	srand(time(0));
	no = loadData(clist);
  printf("> Load %d classes.\n", no);

	while(1)
	{
		// Print menu
		printf("\n[1]모든 책 목록 \n[2]책 추가 \n[3]책 삭제 \n[4]책 정보 수정 \n[5]책 검색 \n[6]변경사항 저장 \n[0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printBookList(clist, no); // Print all list of channels
		}
		else if(menu==2){
			no = addBook(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			no = deleteBook(clist, no); // Pick up random channels
		}
		else if(menu==4){
			updateBook(clist, no);	// Search a channel
		}
		else if(menu==5){
			searchBook(clist, no); // Add a channel
		}
		else if(menu==6){
			save(clist, no); // Modify a channel
		}
		else if(menu==0){
      printf("이용해 주셔서 감사합니다.\n");
			break;
		}
		else {
			printf("잘못된 입력입니다.\n");
		}
	}
	return 0;
}