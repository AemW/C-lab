#define DATA int
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


struct qelemstruct {
	struct qelemstruct *next, *prev;
	int prio;
	DATA *data;
};

struct qstruct {
	struct qelemstruct *head;
	int length;
};                              // anger att qstruct och qiteratorstruct

struct qiteratorstruct {
	struct qstruct *q;
	struct qelemstruct *curr;
};                      // definieras på annat ställe

typedef struct qstruct *Queue;               // typerna Queue och Iterator
typedef struct qiteratorstruct *Iterator;    // skall utnyttjas av användaren

Queue new_queue(){
	Queue queue = (Queue)malloc(sizeof(struct qstruct));
	queue->head = (struct qelemstruct*)malloc(sizeof(struct qelemstruct));
	queue->head->prev = queue->head;
	queue->head->next = queue->head;
	queue->length = 0;
	queue->head->prio = 0;
	queue->head->data = 0;
	return queue;
}                   // allokerar minnesutrymme för en ny kö

void delete_queue(Queue q){
	free(q);
}          // tar bort kön helt och hållet

void clear(Queue q);                 // tar bort köelementen men behåller kön

int  size(Queue q){
	return q->length;
}
                        // ger köns aktuella längd
void add(Queue q, int priority, DATA *d){
	struct qelemstruct *temp;
	struct qelemstruct *qelem = malloc(sizeof(struct qelemstruct));
	qelem->data = d;
	(q->length)++;
	temp = q->head->next;
		
	
	while(temp->prio >= priority ){
		temp = temp->next;
	}
	
	temp->prev->next = qelem;
	qelem->next = temp;
	qelem->prio = priority;
	qelem->prev = temp->prev;
	temp->prev = qelem;
}    

DATA *get_first(Queue q){
	return q->head->next->data;
}                    // avläser första dataelementet 

void remove_first(Queue q);                   // tar bort det första elementet

Iterator new_iterator(Queue q);       // allokerar utrymme för en ny iterator
void delete_iterator(Iterator it);    // tar bort iteratorn
void go_to_first(Iterator it);        // går till köns första element
void go_to_last(Iterator it);         // går till köns sista element
void go_to_next(Iterator it);         // går till till nästa element
void go_to_previous(Iterator it);     // går till föregående element
DATA *get_current(Iterator it);       // ger pekare till aktuellt dataelementet 
int is_valid(Iterator it);            // returnerar 0 om iteratorn inte är giltlig, 
                                       // dvs inte refererar något element, annars 1.
void change_current(Iterator it, DATA *d); // ändrar aktuellt dataelementet
void remove_current(Iterator it);         // tar bort aktuellt dataelement
void find(Iterator it, DATA *d);          // söker d, iteratorn kommer att
                                           // referera till *d eller vara ogiltlig.

int main(){
	int nyttNummer = 2;
	int nyttNummer1 = 3;
	int nyttNummer2 = 4;
	Queue queue = new_queue();
	add(queue,6,&nyttNummer);
	add(queue,8,&nyttNummer1);
	add(queue,9,&nyttNummer2);
	printf("1   prio: %i, data: %i\n",queue->head->next->prio,*(queue->head->next->data));
	printf("2   prio: %i, data: %i\n",queue->head->next->next->prio,*(queue->head->next->next->data));
	printf("3   prio: %i, data: %i\n",(queue->head->next->next->next->prio),*(queue->head->next->next->next->data));
	printf("4   prio: %i, data: %i\n",(queue->head->next->next->next->next->prio),*(queue->head->next->next->next->next->data));
	
	
	return 0;
}
void delete_queue(Queue q);          // tar bort kön helt och hållet
void clear(Queue q);                 // tar bort köelementen men behåller kön
int  size(Queue q);                          // ger köns aktuella längd
void add(Queue q, int priority, DATA *d);    // lägger in d på rätt plats 
DATA *get_first(Queue q);                    // avläser första dataelementet 
void remove_first(Queue q);                   // tar bort det första elementet

Iterator new_iterator(Queue q);       // allokerar utrymme för en ny iterator
void delete_iterator(Iterator it);    // tar bort iteratorn
void go_to_first(Iterator it);        // går till köns första element
void go_to_last(Iterator it);         // går till köns sista element
void go_to_next(Iterator it);         // går till till nästa element
void go_to_previous(Iterator it);     // går till föregående element
DATA *get_current(Iterator it);       // ger pekare till aktuellt dataelementet 
int is_valid(Iterator it);            // returnerar 0 om iteratorn inte är giltlig, 
                                       // dvs inte refererar något element, annars 1.
void change_current(Iterator it, DATA *d); // ändrar aktuellt dataelementet
void remove_current(Iterator it);         // tar bort aktuellt dataelement
void find(Iterator it, DATA *d);          // söker d, iteratorn kommer att
                                           // referera till *d eller vara ogiltlig.

