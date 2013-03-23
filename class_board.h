#ifndef CLASS_BOARD_H
#define CLASS_BOARD_H

#include <vector>
#include <string>

namespace gameboard{

	// There are the marks used for the board
	typedef enum{EMPTY, X, O} t_mark;

	class board
	{
		std::vector<std::vector<t_mark> > myBoard;
		const int size;

		public:
			board(int length);
			void flushBoard();
			void printBoard();
	};
}

#endif