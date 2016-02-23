/*
 * Tester.cpp
 *
 *  Created on: 2016Äê2ÔÂ23ÈÕ
 *      Author: peng
 */

#include "Hooker.h"
#include <stdlib.h>
#include <unistd.h>
#include "util.h"

int (*org_access)(const char *pathname, int mode);
int my_access(const char *pathname, int mode);

int main(int argc, char **argv) {

	LOGD("Hooking ...");
	Cydia::elfHook("libc.so", "access", (void*)my_access, (void**)&org_access);

	LOGD("Test the API ...");
	access("/data/local/tmp/mshook", F_OK);

	return 0;
}

int my_access(const char *pathname, int mode){

	LOGD(">>> Success, hooking %s", pathname);
	return org_access(pathname, mode);
}
