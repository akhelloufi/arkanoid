#ifndef _systeme
#define _systeme

//==========================================================//
// Structure qui permet d'enregistrer les coordonnées à l'écran
//==========================================================//
struct S_COORD
{
  float x;
  float y;
};

float a=0.09 ; //larg case
int taille_cases;          // Taille du cases
int timer=0;
int timerdebut=0;
int timerfin=0;
float taille_barre=0.5;
int niveauTEST=0;
int testtracer=0;
int testpassniveau=0;
int niveau=1;
int fin_niveau=0;
int score=0;
//niveau
float xanime=0;
float yanime=0;
//vitesse
int testtracervitesse=0;
float xanimevitesse=0;
float yanimevitesse=0;
int vitesseballe=50;
//variable de temporaisation de la vitesse
int tv=1;
int debuttimervitesse=0;

//largeur de la barre
int testtracerlargeur=0;
float xanimelargeur=0;
float yanimelargeur;
/******variable pour plus de vie*******/
int testtracervie=0;
float xanimevie=0;
float yanimevie;
/**animation bonus tir**/
int testtir=0;
int t=1;
int testtracerbonuscanon=0;
float xanimecanon=0;
float yanimecanon=0;

/*** POSITION DE TIR ***/
float xtir;
float ytir;
int testTracerTir=0;
int testTracercanon=0;
struct S_COORD positionTir;
//variable de force
int tforce=1;
int testtracerbonuforce=0;//pour le message bonus
int testTracerForce=0;//pour tracer la force
float xanimeforce=0;
float yanimeforce=0;
int debuttimerforce=0;
int toucherballeforce=0;//nombre de fois ou balle touche la force limite de 3 fois et on arrete affichage de la force
      //position de la force
float xf=0.98;
float yf=0.981;
//nombre de vie au commencent du jeu
int vie =2;

//==========================================================//
// Structure spéciale pour les cases sur le cases             //
//==========================================================//
struct S_CASE
{
  float x;  // Coordonnées
  float y;
  float r;  // Couleur RGB ( red, green, blue )
  float v;
  float b;
  int coup;
  int bonusniveau;
  int bonuslargeurbarre;
  int bonusbigballe;
  int bonusdoubleballe;
  int bonusvitesse;
  int bonusvie;
  int bonuscanon;
  int bonusforce;
};


struct S_CASE cases[200];           // Pour toutes les cases
float xpos;

void affiche_anime(float x,float y )
{

  // Ecrit dans une matrice

glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);
  // Place chaque point du carré avec une couleur
       glColor3f (0, 0,1);   glVertex2f ( x-0.1/2,  y+0.1/2);
      glColor3f (0, 0,1);    glVertex2f ( x-0.1/2,  y-0.1/2);
      //glColor3f (1.0f, 1.0f, 1.0f);
      glColor3f (0, 0,1);
                                glVertex2f ( x+0.1/2,  y-0.1/2);
     glColor3f (0, 0,1);   glVertex2f ( x+0.1/2,  y+0.1/2);

  // Fin du dessin
  glEnd ();

  // Fin d'écriture dans la matrice
  glPopMatrix ();


}
//==========================================================//
// Fonction qui permet d'afficher la barre                  //
//==========================================================//
void affiche_barre(struct S_COORD position, float largeur)
{

  // Ecrit dans une matrice
  glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);

  // Place chaque point du carré avec une couleur
  glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (position.x-largeur/2, -1.98f);
  glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (position.x-largeur/2, -0.95f);
  glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (position.x+largeur/2, -0.95f);
  glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (position.x+largeur/2, -1.98f);

  // Fin du dessin
  glEnd ();

  // Fin d'écriture dans la matrice
  glPopMatrix ();
}
//afficher champ de force au niveau de la barre si bonus active
void affiche_champs(float x,float y)
{
  // Ecrit dans une matrice
  glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);

  // Place chaque point du carré avec une couleur
   glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (-0.98, -0.981f);
  glColor3f (0.0f, 0.0f, 0.0f);  glVertex2f (-0.98, -0.999f);
  glColor3f (0.0f, 0.0f, 0.0f);    glVertex2f (0.98, -0.999f);
  glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.98, -0.981f);
  //PARTIE HAUT
  // Fin du dessin
  glEnd ();

  // Fin d'écriture dans la matrice
  glPopMatrix ();
}

//fonction affiche canon
void affiche_canonGauche(struct S_COORD position, float largeur)
{
  // Ecrit dans une matrice
  glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);

  // Place chaque point du carré avec une couleur
   glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (position.x-largeur/2-0.1, -0.88f);
  glColor3f (0.09f, 0.98f, 0.32f);   glVertex2f (position.x-largeur/2-0.1, -0.95f);
  glColor3f (0.09f, 0.98f, 0.32f);    glVertex2f (position.x+largeur/2-0.1, -0.95f);
  glColor3f (0.09f, 0.98f, 0.32f);   glVertex2f (position.x+largeur/2-0.1, -0.88f);
  //PARTIE HAUT
   glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (position.x-largeur/3-0.1, -0.82f);
  glColor3f (0.94f, 0.0f, 0.46f);   glVertex2f (position.x-largeur/3-0.1, -0.95f);
 glColor3f (0.09f, 0.98f, 0.32f);    glVertex2f (position.x+largeur/3-0.1, -0.95f);
 glColor3f (0.09f, 0.98f, 0.32f);   glVertex2f (position.x+largeur/3-0.1, -0.82f);
 //initialiser la position du tir
xtir=position.x+largeur/3 -0.016;
ytir=-0.82;

  // Fin du dessin
  glEnd ();

  // Fin d'écriture dans la matrice
  glPopMatrix ();
}
void affiche_canonDroite(struct S_COORD position, float largeur)
{
  // Ecrit dans une matrice
  glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);

  // Place chaque point du carré avec une couleur
   glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (position.x-largeur/2+0.1, -0.88f);
  glColor3f (0.09f, 0.98f, 0.32f);   glVertex2f (position.x-largeur/2+0.1, -0.95f);
  glColor3f (0.09f, 0.98f, 0.32f);    glVertex2f (position.x+largeur/2+0.1, -0.95f);
  glColor3f (0.09f, 0.98f, 0.32f);   glVertex2f (position.x+largeur/2+0.1, -0.88f);
  //PARTIE HAUT
   glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (position.x-largeur/3+0.1, -0.82f);
  glColor3f (0.94f, 0.0f, 0.46f);   glVertex2f (position.x-largeur/3+0.1, -0.95f);
 glColor3f (0.09f, 0.98f, 0.32f);    glVertex2f (position.x+largeur/3+0.1, -0.95f);
 glColor3f (0.09f, 0.98f, 0.32f);   glVertex2f (position.x+largeur/3+0.1, -0.82f);
 //initialiser la position du tir
xtir=position.x+largeur/3 -0.016+0.1;
ytir=-0.82;

  // Fin du dessin
  glEnd ();

  // Fin d'écriture dans la matrice
  glPopMatrix ();
}
/**************afficher tir **********/
void affiche_tirGauche(float x, float y, float taille)
{
    static float Xtir1=x, Ytir1=y;
  // Ecrit dans une matrice
  glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);

 glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (Xtir1-taille/2, Ytir1+taille/2);
  glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (Xtir1-taille/2, Ytir1-taille/2);
  glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (Xtir1+taille/2, Ytir1-taille/2);
  glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (Xtir1+taille/2, Ytir1+taille/2);

// glColor3f (1.0f, 0.0f, 1.0f);   glVertex2f (x+taille/2, y-taille/2);
 // glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (x+taille/2, y+taille/2);
 //initialiser la position du tir

  // Fin du dessin
  glEnd ();
if(Ytir1<0)
Ytir1=Ytir1+0.05;
else
    Ytir1=Ytir1+0.05;

int i;
struct S_CASE* cases_case=cases;
//gestion des colision avec le Tir  et les cases
  for(i=0; i<taille_cases; i++)
  {
    if(cases_case[i].x!=10)
    {
      if(((Ytir1-taille)<=cases_case[i].y) && ((Ytir1+taille)>=cases_case[i].y)) // Si le tir est au niveau de la case
      {
        // Teste au niveau de l'axe des abscisses
        if(((Xtir1-taille)<=cases_case[i].x+0.01) && ((Xtir1+taille)>=cases_case[i].x+0.01))
        {
            cases_case[i].x=10;//effacer case

          score++;
        }
      }
    }
  }

    //if(Ytir1<1) affiche_tir( x, y,taille);
  // Fin d'écriture dans la matrice


  glPopMatrix ();
if(Ytir1>1){
        testTracerTir=0; Xtir1=x;Ytir1=y;
}
//if(testtir==1) affiche_tir(x,y,taille);
}
/***TIR DROITE***/
void affiche_tirDroite(float x, float y, float taille)
{
    static float Xtir2=x, Ytir2=y;
  // Ecrit dans une matrice
  glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);

 glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (Xtir2-taille/2, Ytir2+taille/2);
  glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (Xtir2-taille/2, Ytir2-taille/2);
  glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (Xtir2+taille/2, Ytir2-taille/2);
  glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (Xtir2+taille/2, Ytir2+taille/2);

// glColor3f (1.0f, 0.0f, 1.0f);   glVertex2f (x+taille/2, y-taille/2);
 // glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (x+taille/2, y+taille/2);
 //initialiser la position du tir

  // Fin du dessin
  glEnd ();
if(Ytir2<0)
Ytir2=Ytir2+0.05;
else
    Ytir2=Ytir2+0.05;

int i;
struct S_CASE* cases_case=cases;
//gestion des colision avec le Tir  et les cases
  for(i=0; i<taille_cases; i++)
  {
    if(cases_case[i].x!=10)
    {
      if(((Ytir2-taille)<=cases_case[i].y) && ((Ytir2+taille)>=cases_case[i].y)) // Si le tir est au niveau de la case
      {
        // Teste au niveau de l'axe des abscisses
        if(((Xtir2-taille)<=cases_case[i].x+0.01) && ((Xtir2+taille)>=cases_case[i].x+0.01))
        {
            cases_case[i].x=10;//effacer case

          score++;
        }
      }
    }
  }

    //if(Ytir1<1) affiche_tir( x, y,taille);
  // Fin d'écriture dans la matrice


  glPopMatrix ();
if(Ytir2>1){
        testTracerTir=0; Xtir2=x;Ytir2=y;
}
//if(testtir==1) affiche_tir(x,y,taille);
}
/******/
void Timer(int extra)
	{
	    if(testTracerTir==1)
	    //affiche_tir(xtir, ytir, 0.025);
	glutPostRedisplay();
	glutTimerFunc(1000,Timer,0);
	}
//==========================================================//
// Fonction qui affiche la barre à la position de la souris //
// et qui renvoie la position actuelle de la barre          //
//==========================================================//
struct S_COORD gestion_barre(float largeur)
{
  struct S_COORD position; // Pour la position de la barre
  POINT pt; // Pour les positions de la souris

  GetCursorPos(&pt); // Récupère la position du curseur à l'écran

  // Transfert les données
  position.x=(2*(float)pt.x/SCREEN_WIDTH)-1;
  position.y=(2*(float)pt.y/SCREEN_HEIGHT)-1;

  // Vérifie la vraisemblance des coordonnées de la barre
  if((position.x-largeur/2)<-1) position.x=largeur/2-1;
  if((position.x+largeur/2)>1) position.x=1-largeur/2;

xtir=position.x+largeur/3 -0.016;
ytir=-0.82;
//affiche le canon sur la barre si bonus canon active
 struct S_COORD positionCanon;

 positionCanon.x=position.x;
 positionCanon.y=position.y;

 if(testTracerTir==1&&timer-timerdebut<30000){
    testtir=1;
       affiche_tirGauche(xtir-0.2,ytir,0.025);//TIR GAUCHE
       affiche_tirDroite(xtir ,ytir,0.025);//TIR DROITE
      //Timer(1);testTracerTir=0;
    }

 if(testTracercanon==1&&t==1){
        //debut de animation du canon
        timerdebut=timer;
        t=0;

 affiche_canonGauche(positionCanon, 0.05);
 affiche_canonDroite(positionCanon, 0.05);
 }
 printf("posTirx=%f\n",xtir);
 printf("posTirY=%f\n",ytir);
  printf("testTracercanon=%d",testTracercanon);
  printf("autoriser de tirer testTracerTir=%d \n",testTracerTir);
 printf("timer=%d",timer);
 printf("debuttimer=%d",timerdebut);
 if(testTracercanon==1&&timer-timerdebut<30000&&t==0){
    affiche_canonGauche(positionCanon, 0.05);
    affiche_canonDroite(positionCanon, 0.05);

 }else {testTracerTir=0;testTracercanon=0;testtir=0;timerdebut=0;t=1;}
 // Affiche la barre
 affiche_barre(position, largeur);
     //TIRER SUR LES BLOC

     //AFFICHER CHAMP SI BONUS TOUCHER ET PENDANT 30SECONDES
//debut du tracer et enregistrement temps de debut
if(testTracerForce==1&&tforce==1&&toucherballeforce<3){

    //affiche_champs();
    debuttimerforce=timer;
    tforce=0;
}
if(timer-debuttimerforce<=30000&&tforce==0&&toucherballeforce<3){

    affiche_champs(xf, yf);

}else{testTracerForce=0;debuttimerforce=0;tforce=1;toucherballeforce=0;}

  return position;
}
/**********fonction texte************/
void ecrire(float x, float y,char *s)
{
    // Ces deux fonctions évitent les problèmes d'affichage du texte
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    // On indique la position du texte (passées par paramètre)
    glRasterPos2f(x,y);
    // Tant qu'un caractère doit être lu
    while (*s) {
    // On écrit le caractère
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*s);
    // On passe au caractère suivant
    s++;
    }
}

void tracerlettrebonus(float *x,float *y ,char *s){


    /* clear the window */

   glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2f(*x,*y);
     glPushMatrix ();
  glColor3f (0, 0,1);

       while (*s) {
    // On écrit le caractère
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_10,*s);
    // On passe au caractère suivant
    s++;
    }
*y=*y-0.0025;//*x=*x-0.001;

 //glutTimerFunc(1000,tracerlettrebonus(x,y,s),0);
}
/*******************/
void bitmap_output(int x,int y,char *string,void *font) {
  int len,i;
  glRasterPos2f(x,y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font,string[i]); }
}
//=======================================================//
// Fonction qui affiche la balle                         //
//=======================================================//
void affiche_balle(float x, float y, float taille)
{
  // Ecrit dans une matrice
  glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);

  // Place chaque point du carré avec une couleur
  glColor3f (1.0f, 0.0f, 1.0f);   glVertex2f (x-taille/2, y+taille/2);
  glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (x-taille/2, y-taille/2);
  glColor3f (1.0f, 0.0f, 1.0f);   glVertex2f (x+taille/2, y-taille/2);
  glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (x+taille/2, y+taille/2);

 glColor3f (1.0f, 0.0f, 1.0f);   glVertex2f (x+taille/2, y-taille/2);
  glColor3f (0.0f, 1.0f, 1.0f);   glVertex2f (x+taille/2, y+taille/2);

  // Fin du dessin
  glEnd ();

  // Fin d'écriture dans la matrice
  glPopMatrix ();
}


//=======================================================//
// Fonction qui affiche une case                         //
//=======================================================//
void affiche_case(struct S_CASE* cases_case, int taille_cases)
{
  int i; // Bcl

  // Ecrit dans une matrice
  glPushMatrix ();

  // Dessine un carré
  glBegin (GL_QUADS);

  // Parcoure le cases
  for(i=0; i<taille_cases; i++)
  {
    // Affiche que s'il le faut
    if(cases_case[i].x!=10)
    {


      //glColor3f (cases_case[i].r, cases_case[i].v, cases_case[i].b);
      glColor3f (1.0f, 1.0f, 1.0f);
      glVertex2f (cases_case[i].x-a/2, cases_case[i].y+a/2);
      glColor3f (cases_case[i].r, cases_case[i].v, cases_case[i].b);   glVertex2f (cases_case[i].x-a/2, cases_case[i].y-a/2);
      //glColor3f (1.0f, 1.0f, 1.0f);
      glColor3f (cases_case[i].r, cases_case[i].v, cases_case[i].b);
                                glVertex2f (cases_case[i].x+a/2, cases_case[i].y-a/2);
      glColor3f (cases_case[i].r, cases_case[i].v, cases_case[i].b);
      //glColor3f (1.0f, 1.0f, 1.0f);
      glVertex2f (cases_case[i].x+a/2, cases_case[i].y+a/2);


    }else{

      if(cases_case[i].bonusniveau==1){
                //passe au niveau suivant
               // niveau++;

      }
    }
  }

  // Fin du dessin
  glEnd ();

  // Fin d'écriture dans la matrice
  glPopMatrix ();
}


//=======================================================//
// Fonction qui bouge la balle et qui gère aussi les     //
// contacts avec les cases placées dans un cases           //
// renvoie 0 si la balle est derrière la barre sinon 1   //
//=======================================================//
int gestion_balle(float x_barre, float larg_barre, float larg_balle, struct S_CASE* cases_case, int taille_cases)
{
  static float Xballe=0, Yballe=-0.75;     // Position de la balle
  static float Xdir=X_DIR, Ydir=Y_DIR;     // Direction de la balle
  int i;                                   // Bcl
                char message[20];

                  sprintf(message,"FORCE:%d",testTracerForce);
                  ecrire(-1,-0.50,message);

                sprintf(message,"TIME: %d",timer/1000);
                ecrire(-1,-0.60,message);
                sprintf(message,"SCORE: %d",score);
                ecrire(-1,-0.7,message);

                sprintf(message,"vie restante: %d",vie);
                ecrire(-1,-0.8,message);
              //  printf("niveau==%d \n\n",niveau);
                sprintf(message,"Niveaus: %d",niveau);
                ecrire(-1,-0.9,message);


                if(testtracer==1&&yanime>=-1){
                     tracerlettrebonus(&xanime,&yanime,"<<Niveau suivant>>");

                }else{testtracer=0;
                xanime=0;
                yanime=0;
                }
                if(testtracervitesse==1&&yanimevitesse>=-1){
                     tracerlettrebonus(&xanimevitesse,&yanimevitesse,"<<Vitesse++>>");

                }else{testtracervitesse=0;
                xanimevitesse=0;
                yanimevitesse=0;
                }
                //POUR BONUS LARGEUR BARRE
                 if(testtracerlargeur==1&&yanimelargeur>=-1){
                     tracerlettrebonus(&xanimelargeur,&yanimelargeur,"<<Largeur Barre++>>");

                }else{testtracerlargeur=0;
                xanimelargeur=0;
                yanimelargeur=0;
                }
                //POUR BONUS VIE SUPPLEMEMENTAIRE
                if(testtracervie==1&&yanimevie>=-1){
                     tracerlettrebonus(&xanimevie,&yanimevie,"<<|VIE|>>");

                }else{testtracervie=0;
                xanimevie=0;
                yanimevie=0;
                }
                //bonus canon message
                 if(testtracerbonuscanon==1&&yanimecanon>=-1){
                     tracerlettrebonus(&xanimecanon,&yanimecanon,"<<|CANON|>>");

                }else{testtracerbonuscanon=0;
                xanimecanon=0;
                yanimecanon=0;
                }
                //bonus force message
                 if(testtracerbonuforce==1&&yanimeforce>=-1){
                     tracerlettrebonus(&xanimeforce,&yanimeforce,"<<|FORCE MAGNETIQUE|>>");

                }else{testtracerbonuforce=0;
                xanimeforce=0;
                yanimeforce=0;
                }
   // Affiche la balle
  affiche_balle(Xballe, Yballe, larg_balle);

  // Affiche les cases
  affiche_case(cases_case, taille_cases);

  // Avance la balle
  Xballe=Xballe+Xdir;
  Yballe=Yballe+Ydir;

  // Gère les rebonds
  if((Xballe+larg_balle/2)>1)  Xdir*=-1;
  if((Xballe-larg_balle/2)<-1) Xdir*=-1;
  if((Yballe+larg_balle/2)>1)  Ydir*=-1;
  if((Yballe-larg_balle/2)<-1.5 ) {
            // La balle est derrière la barre...on donne une autre vie si vie=0  fin du jeu
            if(vie==0){

                return 0;
            }else{

                    //diminution de vie et reaffichage du jeu
                    vie--;
                     // Affiche la balle avec les position initiale
                     Xballe=0, Yballe=-0.05;
                    affiche_balle(Xballe, Yballe, larg_balle);


            }

  }

  // Teste les contacts entre la balle et la barre
  if((Yballe-larg_balle/2<=-0.95) && (Yballe+larg_balle/2>=-0.98)) // Si la balle est au niveau de la barre
  {
    // Teste au niveau de l'axe des abscisses
    if(((Xballe+larg_balle/2)>=(x_barre-larg_barre/2)) && ((Xballe-larg_balle/2)<=(x_barre+larg_barre/2)))
    {
      // Fait le rebond
      Ydir*=-1;

      // Oriente différemment la balle selon le contact avec la barre
      Xdir=(Xballe-x_barre)/10;

      // Met une valeur max et une min
      if(Xdir>0.025)  Xdir=0.025;
      if(Xdir<-0.025) Xdir=-0.025;
    }
  }

  // Teste les contacts entre les cases et la balle
  for(i=0; i<taille_cases; i++)
  {
    if(cases_case[i].x!=10)
    {
      if(((Yballe-larg_balle)<=cases_case[i].y+0.01) && ((Yballe+larg_balle)>=cases_case[i].y+0.01)) // Si la balle est au niveau de la case
      {
        // Teste au niveau de l'axe des abscisses
        if(((Xballe-larg_balle)<=cases_case[i].x+0.01) && ((Xballe+larg_balle)>=cases_case[i].x+0.01))
        {
          // Fait le rebond en fonction de l'endroit où il tape sur la case
          if((Yballe>=(cases_case[i].y+0.001)) || (Yballe<=(cases_case[i].y-0.001))) Ydir*=-1;
          if((Xballe>=(cases_case[i].x+0.001)) || (Xballe<=(cases_case[i].x-0.001))) Xdir*=-1;

          score++;

                           // affiche_anime( );


        printf("cases_case[i].bonusniveau==:::%f",cases_case[i].bonusniveau);

        printf("\n case %i coup %d \n",i,cases_case[i].coup);
          // Efface la case SELON sa couleur ET si coup==1
          if(cases_case[i].coup==1){
                          if(cases_case[i].bonusniveau==1){
                //passe au niveau suivant
               // niveau++;

                           xanime=cases_case[i].x;
                           yanime=cases_case[i].y;
                              // Affiche la balle
                             // affiche_anime(Xball, Yball);
                           printf("yanime==:::%f \n",yanime);
                           printf("xanime==:::%f\n",xanime);
                        testtracer=1;


                                cases_case[i].x=10;
                        }else{
                            if(cases_case[i].bonusvitesse==1){
                                //passe au niveau suivant
                               // niveau++;

                            xanimevitesse=cases_case[i].x;
                           yanimevitesse=cases_case[i].y;
                              // Affiche la balle
                             // affiche_anime(Xball, Yball);
                           printf("yanimevitesse==:::%f \n",yanimevitesse);
                           printf("xanimevitesse==:::%f\n",xanimevitesse);
                        testtracervitesse=1;
                        //vitesseballe=10;

                    cases_case[i].x=10;
                }else{
                            if(cases_case[i].bonuslargeurbarre==1){
                    //passe au niveau suivant
                   // niveau++;

                               xanimelargeur=cases_case[i].x;
                               yanimelargeur=cases_case[i].y;
                                  // Affiche la balle
                                 // affiche_anime(Xball, Yball);
                               printf("yanimelargeur==:::%f \n",yanimelargeur);
                               printf("xanimelargeur==:::%f\n",xanimelargeur);
                               testtracerlargeur=1;
                            //vitesseballe=10;

                            cases_case[i].x=10;
                        }else{
                            if(cases_case[i].bonusvie==1){//pour ajouter une vie

                                    xanimevie=cases_case[i].x;
                                   yanimevie=cases_case[i].y;
                                      // Affiche la balle
                                     // affiche_anime(Xball, Yball);
                                   printf("yanimevie==:::%f \n",yanimevie);
                                   printf("xanimevie==:::%f\n",xanimevie);
                                   testtracervie=1;


                                    cases_case[i].x=10;
                          }else{
                                     if(cases_case[i].bonuscanon==1){//pour ajouter uN CANON 30S

                                    xanimecanon=cases_case[i].x;
                                   yanimecanon=cases_case[i].y;
                                      // Affiche la
                                     // affiche_anime(Xball, Yball);
                                   printf("yanimecanon==:::%f \n",yanimecanon);
                                   printf("xanimecanon==:::%f\n",xanimecanon);
                                   testtracerbonuscanon=1;


                                        cases_case[i].x=10;
                                  }else{
                                               if(cases_case[i].bonusforce==1){//pour afficher le message force magnétique

                                            xanimeforce=cases_case[i].x;
                                           yanimeforce=cases_case[i].y;
                                              // Affiche la
                                             // affiche_anime(Xball, Yball);
                                           printf("yanimeforce==:::%f \n",yanimeforce);
                                           printf("xanimeforce==:::%f\n",xanimeforce);
                                           testtracerbonuforce=1;


                                                cases_case[i].x=10;
                                          }else{ cases_case[i].x=10;}






                                  }
                        }


            }




            }

        }

          }else {

              if(cases_case[i].coup==2){
              cases_case[i].coup=cases_case[i].coup-1;}
              //cases_case[i].r=0.4;
             // cases_case[i].v=0;
             // cases_case[i].b=0;

              }


        }
      }
    }
  }

  //SI BONUS FORCE ACTIVE ET QUE LA BALLE ET AU NIVEAU DE LA FORCE LA FORCE REMPLACE LA BARRE
  if(testTracerForce==1&&toucherballeforce<3){
          if((Yballe-larg_balle/2<=-yf) && (Yballe+larg_balle/2>=-yf)) // Si la balle est au niveau de la barre
          {

              // Fait le rebond
              Ydir*=-1;

              // Oriente différemment la balle selon le contact avec la barre
              //Xdir=(Xballe-x_barre)/10;

              // Met une valeur max et une min
              //if(Xdir>0.025)  Xdir=0.025;
              //if(Xdir<-0.025) Xdir=-0.025;
            toucherballeforce++;//nombre de fois ou balle touche la force
           //
            printf("\n toucherballeforce:%d \n",toucherballeforce);
            //Sleep(4000);
          }


  }
// bonus niveau au niveau barre
if((yanime<=-0.95) && (yanime>=-0.98)) // Si la balle est au niveau de la barre
  {
    if(((xanime)>=(x_barre-larg_barre/2)) && ((xanime)<=(x_barre+larg_barre/2)))
    {
        //reinitialiser les position  d animation du bonus
        xanime=-10;
        yanime=-10;
        //niveau++;
        testpassniveau=1;

    }

  }
  // bonus vitesse ++ au niveau barre
if((yanimevitesse<=-0.95) && (yanimevitesse>=-0.98)) // Si la balle est au niveau de la barre
  {
    if(((xanimevitesse)>=(x_barre-larg_barre/2)) && ((xanimevitesse)<=(x_barre+larg_barre/2)))
    {
        //reinitialiser les position  d animation du bonus
        xanimevitesse=-10;
        yanimevitesse=-10;
        //niveau++;
       // testpassniveau=1;
       vitesseballe=vitesseballe/10;
        //debut de timer de 5seceonde

        debuttimervitesse=timer;
        tv=0;
    }

  }
//collision bonus largeur avec barre
    if((yanimelargeur<=-0.95) && (yanimelargeur>=-0.98)) // Si la balle est au niveau de la barre
  {
    if(((xanimelargeur)>=(x_barre-larg_barre/2)) && ((xanimelargeur)<=(x_barre+larg_barre/2)))
    {
        //reinitialiser les position  d animation du bonus
        xanimelargeur=-10;
        yanimelargeur=-10;
        //niveau++;
       // testpassniveau=1;
       //augmentant largeur de la barre
        taille_barre+=(taille_barre/4);

    }

  }
//colision bonus vie supplementaire
    if((yanimevie<=-0.95) && (yanimevie>=-0.98)) // Si la balle est au niveau de la barre
  {
    if(((xanimevie)>=(x_barre-larg_barre/2)) && ((xanimevie)<=(x_barre+larg_barre/2)))
    {
        //reinitialiser les position  d animation du bonus
        xanimevie=-10;
        yanimevie=-10;
        //niveau++;
        vie++;


    }

  }

//colision bonus canon
    if((yanimecanon<=-0.95) && (yanimecanon>=-0.98)) // Si le message est au niveau de la barre
  {
    if(((xanimecanon)>=(x_barre-larg_barre/2)) && ((xanimecanon)<=(x_barre+larg_barre/2)))
    {
        //reinitialiser les position  d animation du bonus
        xanimecanon=-10;
        yanimecanon=-10;
        //niveau++;
        //le test pour afficher le canon et les tirs
        testTracercanon=1;



    }

  }

  //colision bonus force magnétique
    if((yanimeforce<=-0.95) && (yanimeforce>=-0.98)) // Si le message est au niveau de la barre
  {
    if(((xanimeforce)>=(x_barre-larg_barre/2)) && ((xanimeforce)<=(x_barre+larg_barre/2)))
    {
        //reinitialiser les position  d animation du bonus
        xanimeforce=-10;
        yanimeforce=-10;
        //niveau++;
        //le test pour afficher le canon et les tirs
        testTracerForce=1;



    }

  }
  return 1; // Fin de la fonction, tous s'est bine passé !
}


//==========================================================//
// Fonction qui indique si le plateau de jeu est vide ou pas//
// Renvoie 1 si le plateau est vide                         //
//==========================================================//
int niv_suivant(struct S_CASE* cases_case, int taille_cases)
{
  int i;
  int j=0;
  //on passe si il reste que les jaune aussi ou si rien n existe
  for(i=0; i<taille_cases; i++)
  {
    if(cases_case[i].coup!=-10&&cases_case[i].x<10) j++; // Le plateau n'est pas vide reste des case a detruire

 // printf("\ncases_case[%d].x=%f\n",i,cases_case[i].x);
  }
  printf("\n---j=%d\n",j);
  if(j==0) return 1;
//on passe si il reste que les jaune aussi ou si rien n existe
  for(i=0; i<taille_cases; i++)
  {
    if(cases_case[i].x!=10) return 0; // Le plateau n'est pas vide si autre que les jaunes

  }

  return 1; // Le plateau est vide
}


#endif
