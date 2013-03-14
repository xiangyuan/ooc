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


#include "New.h"

void * new(const void * type,...) {
	size_t len = sizeof(type);
	void * ptr = calloc(1,len);
	assert(ptr);
	return ptr;
}

void delete(void * ptr) {
	if (ptr) {
		free(ptr);
	}
}


