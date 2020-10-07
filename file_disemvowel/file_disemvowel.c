#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 1024
//method for checking for vowels
bool is_vowel(char c) {
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ){
  return true;
  }else{
  return false;
  }
}
//method for copying over the non-vowels
int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
int count = 0; //Initialize variable
  for(int i = 0; i < num_chars-1; i++){
	  if(is_vowel(in_buf[i])==false){ //check if char at location is vowel
		  out_buf[count] = in_buf[i]; //store char at location to out_buf
		  count++; //move location of out_buf up one
	  }
  }
  return count;
}
//method that uses both previous methods to remove vowels and copy constanants over to destination
void disemvowel(FILE* inputFile, FILE* outputFile) {
//Initialize memory variables
char* inBuff = (char*)calloc(BUF_SIZE, sizeof(char));
char* outBuff = (char*)calloc(BUF_SIZE, sizeof(char));
//Initialize variable for storing characters from inputFile
int nChars = 0;
//Store characters from inputFile to nChars
nChars = (int)fread(inBuff, sizeof(char), BUF_SIZE, inputFile);
//Check if no chars where stored, if there are characters then proceed to writing to output file.
if(nChars != 0){
int Consts = copy_non_vowels(nChars, inBuff, outBuff); //Store non-vowels from nChars into a variable Consts
fwrite(outBuff, sizeof(char), Consts, outputFile); //Write to outputFile contents of Consts
  }
free(inBuff); //Free mem
free(outBuff); //Free mem
fclose(inputFile); //Close file
fclose(outputFile); //Close file
  
}

//running the main method
int main(int argc, char *argv[]) {
//Initialize files
  FILE *inputFile;
  FILE *outputFile;
//Check amount of args. If console string input, then do standard console input and output
  if(argc == 1){
  inputFile = stdin;
  outputFile = stdout;
  }
  else //if file input, then open file and print to console output
  if(argc == 2){
  inputFile = fopen(argv[1], "r");
  outputFile = stdout;
  }
  else //if two files input, then read first file and output to second file
  if(argc == 3){
  inputFile = fopen(argv[1], "r");
  outputFile = fopen(argv[2], "w");
  }
  else //otherwise give error and exit
  {
  printf("Please input only at most 2 arguments.");
  exit(0);
  }

  disemvowel(inputFile, outputFile); //Run disemvowel on choosen input
  return 0;
}
