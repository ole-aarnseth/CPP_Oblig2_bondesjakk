#ifndef CLASS_BOARD_H
#define CLASS_BOARD_H

#include <vector>
#include <string>

namespace gameboard{

	// These are the marks used for the board
	typedef enum{EMPTY, X, O} t_mark;

	class board
	{
		std::vector<std::vector<t_mark> > myBoard;

		public:
			void makeBoard(int size);
			void flushBoard();
			void printBoard();
			void insertMark(unsigned int a, unsigned int b, t_mark m);
			void boardStatus();
	};
}

#endif