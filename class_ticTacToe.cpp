#include "class_ticTacToe.h"
#include <sstream>
#include <iostream>

using namespace tttGame;
using namespace gameboard;

ticTacToe::ticTacToe()
{
	std::string instr;
	int size;

	std::cout << "\nPlease input desired board size: ";
	std::getline(std::cin, instr);
	std::stringstream(instr) >> size;

	theBoard.makeBoard(size);
}

void ticTacToe::inputMark(int type)
{
	std::string instr;
	unsigned int x, y;
	t_mark t;
	bool OK = false;

	if (type == 1)
	t = X;

	else
	t = O;

	do
	{
		std::cout << "Please input X,Y coordinates with a comma between: ";
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

void ticTacToe::start()
{
	playRound();
}

void ticTacToe::playRound()
{
	theBoard.printBoard();

	int ibeforeChk = theBoard.getSize() - 1;

	for (int i = 0; i < ibeforeChk; i++)
	{
		std::cout << "\n========Player X========\n";
		inputMark(1);

		theBoard.printBoard();

		std::cout << "\n========Player O========\n";
		inputMark(2);

		theBoard.printBoard();
	}

	t_gamestatus status = theBoard.boardStatus();

	while (status == UNFINISHED)
	{
		std::cout << "\n========Player X========\n";
		inputMark(1);

		theBoard.printBoard();

		std::cout << "\n========Player O========\n";
		inputMark(2);

		theBoard.printBoard();

		status = theBoard.boardStatus();
	}
}