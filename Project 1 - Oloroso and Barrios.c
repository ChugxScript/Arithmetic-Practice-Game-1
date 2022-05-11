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
    int plus2,minus2,divide2,multiply2;
    int plus3,minus3,divide3,multiply3;
    int plus4,minus4,divide4,multiply4;
    int plus5,minus5,divide5,multiply5;
    float ave,ave2,ave3,ave4,ave5;
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
void addition ();
void subtraction ();
void division ();
void multiplication ();
void score();
void save();
void retrieve();
void box();
void smallbox();
void leaderboard();
void AllLead(); void AllLead2(); void AllLead3(); void AllLead4(); void AllLead5();
void AddLead(); void AddLead2(); void AddLead3(); void AddLead4(); void AddLead5();
void SubLead(); void SubLead2(); void SubLead3(); void SubLead4(); void SubLead5();
void DivLead(); void DivLead2(); void DivLead3(); void DivLead4(); void DivLead5();
void MulLead(); void MulLead2(); void MulLead3(); void MulLead4(); void MulLead5();
void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//Global Variables
int items=10,counter,num,marker,marker2,level,start;
char c;

int main(){ //calling the functinos
    srand(time(NULL)); //to prevent same problems
    init();
    retrieve();
    logIn();
    system("cls");
    TitleScreen();
    leaderboard();
    while(1){
        switch(menu()){
            case 1: addition();
                    break;
            case 2: subtraction();
                    break;
            case 3: division();
                    break;
            case 4: multiplication();
                    break;
            case 5: leaderboard();
                    save();
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
    marker = -1; //initialize the value of marker to -1
}

void box(){ //box display using ascii value in log in
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
void smallbox(){ //box display using ascii value in the problems
    int i;
    int l = 186, ul=201,ur=187,w=205,dr=188,dl=200;
    gotoxy(33,4);printf("%c", ul);
    gotoxy(48,4);printf("%c", ur);
    gotoxy(48,10);printf("%c", dr);
    gotoxy(33,10);printf("%c", dl);
    for(i=0;i<=4;i++){
        gotoxy(33,5+i);printf("%c",l);
        gotoxy(48,5+i);printf("%c",l);
    }
    for (i=0;i<14;i++){
        gotoxy(34+i,4);printf("%c",w);
        gotoxy(34+i,10);printf("%c",w);
    }
}

void logIn(){
    SREC player;
    system("cls");
    box();
    gotoxy(45,6);printf("Enter Username/UserID: "); //prompt the user's username/ID
    scanf(" %[^\n]s", player.name);
    int l = locate(player.name); //check if name is already in the list
    if(l > -1){
            here:
            system("cls");
            box();
            gotoxy(45,6);printf("Welcome back, %s!", player.name); //prompt the player's password
            gotoxy(45,7);printf("Enter Password: ");
            scanf(" %[^\n]s", player.pass);
            //check if password is correct
            for(int x=0;x<=marker;x++){
                if (strcmp(player.pass,PLAYER[x].pass)==0){ //check if in the array structure if correct proceed to next part
                    gotoxy(45,9);system("pause");marker2=l;break;
                }else{
                    gotoxy(45,9);printf("Wrong password.");
                    gotoxy(45,11);system("pause");
                    goto here; //goto here is responsible to loop if wrong password
                }
            }
        }else{ //will create new account if not in the list
            marker++;
            strcpy(PLAYER[marker].name,player.name);
            system("cls");
            box();
            gotoxy(45,6);printf("A NEW CHALLENGER!");
            gotoxy(45,7);printf("Enter Password: "); //prompt the new player's password
            scanf(" %[^\n]s", player.pass);
            strcpy (PLAYER[marker].pass,player.pass); //copy the entered password to the array structure
            gotoxy(45,12);marker2=marker;system("pause");
        }
}

int locate(char n[69]){ //locate username input to the array structure
    for(int x=0;x<=marker;x++)
        if (strcmp(n,PLAYER[x].name)==0)
            return x;
    return -1;
}

void TitleScreen(){
    char game_title[21][98]=
    {
        {"##################################################################################################"},
        {"                                                                                                  "},
        {" ..:::::..::..:::::..::....:::::..:::::..:::::..::..:::::..::........:::::..:::::....:::......::: "},
        {" :::'###::::'########::'####:'########:'##::::'##:'##::::'##:'########:'########:'####::'######:: "},
        {" ::'## ##::: ##.... ##:. ##::... ##..:: ##:::: ##: ###::'###: ##.....::... ##..::. ##::'##... ##: "},
        {" :'##:. ##:: ##:::: ##:: ##::::: ##:::: ##:::: ##: ####'####: ##:::::::::: ##::::: ##:: ##:::..:: "},
        {" '##:::. ##: ########::: ##::::: ##:::: #########: ## ### ##: ######:::::: ##::::: ##:: ##::::::: "},
        {" .#########: ##.. ##:::: ##::::: ##:::: ##.... ##: ##. #: ##: ##...::::::: ##::::: ##:: ##::::::: "},
        {" .##.... ##: ##::. ##::: ##::::: ##:::: ##:::: ##: ##:.:: ##: ##:::::::::: ##::::: ##:: ##::: ##: "},
        {" .##:::: ##: ##:::. ##:'####:::: ##:::: ##:::: ##: ##:::: ##: ########:::: ##::::'####:. ######:: "},
        {"                             :.::::::.:...::::::.::..:::::..::........::                          "},
        {"                             :'######::::::'###::::'##::::'##:'########:                          "},
        {"                             '##... ##::::'## ##::: ###::'###: ##.....::                          "},
        {"                             .##:::..::::'##:. ##:: ####'####: ##:::::::                          "},
        {"                             .##::'####:'##:::. ##: ## ### ##: ######:::                          "},
        {"                             .##::: ##:: #########: ##. #: ##: ##...::::                          "},
        {"                             .##::: ##:: ##.... ##: ##:.:: ##: ##:::::::                          "},
        {"                             ..######::: ##:::: ##: ##:::: ##: ########:                          "},
        {"                             :......::::..:::::..::..:::::..::........::                          "},
        {"                                                                                                  "},
        {"##################################################################################################"}
    };
    for (int x=0; x<21; x++) // for looop for printing the title screen
    {
        printf("\t");
        for (int y=0; y<98; y++)
        {
            printf("%c", game_title[x][y]);
        }
        printf("\n");
        system("COLOR 0A");
    }
    gotoxy(40,25);system("pause");
    system("cls");
}

int menu(){ //options
    system("cls");
    gotoxy(45,3);printf("Arithmetic Practice Game");
    gotoxy(40,6);printf("============= MENU ==============");
    gotoxy(42,8);printf("Press [1] for Addition");
    gotoxy(42,9);printf("Press [2] for Subtraction");
    gotoxy(42,10);printf("Press [3] for Division");
    gotoxy(42,11);printf("Press [4] for Multiplication");
    gotoxy(42,12);printf("Press [5] to Save and Exit");
    gotoxy(40,14);printf("=================================");
    gotoxy(40,16);printf("What operation do you want to take? ");
    scanf("%d", &num);
    return num;
}

void addition (){
    int x,y,z,answer,ul=196;
    GetLevel(); // get the value of start and level
    do{ //do while loop if the player wants to try again
        counter = 0;
        for (x=0;x<items;x++){ //number of items
            system("cls");
            //generate random numbers from start - level
            y = rand() % level + start;
            z = rand() % level + start;
            score();
            smallbox();
            for(int i=0;i<7;i++){ //displaying box
                gotoxy(38+i,7);printf("%c",ul);
            }
            gotoxy(35,3);printf("Problem #%d",x+1);
            gotoxy(40,5);printf("  %d ",y);
            gotoxy(40,6);printf("+ %d ",z);
            gotoxy(41,8);scanf("%d",&answer);
            if(answer == y+z){
                gotoxy(33,12);printf("Correct!");
                counter++;score();
            }else{
                gotoxy(33,12);printf("Wrong. The correct answer is %d.",y+z);
            }
            gotoxy(33,14);system("pause");
        }
        system("cls");
        if(level == 10){ //will store the score acording to the level
            PLAYER[marker2].plus = counter;
        }else if(level == 20){
            PLAYER[marker2].plus2 = counter;
        }else if(level == 50){
            PLAYER[marker2].plus3 = counter;
        }else if(level == 80){
            PLAYER[marker2].plus4 = counter;
        }else if(level == 100){
            PLAYER[marker2].plus5 = counter;
        }
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();
                save();
                exit(0);
            }
        }
}

void subtraction (){
    int x,y,z,answer,temp,ul=196;
    GetLevel();
    do{ //do while loop if the player wants to try again
        counter = 0;
        for (x=0;x<items;x++){
            system("cls");
            //generate random numbers from start to level
            y = rand() % level + start;
            z = rand() % level + start;
            score();
            smallbox();
            gotoxy(35,3);printf("Problem #%d",x+1);
            for(int i=0;i<7;i++){ //display the box
                gotoxy(38+i,7);printf("%c",ul);
            }
            if (y>z){
                temp=y-z;
                gotoxy(40,5);printf("  %d ",y);
                gotoxy(40,6);printf("- %d ",z);
            }
            else { //to have no negative answer switch to z - y
                temp=z-y;
                gotoxy(40,5);printf("  %d ",z);
                gotoxy(40,6);printf("- %d ",y);
            }
            gotoxy(41,8);scanf("%d",&answer);
            if(answer == temp){
                gotoxy(33,12);printf("Correct!");
                counter++;score();
            }else{
                gotoxy(33,12);printf("Wrong. The correct answer is %d.",temp);
            }
            gotoxy(33,14);system("pause");
        }
        system("cls");
        if(level == 10){ //will store the score acording to the level
            PLAYER[marker2].minus = counter;
        }else if(level == 20){
            PLAYER[marker2].minus2 = counter;
        }else if(level == 50){
            PLAYER[marker2].minus3 = counter;
        }else if(level == 80){
            PLAYER[marker2].minus4 = counter;
        }else if(level == 100){
            PLAYER[marker2].minus5 = counter;
        }
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();
                save();
                exit(0);
            }
        }
}

void division (){
    int x,y,z,answer,temp,ul=196,s=246;
    GetLevel();
    do{ //do while loop if the player wants to try again
        counter = 0;
        for (x=0;x<items;x++){
            system("cls");
            //generate random numbers from start to level
            y = rand() % level + start;
            z = rand() % level + start;
            score();
            smallbox();
            gotoxy(35,3);printf("Problem #%d",x+1);
            for(int i=0;i<7;i++){
                gotoxy(38+i,7);printf("%c",ul);
            }
            temp = y*z; //to have divisible numbers
            y = temp;
            gotoxy(40,5);printf("  %d",y);
            gotoxy(40,6);printf("%c %d ",s,z);
            gotoxy(41,8);scanf("%d",&answer);
            if(answer == y/z){
                gotoxy(33,12);printf("Correct!");
                counter++;score();
            }else{
                gotoxy(33,12);printf("Wrong. The correct answer is %d.",y/z);
            }
            gotoxy(33,14);system("pause");
        }
        system("cls");
        if(level == 10){ //will store the score acording to the level
            PLAYER[marker2].divide = counter;
        }else if(level == 20){
            PLAYER[marker2].divide2 = counter;
        }else if(level == 50){
            PLAYER[marker2].divide3 = counter;
        }else if(level == 80){
            PLAYER[marker2].divide4 = counter;
        }else if(level == 100){
            PLAYER[marker2].divide5 = counter;
        }
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();
                save();
                exit(0);
            }
        }
}

void multiplication (){
    int x,y,z,answer,ul=196;
    GetLevel();
    do{ //do while loop if the player wants to try again
        counter = 0;
        for (x=0;x<items;x++){
            system("cls");
            //generate random numbers from start to level
            y = rand() % level + start;
            z = rand() % level + start;
            score();
            smallbox();
            gotoxy(35,3);printf("Problem #%d",x+1);
            for(int i=0;i<7;i++){
                gotoxy(38+i,7);printf("%c",ul);
            }
            gotoxy(40,5);printf("  %d ",y);
            gotoxy(40,6);printf("x %d ",z);
            gotoxy(41,8);scanf("%d",&answer);
            if(answer == y*z){
                gotoxy(33,12);printf("Correct!");
                counter++;score();
            }else{
                gotoxy(33,12);printf("Wrong. The correct answer is %d.",y*z);
            }
            gotoxy(33,14);system("pause");
        }
        system("cls");
        if(level == 10){ //will store the score acording to the level
            PLAYER[marker2].multiply = counter;
        }else if(level == 20){
            PLAYER[marker2].multiply2 = counter;
        }else if(level == 50){
            PLAYER[marker2].multiply3 = counter;
        }else if(level == 80){
            PLAYER[marker2].multiply4 = counter;
        }else if(level == 100){
            PLAYER[marker2].multiply5 = counter;
        }
        gotoxy(40,7);printf("Do you want to use this operation again? ");
        gotoxy(45,8);printf(" [Y] if Yes. [N] if No.");
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);printf("Do you want to go to menu?");
            gotoxy(40,11);printf(" [Y] if Yes. [N] to Exit.");
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();
                save();
                exit(0);
            }
        }
}

void score(){ //display updated score
    gotoxy(90,2);printf("Score: %d/%d: %6.2f%%",counter,items,(float)counter/items*100);
}

void GetLevel(){ //assign the value of start and level according to chosen difficulty
    int l;
    system("cls");
    gotoxy(40,5);printf("Select level");
    gotoxy(40,6);printf("Level 1: Very Easy");
    gotoxy(40,7);printf("Level 2: Easy");
    gotoxy(40,8);printf("Level 3: Medium");
    gotoxy(40,9);printf("Level 4: Hard");
    gotoxy(40,10);printf("Level 5: Very Hard");
    gotoxy(40,13);printf("Choose level: ");
    gotoxy(55,13);scanf("%d", &l);
    switch (l){
        case 1: level = 10;
                start = 1; break;
        case 2: level = 20;
                start = 10; break;
        case 3: level = 50;
                start = 20; break;
        case 4: level = 80;
                start = 50; break;
        case 5: level = 100;
                start = 80; break;
        default: printf("1-5 only"); break;
    }
}

void save(){ //will save the data from array structure to the txt file
    FILE *fp;
    int x;
    fp = fopen("BSCS-1CD-Leaderboard.txt","w+");
    if (fp==NULL){
        gotoxy(40,5);printf("Error 404. Saved file was not found.");
        gotoxy(40,10);system("pause");
    }
    else {
        for (x=0;x<=marker;x++)
            fprintf(fp, "%s\t%s\t%d %d %d %d\t%d %d %d %d\t%d %d %d %d\t%d %d %d %d\t%d %d %d %d\n",PLAYER[x].name,PLAYER[x].pass,
                    PLAYER[x].plus,PLAYER[x].minus,PLAYER[x].divide,PLAYER[x].multiply,
                    PLAYER[x].plus2,PLAYER[x].minus2,PLAYER[x].divide2,PLAYER[x].multiply2,
                    PLAYER[x].plus3,PLAYER[x].minus3,PLAYER[x].divide3,PLAYER[x].multiply3,
                    PLAYER[x].plus4,PLAYER[x].minus4,PLAYER[x].divide4,PLAYER[x].multiply4,
                    PLAYER[x].plus5,PLAYER[x].minus5,PLAYER[x].divide5,PLAYER[x].multiply5);
        fclose(fp);
      }
}

void retrieve(){ //will scan the txt file
    FILE *fp;
    SREC players;
    fp = fopen("BSCS-1CD-Leaderboard.txt","r+");
    if (fp==NULL){
        system("cls");
        gotoxy(40,5);printf("Error 404.");
        gotoxy(40,6);printf("BSCS-1CD-Leaderboard.txt was not found.");
        gotoxy(40,10);system("pause");
    }
    else {
        while (!feof(fp)){
            fscanf(fp," %[^\t]s",players.name);
            fscanf(fp," %[^\t]s",players.pass);
            fscanf(fp,"%d %d %d %d\t%d %d %d %d\t%d %d %d %d\t%d %d %d %d\t%d %d %d %d\n",
                   &players.plus,&players.minus,&players.divide,&players.multiply,
                   &players.plus2,&players.minus2,&players.divide2,&players.multiply2,
                   &players.plus3,&players.minus3,&players.divide3,&players.multiply3,
                   &players.plus4,&players.minus4,&players.divide4,&players.multiply4,
                   &players.plus5,&players.minus5,&players.divide5,&players.multiply5);
            AddRec(players);
        }
        fclose(fp);
   }
}
void AddRec(SREC pl){
    //check if array is full
    if (marker == MAX-1){
        printf("Array is Full");
        system("\npause");
    }else{
        //will add the record from the file to the array structure
        marker++;
        PLAYER[marker]=pl;
    }
}

void leaderboard(){
    int i;
    system("cls");
    for (i=0;i<=marker;i++){ //assigning the value of average of every player per level
        PLAYER[i].ave = (PLAYER[i].plus + PLAYER[i].minus + PLAYER[i].divide + PLAYER[i].multiply) / 4.0;
        PLAYER[i].ave2 = (PLAYER[i].plus2 + PLAYER[i].minus2 + PLAYER[i].divide2 + PLAYER[i].multiply2) / 4.0;
        PLAYER[i].ave3 = (PLAYER[i].plus3 + PLAYER[i].minus3 + PLAYER[i].divide3 + PLAYER[i].multiply3) / 4.0;
        PLAYER[i].ave4 = (PLAYER[i].plus4 + PLAYER[i].minus4 + PLAYER[i].divide4 + PLAYER[i].multiply4) / 4.0;
        PLAYER[i].ave5 = (PLAYER[i].plus5 + PLAYER[i].minus5 + PLAYER[i].divide5 + PLAYER[i].multiply5) / 4.0;
    }
    gotoxy(44,5);printf("LEADERBOARDS");
    gotoxy(34,6);printf("Score at least 1 point to qualify");
    gotoxy(47,7);printf("Level 1");
    AddLead();
    SubLead();
    DivLead();
    MulLead();
    printf("\n\n\t\t\t\t\t");system("pause");
    system("cls");
    gotoxy(44,5);printf("LEADERBOARDS");
    gotoxy(34,6);printf("Score at least 1 point to qualify");
    gotoxy(47,7);printf("Level 2");
    AddLead2();
    SubLead2();
    DivLead2();
    MulLead2();
    printf("\n\n\t\t\t\t\t");system("pause");
    system("cls");
    gotoxy(44,5);printf("LEADERBOARDS");
    gotoxy(34,6);printf("Score at least 1 point to qualify");
    gotoxy(47,7);printf("Level 3");
    AddLead3();
    SubLead3();
    DivLead3();
    MulLead3();
    printf("\n\n\t\t\t\t\t");system("pause");
    system("cls");
    gotoxy(44,5);printf("LEADERBOARDS");
    gotoxy(34,6);printf("Score at least 1 point to qualify");
    gotoxy(47,7);printf("Level 4");
    AddLead4();
    SubLead4();
    DivLead4();
    MulLead4();
    printf("\n\n\t\t\t\t\t");system("pause");
    system("cls");
    gotoxy(44,5);printf("LEADERBOARDS");
    gotoxy(34,6);printf("Score at least 1 point to qualify");
    gotoxy(47,7);printf("Level 5");
    AddLead5();
    SubLead5();
    DivLead5();
    MulLead5();
    printf("\n\n\t\t\t\t\t");system("pause");
    system("cls");
    gotoxy(44,5);printf("LEADERBOARDS");
    gotoxy(34,6);printf("Score at least 1 point to qualify");
    AllLead();
    AllLead2();
    AllLead3();
    AllLead4();
    AllLead5();
    printf("\n\n\t\t\t\t\t");system("pause");
    system("cls");
}
void AllLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);printf("Level 1 Overall Rankings");
    //checking every single player and sort in descending order according to the average
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].ave < PLAYER[y+1].ave){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "DATA UNAVAILABLE" if doesn't have a score yet in every operation
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus==NULL||PLAYER[z].minus==NULL||PLAYER[z].multiply==NULL||PLAYER[z].divide==NULL){
            gotoxy(19,9);printf("  PLAYER\t  AVERAGE SCORE(%%)");
            gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,10+z);printf("\t  DATA UNAVAILABLE");
        }
        else{
        gotoxy(19,9);printf("  PLAYER\t  AVERAGE SCORE(%%)");
        gotoxy(17,10+z);printf("%d.  %s\t      %6.2f\n",z+1,PLAYER[z].name,PLAYER[z].ave);
        }
    }
}
void AddLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);printf("Addition");
    //checking every single player and sort in descending order according to the addition score
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].plus < PLAYER[y+1].plus){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus==NULL){
            gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,10+z);printf("\t  ---");
        }
        else{
        gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].plus,(float)PLAYER[z].plus/items*100);
        }
    }
}
void SubLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);printf("Subtraction");
    //checking every single player and sort in descending order according to the subtraction score
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].minus < PLAYER[y+1].minus){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].minus==NULL){
            gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,10+z);printf("\t  ---");
        }
        else{
        gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].minus,(float)PLAYER[z].minus/items*100);
        }
    }
}
void DivLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);printf("Division");
    //checking every single player and sort in descending order according to the division score
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].divide < PLAYER[y+1].divide){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].divide==NULL){
            gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,21+z);printf("\t  ---");
        }
        else{
        gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].divide,(float)PLAYER[z].divide/items*100);
        }
    }
}
void MulLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);printf("Multiplication");
    //checking every single player and sort in descending order according to the multiplication score
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].multiply < PLAYER[y+1].multiply){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].multiply==NULL){
            gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,21+z);printf("\t  ---");
        }
        else{
        gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].multiply,(float)PLAYER[z].multiply/items*100);
        }
    }
}
void AllLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);printf("Level 2 Overall Rankings\n");
    //checking every single player and sort in descending order according to the average in level 2
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].ave2 < PLAYER[y+1].ave2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus2==NULL||PLAYER[z].minus2==NULL||PLAYER[z].multiply2==NULL||PLAYER[z].divide2==NULL){
            gotoxy(59,9);printf("  PLAYER\t  AVERAGE SCORE(%%)");
            gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,10+z);printf("\t  DATA UNAVAILABLE");
        }
        else{
        gotoxy(59,9);printf("  PLAYER\t  AVERAGE SCORE(%%)");
        gotoxy(57,10+z);printf("%d.  %s\t      %6.2f\n",z+1,PLAYER[z].name,PLAYER[z].ave2);
        }
    }
}
void AddLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);printf("Addition");
    //checking every single player and sort in descending order according to the addition score in level 2
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].plus2 < PLAYER[y+1].plus2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus2==NULL){
            gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,10+z);printf("\t  ---");
        }
        else{
        gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].plus2,(float)PLAYER[z].plus2/items*100);
        }
    }
}
void SubLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);printf("Subtraction");
    //checking every single player and sort in descending order according to the subtraction score in level  2
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].minus2 < PLAYER[y+1].minus2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].minus2==NULL){
            gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,10+z);printf("\t  ---");
        }
        else{
        gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].minus2,(float)PLAYER[z].minus2/items*100);
        }
    }
}
void DivLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);printf("Division");
    //checking every single player and sort in descending order according to the division score in level 2
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].divide2 < PLAYER[y+1].divide2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].divide2==NULL){
            gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,21+z);printf("\t  ---");
        }
        else{
        gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].divide2,(float)PLAYER[z].divide2/items*100);
        }
    }
}
void MulLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);printf("Multiplication");
    //checking every single player and sort in descending order according to the multiplication score in level 2
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].multiply2 < PLAYER[y+1].multiply2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].multiply2==NULL){
            gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,21+z);printf("\t  ---");
        }
        else{
        gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].multiply2,(float)PLAYER[z].multiply2/items*100);
        }
    }
}

void AllLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);printf("Level 3 Overall Rankings");
    //checking every single player and sort in descending order according to the average in level 3
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].ave3 < PLAYER[y+1].ave3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus3==NULL||PLAYER[z].minus3==NULL||PLAYER[z].multiply3==NULL||PLAYER[z].divide3==NULL){
             gotoxy(19,20);printf("  PLAYER\t  AVERAGE SCORE(%%)");
            gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,21+z);printf("\t  DATA UNAVAILABLE");
        }
        else{
        gotoxy(19,20);printf("  PLAYER\t  AVERAGE SCORE(%%)");
        gotoxy(17,21+z);printf("%d.  %s\t      %6.2f\n",z+1,PLAYER[z].name,PLAYER[z].ave3);
        }
    }
}
void AddLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);printf("Addition");
    //checking every single player and sort in descending order according to the addition score in level 3
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].plus3 < PLAYER[y+1].plus3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus3==NULL){
            gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,10+z);printf("\t  ---");
        }
        else{
        gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].plus3,(float)PLAYER[z].plus3/items*100);
        }
    }
}
void SubLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);printf("Subtraction");
    //checking every single player and sort in descending order according to the subtraction score in level 3
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].minus3 < PLAYER[y+1].minus3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].minus3==NULL){
            gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,10+z);printf("\t  ---");
        }
        else{
        gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].minus3,(float)PLAYER[z].minus3/items*100);
        }
    }
}
void DivLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);printf("Division");
    //checking every single player and sort in descending order according to the division score in level 3
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].divide3 < PLAYER[y+1].divide3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].divide3==NULL){
            gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,21+z);printf("\t  ---");
        }
        else{
        gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].divide3,(float)PLAYER[z].divide3/items*100);
        }
    }
}
void MulLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);printf("Multiplication");
    //checking every single player and sort in descending order according to the multiplication score in level 3
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].multiply3 < PLAYER[y+1].multiply3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].multiply3==NULL){
            gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,21+z);printf("\t  ---");
        }
        else{
        gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].multiply3,(float)PLAYER[z].multiply3/items*100);
        }
    }
}

void AllLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);printf("Level 4 Overall Rankings");
    //checking every single player and sort in descending order according to the average in level 4
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].ave4 < PLAYER[y+1].ave4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus4==NULL||PLAYER[z].minus4==NULL||PLAYER[z].multiply4==NULL||PLAYER[z].divide4==NULL){
            gotoxy(59,20);printf("  PLAYER\t  AVERAGE SCORE(%%)");
            gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,21+z);printf("\t  DATA UNAVAILABLE");
        }
        else{
        gotoxy(59,20);printf("  PLAYER\t  AVERAGE SCORE(%%)");
        gotoxy(57,21+z);printf("%d.  %s\t      %6.2f\n",z+1,PLAYER[z].name,PLAYER[z].ave4);
        }
    }
}
void AddLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);printf("Addition");
    //checking every single player and sort in descending order according to the addition score in level 4
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].plus4 < PLAYER[y+1].plus4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus4==NULL){
            gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,10+z);printf("\t  ---");
        }
        else{
        gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].plus4,(float)PLAYER[z].plus4/items*100);
        }
    }
}
void SubLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);printf("Subtraction");
    //checking every single player and sort in descending order according to the subtraction score in level 4
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].minus4 < PLAYER[y+1].minus4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].minus4==NULL){
            gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,10+z);printf("\t  ---");
        }
        else{
        gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].minus4,(float)PLAYER[z].minus4/items*100);
        }
    }
}
void DivLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);printf("Division");
    //checking every single player and sort in descending order according to the division score in level 4
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].divide4 < PLAYER[y+1].divide4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].divide4==NULL){
            gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,21+z);printf("\t  ---");
        }
        else{
        gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].divide4,(float)PLAYER[z].divide4/items*100);
        }
    }
}
void MulLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);printf("Multiplication");
    //checking every single player and sort in descending order according to the multiplication score in level 4
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].multiply4 < PLAYER[y+1].multiply4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].multiply4==NULL){
            gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,21+z);printf("\t  ---");
        }
        else{
        gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].multiply4,(float)PLAYER[z].multiply4/items*100);
        }
    }
}

void AllLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(48,31);printf("Level 5 Overall Rankings");
    //checking every single player and sort in descending order according to the average in level 5
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].ave5 < PLAYER[y+1].ave5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus5==NULL||PLAYER[z].minus5==NULL||PLAYER[z].multiply5==NULL||PLAYER[z].divide5==NULL){
            gotoxy(44,32);printf("  PLAYER\t  AVERAGE SCORE(%%)");
            gotoxy(42,33+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(52,33+z);printf("\t  DATA UNAVAILABLE");
        }
        else{
        gotoxy(44,32);printf("  PLAYER\t  AVERAGE SCORE(%%)");
        gotoxy(42,33+z);printf("%d.  %s\t      %6.2f\n",z+1,PLAYER[z].name,PLAYER[z].ave5);
        }
    }
}
void AddLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);printf("Addition");
    //checking every single player and sort in descending order according to the addition score in level 5
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].plus5 < PLAYER[y+1].plus5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].plus5==NULL){
            gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,10+z);printf("\t  ---");
        }
        else{
        gotoxy(19,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].plus5,(float)PLAYER[z].plus5/items*100);
        }
    }
}
void SubLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);printf("Subtraction");
    //checking every single player and sort in descending order according to the subtraction score in level 5
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].minus5 < PLAYER[y+1].minus5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].minus5==NULL){
            gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,10+z);printf("\t  ---");
        }
        else{
        gotoxy(59,9);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,10+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,10+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].minus5,(float)PLAYER[z].minus5/items*100);
        }
    }
}
void DivLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);printf("Division");
    //checking every single player and sort in descending order according to the division score in level 5
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].divide5 < PLAYER[y+1].divide5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].divide5==NULL){
            gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(65,21+z);printf("\t  ---");
        }
        else{
        gotoxy(59,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(57,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(65,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].divide5,(float)PLAYER[z].divide5/items*100);
        }
    }
}
void MulLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);printf("Multiplication");
    //checking every single player and sort in descending order according to the multiplication score in level 5
    for(int x=0;x<=marker;x++){
        for(int y=0;y<marker;y++){
            if (PLAYER[y].multiply5 < PLAYER[y+1].multiply5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker;z++){
        if(PLAYER[z].multiply5==NULL){
            gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
            gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
            gotoxy(25,21+z);printf("\t  ---");
        }
        else{
        gotoxy(19,20);printf("  PLAYER\t  SCORE(%%)");
        gotoxy(17,21+z);printf("%d.  %s",z+1,PLAYER[z].name);
        gotoxy(25,21+z);printf("\t  %d (%6.2f%%)\n",PLAYER[z].multiply5,(float)PLAYER[z].multiply5/items*100);
        }
    }
}
