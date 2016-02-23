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
#include <pthread.h>

int (*org_access)(const char *pathname, int mode);
int my_access(const char *pathname, int mode);
int (*org_ioctl)(int a1, int a2);
int my_ioctl(int a1, int a2);
static void *func_hook(void* params){

	printf("Hooking ...\n");
	Cydia::elfHookFunction("libc.so", "access", (void*)my_access, (void**)&org_access);
	Cydia::elfHookFunction("libc.so", "ioctl", (void*)my_ioctl, (void**)&org_ioctl);

	printf("Test the API ...\n");
	access("/data/local/tmp/mshook", F_OK);
}

int main(int argc, char **argv) {

	func_hook(NULL);
	return 0;
}

int my_access(const char *pathname, int mode){

	printf(">>> Success, hooking %s\n", pathname);
	return org_access(pathname, mode);
}

int my_ioctl(int a1, int a2){
	printf(">>> Success, hooking:a1=%d, a2=%d\n", a1, a2);
	return org_ioctl(a1, a2);
}
