#include <iostream>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};

void printBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

// 'X' ya 'o'= winner, 'D' = draw, ' '= game chal raha hai
char checkWinner() {
int lines[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};
for (int i = 0; i < 8; i++) {
    int a = lines[i][0], b = lines[i][1], c = lines[i][2];
    if (board[a] == board[b] && board[b] == board[c])
    return board[a];
}
for (int i = 0; i < 9; i++)
if (board[i] != 'X' && board[i] != 'o')
return ' ';
return 'D';
}
int main() {
    char player = 'X';
    int pos;
    while (true) {
        printBoard();
        cout << "Player " << player << ", position (1-9): ";
        cin >> pos;
        if (cin.fail() || pos < 1 || pos > 9 || board[pos - 1] == 'X' || board[pos -1] == 'o') {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Galat move, dobara try kar.\n";
            continue;
}

board[pos - 1] = player;
char result = checkWinner();
if (result == 'X' || result == 'o') {

    printBoard();
    cout << "player " << result << " jeet gaya!\n";
    break;
}
if (result == 'D') {
    printBoard();
    cout << "draw ho gaya!\n";
    break;
}

player = (player == 'X') ? 'o' : 'X';
    }
    return 0;
}