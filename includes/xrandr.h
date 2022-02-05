#ifndef __XRANDR_H__
#define __XRANDR_H__

#include <X11/extensions/Xrandr.h>
#include "monitor.h"

extern Bool is_enable_xrandr;

extern Monitor *xrandr_get_monitor(unsigned int x, unsigned int y);
extern Bool xrandr_init(void);

#endif /** End of __XRANDR_H__ */

