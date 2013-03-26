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

	std::cout << "Please input X coordinate: ";
	std::getline(std::cin, instr);
	std::stringstream(instr) >> x;

	std::cout << "Please input Y coordinate: ";
	std::getline(std::cin, instr);
	std::stringstream(instr) >> y;

	if (type == 1)
	theBoard.insertMark(x, y, X);

	else
	theBoard.insertMark(x, y, O);
}

void ticTacToe::start()
{
	playRound();
}

void ticTacToe::playRound()
{
	int in;

	theBoard.printBoard();

	do
	{
		std::cout << "\n========Player X========\n";
		inputMark(1);

		std::cout << "\n========Player O========\n";
		inputMark(2);

		theBoard.printBoard();

		std::string instr;
		std::cout << "Would you like to input more?: ";
		std::getline(std::cin, instr);
		std::stringstream(instr) >> in;
	} while (in == 1);
}