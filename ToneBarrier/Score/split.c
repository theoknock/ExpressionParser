//
//  split.c
//  ToneBarrier3D
//
//  Created by James Bush on 7/8/20.
//  Copyright © 2020 James Bush. All rights reserved.
//

#include "split.h"
#include "string.h"

// The arguments specified in the expression string correspond to a key in a dictionary of values that replace them
// when parsing the expression; this function extracts each argument (specified by the % symbol) individually as a string and
// uses it as the key to the value stored in the dictionary

//size_t getSize ( const char * s )
//{
//    size_t size = 0;
//
//    while ( *s++ ) ++size;
//
//    return size;
//}

unsigned int count_args(char * expression)
{
    char * delimiter = "%";
    unsigned int delimiters_count = 0;
    char * pch;
    pch = strpbrk(expression, delimiter);
    while (pch != NULL)
    {
//        printf ("%c ", *pch);
        pch = strpbrk (pch + 1, delimiter);
        delimiters_count++;
    }

    return delimiters_count;
}

char ** parse_args(char * expression, unsigned int argument_count)
{
    unsigned int args_count = count_args(expression);
    char * expression_vars;
    char * arguments[args_count];

    printf("\nNumber of arguments in expression: %d\n", args_count);
    
    unsigned long argument_length, ptr_array_index;
    expression_vars = strtok(expression, "%");
    
    for (ptr_array_index = 0; ptr_array_index < args_count; ptr_array_index++)
    {
        argument_length = strcspn(expression_vars, " ");
        arguments[ptr_array_index] = (char *)malloc(argument_length + 1);
        strcpy(arguments[ptr_array_index], expression_vars);
        arguments[ptr_array_index][argument_length] = '\0';
        
        printf("\t(%lu)\t%s\n", ptr_array_index + 1, arguments[ptr_array_index]);
        
        expression_vars = strtok(NULL, "%");
    }

    printf("Number of argument pointers in argument pointers array: %lu\n", sizeof(arguments) / sizeof(char *));
    for (int i = 0; i < sizeof(arguments) / sizeof(char *); i++)
    {
        printf("\t(%d) %s\n", i + 1, arguments[i]);
    }
    
    char ** ptr = (char **)malloc(sizeof(char **) * args_count);
    ptr = &arguments[0];
    
    return ptr;
}
