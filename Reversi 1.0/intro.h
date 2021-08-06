#ifndef _intro_h_
#define _intro_h_

#include "globalvar.h"
#include <allegro.h>

void sprawdz_klawisz_myszy_intro() 
{
     if ( (mouse_b & 1) and (warunek_menu==1) )  { koniec_intro=true; }                      else
     if ( (mouse_b & 1) and (warunek_menu==2) ) { przelacznik_intro=1; }                    else
     if ( (mouse_b & 1) and (warunek_menu==3) )  { koniec_intro=true; przelacznik_intro=4; } else
     if ( (mouse_b & 1) and (warunek_menu==5) ) { przelacznik_intro=2; }                    else
     if ( (mouse_b & 1) and (warunek_menu==7) )  { przelacznik_intro=0; }                    else
     if ( (mouse_b & 1) and (warunek_menu==8) )  { wl_opcje_player=true; }                   else
     if ( (mouse_b & 1) and (warunek_menu==9) )  { wl_opcje_player=false; }                  else
     if ( (mouse_b & 1) and (warunek_menu==10) ) { wl_opcje_podpowiedzi=true; }              else
     if ( (mouse_b & 1) and (warunek_menu==11) ) { wl_opcje_muzyka=true; }                                     
}

void wyswietl_intro(int wysw)
{     
     if (wysw==0) { blit(intro_menu, screen, 0, 0, 0, 0, 1024, 768);
                    blit(opcje_menu, intro_menu, 0, 0, 770, 340, 770,340);
                    if (wl_opcje_player==true)  { blit(opcje_1vs1_podsw, intro_menu, 0, 0, 790, 380, 790, 380); blit(opcje_1vskomp, intro_menu, 0, 0, 799, 420, 799, 420); } else
                    if (wl_opcje_player==false) { blit(opcje_1vskomp_podsw, intro_menu, 0, 0, 799, 420, 799, 420); blit(opcje_1vs1, intro_menu, 0, 0, 790, 380, 790, 380); }
                    if (wl_opcje_podpowiedzi==true)  { blit(opcje_podpowiedzi_podsw, intro_menu, 0, 0, 797, 460, 797, 460); } else
                    if (wl_opcje_podpowiedzi==false)  { blit(opcje_podpowiedzi, intro_menu, 0, 0, 797, 460, 797, 460); }
                    if (wl_opcje_muzyka==true)  { blit(opcje_mu_podsw, intro_menu, 0, 0, 800, 500, 800, 500); } else
                    if (wl_opcje_muzyka==false)  { blit(opcje_mu, intro_menu, 0, 0, 800, 500, 800, 500); }                    
                  }
                   
     if (wysw==1) { blit(intro_menu_nowa_gra, screen, 0, 0, 349, 226, 1024, 768); }  
     if (wysw==2) { blit(intro_menu_instrukcje, screen, 0, 0, 349, 226, 1024, 768); } 
     if (wysw==3) { blit(intro_menu_wyjscie, screen, 0, 0, 349, 226, 1024, 768); } 
     if (wysw==4) { blit(intro_menu_inst1, screen, 0, 0, 349, 226, 1024, 768); } 
     if (wysw==5) { blit(intro_menu_inst1_dalej_podsw,screen, 0, 0, 349, 226, 1024, 768); } 
     if (wysw==6) { blit(intro_menu_inst2, screen, 0, 0, 349, 226, 1024, 768); } 
     if (wysw==7) { blit(intro_menu_inst2_menu_podsw,screen, 0, 0, 349, 226, 1024, 768); }
     if (wysw==8) { line(screen,810, 410, 860, 410, makecol(255,255,255) ); }
     if (wysw==9) { line(screen,810, 450, 860, 450, makecol(255,255,255) ); }
     if (wysw==10) { line(screen,810, 490, 860, 490, makecol(255,255,255) ); }
     if (wysw==11) { line(screen,810, 530, 860, 530, makecol(255,255,255) ); }
}

void sprawdz_mysz_intro()
{ 
     if ( ((mouse_x>520) and (mouse_x<640)) and ((mouse_y>270) and (mouse_y<320)) )   //polozenie myszy w menu na polu "nowa gra"
     {  (warunek_menu=1); }    
      
     else
     if ( ((mouse_x>508) and (mouse_x<635)) and ((mouse_y>321) and (mouse_y<372)) )   //polozenie myszy w menu na polu "instrukcje"
     {   (warunek_menu=2); }   
     
     else
     if ( ((mouse_x>510) and (mouse_x<600)) and ((mouse_y>398) and (mouse_y<438)) )   //polozenie myszy w menu na polu "wyjscie"
     {   (warunek_menu=3); }   
     
     else
     if ( ((mouse_x>810) and (mouse_x<860)) and ((mouse_y>390) and (mouse_y<410)) )   //polozenie myszy w menu na polu "1 vs 1"
     {   (warunek_menu=8); }
     
     else
     if ( ((mouse_x>810) and (mouse_x<923)) and ((mouse_y>430) and (mouse_y<450)) )   //polozenie myszy w menu na polu "1 vs komp"
     {   (warunek_menu=9); }
     
     else
     if ( ((mouse_x>810) and (mouse_x<900)) and ((mouse_y>470) and (mouse_y<490)) )   //polozenie myszy w menu na polu "podpowiedzi"
     {   (warunek_menu=10); }
     
     else
     if ( ((mouse_x>810) and (mouse_x<938)) and ((mouse_y>510) and (mouse_y<530)) )   //polozenie myszy w menu na polu "muzyka"
     {   (warunek_menu=11); }
     
     else 
     { warunek_menu = 0;  }
        
}

void sprawdz_mysz_intro_inst()
{ 
     if ( ((mouse_x>670) and (mouse_x<750)) and ((mouse_y>630) and (mouse_y<665)) )   //polozenie myszy w menu na polu "dalej..."
     { warunek_menu = 5;  }   
     
     else warunek_menu = 4;
     
} 

void sprawdz_mysz_intro_inst2()
{  
     if ( ((mouse_x>620) and (mouse_x<710)) and ((mouse_y>660) and (mouse_y<690)) )   //polozenie myszy w menu na polu "menu..."
     { warunek_menu = 7; }
     
     else warunek_menu = 6;
     
}     

//--------------------------------INTRO---------------------------------------//
    
void intro()
{
     blit(intro_menu, screen, 0, 0, 0, 0, 1024, 768);
     przelacznik_intro = 0;
     warunek_menu=0;
     koniec_intro=false;
     
     while ( koniec_intro!=true )
     {
          if (przelacznik_intro==0) { sprawdz_mysz_intro(); wyswietl_intro(warunek_menu); }
          
          else
          if (przelacznik_intro==1) { sprawdz_mysz_intro_inst(); wyswietl_intro(warunek_menu); }
          
          else
          if (przelacznik_intro==2) { sprawdz_mysz_intro_inst2(); wyswietl_intro(warunek_menu); }

     
     sprawdz_klawisz_myszy_intro();
          
}    }

#endif
