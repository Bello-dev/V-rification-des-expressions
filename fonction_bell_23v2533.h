#ifndef FONCTION_BELL__
#define FONCTION_BELL__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAXBE 100

typedef struct {
    char dataBE[MAXBE];
    int teteBE;
} PileTab_tBE;


void pushTabBE(char cBE, PileTab_tBE* PBE);
char pullTabBE(PileTab_tBE* PBE);
char headTabBE(PileTab_tBE* PBE);
bool isEmptyTabBE(PileTab_tBE* PBE);
bool isPlentyTab(PileTab_tBE* PBE);
bool verifierExpressionBE(const char* expressionBE);


#endif