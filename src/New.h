/*
 * New.h
 *
 *  Created on: Mar 14, 2013
 *      Author: liyajie1209
 */

#ifndef NEW_H_
#define NEW_H_

//memory management
void * new(const void * type,...);

/*
 * release the memory
 * @param item
 */
void delete(void * ptr);

#endif /* NEW_H_ */
