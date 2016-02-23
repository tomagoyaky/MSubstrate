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
#include <sys/ioctl.h>

int (*org_access)(const char *pathname, int mode);
int my_access(const char *pathname, int mode);
int (*org_ioctl)(int a1, int a2);
int my_ioctl(int a1, int a2);
int main(int argc, char **argv) {

	LOGD("Hooking ...");
	Cydia::elfHook("libc.so", "access", (void*)my_access, (void**)&org_access);
	Cydia::elfHook("libc.so", "ioctl", (void*)my_ioctl, (void**)&org_ioctl);

	LOGD("Test the API ...");
	access("/data/local/tmp/mshook", F_OK);
//	ioctl();

	return 0;
}

int my_access(const char *pathname, int mode){

	LOGD(">>> Success, hooking %s", pathname);
	return org_access(pathname, mode);
}

int my_ioctl(int a1, int a2){
	LOGD(">>> Success, hooking:a1=%d, a2=%d", a1, a2);
	return org_ioctl(a1, a2);
}
