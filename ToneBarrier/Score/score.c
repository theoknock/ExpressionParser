//
//  score.c
//  ToneBarrier
//
//  Created by James Bush on 7/7/20.
//

#include <stdlib.h>
#include <stdarg.h>
#include "score.h"

keyval *keyval_new(char *key, void *value){
    keyval *out = malloc(sizeof(keyval));
    *out = (keyval){.key = key, .value=value};
    return out;
}

void keyval_free(keyval *in){ free(in); }

double calculation(char * exp, int num_args, ...) {
    double val = 0.0;
    va_list ap;
    int i;
    
    va_start(ap, num_args);
    for(i = 0; i < num_args; i++) {
        val += va_arg(ap, double);
    }
    va_end(ap);
    
    return val;
}

