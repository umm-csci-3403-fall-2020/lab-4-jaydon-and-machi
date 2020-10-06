#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
return 0; 
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
  printf("There were %d files.\n", num_files);

  return 0;
}























