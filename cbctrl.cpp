

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "cbredisclient.h"
#include <sstream>
//#include <sys/filio.h>

using namespace std;

int main(int argc, char* argv[]){
	if (argc != 2){
		printf("Please povide a chatter id.\n \
			\t cbctrl CHATTERBOX_ID\n \
			for example: cbctrl cb13\n");
		return 1;
	}
	printf("Chatterbox remote controller usage:\n \
		\t press the key continuously\n	      \
		\t w for forward\n                    \
		\t s for backward\n                   \
		\t a for left\n                       \
		\t d for right\n                      \
		\t z for spin\n                       \
		\t q for quit (IMPORTANT!)\n                      \
		\n if none of the keys is pressed, the chatterbox stops.\n");
	CBRedisClient* redis = new CBRedisClient(argv[1], "hal", 6379);
	char input = 0;
	char prev = 0;
	while(input != 'q'){
		system("stty raw");
		input = getchar();
		string inputs;
		stringstream ss;
		ss << input;
		ss >> inputs;	
		
		if(!redis->setCommand(inputs)){
			cout << "error set command!" << endl;
		}
		if(input != prev){
			switch (input){
			case 'w':
				cout << endl << "moving forward" << endl;
				break;
			case 'a':
				cout << endl << "moving left" << endl;
				break;
			case 's':
				cout << endl << "moving backward" << endl;
				break;
			case 'd':
				cout << endl << "moving right" << endl;
				break;
			}
		}
		prev = input;
		inputs.empty();
		system("stty cooked");
	}
	return 0;
}


