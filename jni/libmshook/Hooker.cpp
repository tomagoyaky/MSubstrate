/*
 * Hooker.cpp
 *
 *  Created on: 2016Äê2ÔÂ22ÈÕ
 *      Author: peng
 */
#include <unistd.h>
#include "Hooker.h"
#include "util.h"
#include "ARM.h"
#include "Thumb.h"
#include "x86.h"

_extern void Cydia::MSHookFunction(void *symbol, void *replace, void **result) {

    SubstrateProcessRef process = NULL;
    if (MSDebug){
        MSLog(MSLogLevelNotice, "SubstrateHookFunction(process:%p, symbol:%p, replace:%p, result:%p)", process, symbol, replace, result);
    }
//    LOGD("%d", __LINE__);
#if defined(__arm__) || defined(__thumb__)
    LOGD("%d", __LINE__);
    if ((reinterpret_cast<uintptr_t>(symbol) & 0x1) == 0){
    	LOGD("%s", "-- ARM");
        return ARM::SubstrateHookFunctionARM(process, symbol, replace, result);
    }else{
    	LOGD("%s", "-- Thumb");
        return Thumb::SubstrateHookFunctionThumb(process, reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(symbol) & ~0x1), replace, result);
    }
    LOGD("%d", __LINE__);
#endif


#if defined(__i386__) || defined(__x86_64__)
    return x86::SubstrateHookFunctionx86(process, symbol, replace, result);
#endif
}

_extern void Cydia::elfHook(const char *soname, const char *symbol, void *replace_func, void **old_func) {
	void *addr = NULL;
	if (find_name(getpid(), symbol, soname, (unsigned long *)&addr) < 0) {
		LOGW("Not find: %s\n", symbol);
		return;
	}
	Cydia::MSHookFunction(addr, replace_func, old_func);
}
