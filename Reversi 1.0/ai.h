#ifndef _ai_h_
#define _ai_h_

#include "api.h"
#include "globalvar.h"
#include <allegro.h>

bool dostepny_dla_AI[10][10];                              //true - mozliwy ruch
int  dostepny_dla_AI_max[10][10];                                     //max pole

void sprawdz_linie_AI(int ii,int jj)                  //sprawdza dostepny ruch
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
    }
} 

//----------------------------RUSZAJ AI---------------------------------------//
void ruszaj_AI()
{ 
     for (int i=1; i<=10; i++)                                           //reset
     {   for (int j=1; j<=10; j++)
         {   
            dostepny_dla_AI[i][j]=false; 
     }   }
     sumxi=0;
     summax=0;
     sumdost=0;
     
     int imax,jmax;
     
     for (int i=1; i<=10; i++)                   //(i,j) wsp pól przeszukiwanych
     {   for (int j=1; j<=10; j++)
         {   
            sprawdz_linie_AI(i,j);
            sumxi=0;
            sumxi = xi[1]+xi[2]+xi[3]+xi[4]+xi[5]+xi[6]+xi[7]+xi[8];            
            if ( (sumxi > summax) )  { summax=sumxi; imax=i; jmax=j; sumdost+=1;}
            
     }   }
     
     sprawdz_linie_AI(imax,jmax);
     
     sumxi = xi[1]+xi[2]+xi[3]+xi[4]+xi[5]+xi[6]+xi[7]+xi[8];
     wypelnij_linie_nieb(imax,jmax);
     if (sumdost>0) wlacznik_ruchu=1; 
     if (sumdost<=0) { wlacznik_ruchu=2; textprintf_ex(screen,font,800,600,makecol(0,0,0),-1,"UTRATA RUCHU");  }    
}

#endif
