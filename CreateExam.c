#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void Error(char* msg){fprintf(stderr,"Error:%s\n",msg); exit(1);}
//main
int main(int argc,char* argv[]){
if(argc<3) Error("Not enough arguments passed!");
int wbytes,i=0,fdexam,num,pid;
char kelet2[256]="\0",kelet1[10]="\0",q[25]="Qusetion ",snum[10]="\0";

if( ( fdexam = open( argv[0], O_WRONLY | O_CREAT, 0664 ) ) == -1 )
		{ Error("open to"); return( -1 ); }


//
if( ( wbytes = write( fdexam, argv[1], strlen(argv[1]))) == -1 )
			{ Error( "write" ); return( -1 ); }
if( ( wbytes = write( fdexam, "\n", strlen("\n"))) == -1 )
			{ Error( "write" ); return( -1 ); }

//
printf("Insert Number of Question:\n");
scanf("%d",&num);
sprintf(kelet1, "%d", num);
strcat(kelet1,"\n\n");
if( ( wbytes = write( fdexam, kelet1, strlen(kelet1))) == -1 )
			{ Error( "write" ); return( -1 ); }




// take the Q's
while(i!=num){
//
printf("Insert Qusetion %d:\n",i+1);
sprintf(snum, "%d",i+1);
strcat(q,snum);
strcat(q,":\n");
if( ( wbytes = write( fdexam, q, strlen(q))) == -1 )
			{ Error( "write" ); return( -1 );}
strcpy(q,"Qusetion ");
scanf(" %256[^\n]",kelet2);
strcat(kelet2,"\n\n");
if( ( wbytes = write( fdexam, kelet2, strlen(kelet2))) == -1 )
			{ Error( "write" ); return( -1 ); }

//inswers
printf("Insert 4 Answers:\n");

//1
printf("1.");
scanf("%s",snum);
sprintf(kelet1, "%d",1);
strcat(kelet1,".");
strcat(kelet1,snum);
strcat(kelet1,"\n\n");
if( ( wbytes = write( fdexam, kelet1, strlen(kelet1))) == -1 )
			{ Error( "write" ); return( -1 );}
//2
printf("2.");
scanf("%s",snum);
sprintf(kelet1, "%d",2);
strcat(kelet1,".");
strcat(kelet1,snum);
strcat(kelet1,"\n\n");
if( ( wbytes = write( fdexam, kelet1, strlen(kelet1))) == -1 )
			{ Error( "write" ); return( -1 );}

//3
printf("3.");
scanf("%s",snum);
sprintf(kelet1, "%d",3);
strcat(kelet1,".");
strcat(kelet1,snum);
strcat(kelet1,"\n\n");
if( ( wbytes = write( fdexam, kelet1, strlen(kelet1))) == -1 )
			{ Error( "write" ); return( -1 );}

//4
printf("4.");
scanf("%s",snum);
sprintf(kelet1, "%d",4);
strcat(kelet1,".");
strcat(kelet1,snum);
strcat(kelet1,"\n\n");
if( ( wbytes = write( fdexam, kelet1, strlen(kelet1))) == -1 )
			{ Error( "write" ); return( -1 );}
i++;
}
strcpy(kelet2,"Successfully\n");
strcat(kelet2,argv[2]);
strcat(kelet2,"\n");
if( ( wbytes = write( fdexam, kelet2, strlen(kelet2))) == -1 )
		{ Error( "write" ); return( -1 );}

close(fdexam);
return 0;
}



