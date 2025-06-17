#include <iostream>
using namespace std;

char grid[3][3];
char turn;

void reset() {
    char symbol = '1';
    for(int x = 0; x < 3; x++)
        for(int y = 0; y < 3; y++)
            grid[x][y] = symbol++;
    turn = 'X';
}

void show() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << grid[i][j];
            if(j != 2) cout << " | ";
        }
        cout << "\n";
        if(i != 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool update(int pos) {
    int r = (pos - 1) / 3;
    int c = (pos - 1) % 3;

    if(grid[r][c] != 'X' && grid[r][c] != 'O') {
        grid[r][c] = turn;
        return true;
    }
    return false;
}

bool winner() {
    for(int i = 0; i < 3; i++) {
        if((grid[i][0] == turn && grid[i][1] == turn && grid[i][2] == turn) ||
           (grid[0][i] == turn && grid[1][i] == turn && grid[2][i] == turn))
            return true;
    }
    if((grid[0][0] == turn && grid[1][1] == turn && grid[2][2] == turn) ||
       (grid[0][2] == turn && grid[1][1] == turn && grid[2][0] == turn))
        return true;

    return false;
}

bool tie() {
    for(int a = 0; a < 3; a++)
        for(int b = 0; b < 3; b++)
            if(grid[a][b] != 'X' && grid[a][b] != 'O')
                return false;
    return true;
}

void swapTurn() {
    turn = (turn == 'X') ? 'O' : 'X';
}

void run() {
    int sel;
    bool over = false;
    reset();

    while(!over) {
        show();
        cout << "Move for " << turn << " (1-9): ";
        cin >> sel;

        if(sel < 1 || sel > 9 || !update(sel)) {
            cout << "Retry! Invalid slot.\n";
            continue;
        }

        if(winner()) {
            show();
            cout << turn << " has won the game!\n";
            over = true;
        } else if(tie()) {
            show();
            cout << "Match is a draw.\n";
            over = true;
        } else {
            swapTurn();
        }
    }
}

int main() {
    char replay;
    do {
        run();
        cout << "Restart game? (y/n): ";
        cin >> replay;
    } while(replay == 'y' || replay == 'Y');
    return 0;
}
