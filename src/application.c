/*
 * application.c
 *
 *  Created on: Mar 14, 2013
 *      Author: liyajie1209
 */

#include "New.h"
#include "String.h"

int main(int argc, char **argv) {
	void * a = new (String,"a");
	void * aa  = clone(a);

	printf("size a = %u\n",sizeOf(a));

	if (compare(a,aa)) {
		puts("compare");
	}

	//delete datas
	delete(a),delete(aa);
}

