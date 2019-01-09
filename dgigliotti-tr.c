//
// Assignment 3
// Daniela Gigliotti
// COM SCI X 414.20 (Fall 2018)
//

// Declare libraries
#include <stdio.h>

// Define function prototypes
void ReadAmt(void);    // Reads transaction type and amount from source file
void CalcNetBal(void);  // Calculates net balance
void PrintDetail(void); // Prints transaction type, amount, and net balance to report


// Define variables
char transaction[10];   // Transaction type
float amount;           // Amount in dollars
float NetBal = 1000;    // Net balance, initially set to 1000
int counter;            // Count of transactions processed


// Declare input and output files
FILE *inputfile;
FILE *outputfile;


// Main function to open report and call other functions
float main(void){

    // Open source file with transactions and amounts
    inputfile = fopen("c:\\class\\transactions.txt", "r");

    // Open and write output file
    outputfile = fopen ("c:\\class\\dgigliotti-tr.txt","w");

    // Print report header
    fprintf(outputfile, "Turtle Bay Traders\n");
    fprintf(outputfile, "4800 Palawan Way\n");
    fprintf(outputfile, "Mandalay Beach, CA 99499\n\n");
    
    fprintf(outputfile, "Operating Account Starting Balance:  %6.2f\n\n", NetBal);
    
    fprintf(outputfile, "Transaction       Amount                 Net\n");
    fprintf(outputfile, "-----------       ------                 ---\n");

    // Call functions
    while (!feof(inputfile)) {
    ReadAmt();    // Reads transaction type and amount from source file
    CalcNetBal();  // Calculates net balance
    PrintDetail(); // Prints transaction type, amount, and net balance to report
    }

    // Print ending balance and number of transactions processed
    fprintf(outputfile, "\nOperating Account Ending Balance:   %8.2f\n", NetBal);
    fprintf(outputfile, "There were %d transactions processed.", counter);
    
    // Close input file
    fclose(inputfile);
    
    // Close output file
    fclose(outputfile);
    
    return 0;
}


// Reads transaction type and amount from source file
void ReadAmt(void) {
    fgets(transaction, 10, inputfile);
    fscanf(inputfile, "%f\n", &amount);

}


// Calculates net balance
void CalcNetBal(void) {
    NetBal = NetBal + amount;

}


// Prints transaction type, amount, and net balance to report
void PrintDetail(void) {
    fprintf(outputfile, "%s        %7.2f            %8.2f\n", transaction, fabs(amount), NetBal);
    counter++;

}

