/*Project 1 - Arithmetic Practice Game in C using Array of structures
Made By Oloroso, Andrew R. and Barrios, Armand Angelo C.*/
#include <stdio.h>
#include <windows.h>
#include <time.h>

//Functions definitions
void TitleScreen();
int menu();
void GetItems(int *n);
void addition (int n);
void subtraction (int n);
void division (int n);
void multiplication (int n);
void score();
void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//Global Variables
int items,counter,num;
char c;

int main(){
    srand(time(NULL));
    TitleScreen();
    while(1){
        switch(menu()){
            case 1: GetItems(&items);
                    addition(items);
                    break;
            case 2: system("cls");
                    gotoxy(40,5);printf("How many items? ");
                    scanf("%d", &items);
                    subtraction(items);
                    break;
            case 3: system("cls");
                    gotoxy(40,5);printf("How many items? ");
                    scanf("%d", &items);
                    division(items);
                    break;
            case 4: system("cls");
                    gotoxy(40,5);printf("How many items? ");
                    scanf("%d", &items);
                    multiplication(items);
                    break;
            case 5: exit(0);
                    break;
            default:system("cls");
                    gotoxy(40,5);printf("Numbers 1-5 only.");
                    gotoxy(40,6);system("pause");
                    break;
        }
    }
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
}

void GetItems(int *n){
    system("cls");
    gotoxy(40,5);printf("How many items? ");
    scanf("%d", &n);
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
    int x,y,z,answer,level,diff=5;
    do{
        counter = 0;
        level = diff;
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
        if (counter >= (float)n/2){
        //the random random number will increase for the level of difficulty
        diff = level + 10;
        gotoxy(47,5);printf("YOU ARE NOW LEVEL UP!");
        }
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                    exit(0);
                }
            if(c == 'y' || c == 'Y'){
                    return main();
                }
                getch();
            }
    }while(c == 'y' || c == 'Y');
}

void subtraction (int n){
    int x,y,z,answer,temp,level,diff=5;
    do{
        counter = 0;
        level = diff;
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
        if (counter >= (float)n/2){
        //the random random number will increase for the level of difficulty
        diff = level + 10;
        gotoxy(47,5);printf("YOU ARE NOW LEVEL UP!");
        }
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                    exit(0);
                }
            if(c == 'y' || c == 'Y'){
                    return main();
                }
                getch();
            }
    }while(c == 'y' || c == 'Y');
}

void division (int n){
    int x,y,z,answer,temp,level,diff=2;
    do{
        counter = 0;
        level = diff;
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
        if (counter >= (float)n/2){
        //the random random number will increase for the level of difficulty
        diff = level + 10;
        gotoxy(47,5);printf("YOU ARE NOW LEVEL UP!");
        }
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                    exit(0);
                }
            if(c == 'y' || c == 'Y'){
                    return main();
                }
                getch();
            }
    }while(c == 'y' || c == 'Y');
}

void multiplication (int n){
    int x,y,z,answer,level,diff=5;
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
        if (counter >= (float)n/2){
        //the random random number will increase for the level of difficulty
        diff = level + 10;
        gotoxy(47,5);printf("YOU ARE NOW LEVEL UP!");
        }
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                    exit(0);
                }
            if(c == 'y' || c == 'Y'){
                    return main();
                }
                getch();
            }
    }while(c == 'y' || c == 'Y');
}

void score(){
    gotoxy(90,2);printf("Score: %d/%d: %6.2f%%",counter,items,(float)counter/items*100);
}

void LuckyPick642(){
    int i, num;
    srand(time(NULL));
    for (i=0;i<6;i++){
        num = rand() % 42 + 1;
        printf("%d.) %d\n",i+1,num);
    }
}
