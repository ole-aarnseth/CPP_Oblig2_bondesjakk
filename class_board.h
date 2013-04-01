// Navn: Ole Aarnseth
// Studentnr: s180482

#ifndef CLASS_BOARD_H
#define CLASS_BOARD_H

#include <vector>
#include <string>

namespace gameboard{

	// These are the marks used for the board
	typedef enum{EMPTY, X, O} t_mark;

	// These are used as gamestatus-indicators returned by the boardStatus-funkction
	typedef enum{UNFINISHED, XWIN, OWIN, DRAW} t_gamestatus;

	class board
	{
		std::vector<std::vector<t_mark> > myBoard;

		public:
			void makeBoard(int size);
			void flushBoard();
			int getSize();
			void printBoard();
			bool insertMark(unsigned int a, unsigned int b, t_mark m);
			t_gamestatus boardStatus();
	};
}

#endif