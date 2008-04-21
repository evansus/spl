#include <sys/sysmacros.h>
#include <sys/cmn_err.h>
#include "config.h"

#ifdef DEBUG_SUBSYSTEM
#undef DEBUG_SUBSYSTEM
#endif

#define DEBUG_SUBSYSTEM S_GENERIC

static char ce_prefix[CE_IGNORE][10] = { "", "NOTICE: ", "WARNING: ", "" };
static char ce_suffix[CE_IGNORE][2] = { "", "\n", "\n", "" };

void
vpanic(const char *fmt, va_list ap)
{
	char msg[MAXMSGLEN];

	vsnprintf(msg, MAXMSGLEN - 1, fmt, ap);
	panic(msg);
} /* vpanic() */
EXPORT_SYMBOL(vpanic);

void
cmn_err(int ce, const char *fmt, ...)
{
	char msg[MAXMSGLEN];
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(msg, MAXMSGLEN - 1, fmt, ap);
	va_end(ap);

	CERROR("%s", msg);
} /* cmn_err() */
EXPORT_SYMBOL(cmn_err);

void
vcmn_err(int ce, const char *fmt, va_list ap)
{
	char msg[MAXMSGLEN];

        if (ce == CE_PANIC)
                vpanic(fmt, ap);

        if (ce != CE_NOTE) { /* suppress noise in stress testing */
		vsnprintf(msg, MAXMSGLEN - 1, fmt, ap);
		CERROR("%s%s%s", ce_prefix[ce], msg, ce_suffix[ce]);
        }
} /* vcmn_err() */
EXPORT_SYMBOL(vcmn_err);