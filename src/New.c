/*
 * New.c
 *
 *  Created on: Mar 14, 2013
 *      Author: liyajie1209
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

#include "New.h"

struct Class {
	size_t size;
	/*constructor of the definition*/
	void* (* constructor)(void * self,va_list *parameter);
	//destructor
	void * (*destructor) (void* self);
	int (*compare)(void * self,void * obj);
};

void * new(const void * _class,...) {
//	size_t len = sizeof(type);
//	void * ptr = calloc(1,len);
//	assert(ptr);
//	return ptr;
	const struct Class * class = _class;
	void * ptr = calloc(1,class->size);//malloc the memory
	assert(ptr);
	// ptr to the class struct
	(struct Class **)ptr = &class;

	if(class->constructor) {
		va_list ap;
		va_start(ap,_class);
		ptr = class->constructor(ptr,&ap);
		va_end(ap);
	}
	return ptr;
}

void delete(void * self) {
	const struct Class ** ptr = self;
	if (self && * ptr && (*ptr)->destructor) {
		self = (*ptr)->destructor(self);
	}
	free(self);
}


