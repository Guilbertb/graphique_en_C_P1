/****************************************************/
/* Jeux de fonctions utilisant le format image PBM  */
/* (c)Bogt 2018                                     */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "fonctions_graphique.h"


int main()
{
    efface();
//    ligne (4,200,200,4);
//    ligne (4,4,200,200);
    ligne (1,1, 4,5);
//    ligne_horizontale(4,100,200);
    if (sauve_image_P1("image.pbm")==EXIT_FAILURE)
    {
        perror("Pas de fichier généré");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


