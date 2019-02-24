/*--------------------------------------------------------------------\
|                                                                     |
|  Definição dum tipo abstracto de dados  STACK:                      |
|    ("pilha" com elementos do tipo int)                              |
|                                                                     |
|   A.P.Tomás, CC211 (material para prova pratica), DCC-FCUP, 2012    |
|   Last modified: 2012.12.28                                         |
\--------------------------------------------------------------------*/


/*

 Modificado e adaptado para o 1º Trabalho de Inteligencia Artifical 2019
 Yuanxiao Ye, Joao Varelas

 Stack para arrays de inteiros
 (Representacao do tabuleiro do Jogo dos 15)

*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define SIZE 16



typedef struct {
  int top, maxstack;
  Array *stack;
} STACK, *PSTACK;


// protótipos das funções para interface a uma pilha 
PSTACK st_make_empty(int nmax);
void st_destroy(PSTACK pstack);
bool st_is_empty(PSTACK pstack);
bool st_is_full(PSTACK pstack);
void st_push(PSTACK pstack, Array x);
Array st_pop(PSTACK pstack);



// ------------------- implementacao ---------------------------


static void st_exit_error(char *msg)
{ 
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}


PSTACK st_make_empty(int nmax)
{ 
  if (nmax <= 0) 
    st_exit_error("invalid stack");

  PSTACK ps = (PSTACK) malloc(sizeof(STACK));
  if (ps == NULL) 
    st_exit_error("invalid stack");

  ps -> stack = (Array *) malloc(sizeof(Array)*nmax);
  if (ps -> stack == NULL) 
    st_exit_error("invalid stack");
  
  ps -> top = 0;  
  ps -> maxstack = nmax;
  return ps;
}

bool st_is_empty(PSTACK ps) 
{
  if (ps == NULL) 
    st_exit_error("invalid stack");

  if (ps -> top == 0) 
    return true;
  return false;
}

bool st_is_full(PSTACK ps)
{ 
  if (ps == NULL) 
    st_exit_error("invalid stack");

  if (ps -> top == ps -> maxstack) 
    return true;
  return false;
}

void st_destroy(PSTACK ps)
{ 
  if (ps == NULL) 
    st_exit_error("invalid stack");

  free(ps -> stack);
  free(ps);
}


void st_push(PSTACK ps, Array x)
{ 
  if (st_is_full(ps) == true) 
    st_exit_error("stack is full");

  if (ps -> stack == NULL)     
    st_exit_error("invalid stack");

  ps -> stack[ps -> top] = x;
  ps -> top++; 
}

Array st_pop(PSTACK ps)
{ 
  if (st_is_empty(ps)== true) 
    st_exit_error("stack is empty");

  if (ps -> stack == NULL)     
    st_exit_error("invalid stack");

  ps -> top--;  
  return ps -> stack[ps ->top]; 
}
