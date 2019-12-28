#include <stdio.h>

char inputarr[100];
char operarr[100];
int numberArr[100];

int inputCnt = 0;
int opercnt = 0;
int numarr = 0;

void printop() {
	for (int i = 0; i < opercnt; i++) {
		printf("%5c", operarr[i]);
	}
}

void outputnum() {
	for (int i = 0; i < numarr; i++) {
		printf("%d", numberArr[i]);
	}
}

void firstoper(int a) {

	int i;
	for (i = a; i < opercnt; i++) {
		operarr[i] = operarr[i + 1];
	}
}

void firstnum(int a) {
	int i;
	for (i = a; i < numarr; i++) {
		numberArr[i] = numberArr[i + 1];
	}
}
int gopandna() {
	int i;
	for (i = 0; i < opercnt; i++) {
		if (operarr[i] == '*' || operarr[i] == '/') {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int plsandmin() {
	int i;
	for (i = 0; i < opercnt; i++) {
		if (operarr[i] == '+' || operarr[i] == '-') {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int main() {
	printf("> ");
	gets(inputarr);
	printf(">>");

	int i;
	int sum = 0;
	for (i = 0; inputarr[i] != NULL; i++) {

		inputCnt++;
		if ('0' <= inputarr[i] && inputarr[i] <= '9') {
			sum = (sum * 10) + inputarr[i] - 48;
		}

		else if (inputarr[i] == '+' || inputarr[i] == '-' || inputarr[i] == '*' || inputarr[i] == '/') {

			operarr[opercnt] = inputarr[i];
			opercnt++;

			numberArr[numarr] = sum;
			numarr++;
			sum = 0;
		}

		else if (inputarr[i] == 'q' || inputarr[i] == 'Q') {
			return 0;
		}
	}

	if (inputarr[0] == '-' && opercnt == 0) {
		return 0;
	}

	numberArr[numarr] = sum;
	numarr++;



	do {

		for (i = 0; i < opercnt; i++) {
			if (operarr[i] == '*') {
				numberArr[i] = numberArr[i] * numberArr[i + 1];
				firstnum(i + 1);
				numarr--;

				operarr[i] = 'a';
				firstoper(i);
				opercnt--;
			}

			else if (operarr[i] == '/') {
				numberArr[i] = numberArr[i] / numberArr[i + 1];
				firstnum(i + 1);
				numarr--;

				operarr[i] = 'a';
				firstoper(i);
				opercnt--;
			}
		}

	} while (gopandna() == 1);

	do {

		for (i = 0; i < opercnt; i++) {
			if (operarr[i] == '+') {
				numberArr[i] = numberArr[i] + numberArr[i + 1];
				firstnum(i + 1);
				numarr--;

				operarr[i] = 'a';
				firstoper(i);
				opercnt--;
			}

			else if (operarr[i] == '-') {
				numberArr[i] = numberArr[i] - numberArr[i + 1];
				firstnum(i + 1);
				

				operarr[i] = 'a';
				firstoper(i);
				opercnt--;
			}
		}

	} while (plsandmin() == 1);

	outputnum();

}