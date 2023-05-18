#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
int genrandnum()
{
    srand(time(0)); // srand takes seed as an input and is defined inside stdlib.h
    return rand()%3+1;
}
int main()
{
    char str[15];
    int cpguess;
    int userguess, ptuser=0, ptcp=0;
    //printf("%d", cpnum);
    printf("*************************************************\n");
    printf("\t~~~~~~~  Welcome  ~~~~~~~\n\n");
    printf("\t~~~ ROCK PAPER SCISSORS ~~~\n\n");
    printf("Loading Please Wait.... \n");
    sleep(4);
    printf("Enter your name : \n");
    gets(str);
    fflush(stdin);
    printf("\nINSTRUCTIONS : \n");
    printf("--->> In this game you have to select any one from : Rock, paper, scissor\n");
    printf("--->> If rock vs scissors -- rock wins\n--->> If paper vs scissors -- scissor wins \n--->> If paper vs rock -- paper wins\n");
    printf("--->> You get 3 chances out of those who scores highest will be the winner \n\n");
    sleep(5);
    printf("~~~~~~~~~~  All the best!  ~~~~~~~~~~\n\n");
    sleep(2);
    printf("~~~~~~~~~~ Lets start the game ~~~~~~~~~~\n");
    sleep(2);
    for (int i = 0; i < 3; i++)
    {
        cpguess = genrandnum();
        printf("%d CHANCE : \n\n", i+1);
        printf("--->> Press 1 to rock\n");
        printf("--->> Press 2 to paper\n");
        printf("--->> Press 3 to scissor\n");
        printf("--->> Press 0 to exit\n");
        puts(str);
        printf("Turn : \n");
        scanf("%d", &userguess);
        sleep(1);
        if (userguess != 0)
        {
            printf("--->> Press 1 to rock\n");
            printf("--->> Press 2 to paper\n");
            printf("--->> Press 3 to scissor\n");
            printf("--->> Press 0 to exit\n");
            printf("Computer Turn :\n");
            sleep(2);
            printf("%d\n", cpguess);
            sleep(1);
        }
        if (userguess == cpguess)
        {
            printf("Computer selected : %d option\n", cpguess);
            printf("Game tied \n");
            printf("0 points to both \n\n");

        }
        else if (userguess == 1 && cpguess == 3)
        {
            printf("Computer selected : %d Scissor\n", cpguess);
            printf("%s got 1 point\n\n", str);
            ptuser++;
        }
        else if (userguess == 2 && cpguess == 1)
        {
            printf("Computer selected : %d Rock\n", cpguess);
            printf("%s got 1 point\n\n", str);
            ptuser++;
        }
        else if (userguess == 3 && cpguess == 2)
        {
            printf("Computer selected : %d Paper\n", cpguess);
            printf("%s got 1 point\n\n", str);
            ptuser++;
        }
        else if (userguess == 0)
        {
            break;
        }
        else if (userguess > 3) {
            printf("Wrong input given\n");
            printf("Please enter values from 0-3 only\n");
        }
        else
        {
            printf("Computer selected : %d Option \n", cpguess);
            printf("Computer won\n");
            printf("%s lost :( \n\n", str);
            ptcp++;
        }
        sleep(2);
    }
    if (ptuser > ptcp)
    {
        printf("\nRESULT BOARD : \n");
        printf("\tYAY!!!!\n");
        sleep(1);
        printf("-- %s GOT %d POINTS. \n-- YOU WON !\n", str, ptuser);
        printf("*************************************************\n");
    }
    else if (ptuser == ptcp)
    {
        printf("\nRESULT BOARD : \n");
        sleep(1);
        printf("-- %s GOT %d POINTS. \n-- YOU WON !\n", str, ptuser);
        printf("*************************************************\n");
        
    }
    else if (userguess == 0)
    {
        printf("QUTTING......");
        sleep(1);
    }
    else
    {
        printf("\nRESULT BOARD : \n");
        printf("-- COMPUTER GOT %d POINTS\n", ptcp);
        printf("-- %s LOST :(\n\n", str);
        printf("\tBETTER LUCK NEXT TIME...\n");
        printf("*************************************************\n");
    }
    return 0;
}