#include "class_board.h"

using namespace gameboard;

board::board(int length) : size(length)
{
	flushBoard();
}

void board::flushBoard()
{
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

void board::printBoard()
{

}

int main()
{
	board theboard(8);

	return 0;
}