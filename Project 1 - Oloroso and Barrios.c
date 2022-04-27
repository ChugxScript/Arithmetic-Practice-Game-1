/*Project 1 - Arithmetic Practice Game in C using Array of structures
Made By Oloroso, Andrew R. and Barrios, Armand Angelo C.*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define MAX 50

//Array Structure
typedef struct playerRec{
    int addition,subtraction,division,multiplication;
    char name[69];
    char pass[69];
}SREC;
SREC PLAYER[MAX];

//Functions definitions
void logIn(SREC *pl);
void verify(SREC pl);
int locate(char n[69]);
void init();
void TitleScreen();
int menu();
void GetLevel();
void addition (int n);
void subtraction (int n);
void division (int n);
void multiplication (int n);
void score();
void save();
void retrieve();
void box();
void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//Global Variables
int items,counter,num,marker,level;
char c;

int main(){
    SREC player;
    srand(time(NULL));
    init();
    retrieve();
    logIn(&player);
    verify(player);
    system("cls");
    TitleScreen();
    while(1){
        switch(menu()){
            case 1: GetLevel();
                    addition(items);
                    break;
            case 2: GetLevel();
                    subtraction(items);
                    break;
            case 3: GetLevel();
                    division(items);
                    break;
            case 4: GetLevel();
                    multiplication(items);
                    break;
            case 5: save();
                    exit(0);
                    break;
            default:system("cls");
                    gotoxy(40,5);printf("Numbers 1-5 only.");
                    gotoxy(40,6);system("pause");
                    break;
        }
    }
}

void init(){
    marker = -1;
}
void box(){
    int i;
    int l = 186, ul=201,ur=187,w=205,dr=188,dl=200;
    gotoxy(40,5);printf("%c", ul);
    gotoxy(90,5);printf("%c", ur);
    gotoxy(90,13);printf("%c", dr);
    gotoxy(40,13);printf("%c", dl);
    for (i=0;i<=6;i++){
         gotoxy(40,6+i);printf("%c", l);
         gotoxy(90,6+i);printf("%c", l);
    }
    for (i=0;i<49;i++){
        gotoxy(41+i,5);printf("%c", w);
        gotoxy(41+i,13);printf("%c", w);
    }
}

void logIn(SREC *pl){
    system("cls");
    box();
    gotoxy(45,6);printf("Enter Username/UserID: ");
    scanf(" %[^\n]s", pl->name);
    gotoxy(45,7);printf("Enter Password: ");
    scanf(" %[^\n]s", pl->pass);
}

void verify(SREC pl){
    int x,p;
    //check if array is full
    if (marker == MAX-1){
        printf("Array is Full");
        system("\npause");
    }else{
        //check if name is already in the list
        int l = locate(pl.name);
        if(l > -1){
            system("cls");
            printf("Welcome back %s", pl.name);
            system("\npause");

        }else{
            marker++;
            PLAYER[marker]=pl;
            system("cls");
            printf("A NEW CHALLENGER!");
            printf("\nWelcome to...\n");
            system("pause");
        }
    }
}

int locate(char n[69]){
    for(int x=0;x<=marker;x++)
        if (strcmp(n,PLAYER[x].name)==0)
            return x;
    return -1;
}

void TitleScreen(){
    char game_title[24][101]=
    {
        {"#####################################################################################################"},
        {"#                                                                                                   #"},
        {"#        #       #####    #######  #######  #     #  ###   ###  ######  #######  #######   ######   #"},
        {"#       # #      #    #      #        #     #     #  #  # #  #  #          #        #     #         #"},
        {"#      #   #     #    #      #        #     #######  #   #   #  ####       #        #     #         #"},
        {"#     #######    #####       #        #     #     #  #       #  #          #        #     #         #"},
        {"#    #       #   #    #      #        #     #     #  #       #  #          #        #     #         #"},
        {"#   #         #  #     #  #######     #     #     #  #       #  ######     #     #######   ######   #"},
        {"#                                                                                                   #"},
        {"#                                                                                                   #"},
        {"#           ################              #              ###           ###   ##############         #"},
        {"#          #                             # #             #  #         #  #   #                      #"},
        {"#          #                            #   #            #   #       #   #   #                      #"},
        {"#          #                           #     #           #    #     #    #   #                      #"},
        {"#          #                          #       #          #     #   #     #   #                      #"},
        {"#          #                         #         #         #      # #      #   ##########             #"},
        {"#          #       #########        #############        #       #       #   #                      #"},
        {"#          #               #       #             #       #               #   #                      #"},
        {"#          #               #      #               #      #               #   #                      #"},
        {"#          #               #     #                 #     #               #   #                      #"},
        {"#          #               #    #                   #    #               #   #                      #"},
        {"#           ################   #                     #   #               #   ##############         #"},
        {"#                                                                                                   #"},
        {"#####################################################################################################"}
    };
    // for looop for printing the title screen
    for (int x=0; x<24; x++)
    {
        printf("\t");
        for (int y=0; y<101; y++)
        {
            printf("%c", game_title[x][y]);
        }
        printf("\n");
        system("COLOR 0A");
    }
    gotoxy(40,25);system("pause");
    system("cls");
}

void GetLevel(){
    int l;
    system("cls");
    printf("Select level\n");
    printf("1\n");
    printf("2\n");
    printf("3\n");
    printf("4\n");
    printf("5\n");
    scanf("%d", &l);
    switch (l){
        case 1: level = 10; 
                items = 5; break;
        case 2: level = 20; break;
                items = 10; break;
        case 3: level = 50; break;
                items = 10; break;
        case 4: level = 80; break;
                items = 15; break;
        case 5: level = 100; break;
                items = 15; break;
        default: printf("1-5 only"); break;
    }
}

int menu(){
    system("cls");
    gotoxy(45,3);printf("Arithmetic Practice Game");
    gotoxy(40,6);printf("============= MENU ==============");
    gotoxy(42,8);printf("Press [1] for Addition");
    gotoxy(42,9);printf("Press [2] for Subtraction");
    gotoxy(42,10);printf("Press [3] for Division");
    gotoxy(42,11);printf("Press [4] for Multiplication");
    gotoxy(42,12);printf("Press [5] to Exit");
    gotoxy(40,14);printf("=================================");
    gotoxy(40,16);printf("What operation you want to take? ");
    scanf("%d", &num);
    return num;
}

void addition (int n){
    int x,y,z,answer;
    do{
        counter = 0;
        for (x=0;x<n;x++){
            system("cls");
            //generate random numbers from 1 - level
            y = rand() % level + 1;
            z = rand() % level + 1;
            score();
            gotoxy(40,5);printf("%d.) What is %d + %d? ",x+1,y,z);
            scanf("%d",&answer);
            if(answer == y+z){
                gotoxy(40,6);printf("Correct!");
                counter++;score();
            }else{
                gotoxy(40,6);printf("Wrong. The correct answer is %d.",y+z);
            }
            gotoxy(40,8);system("pause");
        }
        system("cls");
        PLAYER->addition = counter;
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                    save();
                    exit(0);
                }
            if(c == 'y' || c == 'Y'){
                    return menu();
                }
                getch();
            }
    }while(c == 'y' || c == 'Y');
}

void subtraction (int n){
    int x,y,z,answer,temp;
    do{
        counter = 0;
        for (x=0;x<n;x++){
            system("cls");
            //generate random numbers from 1 - level
            y = rand() % level + 1;
            z = rand() % level + 1;
            score();
            if (y>z){
                gotoxy(40,5);printf("%d.) What is %d - %d? ",x+1,y,z);
                scanf("%d",&answer);
                temp=y-z;
            }
            //if Random number 1 is less than random number 2, switch random number 2 so there is no negative answer
            else {
                gotoxy(40,5);printf("%d.) What is %d - %d? ",x+1,z,y);
                scanf("%d",&answer);
                temp=z-y;
            }
            if(answer == temp){
                gotoxy(40,6);printf("Correct!");
                counter++;score();
            }else{
                gotoxy(40,6);printf("Wrong. The correct answer is %d.",temp);
            }
            gotoxy(40,8);system("pause");
        }
        system("cls");
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                    save();
                    exit(0);
                }
            if(c == 'y' || c == 'Y'){
                    return menu();
                }
                getch();
            }
    }while(c == 'y' || c == 'Y');
}

void division (int n){
    int x,y,z,answer,temp;
    do{
        counter = 0;
        for (x=0;x<n;x++){
            system("cls");
            //generate random numbers from 1 - level
            y = rand() % level + 1;
            z = rand() % level + 1;
            score();
            //to have divisible numbers
            temp = y*z;
            y = temp;
            gotoxy(40,5);printf("%d.) What is %d / %d? ",x+1,y,z);
            scanf("%d",&answer);
            if(answer == y/z){
                gotoxy(40,6);printf("Correct!");
                counter++;score();
            }else{
                gotoxy(40,6);printf("Wrong. The correct answer is %d.",y/z);
            }
            gotoxy(40,8);system("pause");
        }
        system("cls");
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                    save();
                    exit(0);
                }
            if(c == 'y' || c == 'Y'){
                    return menu();
                }
                getch();
            }
    }while(c == 'y' || c == 'Y');
}

void multiplication (int n){
    int x,y,z,answer;
    do{
        counter = 0;
        level = diff;
        for (x=0;x<n;x++){
            system("cls");
            //generate random numbers from 1 - level
            y = rand() % level + 1;
            z = rand() % level + 1;
            score();
            gotoxy(40,5);printf("%d.) What is %d x %d? ",x+1,y,z);
            scanf("%d",&answer);
            if(answer == y*z){
                gotoxy(40,6);printf("Correct!");
                counter++;score();
            }else{
                gotoxy(40,6);printf("Wrong. The correct answer is %d.",y*z);
            }
            gotoxy(40,8);system("pause");
        }
        system("cls");
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                    save();
                    exit(0);
                }
            if(c == 'y' || c == 'Y'){
                    return menu();
                }
                getch();
            }
    }while(c == 'y' || c == 'Y');
}

void score(){
    gotoxy(90,2);printf("Score: %d/%d: %6.2f%%",counter,items,(float)counter/items*100);
}

void save(){
    FILE *fp;
    int x;
    fp = fopen("BSCS-1CD-Leaderboard.txt","w+");
    if (fp==NULL){
        printf("Error 404. File not found.\n");
        system("pause");
    }
    else {
        for (x=0;x<=marker;x++)
            fprintf(fp, "%s\t%d %d %d %d\n",PLAYER[x].name,PLAYER[x].addition,&PLAYER[x].subtraction,&PLAYER[x].division,&PLAYER[x].multiplication);
        fclose(fp);
      }
}

void retrieve(){
    FILE *fp;
    SREC players;
    fp = fopen("BSCS-1CD-Leaderboard.txt","r+");
    if (fp==NULL){
        printf("Error 404.\nBSCS-1CD-Leaderboard.txt File not found.\n");
        system("pause");
    }
    else {
        while (!feof(fp)){
            fscanf(fp," %[^\t]s",players.name);
            fscanf(fp,"%d %d %d %d\n", &players.addition,&players.subtraction,&players.division,&players.multiplication);
            verify(players);
        }
        fclose(fp);
   }
}
