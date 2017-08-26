#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

void delay(unsigned int mseconds);

void delay(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
while (goal > clock());
}

void shutdown(void){
FILE *fp;
if ((fp = fopen("SD.bat", "w"))==NULL) {
printf("File could not be opened.");
exit(1);
}
fprintf(fp, "@echo off\n");
fprintf(fp, "shutdown -s -f -t 0");
fclose(fp);
system("SD.bat");
}

void restart(void){
FILE *fp;
if ((fp = fopen("restart.bat", "w"))==NULL) {
printf("File could not be opened.");
exit(1);
}
fprintf(fp, "@echo off\n");
fprintf(fp, "shutdown -r -f -t 0");
fclose(fp);
system("restart.bat");
}
char History(){
    FILE *fp;
    char j[100000];
    if((fp=fopen("Recent.txt","r"))==NULL)
{
printf("File could not be opened.");
exit(1);
}
while(!feof(fp))
{
if(fgets(j,1000,fp))
printf("%s\n",j);
}
fclose(fp);
}


int main()
{
 int h=0,m=0,s,l,a,c,i=1,z,y;
 char k[50];
 FILE *fp;
 N:
system("cls");
printf("\t\t  *********************************************\n");
printf("\t\t\t Welcome to Auto Shutdown Apps\n");
printf("\t\t  *********************************************\n");
printf("\n\t\t\t Enter Your Name : ");
scanf("%s",&k);
K:
system("cls");
while(i){
printf(" \t\t\t\t  Hi! %s\n",k);
printf("\n\t\t\t\t1  Shutdown\n");
printf("\n\t\t\t\t2  Restart\n");
printf("\n\t\t\t\t3  History\n");
printf("\n\t\t\t\t4  Main Menu\n");
printf("\n\t\t\t   Plaese Chose One Chioce ");
scanf("%d",&c);
if(c==1||c==2)
    i=0;
if(c==3)
    goto L;
if(c==4)
    goto N;
if(c!=1&&c!=2&&c!=3&&c!=4)
    goto K;

    }

{
X:
system("cls");
printf("\n\t\t\t     Pasese input Hour : ");
scanf("%d",&h);
printf("\n\t\t\t    Prese input Minute : ");
scanf("%d",&m);
if(h>24||h<=-1||m>60||m<=-1){
    printf("\n\t\t\t     Error Hour is 0-23\n");
    printf("\n\t\t\t     Error Minute is 0-59\n");
    goto X;
}
if ((fp = fopen("recent.txt", "a"))==NULL) { //ปริ้นเป็นบันทึกการใช้งาน
printf("File could not be opened.");
exit(1);
}

fprintf(fp, "\nName : %s\n",k);
    if(c==1){
        fprintf(fp, "Type : Shutdown");
        }
    else{
        fprintf(fp, "Type : Restart");
        }
fprintf(fp, "\nUsed time : %d Hour %d minute\n",h,m);
fprintf(fp, "___________________________________________________\n");
fclose(fp);



if(h>0){//ทำชั่วโมงให้เป็นวินาที
    h=h*3600;
}
if(m>0){
   m=m*60;
}
                    l=h+m;
                    h=0;
                    m=0;
                    y=60;
                    z=1;
                    a=60;
                    for (s=0;s<l;s++)//นับวินาที
                    {
                        printf("\t\t  *********************************************\n");
                        printf("\t\t\t\t      HH:MM\n");
                         printf("\t\t\t\t       %d:%d\n",h,m);
                     printf("\t\t  *********************************************\n");
                         delay(1000); //หน่วงเวลา 1วินาที
                            y=60*z;

                         if(s==y)
                        {
                            z++;
                            m++;
                         }
                        if(m==a)
                        {
                            h++;
                            m=0;
                        }
                        system("cls");
                   }
               }
if(c==1)
shutdown();

if(c==2)
restart();

L:
if(c==3){
   system("cls");
History();
}
}

