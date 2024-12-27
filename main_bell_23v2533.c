#include "fonction_bell_23v2533.h"


int main() {
    system("clear");

    char choixBE;
    char fichierBE[100];
    FILE* fpBE = NULL;
    char cBE;
    do
    {
        // system("figlet 'Menu' | lolcat");
        printf("\t\tMENU\n\t1. Verifier une expression à partir du clavier\n\t2. Verifier une expression à partir d'un fichier\n\t0. Quitter\n\nChoix : ");
        scanf(" %c", &choixBE);
        switch(choixBE)
        {  
            case '1':
                system("clear");
                printf("Entrez l'expression à verifier : ");
                char exprBE[255];
                scanf("%s", exprBE);
                system("clear");
                if(verifierExpressionBE(exprBE))
                    printf("L'expression \"%s\" est bien formée.\n", exprBE);
                else
                    printf("L'expression \"%s\" n\'est pas bien formée.\n", exprBE);

                break;

            case '2': 
                system("clear");
                printf("Voulez-vous tester un fichier existant ou avez-vous un fichier à bien spécifique à tester ?\n");
                printf("\n\t1. Je veux tester un fichier existant\n\t2. J'ai un fichier bien spécifique à tester\n\nChoix : ");
                scanf(" %c", &cBE);
                switch(cBE)
                {
                    case '1':
                        system("clear");
                        printf("\tNom du fichier: \"bien_forme.txt\"\n");
                        fpBE = fopen("bien_forme.txt", "r");
                        sleep(1);
                        break;

                    case '2':
                    system("clear");                        
                        printf("Entrez le nom du fichier contenant les expressions : ");
                        scanf("%s", fichierBE);
                        fpBE = fopen(fichierBE, "r");
                        break;

                    default:
                        system("clear");
                        printf("Choix non valide\n");
                        break;
                }
                
                // system("clear");
                if (!fpBE) {
                    printf("Erreur : Impossible d'ouvrir le fichier.\n");
                    // return 1;
                    break;
                }

                char ligneBE[256];
                while (fgets(ligneBE, sizeof(ligneBE), fpBE)) 
                {
                    if (verifierExpressionBE(ligneBE)) 
                        printf("L'expression \"%s\" est bien formée.\n", ligneBE);
                    else
                        printf("L'expression \"%s\" n'est pas bien formée.\n", ligneBE);
                }
                break;
            case '0':
                printf("Au revoir et merci d'avoir testé mon programme\n\n");
                sleep(1);
                break;

            default:
                system("clear");            
                printf("Choix non disponible\n");
                break;
        }
    }while(choixBE != '0');

    if(fpBE)
        fclose(fpBE);

    return 0;
}
