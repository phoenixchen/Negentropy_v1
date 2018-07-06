#include <WINSOCK2.H>
#include <time.h>

int locatetransform(char locate) {

    int after = 0;
	if (locate > 0)
		after = locate + 128;
	if (locate <= 0)
		after = abs(locate);
	return after;
}

char locatetransformrevers(int locate){

    int before = 0;
	if (locate > 128)
		before = locate - 128;
	if (locate <= 128)
		before = 0 - locate;
	return before;
}

void initchess1v1(char * chess) {

    int i = 0;
	for (i = 0; i < 256; i++) {
		chess[i] = 0;
	}

	char wall[26] = { 5,15,22,25,29,35,36,43,50,52,67,69,84,85,86,92,95,99,101,103,105,106,113,115,118,125 };
	for (i = 0; i < 26; i++) {
		chess[wall[i]] = -1;
		chess[(wall[i]+128)] = -1;		//正的為該值+128，負的為該值取絕對值
	}

	char init1v1[10] = {75,65,55,45,82,72,62,89,79,96};
    for (i = 0; i < 10; i++) {
		chess[init1v1[i]] = 1;
		chess[(init1v1[i]+128)] = 2;		//正的為該值+128，負的為該值取絕對值
	}

}

void initchess1v1v1(char * chess) {

    int i = 0;
	for (i = 0; i < 256; i++) {
		chess[i] = 0;
	}

	char wall[26] = { 5,15,22,25,29,35,36,43,50,52,67,69,84,85,86,92,95,99,101,103,105,106,113,115,118,125 };
	for (i = 0; i < 26; i++) {
		chess[wall[i]] = -1;
		chess[(wall[i]+128)] = -1;		//正的為該值+128，負的為該值取絕對值
	}

	char init1v1v1[30] = {-75,-65,-55,-45,-82,-72,-62,-89,-79,-96,-12,-2,8, \
	18,-19,-9,1,-26,-16,-33,78,88,98,108,71,81,91,64,74,57};
    for (i = 0; i < 10; i++) {
        chess[locatetransform(init1v1v1[i])] = 1;
	}
    for (i = 10; i < 20; i++) {
        chess[locatetransform(init1v1v1[i])] = 2;
	}
    for (i = 20; i < 30; i++) {
        chess[locatetransform(init1v1v1[i])] = 3;
	}

}

void initchessTEST(char * chess) {

    int i = 0;
	for (i = 0; i < 256; i++) {
		chess[i] = 0;
	}

	char wall[26] = { 5,15,22,25,29,35,36,43,50,52,67,69,84,85,86,92,95,99,101,103,105,106,113,115,118,125 };
	for (i = 0; i < 26; i++) {
		chess[wall[i]] = -1;
		chess[(wall[i]+128)] = -1;		//正的為該值+128，負的為該值取絕對值
	}

	char init1v1[10] = {79,72,82,58,31,34,38,55,7,21};
    for (i = 0; i < 10; i++) {
		chess[init1v1[i]] = 1;
		chess[(init1v1[i]+128)] = 2;		//正的為該值+128，負的為該值取絕對值
	}

}
