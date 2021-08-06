#ifndef _api_h_
#define _api_h_

#include "globalvar.h"
#include <allegro.h>

//----------------------INIT!!!!!!!!!!!!!!!!!!!!------------------------------//

void init() 
{
    int depth, res; allegro_init(); depth = desktop_color_depth();
	if (depth == 0) depth = 32; set_color_depth(depth); res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1024, 768, 0, 0);
	if (res != 0) 
    {   allegro_message(allegro_error);
		exit(-1); }
    install_timer(); install_keyboard(); install_mouse(); install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,""); 
    set_volume(255,255);
    
    klik = load_sample("klik.wav");
    instrumental = load_sample("instr2.wav");
       
    //-------------Ladowanie bitmap Intro-------------------------------------//
    intro_menu = load_bmp("intro_menu.bmp",default_palette);
    intro_menu_nowa_gra = load_bmp("intro_menu_nowa_gra.bmp",default_palette); 
    intro_menu_instrukcje = load_bmp("intro_menu_instrukcje.bmp",default_palette); 
    intro_menu_wyjscie = load_bmp("intro_menu_wyjscie.bmp",default_palette);  
    intro_menu_inst1 = load_bmp("intro_menu_inst1.bmp",default_palette);
    intro_menu_inst1_dalej_podsw = load_bmp("intro_menu_inst1_dalej_podsw.bmp",default_palette);
    intro_menu_inst2 = load_bmp("intro_menu_inst2.bmp",default_palette);
    intro_menu_inst2_menu_podsw = load_bmp("intro_menu_inst2_menu_podsw.bmp",default_palette);
    //-------------Ladowanie bitmap Opcje-------------------------------------//
    opcje_menu = load_bmp("opcje_menu.bmp",default_palette);
    opcje_1vs1 = load_bmp("opcje_1vs1.bmp",default_palette);
    opcje_1vs1_podsw = load_bmp("opcje_1vs1_podsw.bmp",default_palette);
    opcje_1vskomp = load_bmp("opcje_1vskomp.bmp",default_palette);
    opcje_1vskomp_podsw = load_bmp("opcje_1vskomp_podsw.bmp",default_palette);
    opcje_podpowiedzi = load_bmp("opcje_podpowiedzi.bmp",default_palette);
    opcje_podpowiedzi_podsw = load_bmp("opcje_podpowiedzi_podsw.bmp",default_palette);
    opcje_mu = load_bmp("opcje_mu.bmp",default_palette);
    opcje_mu_podsw = load_bmp("opcje_mu_podsw.bmp",default_palette);
    //-------------Ladowanie bitmap MAIN--------------------------------------//
    tlo = load_bmp("tlo2.bmp",default_palette);
    ramka = load_bmp("ramka.bmp",default_palette); 
    pusty = load_bmp("pusty.bmp",default_palette); 
    czerwony = load_bmp("czerwony.bmp",default_palette);   
    niebieski = load_bmp("niebieski.bmp",default_palette); 
    czerwony_podsw = load_bmp("czerwony_podsw.bmp",default_palette);   
    niebieski_podsw = load_bmp("niebieski_podsw.bmp",default_palette);        
    tablica_wynikow = create_bitmap(300,420);   
    animacja_k = create_bitmap(1024,768);
    //------------------------------------------------------------------------//
    
}

void definiuj_plansze()                    
{
     for (int i=1; i<=10; i++)
     {   for (int j=1; j<=10; j++)
         {   xp[i]=i*60;
             yp[j]=j*60;
             typ[i][j]=0;
}    }   }        

//----------------------RYSOWANIE---------------------------------------------//



void rysuj_pusty(int ii,int jj)
{
     blit(pusty, tlo, 0, 0, xp[ii]+2, yp[jj]+2, 1024, 768);
     rect    (tlo,xp[ii]+1,yp[jj]+1,xp[ii]+59,yp[jj]+59,makecol(123,253,6));
     rect    (tlo,xp[ii]+22,xp[jj]+22,yp[ii]+38,yp[jj]+38,makecol(5,188,6));
     typ[ii][jj]=0; 
}

void wstaw_pionek_czerw(int ii,int jj)
{
     rysuj_pusty(ii,jj);
     blit(czerwony, tlo, 0, 0, xp[ii]+2, yp[jj]+2, 1024, 768);
     typ[ii][jj]=1;
}

void wstaw_pionek_nieb(int ii,int jj)
{
     rysuj_pusty(ii,jj);
     blit(niebieski, tlo, 0, 0, xp[ii]+2, yp[jj]+2, 1024, 768);
     typ[ii][jj]=2;
}

void rysuj_podswietlony_czerw(int ii,int jj)
{
     if (wl_opcje_podpowiedzi==true) {
     rysuj_pusty(ii,jj);
     blit(czerwony_podsw, tlo, 0, 0, xp[ii]+2, yp[jj]+2, 1024, 768);
     }
}

void rysuj_podswietlony_nieb(int ii,int jj)
{
     if (wl_opcje_podpowiedzi==true) {
     rysuj_pusty(ii,jj);
     blit(niebieski_podsw, tlo, 0, 0, xp[ii]+2, yp[jj]+2, 1024, 768);
     }
}

void rysuj_plansze()
{
     blit(tlo, screen, 0, 0, 0, 0, 1024, 768);
     blit(ramka, tlo, 0, 0, 35, 35, 1024, 768);
     
     for (int i=1; i<=10; i++)
     {   for (int j=1; j<=10; j++)
         {   switch(typ[i][j])
             {
                 case 0: rysuj_pusty(i,j);
                 break;
                 
                 case 1: wstaw_pionek_czerw(i,j);
                 break; 
                 
                 case 2: wstaw_pionek_nieb(i,j);
                 break; 
}}}}

void pokaz_wynik()
{
     clear_to_color(tablica_wynikow,makecol(179,135,90));
     ile_czerw=0; ile_nieb=0; ile_pust=0;
     for (int ii=1; ii<=10; ii++)
     {   for (int jj=1; jj<=10; jj++)
         {   if (typ[ii][jj]==1) ile_czerw=ile_czerw+1;
             if (typ[ii][jj]==2) ile_nieb=ile_nieb+1;
             if (typ[ii][jj]==0) ile_pust=ile_pust+1;    } }
             
     if (wlacznik_ruchu==1) 
     textprintf_ex(tablica_wynikow,font,10,10,makecol(255,0,0),-1,"RUCH GRACZA: %d",wlacznik_ruchu);
     else
     if (wlacznik_ruchu==2) 
     textprintf_ex(tablica_wynikow,font,10,10,makecol(0,0,255),-1,"RUCH GRACZA: %d",wlacznik_ruchu);
     
     textprintf_ex(tablica_wynikow,font,10,30,makecol(0,0,0),-1,"GRACZ 1 punktow -  %d ",ile_czerw); 
     textprintf_ex(tablica_wynikow,font,10,40,makecol(0,0,0),-1,"GRACZ 2 punktow -  %d ",ile_nieb);
          
     rect(tablica_wynikow, 0, 0, 299, 419, makecol(132,88,51));
     rect(tablica_wynikow, 1, 1, 298, 418, makecol(112,77,41));
     blit(tablica_wynikow, tlo, 0, 0, 700, 60, 300, 420); 
}
 
void wypelnij_linie_czerw(int ii,int jj)
{
     for (int iii=1; iii<=xi[1]; iii++)  //prawa-góra
     { typ[ii+iii][jj-iii]=1; wstaw_pionek_czerw(ii,jj);} 
     
     for (int iii=1; iii<=xi[2]; iii++)  //prawa
     { typ[ii+iii][jj]=1; wstaw_pionek_czerw(ii,jj);} 
     
     for (int iii=1; iii<=xi[3]; iii++)  //prawa-dó³ 
     { typ[ii+iii][jj+iii]=1; wstaw_pionek_czerw(ii,jj);} 
     
     for (int iii=1; iii<=xi[4]; iii++)  //dó³ 
     { typ[ii][jj+iii]=1; wstaw_pionek_czerw(ii,jj);} 
     
     for (int iii=1; iii<=xi[5]; iii++)  //lewa-dó³ 
     { typ[ii-iii][jj+iii]=1; wstaw_pionek_czerw(ii,jj);}   

     for (int iii=1; iii<=xi[6]; iii++)  //lewa
     { typ[ii-iii][jj]=1; wstaw_pionek_czerw(ii,jj);} 

     for (int iii=1; iii<=xi[7]; iii++)  //lewa-góra
     { typ[ii-iii][jj-iii]=1; wstaw_pionek_czerw(ii,jj);}   

     for (int iii=1; iii<=xi[8]; iii++)  //góra
     { typ[ii][jj-iii]=1; wstaw_pionek_czerw(ii,jj);} 
}

void wypelnij_linie_nieb(int ii,int jj)
{
     
     for (int iii=1; iii<=xi[1]; iii++)  //prawa-góra
     { typ[ii+iii][jj-iii]=2; wstaw_pionek_nieb(ii,jj);} 
     
     for (int iii=1; iii<=xi[2]; iii++)  //prawa
     { typ[ii+iii][jj]=2; wstaw_pionek_nieb(ii,jj);} 
     
     for (int iii=1; iii<=xi[3]; iii++)  //prawa-dó³ 
     { typ[ii+iii][jj+iii]=2; wstaw_pionek_nieb(ii,jj);} 
     
     for (int iii=1; iii<=xi[4]; iii++)  //dó³ 
     { typ[ii][jj+iii]=2; wstaw_pionek_nieb(ii,jj);} 
     
     for (int iii=1; iii<=xi[5]; iii++)  //lewa-dó³ 
     { typ[ii-iii][jj+iii]=2; wstaw_pionek_nieb(ii,jj);}   
     
     for (int iii=1; iii<=xi[6]; iii++)  //lewa
     { typ[ii-iii][jj]=2; wstaw_pionek_nieb(ii,jj);} 
     
     for (int iii=1; iii<=xi[7]; iii++)  //lewa-góra
     { typ[ii-iii][jj-iii]=2; wstaw_pionek_nieb(ii,jj);}   
     
     for (int iii=1; iii<=xi[8]; iii++)  //góra
     { typ[ii][jj-iii]=2; wstaw_pionek_nieb(ii,jj);} 
}

//--------------------------------SPRAWDZANIE ZMIAN---------------------------//

void sprawdz_klawisz_myszy(int ii,int jj)
{
     if ( (mouse_b!=0) and (wlacznik_ruchu==1) ) 
     {
         wypelnij_linie_czerw(ii,jj); wlacznik_ruchu=2; 
         if (wl_opcje_muzyka==true) { play_sample(klik, 255,127,1000,0); }

     }
     else
     if ( (mouse_b!=0) and (wlacznik_ruchu==2) ) 
     {
         wypelnij_linie_nieb(ii,jj); wlacznik_ruchu=1;
         if (wl_opcje_muzyka==true) { play_sample(klik, 255,127,1000,0); }

}    }

void sprawdz_linie_czerw(int ii,int jj)                 //sprawdza dostepny ruch
{
     bool dalej=true; 
     
     wlacznik1=false;
     xi[1]=0,xi[2]=0,xi[3]=0,xi[4]=0,xi[5]=0,xi[6]=0,xi[7]=0,xi[8]=0;
     
     for (int iii=1; dalej==true; iii++) {                         // 1 prawa-góra
      if ( (typ[ii+iii][jj-iii]==2) and (typ[ii][jj]==0) ) {
         if (typ[ii+iii+1][jj-iii-1]==2) { dalej=true; } else { xi[1]=0; dalej=false; } 
         if (typ[ii+iii+1][jj-iii-1]==1) { dalej=false; xi[1]=iii; } 
         if (typ[ii+iii+1][jj-iii-1]==0) { dalej=false; xi[1]=0; }
           
      } else if ( (typ[ii+iii][jj-iii]==0) or (typ[ii+iii][jj-iii]==1) ) { break; xi[1]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 2 prawa
      if ( (typ[ii+iii][jj]==2) and (typ[ii][jj]==0) ) {
         if (typ[ii+iii+1][jj]==2) { dalej=true; } else { xi[2]=0; dalej=false; } 
         if (typ[ii+iii+1][jj]==1) { dalej=false; xi[2]=iii; } 
         if (typ[ii+iii+1][jj]==0) { dalej=false; xi[2]=0; }
           
      } else if ( (typ[ii+iii][jj]==0) or (typ[ii+iii][jj]==1) ) { break; xi[2]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 3 prawa-dó³
      if ( (typ[ii+iii][jj+iii]==2) and (typ[ii][jj]==0) ) {
         if (typ[ii+iii+1][jj+iii+1]==2) { dalej=true; } else { xi[3]=0; dalej=false; } 
         if (typ[ii+iii+1][jj+iii+1]==1) { dalej=false; xi[3]=iii; } 
         if (typ[ii+iii+1][jj+iii+1]==0) { dalej=false; xi[3]=0; }
           
      } else if ( (typ[ii+iii][jj+iii]==0) or (typ[ii+iii][jj+iii]==1) ) { break; xi[3]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 4 dó³
      if ( (typ[ii][jj+iii]==2) and (typ[ii][jj]==0) ) {
         if (typ[ii][jj+iii+1]==2) { dalej=true; } else { xi[4]=0; dalej=false; } 
         if (typ[ii][jj+iii+1]==1) { dalej=false; xi[4]=iii; } 
         if (typ[ii][jj+iii+1]==0) { dalej=false; xi[4]=0; }
           
      } else if ( (typ[ii][jj+iii]==0) or (typ[ii][jj+iii]==1) ) { break; xi[4]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 5 lewa-dó³
      if ( (typ[ii-iii][jj+iii]==2) and (typ[ii][jj]==0) ) {
         if (typ[ii-iii-1][jj+iii+1]==2) { dalej=true; } else { xi[5]=0; dalej=false; } 
         if (typ[ii-iii-1][jj+iii+1]==1) { dalej=false; xi[5]=iii; } 
         if (typ[ii-iii-1][jj+iii+1]==0) { dalej=false; xi[5]=0; }
           
      } else if ( (typ[ii-iii][jj+iii]==0) or (typ[ii-iii][jj+iii]==1) ) { break; xi[5]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 6 lewa
      if ( (typ[ii-iii][jj]==2) and (typ[ii][jj]==0) ) {
         if (typ[ii-iii-1][jj]==2) { dalej=true; } else { xi[6]=0; dalej=false; } 
         if (typ[ii-iii-1][jj]==1) { dalej=false; xi[6]=iii; } 
         if (typ[ii-iii-1][jj]==0) { dalej=false; xi[6]=0; }
           
      } else if ( (typ[ii-iii][jj]==0) or (typ[ii-iii][jj]==1) ) { break; xi[6]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 7 lewa-góra
      if ( (typ[ii-iii][jj-iii]==2) and (typ[ii][jj]==0) ) {
         if (typ[ii-iii-1][jj-iii-1]==2) { dalej=true; } else { xi[7]=0; dalej=false; } 
         if (typ[ii-iii-1][jj-iii-1]==1) { dalej=false; xi[7]=iii; } 
         if (typ[ii-iii-1][jj-iii-1]==0) { dalej=false; xi[7]=0; }
           
      } else if ( (typ[ii-iii][jj-iii]==0) or (typ[ii-iii][jj-iii]==1) ) { break; xi[7]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 8 góra
      if ( (typ[ii][jj-iii]==2) and (typ[ii][jj]==0) ) {
         if (typ[ii][jj-iii-1]==2) { dalej=true; } else { xi[8]=0; dalej=false; } 
         if (typ[ii][jj-iii-1]==1) { dalej=false; xi[8]=iii; } 
         if (typ[ii][jj-iii-1]==0) { dalej=false; xi[8]=0; }
           
      } else if ( (typ[ii][jj-iii]==0) or (typ[ii][jj-iii]==1) ) { break; xi[8]=0; }  
}    }

void sprawdz_linie_nieb(int ii,int jj)                  //sprawdza dostepny ruch
{
     bool dalej=true; wlacznik1=false;
     xi[1]=0,xi[2]=0,xi[3]=0,xi[4]=0,xi[5]=0,xi[6]=0,xi[7]=0,xi[8]=0;
     
     for (int iii=1; dalej==true; iii++) {                         // 1 prawa-góra
      if ( (typ[ii+iii][jj-iii]==1) and (typ[ii][jj]==0) ) {
         if (typ[ii+iii+1][jj-iii-1]==1) { dalej=true; } else { xi[1]=0; dalej=false; } 
         if (typ[ii+iii+1][jj-iii-1]==2) { dalej=false; xi[1]=iii; } 
         if (typ[ii+iii+1][jj-iii-1]==0) { dalej=false; xi[1]=0; }
           
      } else if ( (typ[ii+iii][jj-iii]==0) or (typ[ii+iii][jj-iii]==2) ) { break; xi[1]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 2 prawa
      if ( (typ[ii+iii][jj]==1) and (typ[ii][jj]==0) ) {
         if (typ[ii+iii+1][jj]==1) { dalej=true; } else { xi[2]=0; dalej=false; } 
         if (typ[ii+iii+1][jj]==2) { dalej=false; xi[2]=iii; } 
         if (typ[ii+iii+1][jj]==0) { dalej=false; xi[2]=0; }
           
      } else if ( (typ[ii+iii][jj]==0) or (typ[ii+iii][jj]==2) ) { break; xi[2]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 3 prawa-dó³
      if ( (typ[ii+iii][jj+iii]==1) and (typ[ii][jj]==0) ) {
         if (typ[ii+iii+1][jj+iii+1]==1) { dalej=true; } else { xi[3]=0; dalej=false; } 
         if (typ[ii+iii+1][jj+iii+1]==2) { dalej=false; xi[3]=iii; } 
         if (typ[ii+iii+1][jj+iii+1]==0) { dalej=false; xi[3]=0; }
           
      } else if ( (typ[ii+iii][jj+iii]==0) or (typ[ii+iii][jj+iii]==2) ) { break; xi[3]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 4 dó³
      if ( (typ[ii][jj+iii]==1) and (typ[ii][jj]==0) ) {
         if (typ[ii][jj+iii+1]==1) { dalej=true; } else { xi[4]=0; dalej=false; } 
         if (typ[ii][jj+iii+1]==2) { dalej=false; xi[4]=iii; } 
         if (typ[ii][jj+iii+1]==0) { dalej=false; xi[4]=0; }
           
      } else if ( (typ[ii][jj+iii]==0) or (typ[ii][jj+iii]==2) ) { break; xi[4]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 5 lewa-dó³
      if ( (typ[ii-iii][jj+iii]==1) and (typ[ii][jj]==0) ) {
         if (typ[ii-iii-1][jj+iii+1]==1) { dalej=true; } else { xi[5]=0; dalej=false; } 
         if (typ[ii-iii-1][jj+iii+1]==2) { dalej=false; xi[5]=iii; } 
         if (typ[ii-iii-1][jj+iii+1]==0) { dalej=false; xi[5]=0; }
           
      } else if ( (typ[ii-iii][jj+iii]==0) or (typ[ii-iii][jj+iii]==2) ) { break; xi[5]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 6 lewa
      if ( (typ[ii-iii][jj]==1) and (typ[ii][jj]==0) ) {
         if (typ[ii-iii-1][jj]==1) { dalej=true; } else { xi[6]=0; dalej=false; } 
         if (typ[ii-iii-1][jj]==2) { dalej=false; xi[6]=iii; } 
         if (typ[ii-iii-1][jj]==0) { dalej=false; xi[6]=0; }
           
      } else if ( (typ[ii-iii][jj]==0) or (typ[ii-iii][jj]==2) ) { break; xi[6]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 7 lewa-góra
      if ( (typ[ii-iii][jj-iii]==1) and (typ[ii][jj]==0) ) {
         if (typ[ii-iii-1][jj-iii-1]==1) { dalej=true; } else { xi[7]=0; dalej=false; } 
         if (typ[ii-iii-1][jj-iii-1]==2) { dalej=false; xi[7]=iii; } 
         if (typ[ii-iii-1][jj-iii-1]==0) { dalej=false; xi[7]=0; }
           
      } else if ( (typ[ii-iii][jj-iii]==0) or (typ[ii-iii][jj-iii]==2) ) { break; xi[7]=0; }  
     }
     dalej=true;
     for (int iii=1; dalej==true; iii++) {                         // 8 góra
      if ( (typ[ii][jj-iii]==1) and (typ[ii][jj]==0) ) {
         if (typ[ii][jj-iii-1]==1) { dalej=true; } else { xi[8]=0; dalej=false; } 
         if (typ[ii][jj-iii-1]==2) { dalej=false; xi[8]=iii; } 
         if (typ[ii][jj-iii-1]==0) { dalej=false; xi[8]=0; }
           
      } else if ( (typ[ii][jj-iii]==0) or (typ[ii][jj-iii]==2) ) { break; xi[8]=0; }  
}    }


void ruszaj_czerwony()
{      
     sumxi=0;
     sumdost=0;
      
     for (int i=1; i<=10; i++)
     {   for (int j=1; j<=10; j++)
         {
             sprawdz_linie_czerw(i,j);
             sumxi=0;
             sumxi = xi[1]+xi[2]+xi[3]+xi[4]+xi[5]+xi[6]+xi[7]+xi[8];
             if (sumxi > 0) { rysuj_podswietlony_czerw(i,j); sumdost+=1;}
             else continue; 
     }   } 
     
     
     for (int i=1; i<=10; i++)
     {   for (int j=1; j<=10; j++)
         {
             if ( (((mouse_x>xp[i]) and (mouse_x<xp[i+1]))  and ((mouse_y>yp[j]) and (mouse_y<yp[j+1]))) 
             or   (((mouse_x>xp[i]) and (mouse_x<xp[i]+60)) and ((mouse_y>yp[j]) and (mouse_y<yp[j]+60))) )   //polozenie myszy
             
             //----------dla czerwonego---------------------------------------//
             {
             sprawdz_linie_czerw(i,j);
             sumxi=0;
             sumxi = xi[1]+xi[2]+xi[3]+xi[4]+xi[5]+xi[6]+xi[7]+xi[8];
             if ((sumxi > 0) and (sumdost > 0)) { sprawdz_klawisz_myszy(i,j); } 
             else continue;
             }
     }   } 
     if (sumdost<=0) { wlacznik_ruchu=2;  textprintf_ex(screen,font,800,600,makecol(0,0,0),-1,"UTRATA RUCHU"); _sleep(500); }
      
}


void ruszaj_niebieski()
{ 
     sumxi=0;
     sumdost=0;    
     
     for (int i=1; i<=10; i++)
     {   for (int j=1; j<=10; j++)
         {
             sprawdz_linie_nieb(i,j);
             sumxi=0;
             sumxi = xi[1]+xi[2]+xi[3]+xi[4]+xi[5]+xi[6]+xi[7]+xi[8];
             if (sumxi > 0) { rysuj_podswietlony_nieb(i,j); sumdost+=1;}
             else continue; 
     }   } 
     
     for (int i=1; i<=10; i++)
     {   for (int j=1; j<=10; j++)
         {
             if ( (((mouse_x>xp[i]) and (mouse_x<xp[i+1]))  and ((mouse_y>yp[j]) and (mouse_y<yp[j+1]))) 
             or   (((mouse_x>xp[i]) and (mouse_x<xp[i]+60)) and ((mouse_y>yp[j]) and (mouse_y<yp[j]+60))) )   //polozenie myszy

             //----------dla niebieskiego-------------------------------------//
             {
             sprawdz_linie_nieb(i,j);
             sumxi=0;
             sumxi = xi[1]+xi[2]+xi[3]+xi[4]+xi[5]+xi[6]+xi[7]+xi[8];
             if ((sumxi > 0) and (sumdost > 0)) { sprawdz_klawisz_myszy(i,j); }
             else continue;
             }
     }   }
     if (sumdost<=0) { wlacznik_ruchu=1; textprintf_ex(screen,font,800,600,makecol(0,0,0),-1,"UTRATA RUCHU"); _sleep(500); }    
}



//-----------------------------INNE-------------------------------------------//
int czy_koniec()
{      
     ile_czerw=0; ile_nieb=0; ile_pust=0;
     for (int ii=1; ii<=10; ii++)
     {   for (int jj=1; jj<=10; jj++)
         {   if (typ[ii][jj]==1) ile_czerw=ile_czerw+1;
             if (typ[ii][jj]==2) ile_nieb=ile_nieb+1;
             if (typ[ii][jj]==0) ile_pust=ile_pust+1;    } }
     
     if ( (ile_czerw==0) or (ile_nieb==0) ) koniec=true; else 
     if (ile_pust<=0) koniec=true; else 
     if (przelacznik_intro==4) koniec=true; else koniec=false;     
}

void animacja_koncowa()
{
     clear_to_color(animacja_k,makecol(0,0,0));
     for (int i=1; i<3; i++) 
     {
         for (int j=1; j<=255; j++)
             {
             textprintf_ex(animacja_k,font,380,600,makecol(255-j,255-j,255-j),-1,"Thanks for playing Ultimate Reversi!!");
             textprintf_ex(animacja_k,font,470,384,makecol(255,255,255),-1,"KONIEC!!!!!!!");
             if ( ile_czerw > ile_nieb ) textprintf_ex(animacja_k,font,440,400,makecol(255,0,0),-1,"Wygyrwa gracz czerwony");
             if ( ile_czerw < ile_nieb ) textprintf_ex(animacja_k,font,440,400,makecol(0,0,255),-1,"Wygyrwa gracz niebieski");
             if ( ile_czerw == ile_nieb ) textprintf_ex(animacja_k,font,500,400,makecol(255,255,255),-1,"Remis");
             blit(animacja_k, screen, 0, 0, 0, 0, 1024, 768);
             }
         
         for (int j=1; j<=255; j++)
             {
             textprintf_ex(animacja_k,font,380,600,makecol(0+j,0+j,0+j),-1,"Thanks for playing Ultimate Reversi!!");
             textprintf_ex(animacja_k,font,470,384,makecol(255,255,255),-1,"KONIEC!!!!!!!");
             if ( ile_czerw > ile_nieb ) textprintf_ex(animacja_k,font,440,400,makecol(255,0,0),-1,"Wygyrwa gracz czerwony");
             if ( ile_czerw < ile_nieb ) textprintf_ex(animacja_k,font,440,400,makecol(0,0,255),-1,"Wygyrwa gracz niebieski");
             if ( ile_czerw == ile_nieb ) textprintf_ex(animacja_k,font,500,400,makecol(255,255,255),-1,"Remis");
             blit(animacja_k, screen, 0, 0, 0, 0, 1024, 768);
             }       
     }
}

void deinit() 
{
     destroy_bitmap(tlo); 
     destroy_bitmap(tablica_wynikow);
     destroy_bitmap(animacja_k);   
     clear_keybuf();
}

#endif
