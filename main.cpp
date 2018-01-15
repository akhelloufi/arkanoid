 #ifdef WIN32
  #include <windows.h>
#endif
#include <gl/gl.h>
#include <gl/glut.h>
#include <stdio.h>

#include <malloc.h>
#include <stdlib.h>
#include "main.h"


/* GLUT callback Handlers */



void clavier(int key, int x, int y)
{
switch (key)
{
case GLUT_KEY_LEFT : //testTracerTir=1;
    break;
case GLUT_KEY_RIGHT :  testTracerTir=0; break;
case GLUT_KEY_UP :   break;
case GLUT_KEY_DOWN :   break;

case GLUT_KEY_F5 : exit(2); break;
}
glutPostRedisplay(); // On redessine
}
void souris(int bouton,int etat,int x,int y) {

if(bouton==0){

  testTracerTir=1;
  POINT p1;
GetCursorPos(&p1);

 xtir=p1.x+taille_barre/3 -0.016+0.1;
  //ytir=0;
 //Timer(1);


}
glutPostRedisplay();
}
static void display(void)
{glClearColor(0.5,0.5,0.5,0.0);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
    int perdu=jouer();

    //if(perdu==0)vie--;
    //glutSwapBuffers();
    if(perdu!=0){

            glutPostRedisplay();}

    else{



            exit(0);
            }

   // printf("NIVEAU=%d",niveau);
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':

            break;

        case '-':

            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{

    glutPostRedisplay();
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_HEIGHT ,SCREEN_WIDTH);
    glutInitWindowPosition(150,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT ");

    glutDisplayFunc(display);
    //glutKeyboardFunc(key);
    glutSpecialFunc(clavier);
    glutMouseFunc(souris);
     glutIdleFunc(idle);



    glutMainLoop();

    return EXIT_SUCCESS;
}
