// Navn: Ole Aarnseth
// Studentnr: s180482

#ifndef CLASS_TICTACTOE_H
#define CLASS_TICTACTOE_H

#include "class_board.h"

namespace tttGame{

	class ticTacToe
	{
		gameboard::board theBoard;

		public:
			ticTacToe();
			void inputMark(int turn);
			void playRound();
	};
}

#endif