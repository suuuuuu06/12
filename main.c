#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingo board.h"

#define BINGO_RES_UNFINISHED -1
#define BINGO_RES_FINISHED 0

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//int get_number(void);
int get_number(void)
{
	int selNum=0;
	
	do{
		printf("select a number : ");
		scanf("%d", &selNum);
		fflush(stdin);
		
		if (selNum<1||selNum> N_SIZE*N_SIZE || bingo_checkNum(selNum)== BINGO_NUMSTATUS_ABSENT)
		{
			printf("%i is not on the board! select other one.\n", selNum);
			
		}
	} while(selNum<1||selNum> N_SIZE*N_SIZE || bingo_checkNum(selNum)== BINGO_NUMSTATUS_ABSENT);

	return selNum;	
}

int check_gameEnd(void)
{
	int res= BINGO_RES_UNFINISHED;
	
	if (bingo_countCompletedLine() >= N_LINE)
	{
		res=BINGO_RES_FINISHED;
	}
	
	return res;
}

int main(int argc, char *argv[]) {
	int selNum;
	srand((unsigned)time(NULL));
	//opening
	printf("===========================================================\n");
	printf("===========================================================\n");
	printf("                        BINGO GAME                           \n");
	printf("===========================================================\n");
	printf("===========================================================\n\n\n");
	
	//game
	
	bingo_init();
	
	while(check_gameEnd() == BINGO_RES_UNFINISHED)
	{   	
		bingo_printBoard();
		selNum = get_number();
		bingo_inputNum(selNum);
		printf("no of completed lines : %i\n",bingo_countCompletedLine());
			
	}
	
	
	


	
	//initialize bingo board
	/*while(game is not end) //줄 수가 n_bingo보다 작음
	{
		bingo board print
		
		print no of complited line
		
		select number
		
		uptate board status
	}
	*/


	//closing
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("===========================================================\n");
	printf("===========================================================\n");
	printf("                    <----@ BINGO @---->                      \n");
	printf("                          YOU WIN!                 \n");
	printf("===========================================================\n");
	printf("===========================================================\n");
	
	
	return 0;
}


