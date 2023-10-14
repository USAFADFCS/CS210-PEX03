/** pex3.c
 * =============================================================
 * Name: The Name of You
 * Section:  Your Section
 * Project:  FILL IN
 * Purpose:  FILL IN
 * Documentation Statement:  FILL IN
 * ============================================================= */
#include "pex3functs.h"
#include "pex3test.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /** 
     * Use gcc *.c -D RUNTESTS -Wall -Werror -o PEX3
     * to run testing code.  Remove -D RUNTESTS and 
     * recompile to run without testing
     **/
    #ifdef RUNTESTS
        runAllTests();
        exit(0);
    #endif

    /** 
     * Note: The following printfs/calls run with pex3Data1.txt they
     * will be useful during development of your test cases and
     * implmenentation of your functions. The function call is followed
     * by the expected result.  Leave these in your PEX.
    */
    int numSequences = 0;
    DNA* knownSequences = readFile("pex3Data1.txt", &numSequences);
    
    printSequences(knownSequences, numSequences);
    printf("hamming = %d\n", hammingDistance("AAA", "CC")); // result= -1
    printf("hamming = %d\n", hammingDistance("ACCT", "ACCG")); //result= 1
    printf("hamming = %d\n", hammingDistance("ACGGT", "CCGTT")); //result= 2
    printf("simularity = %0.3f\n", similarityScore("CCC", "CCC")); // result= 1.0
    printf("simularity = %0.3f\n", similarityScore("ACCT", "ACCG")); // result= 0.75
    printf("simularity = %0.3f\n", similarityScore("ACGGT", "CCGTT")); // result= 0.6
    printf("simularity = %0.3f\n", similarityScore("CCGCCGCCGA", "CCTCCTCCTA")); // result= 0.7
    printf("# matches = %d\n", countMatches("CCGCCGCCGA", "TTT", 0.6)); // result= 0
    printf("# matches = %d\n", countMatches("CCGCCGCCGA", "CCG", 0.2)); // result= 8
    printf("# matches = %d\n", countMatches(knownSequences[1].dna, "CGCTT", 0.5)); // result= 36
    printf("# matches = %d\n", countMatches(knownSequences[0].dna, "CGC", 0.3)); // result= 215
    printf("best match = %0.3f\n", findBestMatch("CCGCCGCCGA", "TTT")); // result= 0.0
    printf("best match = %0.3f\n", findBestMatch("CTGCCACCAA", "CCGC")); // result= 0.75
    printf("best match = %0.3f\n", findBestMatch(knownSequences[2].dna, "CGCTT")); // result= 0.8
    printf("best match = %0.3f\n", findBestMatch(knownSequences[0].dna, "CGC")); // result= 1.0
    printf("likely genome match = %s\n", knownSequences[findBestGenome(knownSequences, numSequences, "CTTTAGGCCGGTT")].species); //result=Cat
    printf("likely genome match = %s\n", knownSequences[findBestGenome(knownSequences, numSequences, "CTTTAGGCCGGG")].species); //result= Human
    printf("likely genome match = %s\n", knownSequences[findBestGenome(knownSequences, numSequences, "CTTAATTCTTTT")].species); //result= Mouse
        
    return 0;
}