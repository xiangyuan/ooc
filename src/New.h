/*
 * New.h
 *
 *  Created on: Mar 14, 2013
 *      Author: liyajie1209
 */

#ifndef NEW_H_
#define NEW_H_

extern struct Class;

//memory management
void * new(const void * _class,...);

/*
 * release the memory
 * @param item
 */
void delete(void * _class);

#endif /* NEW_H_ */
