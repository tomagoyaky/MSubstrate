/*
 * Hooker.cpp
 *
 *  Created on: 2016Äê2ÔÂ22ÈÕ
 *      Author: peng
 */
#include "Hooker.h"

#include "ARM.h"
#include "Thumb.h"
#include "x86.h"

_extern void Cydia::MSHookFunction(void *symbol, void *replace, void **result) {
    SubstrateProcessRef process = NULL;
    if (MSDebug)
        MSLog(MSLogLevelNotice, "SubstrateHookFunction(%p, %p, %p, %p)", process, symbol, replace, result);

#if defined(__arm__) && defined(__thumb__)
    if ((reinterpret_cast<uintptr_t>(symbol) & 0x1) == 0)
        return ARM::SubstrateHookFunctionARM(process, symbol, replace, result);
    else
        return Thumb::SubstrateHookFunctionThumb(process, reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(symbol) & ~0x1), replace, result);
#endif


#if defined(__i386__) || defined(__x86_64__)
    return x86::SubstrateHookFunctionx86(process, symbol, replace, result);
#endif
}
