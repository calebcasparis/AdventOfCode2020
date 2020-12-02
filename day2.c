#include <stdio.h>

#define MAXCHAR 50

/****************************************************************
 *  .-.                                                   \ /	*
 * ( (                                |                  - * -	*
 *  '-`                              -+-                  / \	*
 *           \            o          _|_          \		*
 *           ))          }^{        /___\         ))		*
 *         .-#-----.     /|\     .---'-'---.    .-#-----.	*
 *    ___ /_________\   //|\\   /___________\  /_________\	*
 *   /___\ |[] _ []|    //|\\    | A /^\ A |    |[] _ []| _.O,_	*
 *...|"#"|.|  |*|  |...///|\\\...|   |"|   |....|  |*|  |..(^)..*
 *								*
 ****************************************************************/

main()

{
	int i;
	char c;

	int min, max, inv1, inv2, inst, ninputs;
	char password[MAXCHAR];
	inv1 = inv2 = ninputs = 0;

	while((fscanf(stdin,"%d-%d %c: %s\n", &min, &max, &c, &password)) != EOF) {

		inst = 0;								//Counts instances of the important character

		for(int i=0; password[i] != '\0'; ++i) {
			if(password[i] == c) {
				++inst;
			}
        	}
		if(min > inst || max < inst) {
			++inv1;
		}
		if(!((password[min-1] == c) != (password[max-1] == c))) {		//Corrects for index 0
			++inv2;
		}
		++ninputs;

	}
	printf("\nValid Part 1: %d\nValid Part 2: %d\n",ninputs-inv1,ninputs-inv2);
	return 0;

}
