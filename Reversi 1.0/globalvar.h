#ifndef _globalvar_h_
#define _globalvar_h_

#include <allegro.h>


//----------------------------INTRO-MENU--------------------------------------//

BITMAP *intro_menu = NULL;   
BITMAP *intro_menu_nowa_gra = NULL;      
BITMAP *intro_menu_instrukcje = NULL;      
BITMAP *intro_menu_wyjscie = NULL;           
BITMAP *intro_menu_inst1 = NULL;
BITMAP *intro_menu_inst2 = NULL;
BITMAP *intro_menu_inst1_dalej_podsw = NULL;
BITMAP *intro_menu_inst2_menu_podsw = NULL;

BITMAP *opcje_menu = NULL;
BITMAP *opcje_1vs1 = NULL;
BITMAP *opcje_1vs1_podsw = NULL;
BITMAP *opcje_1vskomp = NULL;
BITMAP *opcje_1vskomp_podsw = NULL;
BITMAP *opcje_podpowiedzi = NULL;
BITMAP *opcje_podpowiedzi_podsw = NULL;
BITMAP *opcje_mu = NULL;
BITMAP *opcje_mu_podsw = NULL;

bool koniec_intro;
unsigned short int warunek_menu;
unsigned short int przelacznik_intro;       //okresla jaki ekran menu jest wyswietlany (1-ekran gl; 2-instr1; 3-instr2; 4-przeskakuje do gry 1vs1)

bool wl_opcje_player;                               //Przelaczniki do menu opcji
bool  wl_opcje_podpowiedzi;
bool  wl_opcje_muzyka;

//---------------------------------GRA----------------------------------------//


BITMAP *tablica_wynikow = NULL;                    //WskaŸniki do buforów bitmap 
BITMAP *animacja_k = NULL;                         
BITMAP *tlo = NULL;                                
BITMAP *ramka = NULL;                              
BITMAP *pusty = NULL;                              
BITMAP *czerwony = NULL;                           
BITMAP *niebieski = NULL;                          
BITMAP *czerwony_podsw = NULL;                     
BITMAP *niebieski_podsw = NULL;                    

SAMPLE *klik = NULL;                               // .....            i dzwieku
SAMPLE *instrumental = NULL;


unsigned short int ile_czerw=0; int ile_nieb=0; int ile_pust=0;    //zmienne do liczenia wyniku  
 
unsigned short int wlacznik_ruchu;                                 //wlacznik kolejnosci ruchow
bool wlacznik1;                                                    //odbezpiecza wykonanie ruchu | true-mozna klikac       


unsigned short int xi[8];                                          //zmienne odleglosci flankujacych pionkow
                                                                   //od dostepnego ruchu||1-prawa gora 2-prawo 3-prawo-dol ...
                                               
unsigned short int xp[15]; unsigned short int yp[15];              //wspó³rzêdne pól planszy||lewy gorny róg kwadratu
unsigned short int typ[15][15];                                    //pole zajmowane przez||0-pusty 1-czerw 2-nieb ...
          
bool koniec=false;

int sumxi;
int sumdost;
int summax;


#endif
