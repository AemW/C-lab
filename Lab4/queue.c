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
};                              

struct qiteratorstruct {
	struct qstruct *q;
	struct qelemstruct *curr;
};

Queue new_queue(){
	Queue queue = (Queue)malloc(sizeof(Queue));
	queue->head = (struct qelemstruct*)malloc(sizeof(struct qelemstruct));
	queue->head->prev = queue->head;
	queue->head->next = queue->head;
	queue->length = 0;
	queue->head->prio = 0;
	queue->head->data = NULL;
	return queue;
}// allokerar minnesutrymme för en ny kö

void delete_queue(Queue q){//Free q ???????????????
	clear(q);		// rensa alla element
	free(q->head);	// fria head
	free(q); 		// FFEEEL!
}// tar bort kön helt och hållet

void clear(Queue q){
	while(size(q) > 0){
		remove_first(q);
	}
}// tar bort köelementen men behåller kön

int size(Queue q){
	return q->length;
}// ger köns aktuella längd

void add(Queue q, int priority, DATA *d){
	struct qelemstruct *temp;
	struct qelemstruct *qelem = malloc(sizeof(struct qelemstruct));
	qelem->data = d;
	qelem->prio = priority;
	
	temp = q->head->next;
		

	while(temp->prio >= priority && temp != q->head){
		temp = temp->next;
	}
	
	temp->prev->next = qelem;
	qelem->next = temp;
	qelem->prev = temp->prev;
	temp->prev = qelem;
	(q->length)++;
}// lägger till nytt element i kön

DATA *get_first(Queue q){
	return q->head->next->data;
}// avläser första dataelementet 

void remove_first(Queue q){//untried
	
	if(q->length > 0){
		struct qelemstruct* tmp;	
		tmp = q->head->next;
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
		(q->length)--; 
		
	}
	
}// tar bort det första elementet

Iterator new_iterator(Queue q){
	Iterator itr = (Iterator)malloc(sizeof(Iterator));
	
	itr->q = q;
	itr->curr = q->head->next;
	
	return itr;
}      // allokerar utrymme för en ny iterator

void delete_iterator(Iterator it){
	free(it);
}    // tar bort iteratorn

void go_to_first(Iterator it){// if valid?
		it->curr = it->q->head->next;	
}        // går till köns första element

void go_to_last(Iterator it){//if valid?
	it->curr = it->q->head->prev;
}         // går till köns sista element

void go_to_next(Iterator it){
	if(is_valid(it)){
		it->curr = it->curr->next; 
	}	
}         // går till till nästa element 

void go_to_previous(Iterator it){
	if(is_valid(it)){
		it->curr = it->curr->prev;
	}
}     // går till föregående element

DATA *get_current(Iterator it){
	
	return it->curr->data;
	
}       // ger pekare till aktuellt dataelementet 

int is_valid(Iterator it){
	
	return it->curr != it->q->head;
	
}            // returnerar 0 om iteratorn inte är giltlig, 
                                       // dvs inte refererar något element, annars 1.
									   
void change_current(Iterator it, DATA *d){
	if(is_valid(it)){
		it->curr->data=d;
	}
	
} // ändrar aktuellt dataelementet

void remove_current(Iterator it){// sätta DATA i ett element till 0 eller ta bort element ur kön?
	
		struct qelemstruct* tmp;	
		tmp = it->curr;
		it->curr = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
		(it->q->length)--; 
		
}         // tar bort aktuellt dataelement

void find(Iterator it, DATA *d){
	go_to_first(it);
	while(get_current(it) != d && is_valid(it)){
		go_to_next(it);
	}
	
}         // söker d, iteratorn kommer att
                                           // referera till *d eller vara ogiltlig.
/*
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

*/