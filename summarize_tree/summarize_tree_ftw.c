#include <stdio.h>
#include <sys/stath>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
 
}

#define MAX_FTW_DEPTH 16
int main(int argc, char** argv) {
 // check arguments and set things up

 ftw(argv[1], callback, MAX_FTW_DEPTH);
 
 // Print out the results  
}























