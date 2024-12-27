#include "fonction_bell_23v2533.h"


void pushTabBE(char cBE, PileTab_tBE* PBE) 
{
    if (PBE->teteBE < MAXBE - 1) 
        PBE->dataBE[++(PBE->teteBE)] = cBE;
    else
        printf("Erreur : La pile est pleine.\n");
}

char pullTabBE(PileTab_tBE* PBE) 
{
    if (PBE->teteBE >= 0)
        return PBE->dataBE[(PBE->teteBE)--];
    else
        printf("Erreur : La pile est vide.\n");
        return '\0';
}

char headTabBE(PileTab_tBE* PBE) 
{
    if (PBE->teteBE >= 0)
        return PBE->dataBE[PBE->teteBE];
    else
        printf("Erreur : La pile est vide.\n");
        return '\0';
}

bool isEmptyTabBE(PileTab_tBE* PBE) 
{
    return PBE->teteBE == -1;
}

bool isPlentyTab(PileTab_tBE* PBE) 
{
    return PBE->teteBE == MAXBE - 1;
}

// Fonction pour vérifier les expressions bien formées
bool verifierExpressionBE(const char* expressionBE) 
{
    PileTab_tBE pileBE;
    pileBE.teteBE = -1;

    for (int iBE = 0; expressionBE[iBE] != '\0'; iBE++) 
    {
        char cBE = expressionBE[iBE];
        switch (cBE) 
        {
            case '(':
            case '[':
            case '{':
            case '|':
                // Si c'est une barre verticale, vérifier le contexte
                if (cBE == '|' && !isEmptyTabBE(&pileBE) && headTabBE(&pileBE) == '|')
                    pullTabBE(&pileBE); // Fermeture de la barre
                else
                    pushTabBE(cBE, &pileBE);

                break;
            case ')':
                if (isEmptyTabBE(&pileBE) || headTabBE(&pileBE) != '(')
                    return false;

                pullTabBE(&pileBE);
                break;
            case ']':
                if (isEmptyTabBE(&pileBE) || headTabBE(&pileBE) != '[')
                    return false;

                pullTabBE(&pileBE);
                break;

            case '}':
                if (isEmptyTabBE(&pileBE) || headTabBE(&pileBE) != '{')
                    return false;

                pullTabBE(&pileBE);
                break;
        }
    }

    return isEmptyTabBE(&pileBE);
}