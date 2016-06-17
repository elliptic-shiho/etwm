#ifndef __XINERAMA_H__
#define __XINERAMA_H__

#include <X11/extensions/Xinerama.h>

extern Bool is_enable_xinerama;

extern int get_display_number_from_coordinate(unsigned int x, unsigned int y);
extern void init_xinerama(void);
extern int get_screen_width(int screen_id);
extern int get_screen_height(int screen_id);
extern int get_screen_org_x(int screen_id);
extern int get_screen_org_y(int screen_id);
extern int get_screen_count(void);
extern XineramaScreenInfo *get_screen_info(void);

#endif /** End of __XINERAMA_H__ */
