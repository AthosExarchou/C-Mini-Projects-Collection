/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* global variables */
char board[3][3]; //tic-tac-toe board
const char PLAYER = 'X'; //player's symbol
const char COMPUTER = 'O'; //computer's symbol

/* functions */
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


int main(int argc, char** argv) {

    /* holds the winner ('X' for player, 'O' for computer, ' ' for tie or ongoing game) */
    char winner = ' ';
    char response; //response for replaying the game
    
    do
    {
        winner = ' '; //resets winner for each new game
        resetBoard(); //resets the game board at the start of each game

        /* Main game loop: continues until there's a winner or no free spaces left */
        while (winner == ' ' && checkFreeSpaces() != 0) {

            printBoard(); //displays the current game board

            playerMove(); //lets the player make a move
            winner = checkWinner(); //checks if the player won
            if (winner != ' ' || checkFreeSpaces() == 0) {
                break; //exits loop if there's a winner or no free spaces left
            }

            computerMove(); //lets the computer make a move
            winner = checkWinner(); //checks if the computer won
            if (winner != ' ' || checkFreeSpaces() == 0) {
                break; //exits loop if there's a winner or no free spaces left
            }
        }
        
        printBoard(); //prints the final board after the game ends
        printWinner(winner); //prints the winner of the game

        /* asks the player if they want to play again */
        printf("Would you like to play again? (Y/N): ");
         /* reads the user's response, with leading space to clear any leftover newline character */
        scanf(" %c", &response);
        response = toupper(response); //converts the response to uppercase for consistency

    } while (response == 'Y'); //repeats the game loop if the user enters 'Y' (yes)
   
    printf("Thanks for playing!\n"); //prints thank you message when exiting

    return 0; //end of program
}

/* Function to reset the board to its initial empty state */
void resetBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' '; //initializes all positions to empty space
        }
    }
}

/* Function to display the current state of the game board */
void printBoard() {
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/* Function to check the number of free spaces left on the board */
int checkFreeSpaces() {
    int freeSpaces = 9; //total spaces on the board (3x3)
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != ' ') { //if the space is already filled
                freeSpaces--; //decreases the count of free spaces
            }
        }
    }
    return freeSpaces; //returns the number of free spaces
}

/* Function to handle the player's move */
void playerMove() {

    int x, y; //row and column input for the player's move

    /* Loop until the player makes a valid move */
    do {
        printf("Enter row #(1-3): ");
        scanf("%d", &x); //reads row number (1-3)
        x--; //adjusts for zero-indexed array

        printf("Enter column #(1-3): ");
        scanf("%d", &y); //reads row number (1-3)
        y--; //adjusts for zero-indexed array

        /* checks if the selected spot is free */
        if (board[x][y] != ' ') {
            printf("Invalid move!\n"); //informs the player
        } else {
            board[x][y] = PLAYER; //places the player's mark on the board
            break; //exits the loop after a valid move
        }
    } while (board[x][y] != ' '); //repeats until a valid move is made

}

/* Function to handle the computer's move */
void computerMove() {

    /* random number generator seed with the current time */
    srand(time(NULL));
    int x, y; //row and column for the computer's move

    /* makes a move only if there are free spaces available */
    if (checkFreeSpaces() > 0) {
        do {
            x = rand() % 3; //random row (0-2)
            y = rand() % 3; //random column (0-2)
        } while(board[x][y] != ' '); //ensures the selected spot is free

        board[x][y] = COMPUTER; //places the computer's mark on the board
    } else {
        printWinner(' '); //if no spaces are left, it's a tie
    }
}

/* Function to check if there's a winner */
char checkWinner() {
    /* checks rows for a winner */
    for (int i = 0; i < 3; i++) {

        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0]; //returns the winner ('X' or 'O')
        }

    }

    /* checks columns for a winner */
    for (int i = 0; i < 3; i++) {

        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i]; //returns the winner ('X' or 'O')
        }

    }
    
    /* checks diagonals for a winner */
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0]; //returns the winner ('X' or 'O')
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2]; //returns the winner ('X' or 'O')
    }

    return ' '; //returns ' ' if there is no winner yet

}

/* Function to print the result of the game */
void printWinner(char winner) {

    if (winner == PLAYER) {

        printf("YOU WIN!\n"); //player wins

    } else if (winner == COMPUTER) {

        printf("YOU LOSE!\n"); //computer wins

    } else {
        printf("IT'S A TIE!\n"); //tie
    }
}
