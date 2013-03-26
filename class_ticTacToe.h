#ifndef CLASS_TICTACTOE_H
#define CLASS_TICTACTOE_H

#include "class_board.h"

namespace tttGame{

	class ticTacToe
	{
		gameboard::board theBoard;

		public:
			ticTacToe();
			void inputMark(int type);
			void start();
			void playRound();
	};
}

#endif