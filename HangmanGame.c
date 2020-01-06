#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int length, count=0, l=0, k=0, test=0, testnew=0;
char space[100], s[100], mistakes[100];
char guess='a';
int main()
{
    int l, flag=0;
    printf("\n*************************HANGMAN GAME*************************\n\n");
    printf("\n#RULES#\n\n\n");
    printf("1: Player 1 will enter a word and Player 2 will guess the word\n\n2: Special characters like '*' '@' are NOT allowed\n\n");
    printf("3: Both the players can only enter lower case alphabets\n\n");
    printf("4: Player 2 can only enter one character at a time\n\n");
    printf("5: Player 2 will get 8 lives\n\n");
    printf("6: Player 1 can only enter meaningful words\n\n\n");
    printf("Player 1 enter the word:- ");
    gets(s);
    length=strlen(s);
    system("cls");
    for(int j=49;j<length+49;j++)
    {
        space[j-48]='*';
    }
    l=-1;
//main loop for running the game
    for(int p=0;l==-1;p++)
    {
        screen();
        printf("\n\n\nEnter your guess\n");
        guess=getchar();
        for(int i=1;i<length+1;i++)
        {
            if(guess==s[i-1])
            {
                space[i]=s[i-1];
                flag=1;
            }
        }
        if(flag==0 && p%2==0)
        {
            mistakes[k]=guess;
            k++;
            count++;
        }
        flag=0;
        l=check();
        if(count==8)
        {
            screen();
            l=0;
            break;
        }
    }
    if(l==1)
    {
        printf("\nPLAYER 2 WINS!!!");
    }
    if(l==0)
    {
        printf("\nPLAYER 1 WINS!!!\n");
        printf("\nThe word was ");
        puts(s);
    }
    return 0;
}
//loop for refreshing the screen after each guess
void screen()
{
    int i;
    system("cls");
    printf("\n*************************HANGMAN GAME*************************\n\n");
    for(i=1;i<length+1;i++)
    {
        printf("%c ", space[i]);
    }
    printf("\n");
    for(i=1;i<length+1;i++)
    {
        printf("- ");
    }
    printf("\n\nWrong Guesses: ");
    for(int f=0;mistakes[f]!='\0';f++)
    {
        printf("%c ", mistakes[f]);
    }
    if(count==1)
    {
        printf("\n\n");
        printf("-----------\n7 lives remaining\n");
    }
    if(count==2)
    {
        printf("\n\n");
        printf("-----------\n");
        printf("     |    \n");
        printf("     |    \n6 lives remaining\n");
    }
    if(count==3)
    {
        printf("\n\n");
        printf("-----------\n");
        printf("     |    \n");
        printf("     |    \n");
        printf("   -----\n");
        printf("  | - - |\n");
        printf("  |  -  |");
        printf("\n   ----- \n5 lives remaining\n");
    }
    if(count==4)
    {
        printf("\n\n");
        printf("-----------\n");
        printf("     |    \n");
        printf("     |    \n");
        printf("   -----\n");
        printf("  | - - |\n");
        printf("  |  -  |");
        printf("\n   ----- \n");
        printf("     |    \n");
        printf("     |     \n");
        printf("     |    \n");
        printf("     |    \n4 lives remaining\n");
    }
    if(count==5)
    {
        printf("\n\n");
        printf("-----------\n");
        printf("     |    \n");
        printf("     |    \n");
        printf("   -----\n");
        printf("  | - - |\n");
        printf("  |  -  |");
        printf("\n   ----- \n");
        printf("     |    \n");
        printf("     |\\    \n");
        printf("     |    \n");
        printf("     |    \n3 lives remaining\n");
    }
    if(count==6)
    {
        printf("\n\n");
        printf("-----------\n");
        printf("     |    \n");
        printf("     |    \n");
        printf("   -----\n");
        printf("  | - - |\n");
        printf("  |  -  |");
        printf("\n   ----- \n");
        printf("     |    \n");
        printf("    /|\\    \n");
        printf("     |    \n");
        printf("     |    \n2 lives remaining\n");
    }
    if(count==7)
    {
        printf("\n\n");
        printf("-----------\n");
        printf("     |    \n");
        printf("     |    \n");
        printf("   -----\n");
        printf("  | - - |\n");
        printf("  |  -  |");
        printf("\n   ----- \n");
        printf("     |    \n");
        printf("    /|\\    \n");
        printf("     |    \n");
        printf("     |    \n");
        printf("      \\  \n1 life remaining\n");
    }
    if(count==8)
    {
        printf("\n\n");
        printf("-----------\n");
        printf("     |    \n");
        printf("     |    \n");
        printf("   -----\n");
        printf("  | - - |\n");
        printf("  |  -  |");
        printf("\n   ----- \n");
        printf("     |    \n");
        printf("    /|\\    \n");
        printf("     |    \n");
        printf("     |    \n");
        printf("    / \\  \n");
    }
}
//loop for checking the win
int check()
{
    for(int i=1;i<length+1;i++)
    {
        if(space[i]==s[i-1])
        {
            continue;
        }
        return -1;
    }
    screen();
    return 1;
}
