#include <stdio.h>
#include <stdlib.h>
#include <WINSOCK2.H>
#include "array.h"

struct adjlist{
    char locate;
    struct adjlist *next;
};

struct headadjlist{
    char head;
    struct headadjlist *next;
    struct adjlist *canjumpto;
};

void initadjlist(char * chess,struct adjlist * adjlist1,struct adjlist * adjlist2){

    char init1v1[10] = {75,65,55,45,82,72,62,89,79,96};

    adjlist1 = (struct adjlist *)malloc(sizeof(struct adjlist));
}

int compare(void const *e1, void const *e2)
{
    char *i = *((char **) e1);
    char *j = *((char **) e2);

    if (*i < *j)
        return -1;
    if (*i > *j)
        return 1;
    return 0;
}

bool Visited(char new_element, Array *array){

    bool visited = false;

    char *element;
    for(int i=0;i<array_size(array);i++){
        array_get_at(array, i,(void*)&element);
        if(new_element==*element){
            visited = true;
            break;
        }
    }
    return visited;
}

void FindAllSingleMove(char * chess , char start , Array *ends){

    char *element;

    if( chess[locatetransform(start+7)]==0 ){
        element = (char *)malloc(sizeof(char));
        *element = start+7;
        array_add(ends, element);
    }
    if( chess[locatetransform(start+10)]==0 ){
        element = (char *)malloc(sizeof(char));
        *element = start+10;
        array_add(ends, element);
    }
    if( chess[locatetransform(start+17)]==0 ){
        element = (char *)malloc(sizeof(char));
        *element = start+17;
        array_add(ends, element);
    }
    if( chess[locatetransform(start-7)]==0 ){
        element = (char *)malloc(sizeof(char));
        *element = start-7;
        array_add(ends, element);
    }
    if( chess[locatetransform(start-10)]==0 ){
        element = (char *)malloc(sizeof(char));
        *element = start-10;
        array_add(ends, element);
    }
    if( chess[locatetransform(start-17)]==0 ){
        element = (char *)malloc(sizeof(char));
        *element = start-17;
        array_add(ends, element);
    }
}

void FindAllJump(char * chess , char start , Array *ends){

    char *element;

    if(!Visited(start+14,ends)){
        if( chess[locatetransform(start+14)]==0 && chess[locatetransform(start+7)]!=0 && chess[locatetransform(start+7)]!=-1){
            element = (char *)malloc(sizeof(char));
            *element = start+14;
            array_add(ends, element);
            FindAllJump(chess,*element,ends);
        }
    }
    if(!Visited(start+34,ends)){
        if( chess[locatetransform(start+34)]==0 && chess[locatetransform(start+17)]!=0 && chess[locatetransform(start+17)]!=-1){
            element = (char *)malloc(sizeof(char));
            *element = start+34;
            array_add(ends, element);
            FindAllJump(chess,*element,ends);
        }
    }
    if(!Visited(start+20,ends)){
        if( chess[locatetransform(start+20)]==0 && chess[locatetransform(start+10)]!=0 && chess[locatetransform(start+10)]!=-1){
            element = (char *)malloc(sizeof(char));
            *element = start+20;
            array_add(ends, element);
            FindAllJump(chess,*element,ends);
        }
    }
    if(!Visited(start-14,ends)){
        if( chess[locatetransform(start-14)]==0 && chess[locatetransform(start-7)]!=0 && chess[locatetransform(start-7)]!=-1){
            element = (char *)malloc(sizeof(char));
            *element = start-14;
            array_add(ends, element);
            FindAllJump(chess,*element,ends);
        }
    }
    if(!Visited(start-34,ends)){
        if(chess[locatetransform(start-34)]==0 && chess[locatetransform(start-17)]!=0 && chess[locatetransform(start-17)]!=-1){
            element = (char *)malloc(sizeof(char));
            *element = start-34;
            array_add(ends, element);
            FindAllJump(chess,*element,ends);
        }
    }
    if(!Visited(start-20,ends)){
        if(chess[locatetransform(start-20)]==0 && chess[locatetransform(start-10)]!=0 && chess[locatetransform(start-10)]!=-1){
            element = (char *)malloc(sizeof(char));
            *element = start-20;
            array_add(ends, element);
            FindAllJump(chess,*element,ends);
        }
    }
}


Array * ReturnAllOfTheMove(char * chess , char start){
    Array *ends;
    array_new(&ends);
    FindAllJump(chess,start,ends);
    FindAllSingleMove(chess,start,ends);
    char *element;

/*
    printf("size:%d -> ",array_size(ends));
    while(array_size(ends)!=0){
        array_remove_at(ends, 0,(void*)&element);
        printf("%3d ",*element);
    }
    system("PAUSE");
*/

    return ends;
}

void FirstScore(char * chess){
    chess[locatetransform(-96)]=1;
    chess[locatetransform(-89)]=3;
    chess[locatetransform(-79)]=3;
    chess[locatetransform(-82)]=5;
    chess[locatetransform(-72)]=6;
    chess[locatetransform(-62)]=5;
    chess[locatetransform(-75)]=7;
    chess[locatetransform(-65)]=8;
    chess[locatetransform(-55)]=8;
    chess[locatetransform(-45)]=7;
    chess[locatetransform(-108)]=5;
    chess[locatetransform(-98)]=6;
    chess[locatetransform(-88)]=7;
    chess[locatetransform(-78)]=8;
    chess[locatetransform(-68)]=9;
    chess[locatetransform(-58)]=10;
    chess[locatetransform(-48)]=11;
    chess[locatetransform(-38)]=10;
    chess[locatetransform(-28)]=9;
    chess[locatetransform(-18)]=8;
    chess[locatetransform(-8)]=7;
    chess[locatetransform(2)]=6;
    chess[locatetransform(12)]=5;
    chess[locatetransform(-91)]=8;
    chess[locatetransform(-81)]=9;
    chess[locatetransform(-71)]=10;
    chess[locatetransform(-61)]=11;
    chess[locatetransform(-51)]=12;
    chess[locatetransform(-41)]=13;
    chess[locatetransform(-31)]=13;
    chess[locatetransform(-21)]=12;
    chess[locatetransform(-11)]=11;
    chess[locatetransform(-1)]=10;
    chess[locatetransform(9)]=9;
    chess[locatetransform(19)]=8;
    chess[locatetransform(-74)]=11;
    chess[locatetransform(-64)]=12;
    chess[locatetransform(-54)]=13;
    chess[locatetransform(-44)]=14;
    chess[locatetransform(-34)]=15;
    chess[locatetransform(-24)]=16;
    chess[locatetransform(-14)]=15;
    chess[locatetransform(-4)]=14;
    chess[locatetransform(6)]=13;
    chess[locatetransform(16)]=12;
    chess[locatetransform(26)]=11;
    chess[locatetransform(-57)]=14;
    chess[locatetransform(-47)]=15;
    chess[locatetransform(-37)]=16;
    chess[locatetransform(-27)]=17;
    chess[locatetransform(-17)]=18;
    chess[locatetransform(-7)]=18;
    chess[locatetransform(3)]=17;
    chess[locatetransform(13)]=16;
    chess[locatetransform(23)]=15;
    chess[locatetransform(33)]=14;
    chess[locatetransform(-40)]=17;
    chess[locatetransform(-30)]=18;
    chess[locatetransform(-20)]=19;
    chess[locatetransform(-10)]=20;
    chess[locatetransform(0)]=21;
    chess[locatetransform(10)]=20;
    chess[locatetransform(20)]=19;
    chess[locatetransform(30)]=18;
    chess[locatetransform(40)]=17;
    chess[locatetransform(-33)]=19;
    chess[locatetransform(-23)]=20;
    chess[locatetransform(-13)]=21;
    chess[locatetransform(-3)]=22;
    chess[locatetransform(7)]=23;
    chess[locatetransform(17)]=23;
    chess[locatetransform(27)]=22;
    chess[locatetransform(37)]=21;
    chess[locatetransform(47)]=20;
    chess[locatetransform(57)]=19;
    chess[locatetransform(-26)]=21;
    chess[locatetransform(-16)]=22;
    chess[locatetransform(-6)]=23;
    chess[locatetransform(4)]=24;
    chess[locatetransform(14)]=25;
    chess[locatetransform(24)]=26;
    chess[locatetransform(34)]=25;
    chess[locatetransform(44)]=24;
    chess[locatetransform(54)]=23;
    chess[locatetransform(64)]=22;
    chess[locatetransform(74)]=21;
    chess[locatetransform(-19)]=23;
    chess[locatetransform(-9)]=24;
    chess[locatetransform(1)]=25;
    chess[locatetransform(11)]=26;
    chess[locatetransform(21)]=27;
    chess[locatetransform(31)]=28;
    chess[locatetransform(41)]=28;
    chess[locatetransform(51)]=27;
    chess[locatetransform(61)]=26;
    chess[locatetransform(71)]=25;
    chess[locatetransform(81)]=24;
    chess[locatetransform(91)]=23;
    chess[locatetransform(-12)]=25;
    chess[locatetransform(-2)]=26;
    chess[locatetransform(8)]=27;
    chess[locatetransform(18)]=28;
    chess[locatetransform(28)]=29;
    chess[locatetransform(38)]=30;
    chess[locatetransform(48)]=31;
    chess[locatetransform(58)]=30;
    chess[locatetransform(68)]=29;
    chess[locatetransform(78)]=28;
    chess[locatetransform(88)]=27;
    chess[locatetransform(98)]=26;
    chess[locatetransform(108)]=25;
    chess[locatetransform(45)]=32;
    chess[locatetransform(55)]=33;
    chess[locatetransform(65)]=33;
    chess[locatetransform(75)]=32;
    chess[locatetransform(62)]=35;
    chess[locatetransform(72)]=36;
    chess[locatetransform(82)]=35;
    chess[locatetransform(79)]=38;
    chess[locatetransform(89)]=38;
    chess[locatetransform(96)]=41;
}

void SecondScore(char * chess){

    chess[locatetransform(-96)]=41;
    chess[locatetransform(-89)]=38;
    chess[locatetransform(-79)]=38;
    chess[locatetransform(-82)]=35;
    chess[locatetransform(-72)]=36;
    chess[locatetransform(-62)]=35;
    chess[locatetransform(-75)]=32;
    chess[locatetransform(-65)]=33;
    chess[locatetransform(-55)]=33;
    chess[locatetransform(-45)]=32;
    chess[locatetransform(-108)]=25;
    chess[locatetransform(-98)]=26;
    chess[locatetransform(-88)]=27;
    chess[locatetransform(-78)]=28;
    chess[locatetransform(-68)]=29;
    chess[locatetransform(-58)]=30;
    chess[locatetransform(-48)]=31;
    chess[locatetransform(-38)]=30;
    chess[locatetransform(-28)]=29;
    chess[locatetransform(-18)]=28;
    chess[locatetransform(-8)]=27;
    chess[locatetransform(2)]=26;
    chess[locatetransform(12)]=25;
    chess[locatetransform(-91)]=23;
    chess[locatetransform(-81)]=24;
    chess[locatetransform(-71)]=25;
    chess[locatetransform(-61)]=26;
    chess[locatetransform(-51)]=27;
    chess[locatetransform(-41)]=28;
    chess[locatetransform(-31)]=28;
    chess[locatetransform(-21)]=27;
    chess[locatetransform(-11)]=26;
    chess[locatetransform(-1)]=25;
    chess[locatetransform(9)]=24;
    chess[locatetransform(19)]=23;
    chess[locatetransform(-74)]=21;
    chess[locatetransform(-64)]=22;
    chess[locatetransform(-54)]=23;
    chess[locatetransform(-44)]=24;
    chess[locatetransform(-34)]=25;
    chess[locatetransform(-24)]=26;
    chess[locatetransform(-14)]=25;
    chess[locatetransform(-4)]=24;
    chess[locatetransform(6)]=23;
    chess[locatetransform(16)]=22;
    chess[locatetransform(26)]=21;
    chess[locatetransform(-57)]=19;
    chess[locatetransform(-47)]=20;
    chess[locatetransform(-37)]=21;
    chess[locatetransform(-27)]=22;
    chess[locatetransform(-17)]=23;
    chess[locatetransform(-7)]=23;
    chess[locatetransform(3)]=22;
    chess[locatetransform(13)]=21;
    chess[locatetransform(23)]=20;
    chess[locatetransform(33)]=19;
    chess[locatetransform(-40)]=17;
    chess[locatetransform(-30)]=18;
    chess[locatetransform(-20)]=19;
    chess[locatetransform(-10)]=20;
    chess[locatetransform(0)]=21;
    chess[locatetransform(10)]=20;
    chess[locatetransform(20)]=19;
    chess[locatetransform(30)]=18;
    chess[locatetransform(40)]=17;
    chess[locatetransform(-33)]=14;
    chess[locatetransform(-23)]=15;
    chess[locatetransform(-13)]=16;
    chess[locatetransform(-3)]=17;
    chess[locatetransform(7)]=18;
    chess[locatetransform(17)]=18;
    chess[locatetransform(27)]=17;
    chess[locatetransform(37)]=16;
    chess[locatetransform(47)]=15;
    chess[locatetransform(57)]=14;
    chess[locatetransform(-26)]=11;
    chess[locatetransform(-16)]=12;
    chess[locatetransform(-6)]=13;
    chess[locatetransform(4)]=14;
    chess[locatetransform(14)]=15;
    chess[locatetransform(24)]=16;
    chess[locatetransform(34)]=15;
    chess[locatetransform(44)]=14;
    chess[locatetransform(54)]=13;
    chess[locatetransform(64)]=12;
    chess[locatetransform(74)]=11;
    chess[locatetransform(-19)]=8;
    chess[locatetransform(-9)]=9;
    chess[locatetransform(1)]=10;
    chess[locatetransform(11)]=11;
    chess[locatetransform(21)]=12;
    chess[locatetransform(31)]=13;
    chess[locatetransform(41)]=13;
    chess[locatetransform(51)]=12;
    chess[locatetransform(61)]=11;
    chess[locatetransform(71)]=10;
    chess[locatetransform(81)]=9;
    chess[locatetransform(91)]=8;
    chess[locatetransform(-12)]=5;
    chess[locatetransform(-2)]=6;
    chess[locatetransform(8)]=7;
    chess[locatetransform(18)]=8;
    chess[locatetransform(28)]=9;
    chess[locatetransform(38)]=10;
    chess[locatetransform(48)]=11;
    chess[locatetransform(58)]=10;
    chess[locatetransform(68)]=9;
    chess[locatetransform(78)]=8;
    chess[locatetransform(88)]=7;
    chess[locatetransform(98)]=6;
    chess[locatetransform(108)]=5;
    chess[locatetransform(45)]=7;
    chess[locatetransform(55)]=8;
    chess[locatetransform(65)]=8;
    chess[locatetransform(75)]=7;
    chess[locatetransform(62)]=5;
    chess[locatetransform(72)]=6;
    chess[locatetransform(82)]=5;
    chess[locatetransform(79)]=3;
    chess[locatetransform(89)]=3;
    chess[locatetransform(96)]=1;
}

char *ScoreINIT(bool is_first){

    char *chess_score = (char *)malloc(sizeof(char)*256);

    for(int i=0;i<256;i++)
        chess_score[i] = 0;

    if(!is_first)
        SecondScore(chess_score);
    else
        FirstScore(chess_score);

    return chess_score;
}


int ScoreCaculate(char *chess_score,char start,char end){

    return chess_score[locatetransform(end)] - chess_score[locatetransform(start)];
}


void Random(char * chess){

    int mychess[10];

    int my_chess_color = 2;

    int j=0;
    for(int i =0;i<256;i++){
        if(chess[i] == my_chess_color){
            mychess[j] = (int)locatetransformrevers(i);
            j++;
        }
    }

    int which_chess_to_move;
    int move_direction;

    bool done = false;

    while(!done){

        which_chess_to_move = mychess[(rand()%10)];
        move_direction = rand()%12 + 1;

        switch(move_direction){
            case 1:
                if(chess[locatetransform(which_chess_to_move+7)]==0){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move+7)]=my_chess_color;
                }
            break;
            case 2:
                if(chess[locatetransform(which_chess_to_move-7)]==0){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move-7)]=my_chess_color;
                }
            break;
            case 3:
                if(chess[locatetransform(which_chess_to_move+10)]==0){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move+10)]=my_chess_color;
                }
            break;
            case 4:
                if(chess[locatetransform(which_chess_to_move-10)]==0){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move-10)]=my_chess_color;
                }
            break;
            case 5:
                if(chess[locatetransform(which_chess_to_move+17)]==0){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move+17)]=my_chess_color;
                }
            break;
            case 6:
                if(chess[locatetransform(which_chess_to_move-17)]==0){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move-17)]=my_chess_color;
                }
            break;
            case 7:
                if(chess[locatetransform(which_chess_to_move+7)]==my_chess_color && \
                   chess[locatetransform(which_chess_to_move+14)]==0 ){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move+14)]=my_chess_color;
                }
            break;
            case 8:
                if(chess[locatetransform(which_chess_to_move-7)]==my_chess_color && \
                   chess[locatetransform(which_chess_to_move-14)]==0 ){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move-14)]=my_chess_color;
                }
            break;
            case 9:
                if(chess[locatetransform(which_chess_to_move+10)]==my_chess_color && \
                   chess[locatetransform(which_chess_to_move+20)]==0 ){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move+20)]=my_chess_color;
                }
            break;
            case 10:
                if(chess[locatetransform(which_chess_to_move-10)]==my_chess_color && \
                   chess[locatetransform(which_chess_to_move-20)]==0 ){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move-20)]=my_chess_color;
                }
            break;
            case 11:
                if(chess[locatetransform(which_chess_to_move+17)]==my_chess_color && \
                   chess[locatetransform(which_chess_to_move+34)]==0 ){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move+34)]=my_chess_color;
                }
            break;
            case 12:
                if(chess[locatetransform(which_chess_to_move-17)]==my_chess_color && \
                   chess[locatetransform(which_chess_to_move-34)]==0 ){
                    done = true;
                    chess[locatetransform(which_chess_to_move)]=0;
                    chess[locatetransform(which_chess_to_move-34)]=my_chess_color;
                }
            break;
        }
    }
}

bool PathIsFinish(Array *path,int end){
    char *element;
    array_get_at(path, array_size(path)-1,(void*)&element);
    if(*element == end)
        return true;
    else
        return false;
}

void FindJumpPath(char * chess,char start,char end,Array * path){

    char *element;
    int value;

    if(!Visited(start,path)){

        element = (char *)malloc(sizeof(char));
        *element = start;
        array_add(path, element);

        value = *element;

        if(start == end)
            return;
/*
        for(int i=0;i<array_size(path);i++){
            array_get_at(path, i,(void*)&element);
            printf("%3d ->",*element);
        }
        system("PAUSE");
*/

        if( chess[locatetransform(start+14)]==0 && chess[locatetransform(start+7)]!=0 && chess[locatetransform(start+7)]!=-1){
            FindJumpPath(chess,start+14,end,path);
            if(PathIsFinish(path,end))
                return;
        }
        if( chess[locatetransform(start+20)]==0 && chess[locatetransform(start+10)]!=0 && chess[locatetransform(start+10)]!=-1){
            FindJumpPath(chess,start+20,end,path);
            if(PathIsFinish(path,end))
                return;
        }
        if( chess[locatetransform(start+34)]==0 && chess[locatetransform(start+17)]!=0 && chess[locatetransform(start+17)]!=-1){
            FindJumpPath(chess,start+34,end,path);
            if(PathIsFinish(path,end))
                return;
        }
        if( chess[locatetransform(start-14)]==0 && chess[locatetransform(start-7)]!=0 && chess[locatetransform(start-7)]!=-1){
            FindJumpPath(chess,start-14,end,path);
            if(PathIsFinish(path,end))
                return;
        }
        if( chess[locatetransform(start-20)]==0 && chess[locatetransform(start-10)]!=0 && chess[locatetransform(start-10)]!=-1){
            FindJumpPath(chess,start-20,end,path);
            if(PathIsFinish(path,end))
                return;
        }
        if( chess[locatetransform(start-34)]==0 && chess[locatetransform(start-17)]!=0 && chess[locatetransform(start-17)]!=-1){
            FindJumpPath(chess,start-34,end,path);
            if(PathIsFinish(path,end))
                return;
        }
    }
    else
        return;

    array_remove_at(path, array_size(path)-1,(void*)&element);
}

bool ISJumpToOthersHome(char end_point){

    bool is_illegal = false;
    int illegal[20]={-12,-19,-2,8,-9,-26,18,1,-16,-33,108,98,91,88,81,74,78,71,64,57};
    for(int i=0;i<20;i++){
        if(illegal[i]==end_point || (illegal[i])*(-1)==end_point){
            is_illegal = true;
            break;
        }
    }
    return is_illegal;
}

char* IntToString(int integer){

    char *result=(char *)malloc(sizeof(char)*256);

    if(integer>=0){
        itoa(integer,result,10);
        return result;
    }
    else{
        char posint[10];
        integer = abs(integer);
        result[0]='-';
        result[1]='\0';
        itoa(integer,posint,10);
        strcat(result, posint);
        return result;
    }
}

void Greedy(SOCKET sclient,char * chess,int my_chess_color,int turn){

    bool is_first;

    if(my_chess_color ==1)
        is_first = true;
    if(my_chess_color ==2)
        is_first = false;

    int mychess[10];

    int j=0;

    char * chess_score = ScoreINIT(is_first);

    int firstgoal[10]={75,65,55,45,82,72,62,89,79,96};
    int secondgoal[10]={-75,-65,-55,-45,-82,-72,-62,-89,-79,-96};

    int *mygoal;
    if(is_first)
        mygoal = &firstgoal;
    else
        mygoal = &secondgoal;

    if(turn >= 120){

        int count=0;
        int lostone;
        for(int i=0;i<10;i++){
            if(chess[locatetransform(mygoal[i])]==my_chess_color){
                count++;
            }
            else
                lostone = mygoal[i];
        }

        if(count==9){
            chess_score[locatetransform(lostone)] = chess_score[locatetransform(lostone)] + 3;
            chess_score[locatetransform(lostone+7)] = chess_score[locatetransform(lostone+7)] +2;
            chess_score[locatetransform(lostone-7)] = chess_score[locatetransform(lostone-7)] +2;
            chess_score[locatetransform(lostone+10)] = chess_score[locatetransform(lostone+10)] +2;
            chess_score[locatetransform(lostone-10)] = chess_score[locatetransform(lostone-10)] +2;
            chess_score[locatetransform(lostone+17)] = chess_score[locatetransform(lostone+17)] +2;
            chess_score[locatetransform(lostone-17)] = chess_score[locatetransform(lostone-17)] +2;
            chess_score[locatetransform(lostone+14)] = chess_score[locatetransform(lostone+14)] +1;
            chess_score[locatetransform(lostone-14)] = chess_score[locatetransform(lostone-14)] +1;
            chess_score[locatetransform(lostone+20)] = chess_score[locatetransform(lostone+20)] +1;
            chess_score[locatetransform(lostone-20)] = chess_score[locatetransform(lostone-20)] +1;
            chess_score[locatetransform(lostone+34)] = chess_score[locatetransform(lostone+34)] +1;
            chess_score[locatetransform(lostone-34)] = chess_score[locatetransform(lostone-34)] +1;
        }
    }


    //printf("%d %d %d",chess_score[locatetransform(-96)],chess_score[locatetransform(-62)],chess_score[locatetransform(-48)]);
    //system("PAUSE");

    for(int i =0;i<256;i++){
        if(chess[i] == my_chess_color){
            mychess[j] = (int)locatetransformrevers(i);
            j++;
        }
    }

    Array *ends;
    char best_move_start;
    char best_move_end;
    char * element;
    int best_score = -65535;
    int score_tmp;

    for(int i =0;i<10;i++){
        ends = ReturnAllOfTheMove(chess,mychess[i]);
        for(int j=0;j<array_size(ends);j++){
            array_get_at(ends, j,(void*)&element);
            if(!ISJumpToOthersHome(*element)){
                score_tmp = ScoreCaculate(chess_score,mychess[i],*element);
                if(score_tmp>best_score){
                    best_score = score_tmp;
                    best_move_start = mychess[i];
                    best_move_end = *element;
                }
            }
        }
    }


    char *string_part = NULL;
    char *token = ",";
    char send_string[256]={0};

    Array *path;
    array_new(&path);
    if(abs(best_move_end-best_move_start)==7 || abs(best_move_end-best_move_start)==10 || abs(best_move_end-best_move_start)==17){
        //printf("%3d -> %3d\n",best_move_start,best_move_end);
        string_part = IntToString((int)best_move_start);
        strcat(send_string,string_part);
        strcat(send_string,token);
        string_part = IntToString((int)best_move_end);
        strcat(send_string,string_part);
    }
    else{
        FindJumpPath(chess,best_move_start,best_move_end,path);
        for(int i=0;i<array_size(path);i++){
            array_get_at(path, i,(void*)&element);
            //printf("%3d ->",*element);
            string_part = IntToString((int)*element);
            strcat(send_string,string_part);
            strcat(send_string,token);
        }
        printf("\n");
        for(int i=0;i<256;i++){
            if(send_string[i]=='\0'){
                send_string[i-1]='\0';
                break;
            }
        }
    }
    //system("PAUSE");

    chess[locatetransform(best_move_start)]=0;
    chess[locatetransform(best_move_end)]=my_chess_color;

    array_destroy(path);
    array_destroy(ends);

    int length=0;
    for(int i=0;i<256;i++){
        if(send_string[i]=='\0')
            length = i;
    }
    send(sclient, send_string, length, 0);
}

void GreedyWithoutSend(char * chess,int my_chess_color,int turn){

    int mychess[10];

    int j=0;

    bool is_first;

    if(my_chess_color ==1)
        is_first = true;
    if(my_chess_color ==2)
        is_first = false;

    char * chess_score = ScoreINIT(is_first);

    int firstgoal[10]={75,65,55,45,82,72,62,89,79,96};
    int secondgoal[10]={-75,-65,-55,-45,-82,-72,-62,-89,-79,-96};

    int *mygoal;
    if(is_first)
        mygoal = &firstgoal;
    else
        mygoal = &secondgoal;

    if(turn >= 145){

        int count=0;
        int lostone;
        for(int i=0;i<10;i++){
            if(chess[locatetransform(mygoal[i])]==my_chess_color){
                count++;
            }
            else
                lostone = mygoal[i];
        }

        if(count==9){
            chess_score[locatetransform(lostone)] = chess_score[locatetransform(lostone)] + 3;
            chess_score[locatetransform(lostone+7)] = chess_score[locatetransform(lostone+7)] +2;
            chess_score[locatetransform(lostone-7)] = chess_score[locatetransform(lostone-7)] +2;
            chess_score[locatetransform(lostone+10)] = chess_score[locatetransform(lostone+10)] +2;
            chess_score[locatetransform(lostone-10)] = chess_score[locatetransform(lostone-10)] +2;
            chess_score[locatetransform(lostone+17)] = chess_score[locatetransform(lostone+17)] +2;
            chess_score[locatetransform(lostone-17)] = chess_score[locatetransform(lostone-17)] +2;
            chess_score[locatetransform(lostone+14)] = chess_score[locatetransform(lostone+14)] +1;
            chess_score[locatetransform(lostone-14)] = chess_score[locatetransform(lostone-14)] +1;
            chess_score[locatetransform(lostone+20)] = chess_score[locatetransform(lostone+20)] +1;
            chess_score[locatetransform(lostone-20)] = chess_score[locatetransform(lostone-20)] +1;
            chess_score[locatetransform(lostone+34)] = chess_score[locatetransform(lostone+34)] +1;
            chess_score[locatetransform(lostone-34)] = chess_score[locatetransform(lostone-34)] +1;
        }
    }


    //printf("%d %d %d",chess_score[locatetransform(-96)],chess_score[locatetransform(-62)],chess_score[locatetransform(-48)]);
    //system("PAUSE");

    for(int i =0;i<256;i++){
        if(chess[i] == my_chess_color){
            mychess[j] = (int)locatetransformrevers(i);
            j++;
        }
    }

    Array *ends;
    char best_move_start;
    char best_move_end;
    char * element;
    int best_score = -65535;
    int score_tmp;

    for(int i =0;i<10;i++){
        ends = ReturnAllOfTheMove(chess,mychess[i]);
        for(int j=0;j<array_size(ends);j++){
            array_get_at(ends, j,(void*)&element);
            if(!ISJumpToOthersHome(*element)){
                score_tmp = ScoreCaculate(chess_score,mychess[i],*element);
                if(score_tmp>best_score){
                    best_score = score_tmp;
                    best_move_start = mychess[i];
                    best_move_end = *element;
                }
            }
        }
    }

    Array *path;
    array_new(&path);
    if(abs(best_move_end-best_move_start)==7 || abs(best_move_end-best_move_start)==10 || abs(best_move_end-best_move_start)==17){
        printf("%3d -> %3d\n",best_move_start,best_move_end);
    }
    else{
        FindJumpPath(chess,best_move_start,best_move_end,path);
        for(int i=0;i<array_size(path);i++){
            array_get_at(path, i,(void*)&element);
            printf("%3d ->",*element);
        }
        printf("\n");
    }
    //system("PAUSE");

    chess[locatetransform(best_move_start)]=0;
    chess[locatetransform(best_move_end)]=my_chess_color;

    array_destroy(path);
    array_destroy(ends);
}
