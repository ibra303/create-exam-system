#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void Error(char* msg){fprintf(stderr,"Error:%s\n",msg); exit(1);}
//main
int main(int argc,char* argv[]){
if(argc<1) Error("Not enough arguments passed!");

// virables
char Ename[256] = "\0",buff[256]="\0",Answer[2]="\0";
int fd1,fd2,numOfQ,i,wbytes,rbytes;

//open exam file to get the numOfQ
if( ( fd1 = open( argv[0], O_RDONLY ) ) == -1 )
		{ Error( "File Not Found!" ); return( - 1 ); }

// read num of q from file 
numOfQ=FindNumQ(argv[0]);

//
strcpy(Ename,"\0");
strcpy(Ename,"Sol_");
strcat(Ename,argv[0]);

//new file 
if( ( fd2 = open( Ename, O_WRONLY | O_CREAT, 0664 ) ) == -1 )
		{ Error("cant create"); return( -1 ); }



//
for(i=0;i<numOfQ;i++){
printf("Insert True Sol For Question %d:\n",i+1);
scanf(" %s",Answer);
strcat(Answer,"\n\n");
if( ( wbytes = write( fd2, Answer, strlen(Answer) ) ) == -1 )
	{ Error( "write" ); return( -1 ); }
}
close(fd1);
close(fd2);
return 0;
}





///// find the qustion number
int FindNumQ(char* str){
int fd1,rbytes,i=0,j=0;
char buff[20]="\0",buff1[20]="\0",buff2[20]="1";

if( ( fd1 = open( str, O_RDONLY ) ) == -1 )
		{ Error( "file2 read failed!" ); return( - 1 ); }
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
