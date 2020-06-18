#include"chess.h"

void InitBoard(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++){
			board[i][j] = ' ';
		}
	}
}
void ShowBoard(char board[][COL],int row,int col)
{
	printf("   | 1 | 2 | 3| \n");
	int i = 0;
	for (; i < row; i++)
	{
		printf("-----------------\n");
		printf(" %d | %c | %c | %c |\n", i + 1, board[i][0], board[i][1], board[i][2]);
	}
	printf("-----------------\n");
}
int PlayerMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������Ҫ�����λ��:<x,y># ");
	scanf("%d %d", &x, &y);
	if (x >= 1 && x<= 3 && y >= 1 && y <= 3){
		if (board[x - 1][y - 1] != ' '){
			return 2;     //������ӵĵط����ǿո�Ҳ�����Ѿ��������ˣ���ô�Ͳ����ٷ����ˣ���ʱ����2
		}
		board[x - 1][y - 1] = BLACK_PIECE;
		return 0;      //���Է��ӣ�����󷵻�0
	}
	return 1;     //�������������Ƿ��������룿
}
char JudgeResult(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int k = 0;
	for (; i < row; i++){
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];
		}
	}
	
	for (; k < col; k++){
		if (board[0][k] != ' ' && board[0][k] == board[1][k] && board[1][k] == board[2][k]){
			return board[0][k];
		}
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] ){
		return board[0][0];
	}
	if ( board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
		return board[0][2];
	}
	for (i = 0; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			if (board[i][j] == ' '){
				return 'N';
			}
		}
	}
	return 'E';
}
void ComputerMove(char board[][COL], int row, int col)
{
	while (1){
		int i = rand() % row;
		int j = rand() % col;
		if (' ' == board[i][j]){
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("Computer.....done!\n");
	Sleep(100);
}
void Game()
{
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	char ret = 'N';
	srand((unsigned long)time(NULL));
	while (1)
	{
		ShowBoard(board, ROW, COL);
		int type = PlayerMove(board, ROW, COL);
		if (1 == type){
			printf("������������!\n");
			continue;
		}
		else if (2 == type){
			printf("��λ���ѱ���������!\n");
			continue;
		}
		else {
			printf("player.....done!\n");
		}
	    ret=JudgeResult(board, ROW, COL);
		if (ret != 'N'){
			break;
		}
		 ComputerMove(board, ROW, COL);
		 ret = JudgeResult(board, ROW, COL);
		 if (ret != 'N'){
			 break;
		 }
	}
	ShowBoard(board, ROW, COL);
	switch (ret){
	case BLACK_PIECE:
		printf("��ϲ�������˵��ԣ�\n");
		break;
	case WHITE_PIECE:
		printf("��Ǹ�������ˣ�\n");
		break;
	case 'E':
		printf("������Դ����ƽ�֣�\n");
		break;
	default:
		break;
	}
}