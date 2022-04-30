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
    int plus,minus,divide,multiply;
    char name[69];
    char pass[69];
}SREC;
SREC PLAYER[MAX];

//Functions definitions
void logIn();
void AddRec(SREC pl);
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
    srand(time(NULL));
    init();
    retrieve();
    logIn();
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

void logIn(){
    SREC player;
    system("cls");
    box();
    gotoxy(45,6);printf("Enter Username/UserID: ");
    scanf(" %[^\n]s", player.name);
    //check if name is already in the list
    int l = locate(player.name);
    if(l > -1){
            here:
            system("cls");
            box();
            gotoxy(45,6);printf("Welcome back %s!", player.name);
            gotoxy(45,7);printf("Enter Password: ");
            scanf(" %[^\n]s", player.pass);
            for(int x=0;x<=marker;x++){
                if (strcmp(player.pass,PLAYER[x].pass)==0){
                    gotoxy(45,9);system("pause");
                }else{
                    gotoxy(45,9);printf("Wrong password.");
                    gotoxy(45,11);system("pause");
                    goto here;
                }
            }
        }else{
            marker++;
            strcpy (PLAYER[marker].name,player.name);
            system("cls");
            box();
            gotoxy(45,6);printf("A NEW CHALLENGER!");
            gotoxy(45,7);printf("Enter Password: ");
            scanf(" %[^\n]s", player.pass);
            strcpy (PLAYER[marker].pass,player.pass);
            gotoxy(45,12);system("pause");
        }
}

void AddRec(SREC pl){
    //check if array is full
    if (marker == MAX-1){
        printf("Array is Full");
        system("\npause");
    }else{
        marker++;
        PLAYER[marker]=pl;
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
    int l,c=254,t=175;
    system("cls");
    gotoxy(45,5);printf("%c",t);printf(" Select level\n");
    gotoxy(45,6);printf("%c",c);printf(" Level 1: Very Easy\n");
    gotoxy(45,7);printf("%c",c);printf(" Level 2: Easy\n");
    gotoxy(45,8);printf("%c",c);printf(" Level 3: Medium\n");
    gotoxy(45,9);printf("%c",c);printf(" Level 4: Hard\n");
    gotoxy(45,10);printf("%c",c);printf(" Level 5: Very Hard\n");
    gotoxy(45,12);printf("Enter your choice: ");
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
    gotoxy(40,16);printf("What operation do you want to take? ");
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
        //will add past score to the new score
        PLAYER[marker].plus += counter;
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
                }else{
                    return menu();
                }
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
        //will add past score to the new score
        PLAYER[marker].minus += counter;
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
        //will add past score to the new score
        PLAYER[marker].divide += counter;
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
        //will add past score to the new score
        PLAYER[marker].multiply += counter;
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
            fprintf(fp, "%s\t%s\t%d %d %d %d\n",PLAYER[x].name,PLAYER[x].pass,PLAYER[x].plus,PLAYER[x].minus,PLAYER[x].divide,PLAYER[x].multiply);
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
            fscanf(fp," %[^\t]s",players.pass);
            fscanf(fp,"%d %d %d %d\n", &players.plus,&players.minus,&players.divide,&players.multiply);
            AddRec(players);
        }
        fclose(fp);
   }
}
