#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





struct book_st{
	char title[100]; 
	int bookNum;	  
	char author[100];	  
};



int main(void) {
	int no;	// amount of channels
	struct book_st* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]모든 책 목록 \n[2]대여 가능한 책 목록 \n[3]빌리기 \n[4]반납하기 \n[5]자신이 대출중인 책 목록 보기 \n[6]책 검색 \n[7]책 추가 \n[8]책 삭제 \n[9]책 정보 수정 \n[0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

	return 0;
}
}


int loadData(struct book_st* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}