#include "TicTacToe.h"

//game
void ClrBoard(IN_OUT CBoard& pBoard)
{
	memset(&pBoard, 0, sizeof(CBoard));
	*(int*)&pBoard |= EMPTY_BOARD;
}

bool SetZero(IN_OUT CBoard& pBoard, IN CCell& Pos)
{
	if(Pos < '1' || Pos > '9')
	{
		return RET_FAIL;
	}
	CCell tPos = (Pos << 1) - 2;
	UINT tZero = (*(UINT*)&pBoard & (SETS_MASK << tPos));
	UINT tCross = (*(UINT*)&pBoard | ~(SETS_MASK << tPos));

	if( tZero == NON_ZERO || tCross == NON_CROSS)
	{
		return RET_FAIL;
	}
	else
	{
		*(UINT*)&pBoard &= ~(SETS_MASK << tPos);
		return RET_OK;
	}
}

bool SetCross(IN_OUT CBoard& pBoard, IN CCell& Pos)
{
	if(Pos < '1' || Pos > '9')
	{
		return RET_FAIL;
	}
	CCell tPos = (Pos << 1) - 2;
	UINT tZero = (*(UINT*)&pBoard & (SETS_MASK << tPos));
	UINT tCross = (*(UINT*)&pBoard | ~(SETS_MASK << tPos));

	if( tZero == NON_ZERO || tCross == NON_CROSS)
	{
		return RET_FAIL;
	}
	else
	{
		*(UINT*)&pBoard |= (SETS_MASK << tPos);
		return RET_OK;
	}
}

bool ZeroWin(IN CBoard& pBoard)
{
	for(CCell i = 0; i < WINCOMB_COUNT; i+=1)
	{
		if(!(*(UINT*)&pBoard & WinComb[i]))
		{
			return RET_OK;
		}
	}
	return RET_FAIL;
}

bool CrossWin(IN CBoard& pBoard)
{
	for(CCell i = 0; i < WINCOMB_COUNT; i+=1)
	{
		if((*(UINT*)&pBoard & WinComb[i]) == WinComb[i])
		{
			return RET_OK;
		}
	}
	return RET_FAIL;
}

//game engine
void ShowBoard(IN CBoard& pBoard)
{
	UINT tmp = 1;
	cout<<"\n";
	for(UINT i = 0; i < BIT_COUNT; i+=2, ++tmp)
	{
		if((*(UINT*)&pBoard & (3U << i)) == NULL)
		{
			cout<<" O ";
		}
		else
		{
			if((*(UINT*)&pBoard & (3U << i)) == (3U << i))
			{
				cout<<" X ";
			}
			else
			{
				cout<<" : ";
				//cout<<" "<<(char)(48 + ((i + 2)>>1))<<" ";
			}
		}

		if(tmp%3 == 0)
		{
			cout<<"\n";
		}
	}
}

void EnterZero(IN_OUT CBoard& pBoard)
{
	CCell Input;
	cout<<"\nEnter position of \'O\': ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
		cin>>Input;

	system("cls");

	while(!SetZero(pBoard, Input))
	{		
		ShowBoard(pBoard);
		cout<<"\nErro! Enter position of \'O\': ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
			cin>>Input;
		system("cls");
	}
}

void EnterCross(IN_OUT CBoard& pBoard)
{
	CCell Input;
	cout<<"\nEnter position of \'X\': ";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
		cin>>Input;

	system("cls");

	while(!SetCross(pBoard, Input))
	{		
		ShowBoard(pBoard);
		cout<<"\nErro! Enter position of \'X\': ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
			cin>>Input;
		system("cls");
	}
}