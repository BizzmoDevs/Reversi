#include "api.h"
#include "globalvar.h"
#include "intro.h"
#include "ai.h"

#include <stdlib.h>
#include <iostream>
#include <allegro.h>

//--------------------------------MAIN----------------------------------------//

int main() 
{
	init(); 
    koniec=false;
	show_mouse(screen);
    wl_opcje_muzyka=false;
    
    intro();
    definiuj_plansze();
    if (wl_opcje_muzyka==true) { play_sample(instrumental, 255,127,1000,1); }
    
    
    wstaw_pionek_czerw(5,5);            //------------pionki pocz¹tkowe-------//
    wstaw_pionek_czerw(6,6);            //------------pionki pocz¹tkowe-------//
    wstaw_pionek_nieb(6,5);             //------------pionki pocz¹tkowe-------//
    wstaw_pionek_nieb(5,6);	            //------------pionki pocz¹tkowe-------//
    
        
    wlacznik_ruchu=1;                   //-----------zaczyna czerwony---------//
    
    if (koniec==true) goto koniec;      //--------warunki koñcowe-------------// 
    
    while ( (!key[KEY_ESC]) ) 
    {                                
          if (wlacznik_ruchu==1) 
          { 
               ruszaj_czerwony();
               
          }
          else
          
          if ( (wlacznik_ruchu==2) and (wl_opcje_player==true) ) 
          { 
               ruszaj_niebieski(); 
               
          }
          else
          
          if ( (wlacznik_ruchu==2) and (wl_opcje_player==false) )
          { 
               _sleep(200); 
               ruszaj_AI();
               if (wl_opcje_muzyka==true) { play_sample(klik, 255,127,1000,0); } 
                    
          }
          rysuj_plansze(); 
          pokaz_wynik();
          czy_koniec();  
          if (koniec==true) { _sleep(1000); goto koniec; } //--------warunki koñcowe-------------//                    
    }
    koniec:
    animacja_koncowa();       
    deinit();
	return 0;
}
END_OF_MAIN()
