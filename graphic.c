#include <stdio.h>
#include <stdlib.h>

void printchess(char locate, char * chess,char cursor) {

    if(locate != cursor){

        int locatraned;
        locatraned = locatetransform(locate);

        if(chess[locatraned] == 0)
            printf("¡³");
        if(chess[locatraned] == 1)
            printf("¡¸");
        if(chess[locatraned] == 2)
            printf("¡¾");

        #ifdef linux
        printf(" ");
        #endif

    }
    else{
        printf("¡·");
        #ifdef linux
        printf(" ");
        #endif
    }

    //printf("%2d",cursor);
}


void printfield(char * chess,char cursor,char * message){

    #ifdef WIN32
    system("cls");
    #endif

    #ifdef linux
    system("clear");
    #endif

    int a = 0 , b = 0;
	printf("             ");
	printchess(96,chess,cursor);
	printf("\n");

	printf("            ");
	b = 79;
	for (a = 0; a < 2; a++ ) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");

	printf("           ");
	b = 62;
	for (a = 0; a < 3; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");

	printf("          ");
	b = 45;
	for (a = 0; a < 4; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");

	printf(" ");
	b = -12;
	for (a = 0; a < 13; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");


	printf("  ");
	b = -19;
	for (a = 0; a < 12; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");

	printf("   ");
	b = -26;
	for (a = 0; a < 11; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");

	printf("    ");
	b = -33;
	for (a = 0; a < 10; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");


	printf("     ");
	b = -40;
	for (a = 0; a < 9; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");


	printf("    ");
	b = -57;
	for (a = 0; a < 10; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");


	printf("   ");
	b = -74;
	for (a = 0; a < 11; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");


	printf("  ");
	b = -91;
	for (a = 0; a < 12; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");



	printf(" ");
	b = -108;
	for (a = 0; a < 13; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");



	printf("          ");
	b = -75;
	for (a = 0; a < 4; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");


	printf("           ");
	b = -82;
	for (a = 0; a < 3; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");


	printf("            ");
	b = -89;
	for (a = 0 ; a < 2; a++) {
		printchess(b, chess,cursor);
		b = b + 10;
	}
	printf("\n");


	printf("             ");
	printchess(-96, chess,cursor);
	printf("\n");

	printf("\n%s",message);

}

char cursormove(char * chess,char cursor,char useroperation){

    if( useroperation==2 ){
        if( chess[locatetransform(cursor+7)] != -1 )
            cursor = cursor + 7;
    }
    if( useroperation==3 ){
        if( chess[locatetransform(cursor-7)] != -1 )
            cursor = cursor - 7;
    }
    if( useroperation==0 ){
        if( chess[locatetransform(cursor-10)] != -1 )
            cursor = cursor - 10;
    }
    if( useroperation==1){
        if( chess[locatetransform(cursor+10)] != -1 )
            cursor = cursor + 10;
    }
    return cursor;
}

char* copyfield(char * chess){

    char *clone = (char *)malloc(sizeof(char) * 256 );
    int i;

    for(i=0;i<256;i++){
        clone[i] = chess[i];
    }

    return clone;
}
