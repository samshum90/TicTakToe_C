#include <stdio.h>
#include <stdlib.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int move, player;

int checkWin();
void displayTiles();
void markTile( char mark);

int main(){

    int status;

    char mark;

    player = 1;

    do 
    {
        displayTiles();
        player = ( player % 2 ) ? 1 : 2;

        printf( "Player %d, choose a number for a tile: ", player );
        scanf( "%d", &move );

        mark = (player == 1 ) ? 'X' : 'O';

        markTile(mark);

        status = checkWin();

        player++;

    } while ( status == -1 );

    if ( status == 1 )
        printf("\aPlayer %d wins!! ", --player);
    else
        printf("\aTie Game");

    return 0;
};

int checkWin()
{
    int output = 0;

    if (square[1] == square[2] && square[2] == square[3])
    {
        output = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        output = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        output = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        output = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        output = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        output = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        output = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        output = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        output = 0;
    else output = -1;

    return output;
};

void displayTiles()
{


    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
};

void markTile(char mark)
{
    if (move == 1 && square[1] == '1')
        square[1] = mark;

    else if (move == 2 && square[2] == '2')
        square[2] = mark;

    else if (move == 3 && square[3] == '3')
        square[3] = mark;

    else if (move == 4 && square[4] == '4')
        square[4] = mark;

    else if (move == 5 && square[5] == '5')
        square[5] = mark;

    else if (move == 6 && square[6] == '6')
        square[6] = mark;

    else if (move == 7 && square[7] == '7')
        square[7] = mark;

    else if (move == 8 && square[8] == '8')
        square[8] = mark;

    else if (move == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("Invalid move ");

        player--;
        getchar();
    }
};