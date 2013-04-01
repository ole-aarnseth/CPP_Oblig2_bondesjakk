// Navn: Ole Aarnseth
// Studentnr: s180482

#include "class_board.h"
#include <iostream>

using namespace gameboard;

void board::makeBoard(int size)
{
	if (size < 8)
	size = 8;

	else if (size > 66)
	size = 66;

	for (int i = 0; i < size; i++)
	{
		std::vector<t_mark> v;
		myBoard.push_back(v);

		for (int j = 0; j < size; j++)
		{
			myBoard[i].push_back(EMPTY);
		}
	}
}

void board::flushBoard()
{
	for (unsigned int i = 0; i < myBoard.size(); i++)
	{
		for (unsigned int j = 0; j < myBoard.size(); j++)
		{
			myBoard[i][j] = EMPTY;
		}
	}
}

int board::getSize()
{
	return myBoard.size();
}

void board::printBoard()
{
	std::cout << "\n   Y\n   |\n   ";

	for (unsigned int i = 0; i < myBoard.size(); i++)
	{
		std::cout << "----";
	}

	std::cout << "-";

	for (int i = myBoard.size() - 1; i > -1; i--)
	{
		std::cout << "\n";

		if (i + 1 < 10)
		std::cout << " ";

		std::cout << i + 1 << " ";

		for (unsigned int j = 0; j < myBoard.size(); j++)
		{
			std::cout << "| ";
			t_mark m = myBoard[i][j];

			if (m == EMPTY)
			std::cout << "  ";

			else if (m == X)
			std::cout << "X ";

			else
			std::cout << "O ";
		}

		std::cout << "|\n   ";

		for (unsigned int g = 0; g < myBoard.size(); g++)
		{
			std::cout << "----";
		}

		std::cout << "-";
	}

	std::cout << "-X\n   ";

	for (unsigned int i = 1; i <= myBoard.size(); i++)
	{
		if (i < 10)
		std::cout << "  " << i << " ";

		else
		std::cout << "  " << i;
	}

	std::cout << "\n";
}

bool board::insertMark(unsigned int a, unsigned int b, t_mark m)
{
	if (a > myBoard.size() || a < 1 || b > myBoard.size() || b < 1)
	{
		std::cout << "\nBad cooradinates, please try again\n";
		return false;
	}

	if (myBoard[--b][--a] == X || myBoard[b][a] == O)
	{
		std::cout << "\nThis space is already marked\n";
		return false;
	}

	myBoard[b][a] = m;

	return true;
}

t_gamestatus board::boardStatus()
{
	unsigned int blocked = 0, Xscore = 0, Oscore = 0;

	// Check all vertical rows

	for (unsigned int x = 0; x < myBoard.size(); x++)
	{
		for (unsigned int y = 0; y < myBoard.size(); y++)
		{
			t_mark t = myBoard[y][x];

			if (t == X)
			Xscore++;

			else if (t == O)
			Oscore++;
		}

		if (Xscore == myBoard.size())
		return XWIN;

		else if (Oscore == myBoard.size())
		return OWIN;

		else if (Xscore > 0 && Oscore > 0)
		blocked++;

		Xscore = 0;
		Oscore = 0;
	}


	// Check all horizontal rows

	for (unsigned int y = 0; y < myBoard.size(); y++)
	{
		for (unsigned int x = 0; x < myBoard.size(); x++)
		{
			t_mark t = myBoard[y][x];

			if (t == X)
			Xscore++;

			else if (t == O)
			Oscore++;
		}

		if (Xscore == myBoard.size())
		return XWIN;

		else if (Oscore == myBoard.size())
		return OWIN;

		else if (Xscore > 0 && Oscore > 0)
		blocked++;

		Xscore = 0;
		Oscore = 0;
	}


	// Check top left to bottom right diagonal

	unsigned int x = 0, y = myBoard.size() - 1;

	for (unsigned int i = 0; i < myBoard.size(); i++)
	{
		t_mark t = myBoard[y--][x++];

		if (t == X)
		Xscore++;

		else if (t == O)
		Oscore++;
	}

	if (Xscore == myBoard.size())
	return XWIN;

	else if (Oscore == myBoard.size())
	return OWIN;

	else if (Xscore > 0 && Oscore > 0)
	blocked++;

	Xscore = 0;
	Oscore = 0;


	// Check bottom left to top right diagonal

	for (unsigned int i = 0; i < myBoard.size(); i++)
	{
		t_mark t = myBoard[i][i];

		if (t == X)
		Xscore++;

		else if (t == O)
		Oscore++;
	}

	if (Xscore == myBoard.size())
	return XWIN;

	else if (Oscore == myBoard.size())
	return OWIN;

	else if (Xscore > 0 && Oscore > 0)
	blocked++;


	// Check if all potential rows are blocked

	if (blocked == (myBoard.size() * 2) + 2)
	return DRAW;

	return UNFINISHED;
}