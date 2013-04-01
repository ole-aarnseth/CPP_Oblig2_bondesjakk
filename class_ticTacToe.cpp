// Navn: Ole Aarnseth
// Studentnr: s180482

#include "class_ticTacToe.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <iostream>

using namespace tttGame;
using namespace gameboard;

ticTacToe::ticTacToe()
{
	std::string instr;
	int size;

	std::cout << "\n======================= Welcome to C++ Tic-Tac-Toe =======================\n\nBefore we begin, please input desired board size (8-66): ";
	std::getline(std::cin, instr);
	std::stringstream(instr) >> size;

	theBoard.makeBoard(size);
}

void ticTacToe::inputMark(int turn)
{
	std::string instr;
	unsigned int x, y;
	t_mark t;
	bool OK = false;

	if (turn % 2 == 0)
	{
		std::cout << "\n================= PLAYER 'X' INPUT MARK =================";
		t = X;
	}

	else
	{
		std::cout << "\n================= PLAYER 'O' INPUT MARK =================";
		t = O;
	}

	do
	{
		std::cout << "\n\nPlease input coordinates for new mark [x,y]: ";
		std::getline(std::cin, instr);

		if (instr.length() < 3)
		continue;

		if (instr.at(1) == ',')
		{
			if (instr.length() == 3)
			{
				x = instr.at(0) - '0';
				y = instr.at(2) - '0';
			}

			else if (instr.length() == 4)
			{
				x = instr.at(0) - '0';
				unsigned int a, b;
				a = instr.at(2) - '0';
				b = instr.at(3) - '0';
				y = (a * 10) + b;
			}

			else
			continue;
		}

		else if (instr.at(2) == ',')
		{
			if (instr.length() == 4)
			{
				unsigned int a, b;
				a = instr.at(0) - '0';
				b = instr.at(1) - '0';
				x = (a * 10) + b;
				y = instr.at(3) - '0';
			}

			else if (instr.length() == 5)
			{
				unsigned int a, b;
				a = instr.at(0) - '0';
				b = instr.at(1) - '0';
				x = (a * 10) + b;
				a = instr.at(3) - '0';
				b = instr.at(4) - '0';
				y = (a * 10) + b;
			}

			else
			continue;
		}

		else
		continue;

		OK = theBoard.insertMark(x, y, t);
	} while (!OK);
}

void ticTacToe::playRound()
{
	nyRunde:

	theBoard.printBoard();
	srand(time(NULL));

	int turn = (rand() % 2) + 1;

	if (turn == 2)
	std::cout << "\nPlayer X begins first!\n";

	else
	std::cout << "\nPlayer O begins first!\n";

	int iterationsBeforeChk = (theBoard.getSize() * 2) - 1;

	for (int i = 0; i < iterationsBeforeChk; i++)
	{
		inputMark(turn++);

		theBoard.printBoard();
	}

	t_gamestatus status = theBoard.boardStatus();

	while (status == UNFINISHED)
	{
		inputMark(turn++);

		theBoard.printBoard();

		status = theBoard.boardStatus();
	}

	std::cout << "\n================ END OF ROUND ================\n";

	if (status == XWIN)
	std::cout << "\nPlayer X won the round!\n\n";

	else if (status == OWIN)
	std::cout << "\nPlayer O won the round!\n\n";

	else if (status == DRAW)
	std::cout << "\nAll potetial rows have been blocked and game is unwinnable.\n\n";

	std::string instr;
	std::cout << "Would you like to play a new round? [y/n]: ";
	std::getline(std::cin, instr);

	if (instr.length() > 0 && instr.at(0) == 'y')
	{
		theBoard.flushBoard();
		goto nyRunde;
	}
}