/*
 * String.h
 *
 *  Created on: Mar 14, 2013
 *      Author: liyajie1209
 */

#ifndef STRING_H_
#define STRING_H_

extern void * String;

void * clone (const void * self);

int compare (const void * self,const void * obj);

size_t sizeOf(const void * self);

#endif /* STRING_H_ */
