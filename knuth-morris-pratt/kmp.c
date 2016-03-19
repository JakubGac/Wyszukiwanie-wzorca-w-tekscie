#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int max(int value1, int value2) { return ( (value1 > value2) ? value1 : value2); }

float uruchom_algorytm_kmp(int ile_elementow_tekst,char* tablica_znakow,int ile_elementow_wzorzec,char* tablica_wzorzec) {
	int i,j,t;
	int *tablica = (int*)malloc(ile_elementow_wzorzec * sizeof(*tablica));
	int wynik = 0;
	float time = 0.0;
	clock_t start = clock();

	/* obliczanie tablicy */
	tablica[0] = 0;
	tablica[1] = 0;
	t = 0;
	for(j=2 ; j <= ile_elementow_wzorzec ; j++){
		while ( (t > 0) && (tablica_wzorzec[t] != tablica_wzorzec[j-1]) ) 
			t = tablica[t];
        	if (tablica_wzorzec[t] == tablica_wzorzec[j-1]) 
			t++;
        	tablica[j] = t;
	}

	/* algorytm KMP */
	i = 1;
	j = 0;
	while( i <= ile_elementow_tekst - ile_elementow_wzorzec + 1 ) {
		j = tablica[j];
        	while( (j < ile_elementow_wzorzec) && (tablica_wzorzec[j] == tablica_znakow[i + j - 1]) ) j++;
        	if (j == ile_elementow_wzorzec) wynik = i;
        	i = i + max(1, j - tablica[j]);
	}

	time = (clock() - start ) / (float)CLOCKS_PER_SEC;	

	printf("Pozycja wzorca w tekście: %d\n",wynik);
	sleep(2);
	return time;
}
