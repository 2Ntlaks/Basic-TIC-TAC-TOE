#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//making these data's to be global so that any function can access them
char square[10] ={'0','1','2','3','4','5','6','7','8','9'};
int choice,player;

//function prototypes
int checkingForWin();
void displayBoard();
void MarkBoard(char mark);

int main()
{
    int gameStatus = 0;
    char mark;

    do
    {
        displayBoard(); // DISPLAY BOARD TO THE CONSOLE

        player = (player % 2) ? 1 : 2; // toggle player between 1 and 2

        printf("Player %d, enter a number: ",player);
        scanf("%d",&choice);

        mark = (player == 1) ? 'X' : 'O'; // IF PLAYER IS 1 WE WILL ASSIGN X OTHERWISE ASSIGN 0

        //set board based on user choice or invalid choice
        MarkBoard(mark);

        gameStatus = checkingForWin();

        player++;



    }while(gameStatus == -1);

    if(gameStatus == 1){
        printf("==>\aPlayer %d win ", --player);
    }
    else{
        printf("==>\aGame draw");
    }

    //displayBoard();
    return 0;
}
/*fUNCTION TO RETURN THE GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IN PROGRESS
0 FOR GAME IS OVER AND NO RESULT
*/
int checkingForWin()
{
    int returnValue = 0;
    if(square[1] == square[2] && square[2] == square[3])
    {
       returnValue = 1;
    }
    else if(square[4] == square[5] && square[5] == square[6])
    {
        returnValue = 1;
    }
        else if(square[7] == square[8] && square[8] == square[9])
    {
        returnValue = 1;
    }
        else if(square[1] == square[4] && square[4] == square[7])
    {
        returnValue = 1;
    }
        else if(square[2] == square[5] && square[5] == square[8])
    {
        returnValue = 1;
    }
        else if(square[3] == square[6] && square[6] == square[9])
    {
        returnValue = 1;
    }
        else if(square[1] == square[5] && square[5] == square[9])
    {
        returnValue = 1;
    }
        else if(square[3] == square[5] && square[5] == square[7])
    {
        returnValue = 1;
    }
        else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9' )
        {
            returnValue = 0;
        }
        else{
        returnValue = -1;
    }
   return returnValue;
}

//Function to draw the board of tic tac toe with players mark
void displayBoard()
{
    system("cls");

    printf("\n\n\tTIC TAC TOE\n\n");

    printf("Player 1(X) - Player 2 (0)\n\n\n");

    printf("          |       |    \n");
    printf("     %c    |    %c  |  %c\n",square[1],square[2],square[3]);

    printf("__________|_______|______\n");
    printf("          |       |      \n");

    printf("          |       |    \n");
    printf("     %c    |    %c  |  %c\n",square[4],square[5],square[6]);

    printf("__________|_______|______\n");
    printf("          |       |      \n");

    printf("          |       |    \n");
    printf("     %c    |    %c  |  %c\n",square[7],square[8],square[9]);

    printf("          |       |    \n\n");
}
// set the board with the correct character, x or o in the correct spot in the array
void MarkBoard(char mark)
{
    if(choice == 1 && square[1] == '1')
    {
        square[1] = mark;
    }
    else if(choice == 2 && square[2] == '2')
    {
        square[2] = mark;
    }
    else if(choice == 3 && square[3] == '3')
    {
        square[3] = mark;
    }
    else if(choice == 4 && square[4] == '4')
    {
        square[4] = mark;
    }
    else if(choice == 5 && square[5] == '5')
    {
        square[5] = mark;
    }
    else if(choice == 6 && square[6] == '6')
    {
        square[6] = mark;
    }
    else if(choice == 7 && square[7] == '7')
    {
        square[7] = mark;
    }
    else if(choice == 8 && square[8] == '8')
    {
        square[8] = mark;
    }
    else if(choice == 9 && square[9] == '9')
    {
        square[9] = mark;
    }
    else
    {
        printf("Invalid move ");

        player--;
        //getchar();
    }
}
