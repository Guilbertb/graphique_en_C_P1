#include<stdio.h>
#include<stdlib.h>

/* dimension de l'image */
#define width 600
#define height 400

static FILE *image;
static char ecran[width][height]; /* Image de l'ecran en mémoire */

/* sauvegarde l'image  au format P1 */
int sauve_image_P1(char *nom_fichier)
{
    int x,y;
    image = fopen(nom_fichier,"w"); /* on ouvre en ecriture w */
    if(image == NULL)
    {
        perror("erreur d'ouverture du fichier\n");
        return EXIT_FAILURE;
    }
    /* on crée l'entete du fichier */
    fprintf(image,"P1\n");
    fprintf(image,"# commentaire\n");
    fprintf(image,"%d %d\n",width,height);
    /* on ecris les datas de l'image */
    for(y=0; y<height; y++)
    {
        for(x=0; x <width ; x++)

            fprintf(image,"%c ",ecran[x][y]);  /* place des points blancs */
    }
    return EXIT_SUCCESS;
}

void efface(void)
{
    int x,y;
    for(y=0; y<height; y++)
    {
        for(x=0; x <width ; x++)
            ecran[x][y]='0';  /* place des points blancs */
    }
    return;
}

void point(int x, int y)
{
    if ((x<=width) && (y<=height) && (x>=0) && (y>=0))
    ecran[x][y] = '1';
    else
        printf("On sort de l'ecran %d %d\n",x,y);
    return;
}

void ligne_horizontale(int x, int y , int longueur)
{
    int compteur;
    for(compteur=x; compteur<x+longueur; compteur++)
    {
        point(compteur, y);
    }

    return;
}

/* simple ligne verticale */
void ligne_verticale(int x, int y, int longueur)
{
    int compteur;
    for(compteur=y; compteur<y+longueur; compteur++)
    {
        point(x, compteur);
    }
    return;
}

/* http://raphaello.univ-fcomte.fr/Ig/Algorithme/Algorithmique.htm */

void ligne(int xi,int yi,int xf,int yf)
{
      int dx,dy,cpt,xinc,yinc,cumul,x,y ;
      x = xi ;
      y = yi ;
      /* on determine les distances entre point initial et final */
      dx = xf - xi ;
      dy = yf - yi ;
      /* en fonction du signe des segments on va incrementer ou decrementer */
      if (dx>0) xinc=1; else xinc=-1;
      if (dy>0) yinc=1; else yinc=-1;

      /* on garde la valeur absolue des segments */
      dx = abs(dx) ;
      dy = abs(dy) ;
      /* on place le point initial */
      point(x,y) ;

/* choix du cadran  */
      if ( dx > dy )
      {
        cumul = dx / 2 ;
        for ( cpt = 1 ; cpt <= dx ; cpt++ )
           {
            x += xinc ;
            cumul += dy ;
            if ( cumul >= dx )
                {
                cumul -= dx ;
                y += yinc ;
                }
            point(x,y) ;
            }
      }
        else
      {
        cumul = dy/2 ;
        for ( cpt = 1 ; cpt <= dy ; cpt++ )
            {
            y += yinc ;
            cumul += dx ;
            if ( cumul >= dy )
                {
                cumul -= dy ;
                x += xinc ;
                }
            point(x,y) ;
            }
      }
}
