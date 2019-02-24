/*--------------------------------------------------------------------\
| Definição de um tipo abstracto de dados QUEUE:                      |
|   filas  (FIFO) com valores do tipo int                             |
|                                                                     |
|   A.P.Tomás, CC211 (material para prova pratica), DCC-FCUP, 2012    |
|   Last modified: 2012.12.28                                         |
\--------------------------------------------------------------------*/

/*

 Modificado e adaptado para o 1º Trabalho de Inteligencia Artifical 2019
 Yuanxiao Ye, Joao Varelas

 Queue para arrays de inteiros
 (Representacao do tabuleiro do Jogo dos 15)

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 16



typedef struct {
  int inicio, fim, nmax;
  Array *queue;
} QUEUE;



QUEUE *mk_empty_queue(int n);
void enqueue(Array v, QUEUE *f);
Array dequeue(QUEUE *f);
bool queue_is_empty(QUEUE *f);
bool queue_is_full(QUEUE *f);
void free_queue(QUEUE *f);




/* ---------- Implementaçao ---------- */

static void queue_exit_error(char *msg)
{ 
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}



QUEUE *mk_empty_queue(int n)
{
  QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
  if (q == NULL) 
    queue_exit_error("sem memoria");

  q -> queue =  (Array *) malloc(n*sizeof(Array));
  
  if (q -> queue == NULL) 
    queue_exit_error("sem memoria");

  q -> nmax = n;
  q -> inicio = -1;
  q -> fim = 0;
  return q;
}


void free_queue(QUEUE *q)
{
  if (q != NULL) {
    free(q -> queue);
    free(q);
  } else 
    queue_exit_error("fila mal construida");
}



void enqueue(Array v,QUEUE *q)
{  
  if (queue_is_full(q) == true) 
    queue_exit_error("fila sem lugar");

  if (q -> queue == NULL) 
    queue_exit_error("fila mal construida");

  if (queue_is_empty(q)==true) 
    q -> inicio = q -> fim; // fila fica com um elemento


  q -> queue[q->fim] = v;
  //memcpy(q->queue[q->fim], v, sizeof(Array));
  
  q -> fim = (q -> fim+1)%(q->nmax);
}


Array dequeue(QUEUE *q)
{  
  Array aux;
  if (queue_is_empty(q)) 
    queue_exit_error("fila sem valores");

  if (q -> queue == NULL) 
    queue_exit_error("fila mal construida");

  aux = q ->queue[q ->inicio];
  //memcpy(aux, q->queue[q->inicio]);
  
  q -> inicio = (q -> inicio+1)%(q -> nmax);
  if (q -> inicio ==  q -> fim) {  // se só tinha um elemento
    q -> inicio = -1; q -> fim = 0;  
  }
  return aux;
}


bool queue_is_empty(QUEUE *q)
{ 
  if (q == NULL) 
    queue_exit_error("fila mal construida");

  if (q -> inicio == -1) return true;
  return false;
}


bool queue_is_full(QUEUE *q)
{ 
  if (q == NULL) 
    queue_exit_error("fila mal construida");

  if (q -> fim == q -> inicio) return true;
  return false;
}

