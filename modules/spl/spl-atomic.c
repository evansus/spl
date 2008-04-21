#include <sys/atomic.h>

#ifdef DEBUG_SUBSYSTEM
#undef DEBUG_SUBSYSTEM
#endif

#define DEBUG_SUBSYSTEM S_ATOMIC

/* Global atomic lock declarations */
spinlock_t atomic64_lock = SPIN_LOCK_UNLOCKED;
spinlock_t atomic32_lock = SPIN_LOCK_UNLOCKED;

EXPORT_SYMBOL(atomic64_lock);
EXPORT_SYMBOL(atomic32_lock);