#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<unistd.h>
#include<time.h>
#include<string.h>

void m(void);

void gotoxy(int x,int y){
    COORD p;
    p.X=x;
    p.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);        
}


void background(){
    printf("*******************\n");
    printf("|                 |\n");
    printf("|     CLOCK       |\n");
    printf("|                 |\n");
    printf("*******************\n\n");
    printf("press 1 to set ALARM\n");
    printf("press 2 to see TIME\n");
    printf("press 3 to set STOPWATCH\n");
    printf("press 4 to set TIMER\n");
    printf("press 5 to EXIT\n");
}


void alarm(){

    int hours, mins, ap;
    char msg[20];
    system("cls");
    printf("Alarm : \n");
    printf("Enter time : \n");
    printf("Hours : \n");
    printf("Minutes : \n");
    printf("AM(0)/PM(1) : \n");
    printf("Enter Message : ");

    gotoxy(7, 2);
    scanf("%d", &hours);
    gotoxy(9, 3);
    scanf("%d", &mins);
    gotoxy(13, 4);
    scanf("%d", &ap);
    gotoxy(15, 5);
    fflush(stdin);
    gets(msg);
    system("cls");
    printf("Alarm set : \n");
    time_t sec;
    sec = time(NULL) + (4.5 * 3600);
    printf("%02d : %02d ", (sec / 3600) % 12 + 1, (sec / 60) % 60);
    if (((sec / 3600) + 1) % 24 >= 12)
        printf("PM");
    else
        printf("AM");
    do
    {
        while (time(NULL) % 60 != 0){
            if(kbhit())break;
        }
            
        gotoxy(0, 1);
        sec = time(NULL) + (4.5 * 3600);
        printf("%02d : %02d ", (sec / 3600) % 12 + 1, (sec / 60) % 60);
        if (((sec / 3600) + 1) % 24 >= 12)
            printf("PM");
        else
            printf("AM");
        sleep(1);
        if(kbhit())break;
    } while (((sec / 3600) % 12 + 1) != hours || ((sec / 60) % 60) != mins || (((sec / 3600) + 1) % 24) / 12 != ap);

    gotoxy(0, 2);
    printf("%s", msg);
    getch();

    system("cls");
    background();
    m();
    return;
}


void cl(){
    int f=1;
    time_t sec;
    char c;
    sec = time(NULL) + (4.5 * 3600);
start:
    system("cls");
    printf("*******************\n");
    printf("|       CLOCK     |\n");
    printf("*******************\n\n");
    printf("press space bar to go BACK\n");

    while (f){
        gotoxy(5,5);
        sec = time(NULL) + (4.5 * 3600);
        printf("%02d : %02d ", (sec / 3600) % 12 + 1, (sec / 60) % 60);
        if (((sec / 3600) + 1) % 24 >= 12)
            printf("PM");
        else
            printf("AM");
        sleep(1);
        while (time(NULL) % 60 != 0){
            if(kbhit()){
                f=0;
                break;
            }
        }
        if(!f) break;
    }

    system("cls");
    background();
    m();

end:
    return;
}


void stopwatch() {
    getchar();
    system("cls");

    printf("*******************\n");
    printf("|    STOPWATCH    |\n");
    printf("*******************\n\n");

    int fl = 1,stop=0;
    int min = 0, sec = 0, ms=0;
    char ch;
    printf("press any key to START\n");    
    printf("%d : %d\n", min, sec);
    clock_t t, st;
    t = clock();
    
    if (getchar()) {
        system("cls");

        while (fl) {
            
            printf("*******************\n");
            printf("|    STOPWATCH    |\n");
            printf("*******************\n\n");
            printf("press spacebar to go BACK\n");
            printf("press s to STOP\n");
            st = clock() - t;
            printf("%02d : %02d : %03d", (st / 60000), (st / 1000) % 60, st % 1000);

            if (kbhit()) {
                ch=getch(); 
                fl = 0; 
            }

            while(ch=='s'){
                if(kbhit()) break;
            }

            system("cls");
                                                                                    
        }
    }

   system("cls");
    background();
    m();

    return;
}


void timer(){
    system("cls"); 
    int min,sec;       
    printf("*******************\n");
    printf("|      TIMER      |\n");
    printf("*******************\n\n");
    printf("Enter the duration:-\n");
    printf("Minutes:-\n");  
    printf("Seconds:-\n"); 
    gotoxy(9,5);
    scanf("%d",&min);   
    gotoxy(9,6);
    scanf("%d",&sec); 
    int target=(min*60)+sec;

    while(target>0){
        system("cls");
        printf("%d : %d\n",min,sec);
        target--;
        sec--;
        if(sec==0){
            min--;
            sec=60;
        }
        sleep(1);

    }

    printf("TIME UP!!\n");
    printf("press spacebar to go back");
    if(getch()){
        system("cls");
        background();
        m();
    }

    return;
}


void m(){
    int a,fl=1;

    while(1){
        scanf("%d",&a);
        switch (a){
            case 1:
                    alarm();
                    break;
            case 2:
                   cl();
                   break; 
            case 3:
                   stopwatch();
                   break;
            case 4:
                   timer();
                   break;
            default:
                   fl=0;
                   return;
        }
        if(!fl)break;
    }
    return;
}


int main(){
    system("COLOR 0A");
    background();
    m();

    return 0;
}
