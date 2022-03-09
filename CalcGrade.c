#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void Error(char* msg){fprintf(stderr,"Error:%s\n",msg); exit(1);}
//main
int main(int argc,char* argv[]){
if(argc<2) Error("Not enough arguments passed!");


char buff1[256]="\0",g1[3]="\0",buff2[256]="\0";
int fd1,gForQ,g,rbytes1,wbytes;
strcpy(buff1,"Grade_");
strcat(buff1,argv[1]);
strcat(buff1,"_");
strcat(buff1,argv[0]);
//new file 
if( ( fd1 = open( buff1, O_RDONLY ) ) == -1 )
		{ Error("File Not Found"); return( -1 ); }

if( ( rbytes1 = read( fd1, g1, 1 ) ) == -1 )
		 { Error( "File Not Found" ); return( -1 ); }
close(fd1);
if( ( fd1 = open( buff1, O_WRONLY ) ) == -1 )
		{ Error("File Not Found"); return( -1 ); }
g=atoi(g1);
gForQ=100 / FindNumQ(argv[0]);
sprintf(buff1,"%d",gForQ * g);
strcpy(buff2,"\n\nFinal Grade :");
strcat(buff2,buff1);
strcat(buff2,"/");
strcat(buff2,"100");
printf("%s\n%s\nFinalGrade:%s\n",argv[1],argv[0],buff1);
//printf("\n%s\n",buff2);

lseek(fd1,3,SEEK_SET);
if( ( wbytes = write( fd1, buff2, strlen(buff2) ) ) == -1 )
	{ Error( "write" ); return( -1 ); }
close(fd1);
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
		 { Error( "File Not Found" ); return( -1 ); }
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
		 { Error( "File Not Found" ); return( -1 ); }

if(strcmp(buff2,"\n") ==0)
break;

strcat(buff1,buff2);
j++;
}

int val = atoi(buff1);
return val ;
}

