/*
Name: Gideon Shachar
Id: 204713689
Description: noughts and crosses - game of two players, one of them will be 'x' and the other will be
'o'. the goal of the players is to be the first to complete one column, line or a diagonal and this
player will be the winner and then the game will end in a victory. if the board will be filled with
the signs before a player win there will be a tie between the players.
*/
#include<iostream>
using namespace std;

struct Line { ////line that made from three places 
	char one = ' ';
	char two = ' ';
	char three = ' ';
};
struct Board {////board that made from three lines
	Line A;
	Line B;
	Line C;
};
bool existence(char line, int column, Board board); /////checking if the place is taken
char completeLine(Board board, char sign); ///// check if there is strait line
char completeColumn(Board board, char sign); //// check if there is strait column
char completeDiagonal(Board board, char sign); //// check if there is a strait diagonal
void printBoard(Board board); /////printing the current situation of the board
Board getInBoard(Board NoughtsAndCrosses, char line, int column, char sign); ///put player chose in the table

int main() {
	Board NoughtsAndCrosses;
	int numberOfTurns = 0, column;
	char line, winner = ' ';
	bool gameIsOn = true;
	printBoard(NoughtsAndCrosses);
	while (gameIsOn == true) {
		if ((numberOfTurns % 2) == 0) { /////first player turn
			cout << endl;
			cout << "player number one please chose your next move as (x)" << endl;
			cin >> line >> column;
			cout << endl;
			while (existence(line, column, NoughtsAndCrosses) == true) {///check if place already taken
				cout << "sorry but this place is already taken," << endl;
				cout << "please pick another place.." << endl;
				cin >> line >> column;
			}
			NoughtsAndCrosses = getInBoard(NoughtsAndCrosses, line, column, 'x');
			printBoard(NoughtsAndCrosses);
			if (completeLine(NoughtsAndCrosses, 'x') == 'x')
				winner = 'x';
			if (completeColumn(NoughtsAndCrosses, 'x') == 'x')
				winner = 'x';
			if (completeDiagonal(NoughtsAndCrosses, 'x') == 'x')
				winner = 'x';
		}
		else { //////second player turn 
			cout << endl;
			cout << "player number two please chose your next move as (o)" << endl;
			cin >> line >> column;
			cout << endl;
			while (existence(line, column, NoughtsAndCrosses) == true) {///check if place already taken
				cout << "sorry but this place is already taken," << endl;
				cout << "please pick another place.." << endl;
				cin >> line >> column;
			}
			NoughtsAndCrosses = getInBoard(NoughtsAndCrosses, line, column, 'o');
			printBoard(NoughtsAndCrosses);
			if (completeLine(NoughtsAndCrosses, 'o') == 'o')
				winner = 'o';
			if (completeColumn(NoughtsAndCrosses, 'o') == 'o')
				winner = 'o';
			if (completeDiagonal(NoughtsAndCrosses, 'o') == 'o')
				winner = 'o';
		}
		numberOfTurns++;
		if (numberOfTurns == 9)
			gameIsOn = false;
		if ((winner == 'x') || (winner == 'o'))
			gameIsOn = false;
	}
	if ((winner != 'x')&&(winner != 'o'))
		cout << "The game end with a tie, good luck next time!" << endl;
	else
		cout << "the winner is:" << " " << winner << " " << "good job" << endl;
	system("pause");
	return 0;
}

bool existence(char line, int column, Board board) { /////checking if the place is taken
	if (line > 'C' || line < 'A')
		return true;
	if (column > 3 || column < 1)
		return true;
	if ((line == 'A') && (column == 1)) {
		if (board.A.one != ' ')
			return true;
	}
	if ((line == 'A') && (column == 2)) {
		if (board.A.two != ' ')
			return true;
	}
	if ((line == 'A') && (column == 3)) {
		if (board.A.three != ' ')
			return true;
	}
	if ((line == 'B') && (column == 1)) {
		if (board.B.one != ' ')
			return true;
	}
	if ((line == 'B') && (column == 2)) {
		if (board.B.two != ' ')
			return true;
	}
	if ((line == 'B') && (column == 3)) {
		if (board.B.three != ' ')
			return true;
	}
	if ((line == 'C') && (column == 1)) {
		if (board.C.one != ' ')
			return true;
	}
	if ((line == 'C') && (column == 2)) {
		if (board.C.two != ' ')
			return true;
	}
	if ((line == 'C') && (column == 3)) {
		if (board.C.three != ' ')
			return true;
	}
	return false;
}
char completeLine(Board board, char sign) {///// check if there is strait line
	char winner = '/';
	if ((board.A.one == sign) && (board.A.two == sign) && (board.A.three == sign)) {
		winner = sign;
		return winner;
	}
	if ((board.B.one == sign) && (board.B.two == sign) && (board.B.three == sign)) {
		winner = sign;
		return winner;
	}
	if ((board.C.one == sign) && (board.C.two == sign) && (board.C.three == sign)) {
		winner = sign;
		return winner;
	}
	else
		return winner;
}
char completeColumn(Board board, char sign) {//// check if there is strait column
	char winner = '/';
	if ((board.A.one == sign) && (board.B.one == sign) && (board.C.one == sign)) {
		winner = sign;
		return winner;
	}
	if ((board.A.two == sign) && (board.B.two == sign) && (board.C.two == sign)) {
		winner = sign;
		return winner;
	}
	if ((board.A.three == sign) && (board.B.three == sign) && (board.C.three == sign)) {
		winner = sign;
		return winner;
	}
	else
		return winner;
}
char completeDiagonal(Board board, char sign) {//// check if there is a strait diagonal
	char winner = '/';
	if ((board.A.one == sign) && (board.B.two == sign) && (board.C.three == sign)) {
		winner = sign;
		return winner;
	}
	if ((board.A.three == sign) && (board.B.two == sign) && (board.B.one == sign)) {
		winner = sign;
		return winner;
	}
	else
		return winner;
}
void printBoard(Board board) {/////printing the current situation of the board
	cout << " " << " " << 1 << " " << 2 << " " << 3 << endl;
	cout << "A" << " " << board.A.one << " " << board.A.two << " " << board.A.three << " " << endl;
	cout << "B" << " " << board.B.one << " " << board.B.two << " " << board.B.three << " " << endl;
	cout << "C" << " " << board.C.one << " " << board.C.two << " " << board.C.three << " " << endl;
}
Board getInBoard(Board NoughtsAndCrosses, char line, int column, char sign) {///put player chose in the table
	if ((line == 'A') && (column == 1))
		NoughtsAndCrosses.A.one = sign;
	if ((line == 'A') && (column == 2))
		NoughtsAndCrosses.A.two = sign;
	if ((line == 'A') && (column == 3))
		NoughtsAndCrosses.A.three = sign;
	if ((line == 'B') && (column == 1))
		NoughtsAndCrosses.B.one = sign;
	if ((line == 'B') && (column == 2))
		NoughtsAndCrosses.B.two = sign;
	if ((line == 'B') && (column == 3))
		NoughtsAndCrosses.B.three = sign;
	if ((line == 'C') && (column == 1))
		NoughtsAndCrosses.C.one = sign;
	if ((line == 'C') && (column == 2))
		NoughtsAndCrosses.C.two = sign;
	if ((line == 'C') && (column == 3))
		NoughtsAndCrosses.C.three = sign;
	return NoughtsAndCrosses;
}