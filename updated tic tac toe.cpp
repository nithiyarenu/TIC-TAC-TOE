#include <iostream>
using namespace std;

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int player1Score = 0;
int player2Score = 0;

void board();
int checkwin();
void instructions();
void resetBoard();

int main() {
    int choice;
    do {
        system("cls");
        cout << "**************************\n";
        cout << "*      TIC TAC TOE       *\n";
        cout << "**************************\n";
        cout << "1. Start New Game\n";
        cout << "2. Instructions\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int player = 1, i, choice;
                char mark;
                resetBoard();
                do {
                    board();
                    player = (player % 2) ? 1 : 2;

                    cout << "Player " << player << ", enter your choice: ";
                    cin >> choice;

                    mark = (player == 1) ? 'X' : 'O';

                    if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
                        square[choice] = mark;
                    } else {
                        cout << "Invalid move!";
                        player--;
                        cin.ignore();
                        cin.get();
                    }
                    i = checkwin();
                    player++;
                } while (i == -1);

                board();
                if (i == 1) {
                    cout << "==>\a Player " << --player << " wins!";
                    if (player == 1) {
                        player1Score++;
                    } else {
                        player2Score++;
                    }
                } else {
                    cout << "==>\a Game draw";
                }
                cout << "\n\nScore:\nPlayer 1: " << player1Score << "\nPlayer 2: " << player2Score << endl;
                cin.ignore();
                cin.get();
                break;
            }
            case 2:
                instructions();
                break;
            case 3:
            	cout << "\033[1;34m";
                cout << "Exiting the game. Goodbye!" << endl;
                cout << "\033[0m";
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}

void board() {
    system("cls");
    cout << "\033[1;34m"; // Set text color to blue
    cout << "\n**************************\n";
    cout << "*      TIC TAC TOE       *\n";
    cout << "**************************\n";
    cout << "\033[0m"; // Reset text color
    cout << "PLAYER 1 (\033[1;31mX\033[0m) - PLAYER 2 (\033[1;32mO\033[0m) \n" << endl;
    cout << "     |     |     " << endl;
    for (int i = 1; i <= 9; i++) {
        if (square[i] == 'X')
            cout << "  \033[1;31m" << square[i] << "\033[0m"; // Red for X
        else if (square[i] == 'O')
            cout << "  \033[1;32m" << square[i] << "\033[0m"; // Green for O
        else
            cout << "  " << square[i];
        if (i % 3 == 0) {
            cout << "  \n";
            if (i != 9)
                cout << "_____|_____|_____\n";
            else
                cout << "     |     |     \n";
        } else {
            cout << "  |";
        }
    }
    cout << endl;
}

int checkwin() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void instructions() {
    system("cls");
    cout << "**************************\n";
    cout << "*      INSTRUCTIONS      *\n";
    cout << "**************************\n";
    cout << "1. The game is played on a 3x3 grid.\n";
    cout << "2. Player 1 uses 'X' and Player 2 uses 'O'.\n";
    cout << "3. Players take turns to place their marks in an empty square.\n";
    cout << "4. The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.\n";
    cout << "5. If all 9 squares are filled and no player has 3 marks in a row, the game is a draw.\n";
    cout << "Press Enter to return to the menu.";
    cin.ignore();
    cin.get();
}

void resetBoard() {
    for (int i = 1; i <= 9; i++) {
        square[i] = '0' + i;
    }
}

