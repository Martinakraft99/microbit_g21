#include "IO.h"
#include "gpio.h"

int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	int sleep = 0;
	while(1){

    sendChar();
    reciveChar();



		sleep = 10000;
		while(--sleep);
	}
	return 0;
}
