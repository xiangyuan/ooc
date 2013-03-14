/*
 * Set.h
 *
 *  Created on: Mar 14, 2013
 *      Author: liyajie1209
 */

#ifndef SET_H_
#define SET_H_

extern void* Set;

/**
 * add an element to the set
 */
void* add(void * set,const void * data);

void* find (void * set ,const void * data);

void * remove(void * set, const void * data);

int contain(void * set, const void * data);



#endif /* SET_H_ */
