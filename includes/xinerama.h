#ifndef __XINERAMA_H__
#define __XINERAMA_H__

#include <X11/extensions/Xinerama.h>
#include "monitor.h"

extern Bool is_enable_xinerama;

extern Bool xinerama_init(void);
extern Monitor *xinerama_get_monitor(unsigned int x, unsigned int y);

#endif /** End of __XINERAMA_H__ */
