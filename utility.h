#include <WINSOCK2.H>
#include "array.h"

void initadjlist(char * chess,struct adjlist * adjlist1,struct adjlist * adjlist2);

int compare(void const *e1, void const *e2);

bool Visited(char new_element, Array *ends);

void FindAllJump(char * chess , char start , Array *ends);

Array * ReturnAllOfTheMove(char * chess , char start);

void FirstScore(char * chess);

void SecondScore(char * chess);

char *ScoreINIT(bool is_first);

int ScoreCaculate(char *chess_score,char start,char end);

void Random(char * chess);

Array *FindPath(chess,best_move_start,best_move_end);

bool ISJumpToOthersHome(char end_point);

char* IntToString(int integer);

void Greedy(SOCKET sclient,char * chess,int my_chess_color,int turn);

void GreedyWithoutSend(char * chess,int my_chess_color,int turn);
