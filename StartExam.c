#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void Error(char* msg){fprintf(stderr,"Error:%s\n",msg); exit(1);}
//main
int main(int argc,char* argv[]){
if(argc<2) Error("Not enough arguments passed!");

//vir 
int fd1,fd2,wbytes,pid1,numOfQ=FindNumQ(argv[0]),i,rbytes,pid,q;
int ansArr[numOfQ];
char file[56]="\0",buff[256]="\0";

//printf("%s",argv[0]);
// open file
if( ( fd1 = open( argv[0], O_RDONLY ) ) == -1 )
		{ Error( "File Not Found" ); return( - 1 ); }


//print exam to bash
pid1=fork();
if(pid1 == -1){
Error("Not Working");
}
if(pid1 == 0){
// exec the new 
execl("/bin/cat","cat",argv[0],NULL);
Error("ERROR ERROR ERROR");
}
wait(&pid);



//make new file
strcpy(file,"\0");
strcpy(file,argv[1]);
//printf("%s\n",argv[1]);
strcat(file,"_");
strcat(file,argv[0]);
//printf("%s\n",file);

//new file 
if( ( fd2 = open(file, O_WRONLY | O_CREAT, 0664 ) ) == -1 )
		{ Error("cant create"); return( -1 ); }


// start geting answers from user and print to sol file
printf("Insert number of Qusetion and sol:\n");
for(i=0;i<numOfQ;i++)
{
scanf("%d",&q);
scanf("%d",&ansArr[q-1]);
}

for(i=0;i<numOfQ;i++)
{
strcpy(buff,"\0");
sprintf(buff,"%d",ansArr[i]);
strcat(buff,"\n\n");
if( ( wbytes = write( fd2, buff, strlen(buff) ) ) == -1 )
	{ Error( "write" ); return( -1 ); }
}
close(fd1);
close(fd2);
return 0;
}


//--------------------------------------------------------
///// find the qustion number
int FindNumQ(char* str){
int fd1,rbytes,i=0,j=0;
char buff[20]="\0",buff1[20]="\0",buff2[20]="1";

if( ( fd1 = open( str, O_RDONLY ) ) == -1 )
		{ Error( "File Not Found" ); return( - 1 ); }
//----------------------------
// dwerha dwer dwer 
while(1)
{
if( ( rbytes = read( fd1, buff, 1 ) ) == -1 )
		 { Error( "read 1 failed" ); return( -1 ); }
if(strcmp(buff,"\n") ==0){
lseek(fd1, i + 1,SEEK_SET);
break;
}
lseek(fd1, i + 1,SEEK_SET);
i++;
}
j=i+1;
//-----------------------------
//take all the number 
while(1)
{
lseek(fd1, j ,SEEK_SET);

if( ( rbytes = read( fd1, buff2, 1 ) ) == -1 )
		 { Error( "read 1 failed" ); return( -1 ); }

if(strcmp(buff2,"\n") ==0)
break;

strcat(buff1,buff2);
j++;
}

int val = atoi(buff1);
return val ;
}

