#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "wczytaj_dane.h"
#include "../knuth-morris-pratt/kmp.h"
#include "../boyera-moorea/bm.h"
#include "../karpa-rabina/kr.h"
#include "../naiwny/na.h"
#include "../wszystkie/uruchom_wszystkie.h"

void przygotuj_dane(char* plik_tekst, char* plik_wzorzec, int ktory_algorytm){
	int ile_elementow_tekst;
	int ile_elementow_wzorzec;	
	char *tablica_znakow;
	char *tablica_wzorzec;
	float czas;
		
	printf("Wczytuje z pliku tekst do przeszukania.\n");
	sleep(2);	
	
	ile_elementow_tekst = zlicz_znaki(plik_tekst);
	tablica_znakow = (char*)malloc(ile_elementow_tekst * sizeof(*tablica_znakow));	
	tablica_znakow = wczytaj_dane(ile_elementow_tekst, plik_tekst);
	
	printf("Tekst wczytany.\n");
	sleep(2);
	
	printf("Wczytuje z pliku wzorzec do odnalezienia.\n");
	sleep(2);
	
	ile_elementow_wzorzec = zlicz_znaki(plik_wzorzec);
	tablica_wzorzec = (char*)malloc(ile_elementow_wzorzec * sizeof(*tablica_wzorzec));
	tablica_wzorzec = wczytaj_dane(ile_elementow_wzorzec, plik_wzorzec);
	
	printf("Wzorzec wczytany.\n");
	sleep(2);

	printf("Uruchamiam algorytm i zaczynam liczyć czas jego działania.\n");
	sleep(2);

	switch(ktory_algorytm){
		case 1:
			czas = uruchom_algorytm_kmp(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);	
			printf("Czas działania algorytmu KMP: %0.6f sekundy.\n",czas);
			break;
		case 2:
                        czas = uruchom_algorytm_bm(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);
                        printf("Czas działania algorytmu BM: %0.6f sekundy.\n",czas);
			break;
		case 3:
                        czas = uruchom_algorytm_kr(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);
                        printf("Czas działania algorytmu KR: %0.6f sekundy.\n",czas);	
			break;
		case 4:
                        czas = uruchom_algorytm_na(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);
                        printf("Czas działania algorytmu NA: %0.6f sekundy.\n",czas);
			break;
		case 5:
			uruchom_wszystkie_algorytmy(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);
			break;
	}
} 
