//
//  score.h
//  ToneBarrier
//
//  Created by James Bush on 7/7/20.
//

#ifndef score_h
#define score_h

#include <stdio.h>

typedef struct keyval
{
   char *key;
   void *value;
} keyval;

keyval *keyval_new(char *key, void *value);
void keyval_free(keyval *in);

double calculation(char * exp, int num_args, ...);

#endif /* score_h */
