#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

using namespace std;

typedef unsigned char	CCell;
typedef unsigned int	UINT;

#define IN const
#define IN_OUT

#define RET_OK		true
#define RET_FAIL	false

#define CROSS	2	// 11 - X
#define ZERO	1	// 00 - O
#define EMPTY	0	// 01

#define BIT_COUNT 18

/*win combination X*/
/*
a1|	a2 | a3
--+----+---
b1|	b2 | b3
--+----+---
c1|	c2 | c3
*/
#define WINCOMB_COUNT	8
#define CELL_COUNT		9

#define DOWN_DIAG	0x00030303		//1)	a1 to c3
#define UP_DIAG		0x00003330		//2)	c1 to a3
#define H_LEFT		0x000030C3		//3)	a1 to c1
#define H_MIDDLE	0x0000C30C		//4)	a2 to c2
#define H_RIGHT		0x00030C30		//5)	a3 to c3
#define V_UP		0x0000003F		//6)	a1 to a3
#define V_MIDDLE	0x00000FC0		//7)	b1 to b3
#define V_DOWN		0x0003F000		//8)	c1 to c3
/*end X*/
#define EMPTY_BOARD	0xAAAAAAAA	//empty board

#define SETS_MASK 0x000000003	//0011
#define NON_CROSS	0xFFFFFFFF	//0011
#define NON_ZERO	0x00000000	//0011

const UINT WinComb[WINCOMB_COUNT] = {DOWN_DIAG, UP_DIAG, H_LEFT, H_MIDDLE, H_RIGHT, V_UP, V_MIDDLE, V_DOWN};

struct CBoard 
{
	CCell a1:2;
	CCell a2:2;
	CCell a3:2;

	CCell b1:2;
	CCell b2:2;
	CCell b3:2;

	CCell c1:2;
	CCell c2:2;
	CCell c3:2;

	//reserved bites
	CCell : 6; 
	CCell : 8;
};


//game
void ClrBoard(IN_OUT CBoard& pBoard);
bool SetZero(IN_OUT CBoard& pBoard, IN CCell& Pos);
bool SetCross(IN_OUT CBoard& pBoard, IN CCell& Pos);
bool ZeroWin(IN CBoard& pBoard);
bool CrossWin(IN CBoard& pBoard);

//game engine
void ShowBoard(IN CBoard& pBoard);
void EnterZero(IN_OUT CBoard& pBoard);
void EnterCross(IN_OUT CBoard& pBoard);

#endif /*TICTACTOE_H*/