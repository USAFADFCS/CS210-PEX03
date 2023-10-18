/** pex3functs.h
 * =============================================================
 * Name: Your Name
 * Section:  Your Section
 * Project:  FILL IN
 * Purpose:  FILL IN
 * ============================================================= */
#ifndef PEX3FUNCTS_H
#define PEX3FUNCTS_H

// Define the DNA struct below using a typedef

DNA* readFile(char fileName[], int* numSequences);

void printSequences(DNA sequences[], int numSeq);

int hammingDistance(char str1[], char str2[]);

float similarityScore(char seq1[], char seq2[]);

int countMatches(char genome[], char seq[], float minScore);

float findBestMatch(char genome[], char seq[]);

int findBestGenome(DNA sequences[], int numSeq, char unknownSeq[]);

#endif //PEX3FUNCTS_H
