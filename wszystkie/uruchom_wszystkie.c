#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "../knuth-morris-pratt/kmp.h"
#include "../boyera-moorea/bm.h"
#include "../karpa-rabina/kr.h"
#include "../naiwny/na.h"

void uruchom_wszystkie_algorytmy(int ile_elementow_tekst, char* tablica_znakow, int ile_elementow_wzorzec, char* tablica_wzorzec){

	float* tablica = (float*)malloc(4 * sizeof(*tablica));
	
	tablica[0] = uruchom_algorytm_kmp(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);

        tablica[1] = uruchom_algorytm_bm(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);

        tablica[2] = uruchom_algorytm_kr(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);

        tablica[3] = uruchom_algorytm_na(ile_elementow_tekst, tablica_znakow, ile_elementow_wzorzec, tablica_wzorzec);

	printf("Czasy działania algorytmów:\n");
	printf("Algorytm Knutha-Morrisa-Pratta: %0.6f sekundy.\n",tablica[0]);
	printf("Algorytm Boyera i Moore'a: %0.6f sekundy.\n",tablica[1]);
	printf("Algorytm Karpa-Rabina: %0.6f sekundy.\n",tablica[2]);
	printf("Algorytm Naiwny: %0.6f sekundy.\n",tablica[3]);
	sleep(5);
}
