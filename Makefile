CMP=g++ -Wall

all: tictactoe show_msg

tictactoe: main.o class_ticTacToe.o class_board.o
	$(CMP) main.o class_ticTacToe.o class_board.o -o tictactoe

main.o: main.cpp
	$(CMP) -c main.cpp

class_ticTacToe.o: class_ticTacToe.cpp class_ticTacToe.h
	$(CMP) -c class_ticTacToe.cpp class_ticTacToe.h

class_board.o: class_board.cpp class_board.h
	$(CMP) -c class_board.cpp class_board.h

show_msg:
	@echo Type \'./tictactoe\' to execute program
	
clean:
	rm -f *.o tictactoe