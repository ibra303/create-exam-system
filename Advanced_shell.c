#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void Error(char* msg){fprintf(stderr,"%s\n",msg); exit(1);}
//main
int main(int argc,char* argv[]){
char kelet[256]="\0",arg1[50]="\0",arg0[50]="\0",arg2[50]="\0",arg3[50]="\0";
int i = 0,pid1,pid;
char* pieces = NULL;


while(1){
i=0;
printf("AdvShell>");                          
scanf("%[^\n]%*c",kelet);

// if the user insert done
if(strcmp(kelet,"Goodbye")==0){
break;
}

// get command 
pieces = strtok(kelet, " ");
while( pieces != NULL && i<4){

if(i==0)
strcpy(arg0, pieces);

if(i==1)
strcpy(arg1, pieces);

if(i==2)
strcpy(arg2, pieces);

if(i==3)
strcpy(arg3, pieces);

pieces = strtok(NULL," ");
i++;
}

pid1=fork();
if(pid1 == -1){
Error("Not Working");
}
if(pid1 == 0){
// linux commands
if(strcmp(arg1,"\0"))
execlp(arg0,arg0,arg1,NULL);
else 
execlp(arg0,arg0,NULL);

if(strcmp(arg1,"\0")&& strcmp(arg2,"\0"))
execlp(arg0,arg0,arg1,arg2,NULL);

if(strcmp(arg1,"\0")&& strcmp(arg2,"\0")&&strcmp(arg3,"\0"))
execlp(arg0,arg0,arg1,arg2,arg3,NULL);


//Special comands
execl(arg0,arg1,arg2,arg3,NULL);
Error("Not Supported");
}
wait(&pid);
}
return 0;
}
