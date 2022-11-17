#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingo board.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
	//opening
	printf("===========================================================\n");
	printf("===========================================================\n");
	printf("                        BINGO GAME                           \n");
	printf("===========================================================\n");
	printf("===========================================================\n\n\n");
	
	//game
	
	bingo_init();
	bingo_imputNum(21);
	bingo_printBoard();


	
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
