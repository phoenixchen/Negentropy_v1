#include <stdio.h>
#include <WINSOCK2.H>
#include <time.h>
#include "engine.h"
#pragma  comment(lib,"ws2_32.lib")

int *order;
char *chess;
char buf[255];
int length;
void initmsg(void);
SOCKET socket_connect(void);
int init_order(SOCKET sclient);
void ManualInput(SOCKET sclient);
int myorder;

int main(int argc, char* argv[])
{

    chess = (char *)malloc(sizeof(char)*256);

    SOCKET sclient = socket_connect();
    if(sclient == 0)
        return 0;
    int my_chess_color = init_order(sclient);
    int enemy_chess_color;
    if(my_chess_color==1)
        enemy_chess_color = 2;
    if(my_chess_color==2)
        enemy_chess_color = 1;

    int turn =0;
    int increaseturn = 1;

    char *token=",";
    char *stringtok;

    while(1){
        if((turn+1) == myorder){
            if(increaseturn<13){
                switch(increaseturn){
                    case 1:chess[locatetransform(-45)]=0;chess[locatetransform(-38)]=1;send(sclient,"-45,-38",7,0);break;
                    case 2:chess[locatetransform(45)]=0;chess[locatetransform(38)]=2;send(sclient,"45,38",5,0);break;
                    case 3:chess[locatetransform(-79)]=0;chess[locatetransform(-31)]=1;send(sclient,"-79,-45,-31",11,0);break;
                    case 4:chess[locatetransform(79)]=0;chess[locatetransform(31)]=2;send(sclient,"79,45,31",8,0);break;
                    case 5:chess[locatetransform(-82)]=0;chess[locatetransform(-14)]=1;send(sclient,"-82,-48,-14",11,0);break;
                    case 6:chess[locatetransform(82)]=0;chess[locatetransform(14)]=2;send(sclient,"82,48,14",8,0);break;
                    case 7:chess[locatetransform(-96)]=0;chess[locatetransform(-28)]=1;send(sclient,"-96,-82,-48,-28",15,0);break;
                    case 8:chess[locatetransform(96)]=0;chess[locatetransform(28)]=2;send(sclient,"96,82,48,28",11,0);break;
                    case 9:chess[locatetransform(-55)]=0;chess[locatetransform(-7)]=1;send(sclient,"-55,-21,-7",10,0);break;
                    case 10:chess[locatetransform(55)]=0;chess[locatetransform(7)]=2;send(sclient,"55,21,7",7,0);break;
                    case 11:chess[locatetransform(-89)]=0;chess[locatetransform(-41)]=1;send(sclient,"-89,-55,-21,-41",15,0);break;
                    case 12:chess[locatetransform(89)]=0;chess[locatetransform(41)]=2;send(sclient,"89,55,21,41",11,0);break;
                }
            }
            else
                Greedy(sclient,chess,my_chess_color,increaseturn);
            increaseturn++;
        }
        else{
            if(order[turn]!=0){
                length = recv(sclient, buf, 255, 0);
                if(length > 0){
                    buf[length] = '\0';
                    printf("AI程式接收到了其他人走");
                    printf(buf);
                    printf("\n\n");

                    char copy_string[255];
                    strcpy(copy_string,buf);
                    copy_string[length] = '\0';
                    int times = 0;
                    stringtok = strtok(copy_string, token);
                    while(stringtok!= NULL){
                        stringtok = strtok(NULL, token);
                        times++;
                    }

                    stringtok = strtok(buf, token);
                    int prev;

                    chess[locatetransform(atoi(stringtok))]=0;
                    prev = atoi(stringtok);

                    for(int i=0;i<times-1;i++){
                        stringtok = strtok(NULL, token);
                        chess[locatetransform(atoi(stringtok))]=enemy_chess_color;
                        chess[locatetransform(prev)]=0;
                        prev = atoi(stringtok);
                    }
                    initmsg();
                }
                increaseturn++;
            }
        }
        turn++;
        if(turn==6)
            turn =0;
    }

    closesocket(sclient);
    WSACleanup();
    return 0;
}

void initmsg(void){
    for(int i =0;i<255;i++)
        buf[i]='\0';
}

SOCKET socket_connect(void){

    WORD sockVersion = MAKEWORD(2,2);
    WSADATA data;
    if(WSAStartup(sockVersion, &data) != 0){
        return 0;
    }

    SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sclient == INVALID_SOCKET){
        printf("invalid socket!");
        return 0;
    }

    struct sockaddr_in serAddr;
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(894);
    serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (connect(sclient, (struct sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
    {
        printf("connect error!");
        closesocket(sclient);
        return 0;
    }

    return sclient;
}

int init_order(SOCKET sclient){

    char *token = ",";
    char *stringtok;

    int max_clients = 6;
    order = (int *)malloc(sizeof(int)*max_clients);
    for(int i=0;i<max_clients;i++)
        order[i] = 0;

    int len = recv(sclient,buf,255,0);
    buf[len] = '\0';

    char playercount = -1,human = -1,AIorder =-1;

    if(len > 0){
        stringtok = strtok(buf,token);
        playercount = (char)atoi(stringtok);
        stringtok = strtok(NULL, token);
        human = (char)atoi(stringtok);
        stringtok = strtok(NULL, token);
        AIorder = (char)atoi(stringtok);
    }

    myorder = AIorder;

    if(playercount==2)
        initchess1v1(chess);
    if(playercount==3)
        initchess1v1v1(chess);

    printf("我是%d號玩家\n",AIorder);
    initmsg();

    if(human!=0)
        order[human-1] = -1;

    if(human!=0)
        playercount = playercount-1;
    else
        playercount = playercount;

    int AInumber = 1;

    for(int i=0;i<max_clients;i++){
        if(order[i]==0){
            order[i] =AInumber;
            playercount--;
            AInumber++;
        }
        if(playercount==0)
            break;
    }

    printf("\n\n");
    for(int i=0;i<max_clients;i++){
        printf("%d ,",order[i]);
    }
    printf("\n");

    if(human!=0){
        if(AIorder>human)
            return (int)AIorder;
        else
            return (int)AIorder+1;
    }
    else
        return (int)AIorder;
}

void ManualInput(SOCKET sclient){

    char input[256];

    for(int i=0;i<256;i++){
        input[i]=0;
    }

    printf("請輸入要走的位置:(from,to)\n");
    scanf("%s",&input);
    printf("\n");

    int length=0;
    for(int i=0;i<256;i++){
        if(input[i]=='\0')
            length = i;
    }

    send(sclient, input, length, 0);
}
