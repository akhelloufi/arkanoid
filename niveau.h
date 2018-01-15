//=======================================================//
// Fonction qui permet d'initialiser le niveau 1         //
//=======================================================//
int taille_Case(struct S_CASE* cases_case)
{
  int i,j=0;

  for(i=0; i<200; i++)
  {
    if(cases_case[i].x!=10&&cases_case[i].coup>0){
        j++;
    }
  }

  return j; // Le plateau est vide
}
void translationcases(float trxx,float tryy){
    int i;
 for(i=0; i<200; i++)
  {
    cases[i].x=cases[i].x+trxx;
    cases[i].y=cases[i].y+tryy;
  }


}
void viderCases(){
    int i;
 for(i=0; i<200; i++)
  {
    cases[i].x=0;
    cases[i].y=0;
    cases[i].r=0;
    cases[i].v=0;
    cases[i].b=0;
  }


}
int init_niv1()
{
viderCases();
  int i, j;


 for(i=0; i<10; i++)
  {
    for(j=0; j<20; j++)
    {
     if(i==8&&j%3==0){//jaune ne se detruit pas
      cases[i*20+j].x=j*0.1-1;
      cases[i*20+j].y=i*0.1;
      cases[i*20+j].r=1;
      cases[i*20+j].v=1;
      cases[i*20+j].b=0;
      cases[i*20+j].coup=-10;
     }else {
           if(i%2==0&&j%2==0){// gris 3 coup detruite
                cases[i*20+j].x=j*0.1-1;
                cases[i*20+j].y=i*0.1;
                cases[i*20+j].r=0.5;
                cases[i*20+j].v=0.5;
                cases[i*20+j].b=0.5;
                cases[i*20+j].coup=2;

           }else{//autre couleur un seul coup
        if((i==1&&j==7)||(i==2&&j==19)){//rose case pour les bonus niveau
          cases[i*20+j].x=j*0.1-1;
          cases[i*20+j].y=i*0.1;
          cases[i*20+j].r=1;
          cases[i*20+j].v=0.4;
          cases[i*20+j].b=1;
          cases[i*20+j].coup=1;
          cases[i*20+j].bonusniveau=1;
        }else{

                 if(i==1&&j==10||i==2&&j==15){//bleu case pour les bonus vitesse
                  cases[i*20+j].x=j*0.1-1;
                  cases[i*20+j].y=i*0.1;
                  cases[i*20+j].r=0;
                  cases[i*20+j].v=0;
                  cases[i*20+j].b=1;
                  cases[i*20+j].coup=1;
                  cases[i*20+j].bonusvitesse=1;
                }else{

                 if(i==1&&j==14||i==2&&j==14){//autre couleur ROUGE case pour les bonus largeur de la barre
                  cases[i*20+j].x=j*0.1-1;
                  cases[i*20+j].y=i*0.1;
                  cases[i*20+j].r=1;
                  cases[i*20+j].v=0;
                  cases[i*20+j].b=0;
                  cases[i*20+j].coup=1;
                  cases[i*20+j].bonuslargeurbarre=1;
                }else{

                        if(i==1&&j==8||i==2&&j==8){//autre couleur  case pour UNE GRANDE BALLE QUI DETRUIT LES CASES
                              cases[i*20+j].x=j*0.1-1;
                              cases[i*20+j].y=i*0.1;
                              cases[i*20+j].r=0.94;
                              cases[i*20+j].v=0;
                              cases[i*20+j].b=0.27;
                              cases[i*20+j].coup=1;
                              cases[i*20+j].bonusbigballe=1;
                            }else{

                                         if(i==1&&j==17||i==1&&j==1){//  couleur orange pour une vie
                                          cases[i*20+j].x=j*0.1-1;
                                          cases[i*20+j].y=i*0.1;
                                          cases[i*20+j].r=0.94;
                                          cases[i*20+j].v=0.396;
                                          cases[i*20+j].b=0.27;
                                          cases[i*20+j].coup=1;
                                          cases[i*20+j].bonusvie=1;
                                        }else{

                                              if(i==9&&j==17||i==0&&j==5){//  couleur violet pour le canon
                                              cases[i*20+j].x=j*0.1-1;
                                              cases[i*20+j].y=i*0.1;
                                              cases[i*20+j].r=0.09;
                                              cases[i*20+j].v=0.98;
                                              cases[i*20+j].b=0.32;
                                              cases[i*20+j].coup=1;
                                              cases[i*20+j].bonuscanon=1;
                                            }else{

                                                  if(i==1&&j==11||i==1&&j==5){//  couleur violet pour le canon
                                                  cases[i*20+j].x=j*0.1-1;
                                                  cases[i*20+j].y=i*0.1;
                                                  cases[i*20+j].r=0.0;
                                                  cases[i*20+j].v=0.08;
                                                  cases[i*20+j].b=0.02;
                                                  cases[i*20+j].coup=1;
                                                  cases[i*20+j].bonusforce=1;
                                                }else{

                                                  cases[i*20+j].x=j*0.1-1;
                                                  cases[i*20+j].y=i*0.1;
                                                  cases[i*20+j].r=0;
                                                  cases[i*20+j].v=0.5;
                                                  cases[i*20+j].b=0.5;
                                                  cases[i*20+j].coup=1;

                                                }

                                            }

                                        }


                            }


                }
                }
        }

        }

     }


    }
  }

translationcases(0.05,0.05);
  return 200; // Retourne la taille du cases IL DOIT ETRE EGALE AU CASE SAUF LES JAUNE
}
int init_niv2()
{
viderCases();
    int i, j;



 for(i=0; i<10; i++)
  {
    for(j=0; j<20; j++)
    {
     if(i==3&&j%4==0){//jaune ne se detruit pas
      cases[i*20+j].x=j*0.1-1;
      cases[i*20+j].y=i*0.1;
      cases[i*20+j].r=1;
      cases[i*20+j].v=1;
      cases[i*20+j].b=0;
      cases[i*20+j].coup=-10;
     }else {
           if(i%2==0&&j%2==0){// gris 3 coup detruite
                cases[i*20+j].x=j*0.1-1;
                cases[i*20+j].y=i*0.1;
                cases[i*20+j].r=0.5;
                cases[i*20+j].v=0.5;
                cases[i*20+j].b=0.5;
                cases[i*20+j].coup=2;

           } //autre couleur un seul coup
        if(i==9&&j==1){//rose case pour les bonus
          cases[i*20+j].x=j*0.1-1;
          cases[i*20+j].y=i*0.1;
          cases[i*20+j].r=1;
          cases[i*20+j].v=0;
          cases[i*20+j].b=1;
          cases[i*20+j].coup=1;
          cases[i*20+j].bonusniveau=1;
        }else{

        if(i==5&&j==10){//bleu case pour les bonus vitesse
                  cases[i*20+j].x=j*0.1-1;
                  cases[i*20+j].y=i*0.1;
                  cases[i*20+j].r=0;
                  cases[i*20+j].v=0;
                  cases[i*20+j].b=1;
                  cases[i*20+j].coup=1;
                  cases[i*20+j].bonusvitesse=1;
                }else{

                if(i==5&&j==14){//autre couleur ROUGE case pour les bonus largeur de la barre
                  cases[i*20+j].x=j*0.1-1;
                  cases[i*20+j].y=i*0.1;
                  cases[i*20+j].r=1;
                  cases[i*20+j].v=0;
                  cases[i*20+j].b=0;
                  cases[i*20+j].coup=1;
                  cases[i*20+j].bonuslargeurbarre=1;
                }else{

                  cases[i*20+j].x=j*0.1-1;
                  cases[i*20+j].y=i*0.1;
                  cases[i*20+j].r=0;
                  cases[i*20+j].v=0.5;
                  cases[i*20+j].b=0.5;
                  cases[i*20+j].coup=1;

                 /* cases[i*20+j].x=j*0.1-1;
                  cases[i*20+j].y=i*0.1;
                  cases[i*20+j].r=0.5+(float)(rand()%120)/255.0f;
                  cases[i*20+j].v=0.5+(float)(rand()%120)/255.0f;
                  cases[i*20+j].b=0.5+(float)(rand()%120)/255.0f;
                  cases[i*20+j].coup=1;*/
                }
        }
        }



     }


    }

  }
 translationcases(0.05,0.05);

  return 200; /// Retourne la taille du cases
}

//=======================================================//
// Fonction qui permet d'initialiser le niveau 3 et plus //
//=======================================================//
int init_niv3()
{
viderCases();
  int i, j;


  // Le générateur de nombre premier n'est pas initialiser pour donner l'impression
  // d'un niveau préfait
 for(i=0; i<10; i++)
  {
    for(j=0; j<20; j++)
    {
     if((i==1&&j%3==0)||(i==6&&j%3==0)){//jaune ne se detruit pas
      cases[i*20+j].x=j*0.1-1;
      cases[i*20+j].y=i*0.1;
      cases[i*20+j].r=1;
      cases[i*20+j].v=1;
      cases[i*20+j].b=0;
      cases[i*20+j].coup=-10;
     }else {
           if(i%2==0&&j%2==0){// gris 3 coup detruite
                cases[i*20+j].x=j*0.1-1;
                cases[i*20+j].y=i*0.1;
                cases[i*20+j].r=0.5;
                cases[i*20+j].v=0.5;
                cases[i*20+j].b=0.5;
                cases[i*20+j].coup=2;

           }else{//autre couleur un seul coup
        if(i==5&&j==7){//rose case pour les bonus
          cases[i*20+j].x=j*0.1-1;
          cases[i*20+j].y=i*0.1;
          cases[i*20+j].r=1;
          cases[i*20+j].v=0;
          cases[i*20+j].b=1;
          cases[i*20+j].coup=1;
        }else{
                  cases[i*20+j].x=j*0.1-1;
                  cases[i*20+j].y=i*0.1;
                  cases[i*20+j].r=0;
                  cases[i*20+j].v=0.5;
                  cases[i*20+j].b=0.5;
                  cases[i*20+j].coup=1;
        }

        }

     }


    }
  }
 translationcases(0.05,0.05);
  return 200; // Retourne la taille du cases
}
/**************FIN*************************/

