#include <stdio.h>
#include <stdlib.h>

char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void displayBoard();
int checkWin();
int isValidInput(int choice);

int main() {
    int player = 1;
    int choice, i;
    char mark; // X or O

    do {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        printf("Player %d's turn:\n", player);

        do {
            printf("Enter a number (1-9): ");
            if (scanf("%d", &choice) != 1 || !isValidInput(choice)) {
                printf("Invalid input. Please enter a number between 1 and 9.\n");
                while (getchar() != '\n'); // Clear input buffer
            }
        } while (!isValidInput(choice));

        mark = (player == 1) ? 'X' : 'O';
        arr[choice] = mark;

        i = checkWin();
        player++;

    } while (i == -1);

    displayBoard();
    if (i == 1) {
        printf("Player %d Won\n", --player);
    } else {
        printf("Game Draw\n");
    }

    return 0;
}

void displayBoard() {
    system("cls");
    printf("       |       |      \n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[1], arr[2], arr[3]);
    printf("-------|-------|-------\n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[4], arr[5], arr[6]);
    printf("       |       |      \n");
    printf("-------|-------|-------\n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[7], arr[8], arr[9]);
    printf("       |       |      \n");
}

int checkWin() {
    // Rows, Columns, and Diagonals checking
    for (int i = 1; i <= 7; i += 3) {
        if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2])
            return 1;
    }
    for (int i = 1; i <= 3; i++) {
        if (arr[i] == arr[i + 3] && arr[i + 3] == arr[i + 6])
            return 1;
    }
    if ((arr[1] == arr[5] && arr[5] == arr[9]) || (arr[3] == arr[5] && arr[5] == arr[7]))
        return 1;

    // Draw condition
    for (int i = 1; i <= 9; i++) {
        if (arr[i] != (i + '0'))
            break;
        if (i == 9)
            return 0;
    }
    return -1;
}

int isValidInput(int choice) {
    return (choice >= 1 && choice <= 9 && arr[choice] == (choice + '0'));
}
