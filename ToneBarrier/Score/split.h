//
//  split.h
//  ToneBarrier3D
//
//  Created by James Bush on 7/8/20.
//  Copyright © 2020 James Bush. All rights reserved.
//

#ifndef split_h
#define split_h

#include <stdio.h>
#include <stdlib.h>

unsigned int count_args(char * expression);
char ** parse_args(char * expression, unsigned int args_count);

#endif /* split_h */
