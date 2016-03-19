#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/* wielkosc alfabetu */
#define ASIZE 255

char *bad_character_shift;
int *good_suffix_shift;
int *suff;

/* prepare bad character shift table */
void pre_bad_character_shift(char *pattern, int m) {
        int i;

        for (i = 0; i < ASIZE; i++) {
                bad_character_shift[i] = m;
        }

        for (i = 0; i < m - 1; ++i) {
                bad_character_shift[(int)pattern[i]] = m - i - 1;
	}
}

/* prepare suff table */
void pre_suff(char *pattern, int m) {
        int i, j;
        
	suff[m - 1] = m;
        for (i = m - 2; i >= 0; --i) {
       		for (j = 0; j <= i && pattern[i-j] == pattern[m-j-1]; j++);
        	suff[i] = j;
        }
}

/* prepare good_suffix_shift table */
void pre_good_suffix_shift(char *pattern, int m) {
        int i,j;

        pre_suff(pattern,m);

        for (i = 0; i < m; i++) {
        	good_suffix_shift[i] = m;
        }

        j = 0;
        for (i = m - 1; i >= 0; --i) {
        	if (suff[i] == i + 1) {
        		for (; j < m - 1 - i; ++j) {
        			good_suffix_shift[j] = m - 1 - i;
        		}
        	}
        }

        for (i = 0; i <= m - 2; ++i) {
        	good_suffix_shift[m - 1 - suff[i]] = m - 1 - i;
	}
}

int maximum(int value1, int value2) { return ( (value1 > value2) ? value1 : value2); }


/* Boyer-Moore algorithm */
int BM(char *text, int n, char *pattern, int m) {
        int i, j;
	int wynik;

        pre_bad_character_shift(pattern,m);
        pre_good_suffix_shift(pattern,m);

        j = 0;
        while (j <= n - m) {
        	for (i = m - 1; i >= 0 && pattern[i] == text[i + j]; --i);
        	if (i < 0) {
        		wynik = j;
			j += good_suffix_shift[0];
        	} else {
        		j += maximum(good_suffix_shift[i], bad_character_shift[(int)text[i + j]] - m + 1 + i);
        	}
	}
	return wynik;
}

float uruchom_algorytm_bm(int ile_elementow_tekst,char* tablica_znakow,int ile_elementow_wzorzec,char* tablica_wzorzec) {
	clock_t start;
	int wynik = 0;
	float time = 0.0;
		
	start = clock();

	bad_character_shift = (char*)malloc(ASIZE * sizeof(bad_character_shift));
	good_suffix_shift = (int*)malloc(ile_elementow_wzorzec * sizeof(good_suffix_shift));
	suff = (int*)malloc(ile_elementow_wzorzec * sizeof(suff));

   	wynik = BM(tablica_znakow, ile_elementow_tekst, tablica_wzorzec, ile_elementow_wzorzec);
	
	time = (clock() - start) / (float)CLOCKS_PER_SEC;
	printf("Pozycja wzorca w tekście: %d\n",++wynik);
	sleep(2);
	return time;
}
