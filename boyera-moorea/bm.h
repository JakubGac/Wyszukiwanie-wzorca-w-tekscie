#ifndef _BM_H
#define _BM_H

void pre_bad_character_shift(char *pattern, int m);
void pre_suff(char *pattern, int m);
void pre_good_suffix_shift(char *pattern, int m);
int maximum(int value1, int value2);
int BM(char *text, int n, char *pattern, int m);
float uruchom_algorytm_bm(int ile_elementow_tekst,char* tablica_znakow,int ile_elementow_wzorzec,char* tablica_wzorzec);

#endif
