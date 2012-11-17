#include "TicTacToe.h"



int main()
{
	CBoard B1;
char ch;
CCell turn;
do{
	ClrBoard(B1);
	turn = 1;
	while(true)
	{
		system("cls");
		ShowBoard(B1);
		
		EnterZero(B1);
		if(ZeroWin(B1))
		{
			ShowBoard(B1);
			cout<<"\n\'O\' won! \n";
			system("pause");
			break;
		}
		if(++turn > CELL_COUNT)
		{
			ShowBoard(B1);
			cout<<"\nDraw! \n";
			system("pause");
			break;
		}
		system("cls");

		ShowBoard(B1);

		EnterCross(B1);
		if(CrossWin(B1))
		{
			ShowBoard(B1);
			cout<<"\n\'X\' won! \n";
			system("pause");
			break;
		}
		if(++turn > CELL_COUNT)
		{
			ShowBoard(B1);
			cout<<"\nDraw! \n";
			system("pause");
			break;
		}
	}

	system("cls");
	cout<<"\n\'y\'  -  to play again\n\'AnyKey\' - to exit\n\nLet's enter your choice: ";
	cin>>ch;
}while(ch == 'y');

	cout<<"\nExit!\n";
	system("pause");

	return 0;
}