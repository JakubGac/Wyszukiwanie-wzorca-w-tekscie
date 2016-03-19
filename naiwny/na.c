#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

float uruchom_algorytm_na(int ile_elementow_tekst,char* tablica_znakow,int ile_elementow_wzorzec,char* tablica_wzorzec) {
	clock_t start= clock();
	char *wzorzec = tablica_wzorzec;
	char *tekst = tablica_znakow;
	int n = ile_elementow_tekst;	
	int m = ile_elementow_wzorzec;
	int i,j;
	int wynik = 0;
	float time = 0.0;
		
	i=0;
	while (i<=n-m)	{
		j=0;
		while ( (j<m) && (wzorzec[j]==tekst[i+j]) ) j++;
		if (j==m) wynik = i+1;
		i++;
	}

	time = (clock() - start) / (float)CLOCKS_PER_SEC;
	printf("Pozycja wzorca w tekście: %d\n",wynik);
	sleep(2);
	return time;
}
