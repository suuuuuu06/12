#include "bingo board.h"
#include <stdio.h>
#define BINGONUM_HOLE -1




static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];


void bingo_init(void)
{
	int i, j, k;
	int randNum; //���� ��ȣ (����� ���ڸ� ����) 
	int maxNum = N_SIZE*N_SIZE; //���� �����ִ� �� 
	
	for (i=0;i<N_SIZE*N_SIZE;i++)
		numberStatus[i] = BINGO_NUMSTATUS_ABSENT;
		
	for (i=0;i<N_SIZE;i++)
		for (j=0;j<N_SIZE;j++)
		{
			randNum = rand()%maxNum; //���� ���� ����  
			
			for (k=0;k<N_SIZE*N_SIZE;k++)//�� ���ڿ� ���� ��������  
			{
				if (numberStatus[k] == BINGO_NUMSTATUS_ABSENT ) //���� k+1�� ���� �Ҵ��� �ȵǾ� �ִٸ�  
				{
					if (randNum == 0) //k+1 �� randNum��° �����̸�  
						break;
					else
						randNum--; //�׷��� ������ �ϳ� ����  
				}
			}
			//���� k+1�� �Ҵ� 
			numberStatus[k] = i*N_SIZE + j;
			bingoBoard[i][j] = k+1;
			maxNum--;
		}
}




void bingo_printBoard(void)
{
	int i,j;
	int cnt=1;
	
	
	printf("===========================================================\n");
	for (i=0;i<N_SIZE;i++){
		
		for (j=0;j<N_SIZE;j++){
			
			
			if (bingoBoard[i][j]==BINGONUM_HOLE)
				printf("X\t");
			else
				printf("%i\t",bingoBoard[i][j]);
		}
		
		printf("\n");
	}
	printf("===========================================================\n");
}


void bingo_inputNum(int sel)
{
	int i,j;
	
	//printf("select a number : ");
	//scanf("%d",&sel);
	
	i=numberStatus[sel-1]/N_SIZE;
	j=numberStatus[sel-1]%N_SIZE;
	
	bingoBoard[i][j]=BINGONUM_HOLE;
	
	numberStatus[sel-1]= BINGONUM_HOLE;
	
}


int bingo_countCompletedLine(void)
{
	int i,j;
	int cnt=0;
	int checkBingo;
	
	//row
	for (i=0;i<N_SIZE;i++)
	{
		checkBingo= 1;
		for(j=0;j<N_SIZE;j++)
		{
			if (bingoBoard[i][j]>0)
			{
				checkBingo=0;
				break;
			}
		}
		
		if (checkBingo==1)
		{
			cnt++;
		}
		
	}
	
	//col
	for (j=0;j<N_SIZE;j++)
	{
		checkBingo= 1;
		for(i=0;i<N_SIZE;i++)
		{
			if (bingoBoard[i][j]>0)
			{
				checkBingo=0;
				break;
			}
		}
		
		if (checkBingo==1)
		{
			cnt++;
		}
		
	}
	
	//cross-1
	checkBingo= 1;
	for (i=0;i<N_SIZE;i++)
	{
		
		if (bingoBoard[i][N_SIZE-i-1]>0)
		{
			checkBingo=0;
			break;
		}
	}
		
	if (checkBingo==1)
	{
		cnt++;
	}
	
	
	
	//cross-2
	checkBingo= 1;
	for (i=0;i<N_SIZE;i++)
	{
			
		if (bingoBoard[i][i]>0)
			{
				checkBingo=0;
				break;
			}
		
	}
		
	if (checkBingo==1)
	{
		cnt++;
	}
	
	return cnt;
}



int bingo_checkNum(int selNum)
{
	if(numberStatus[selNum]== BINGONUM_HOLE)
	{
		return BINGO_NUMSTATUS_ABSENT;
	}
	
	else
	{
		return BINGO_NUMSTATUS_PRESENT;
	}
}

