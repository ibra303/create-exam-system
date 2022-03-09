#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
void Error(char* msg){fprintf(stderr,"Error:%s\n",msg); exit(1);}
//main
int main(int argc,char* argv[]){
if(argc<2) Error("Not enough arguments passed!");

int fd1,fd2,fd3,wbytes,rbytes1,rbytes2,result,i=0,count=0,try1=0,try2=0;
char file1[56]="\0",file2[56]="\0",buff1[256]="\0",buff2[256]="\0",str[56]="\0";

// open files for read only
strcpy(file1,"Sol_");
strcat(file1,argv[0]);
if( ( fd1 = open( file1, O_RDONLY ) ) == -1 )
		{ Error( "file1 read failed!" ); return( - 1 ); }
strcpy(file2,argv[1]);
strcat(file2,"_");
strcat(file2,argv[0]);
if( ( fd2 = open( file2, O_RDONLY ) ) == -1 )
		{ Error( "file2 read failed!" ); return( - 1 ); }

//
strcpy(buff1,"Grade_");
strcat(buff1,argv[1]);
strcat(buff1,"_");
strcat(buff1,argv[0]);
//new file 
if( ( fd3 = open( buff1, O_WRONLY | O_CREAT, 0664 ) ) == -1 )
		{ Error("open to"); return( -1 ); }

// find num of qusitions 
int numOfQ = FindNumQ(argv[0]);
strcpy(buff1,"\0");
strcpy(buff2,"\0");

//read the files and put the input in buffs
if( ( rbytes1 = read( fd1, str, 56 ) ) == -1 )
		 { Error( "read 5 failed" ); return( -1 ); }
if( ( rbytes2 = read( fd2, buff2, 256 ) ) == -1 )
		{ Error( "read 3 failed" ); return( -1 ); }


//compare 2 strings if equal 
result=strcmp(str,buff2);
if(result!=0){
while(str[i]!='\0' && buff2[i]!='\0' )
{
if(str[i]==buff2[i]&& str[i]!='\n'){
count++;}
i=i+1;
}
strcpy(str,"\0");
strcpy(buff1,"\0");
sprintf(str,"%d",count);
strcpy(buff1,str);
strcat(buff1,"/");
strcpy(str,"\0");
sprintf(str,"%d",numOfQ);
strcat(buff1,str);
}
//print full grade 
else {
strcpy(buff1,"\0");
sprintf(str,"%d",numOfQ);
strcpy(buff1,str);
strcat(buff1,"/");
strcpy(buff1,str);

}
if( ( wbytes = write( fd3, buff1, strlen(buff1) ) ) == -1 )
	{ Error( "write" ); return( -1 ); }
close(fd1);
close(fd2);
close(fd3);
return 0;
}
//--------------------------------------------------------
///// find the qustion number
int FindNumQ(char* str){
int fd1,rbytes,i=0,j=0;
char buff[20]="\0",buff1[20]="\0",buff2[20]="1";

if( ( fd1 = open( str, O_RDONLY ) ) == -1 )
		{ Error( "file8 read failed!" ); return( - 1 ); }
//----------------------------
// dwerha dwer dwer 
while(1)
{
if( ( rbytes = read( fd1, buff, 1 ) ) == -1 )
		 { Error( "read 7 failed" ); return( -1 ); }
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
		 { Error( "read 6 failed" ); return( -1 ); }

if(strcmp(buff2,"\n") ==0)
break;

strcat(buff1,buff2);
j++;
}

int val = atoi(buff1);
return val ;
}
