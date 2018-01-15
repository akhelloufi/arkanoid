#ifndef _main
#define _main


#define SCREEN_HEIGHT 650  // Taille de l'écran
#define SCREEN_WIDTH  650  //
#define X_DIR         0.01 // Vitesse X
#define Y_DIR         0.03 // Vitesse Y
#define X_POS    0.01//DEPLACEMENT DE LA BARRE AU CLAVIER
//=======================================================//
// Librairies                                            //
//=======================================================//
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <gl/gl.h>
#include <malloc.h>
#include "systeme.h"  // Gére les fonctions du jeu
#include "niveau.h"   // Pour l'affichage les niveaux



//=======================================================//
// Fonction qui gère le jeu                              //
//=======================================================//
int jouer()
{

    //niveau=1;
 static int fin_niveau=1;
      // On initialise la fin du niveau à VRAI pour initialiser les cases
                            // sur l'écran
        // on commence directement au niveau 1
  struct S_COORD position_barre;  // Position de la barre

   //taille_barre=0.5;      // Taille de la barre
  int perdu;                // Renvoie 0 si l'on perd
printf("********niveau==%d \n\n",niveau);
printf("********XANIME==%f \n\n",xanime);
printf("********YANIME==%f \n\n********",yanime);
printf("/n------taille=%d",taille_Case(cases));
  // Initialise les cases s'il le faut
  if(fin_niveau==1)
  {

    // Initialise le cases en fonction du niveau
    if(niveau==1) {taille_cases=init_niv1();


     }
    else if(niveau==2){ taille_cases=init_niv2();

    }
    else{ taille_cases=init_niv3();


    }

    // Rétrécit la barre
    //taille_barre-=(taille_barre/4);

    // On commence un nouveau niveau ( ou le jeu )
    fin_niveau=0;
  }

  // Fond noir
  glClearColor(0.5,0.5,0.5,0.0);
  glClear (GL_COLOR_BUFFER_BIT);

  if(niveauTEST==1){
//printf("niveau dans jouer%d" ,niveau);
//fin_niveau=1;
  //  niveau++;
    niveauTEST=0;
  }

  // Position de la barre
  position_barre=gestion_barre(taille_barre);

  // Si la barre
  perdu=gestion_balle(position_barre.x, taille_barre, 0.075, cases, taille_cases);

  // Teste pour savoir si le niveau est fini
  if(niv_suivant(cases, taille_cases))
  {
    // Le niveau est terminé
    fin_niveau=1;printf("pppppppppppppppppp ==%d \n\n",niveau);
    vie=3;
    // Passe au niveau suivant
    niveau++;
    taille_barre-=(taille_barre/4);
  }
  if(testpassniveau==1){
     fin_niveau=1;
    vie=3;
    // Passe au niveau suivant
    niveau++;
     testpassniveau=0;
     taille_barre-=(taille_barre/4);
    printf("niveau passer==%d \n\n",niveau);
  }

//enregistrer timer
timer=timer+vitesseballe;
 glutSwapBuffers();

 if(timer-debuttimervitesse<=5000&&tv==0){
        printf("debuttimervitesse==%d \n\n",debuttimervitesse);
 printf("vitesseballe==%d \n\n",vitesseballe);
    Sleep (vitesseballe);
 }else{
     vitesseballe=50;
     tv=1;

     Sleep (vitesseballe);
 }


return perdu;
}


#endif
