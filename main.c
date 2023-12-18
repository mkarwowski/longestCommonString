#include <stdio.h>

#define X 5
#define Y 4

void printTabCh (char* x, int l) {
	int i;
	for (i = 0; i < l; i++) {
		printf("%c", x[i]);
	}
	printf("\n");
}


int main() {
	char x[X] = "accaa";
	char y[Y] = "acac";
	int b[X+1][Y+1];
	char c[X+1][Y+1];

	printTabCh(x, X);
	printTabCh(y, Y);

    int i,j;
    //zerowanie pierwszego wiersza i pierwszej kolumny
    for(i = 0; i <= X; i++) {
        b[i][0] = 0;
    }
    for(i = 0; i <= Y; i++) {
        b[0][i] = 0;
    }

    //uzupelnianie tablicy b[][] i c[][]
    for (i = 1; i <= X; i++) {
			for (j = 1; j <= Y; j++) {
				if (x[i - 1] == y[j - 1]) {
					b[i][j] = b[i-1][j-1] + 1;
					c[i][j] = '+';//zamienilem znak "\" na "+"
				}
				else if (b[i-1][j] >= b[i][j-1]) {
					b[i][j] = b[i-1][j];
					c[i][j] = '|';
				}
				else {
					b[i][j] = b[i][j-1];
					c[i][j] = '-';
				}
			}
		}
	int length = b[X][Y];
	int lengthM = length;
	char wynik[length];

    //drukowanie tabeli
    for(i = 0; i <= X; i++) {
        for (j = 0; j <= Y; j++) {
            if (i == 0 || j == 0) {
                printf("%d\t", b[i][j]);
                if (j == Y) printf("\n", b[i][j]);
            }
            else if (j == Y) {
                printf("%c%d\n", c[i][j], b[i][j]);
            }
            else {
                printf("%c%d\t", c[i][j], b[i][j]);
            }
        }
    }
    //drukowanie slowa
    i = X;
    j = Y;
    while (length != 0) {
        if (c[i][j] == '+') {
            wynik[length - 1] = x[i-1];
            length--;
            i--;
            j--;
        }
        else if (c[i][j] == '|') {
            i--;
        }
        else if (c[i][j] == '-') {
            j--;
        }
        else break;
    }
    printf("\n_____________________________________________\n\nNajdluzszy wspolny podciag: ");
    printTabCh(wynik, lengthM);

	return 0;
	}
