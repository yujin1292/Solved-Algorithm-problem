#include "heap+map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
	node tmap; 
	heap theap;
	FILE *fp = fopen("obama.txt", "r+t");
	char input[64];
	tmap.init();
	while (fscanf(fp, "%s", input) != EOF) {
		if (!is_word(input)) 
			continue;
		tmap.insert(input);
	}

	theap.init();
	int dcnt; 
	hnode temp;
	temp.init();


	while (1) {
		strcpy(input, tmap.get_data());
		dcnt = tmap.get_cnt();

		temp.set(dcnt, input); 

		theap.push(temp);
		if (tmap.remove(input)) 
			break;

	}
	/*for (int i = 1; i < theap.get_cnt(); i++) {
		theap.list(i).print();
	}
	printf("\n\n");*/

	int i; 
	for (i = 0; i < 10; i++) { 
		printf("[%d]  ", i+1);
		temp = theap.pop();
		printf("%s (%d)\n", temp.get_data(), temp.get_cnt());
	}

	/*for (int i = 1; i < theap.get_cnt(); i++) {
		theap.list(i).print();
	}*/

	return 0;
	system("pause"); 

}