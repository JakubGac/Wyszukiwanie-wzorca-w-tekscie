#ifndef _URUCHOM_WSZYSTKIE_H
#define _URUCHOM_WSZYSTKIE_H

#include "../knuth-morris-pratt/kmp.h"
#include "../boyera-moorea/bm.h"
#include "../karpa-rabina/kr.h"
#include "../naiwny/na.h"

void uruchom_wszystkie_algorytmy(int ile_elementow_tekst, char* tablica_znakow, int ile_elementow_wzorzec, char* tablica_wzorzec);

#endif
