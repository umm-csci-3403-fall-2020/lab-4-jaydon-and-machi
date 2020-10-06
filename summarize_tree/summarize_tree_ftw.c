#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

static int num_dirs, num_files;
static int callback(const char *fpath, const struct stat *sb, int typeflag) {
	if(typeflag == FTW_D){ //Check to see if the flag value is set to FTW_D
		num_dirs++;
	}
	if(typeflag == FTW_F){ //Check to see if the flag value is set to FTW_F
		num_files++;
	}
return 0; //If typeflag is something else we don't want it.
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
 // check arguments and set things up
 if (argc != 2) {
 printf("Usage: %s <path>\n", argv[0]);
 printf("       where <path> is the file or root of the tree you want to summarize.\n");
 return 1;
 }
 
 ftw(argv[1], callback, MAX_FTW_DEPTH);
  
 // Print out the results  
  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_files);

  return 0;
}























