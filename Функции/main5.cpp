#include <iostream>
#include <string>
using namespace std;

bool correctInput(string str) {
    if (str.length() != 3) return false;
    else {
        for (int i = 0; i < 3; i++) {
            if (str[i] != '.' && str[i] != 'O' && str[i] != 'X') {
                return false;
            }
        }
    }
    return true;
}


int checkingRows(string str[], char mark) {
    bool win;
    int winCounter = 0;
    for (int i = 0; i < 3; i++) {
        win = true;
        for (int j = 0; j < 3; j++) {
            if (str[i][j] != mark) {
                win = false;
                break;
            }
        }
        if (win) {
            winCounter++;
        }
    }
    return winCounter;
}

int checkingCols(string str[], char mark) {
    bool win;
    int winCounter = 0;
    for (int i = 0; i < 3; i++) {
        win = true;
        for (int j = 0; j < 3; j++) {
            if (str[j][i] != mark) {
                win = false;
                break;
            }
        }
        if (win) {
            winCounter++;
        }
    }
    return winCounter;
}

int checkingDiagonals(string str[], char mark) {
    int winCounter = 0;

    if (str[1][1] == mark) {
        if (str[0][0] == mark && str[2][2] == mark) {
            winCounter++;
        }
        if (str[0][2] == mark && str[2][0] == mark) {
            winCounter++;
        }
    }
    return winCounter;
}

int gameWon(string str[], char mark) {
    return checkingRows(str, mark) + checkingCols(str, mark) + checkingDiagonals(str, mark);
}

string gameResult(string str[]) {
    int circles = 0, crosses = 0;
    int circleWinCounter = gameWon(str, 'O');
    int crossWinCounter = gameWon(str, 'X');
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (str[i][j] == 'X') crosses++;
            else if (str[i][j] == 'O') circles++;
        }
    }

    int diff = crosses - circles;
    if ((circleWinCounter == 1 && crossWinCounter == 1)
        || (circleWinCounter == 1 && (crosses != circles))
        || (crossWinCounter == 1 && (diff != 1))
        || (circleWinCounter > 1) || (crossWinCounter > 1)
        || (crossWinCounter + circleWinCounter == 0 && (diff != 0 && diff != 1))) {
        return "Incorrect";
    }
    else if (gameWon(str, 'O')) {
        return "Vanya won";
    }
    else if (gameWon(str, 'X')) {
        return "Petya won";
    }
    else {
        return "Nobody";
    }
}


int main() {
    string row[3];
    string str;
    for (int i = 0; i < 3; i++) {
        cin >> str;
        if (!correctInput(str)) {
            cout << "Invalid input";
            return 0;
        }
        row[i] = str;
    }
    cout << gameResult(row);
}