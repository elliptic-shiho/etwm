#include <stdio.h>
#include "twm.h"
#include "xinerama.h"

Bool is_enable_xinerama;

Monitor *xinerama_get_monitor(unsigned int x, unsigned int y) {
  Monitor *ret = NULL;

  if (is_enable_xinerama) {
    int n;
    XineramaScreenInfo *info = XineramaQueryScreens(dpy, &n);
    for (int i = 0; i < n; i++) {
      if ((x - info[i].x_org) < info[i].width && (y - info[i].y_org) < info[i].height) {
        ret = monitor_alloc();
        ret->width = info[i].width;
        ret->height = info[i].height;
        ret->x = info[i].x_org;
        ret->y = info[i].y_org;
        break;
      }
    }
    XFree(info);
  }

  return ret;
}

Bool xinerama_init(void) {
  if (XineramaIsActive(dpy)) {
    int major, minor;
    XineramaQueryVersion(dpy, &major, &minor);
    fprintf(stderr, "[+] Xinerama is enabled: version %d.%d\n", major, minor);
    is_enable_xinerama = True;
  } else {
    is_enable_xinerama = False;
  }

  return is_enable_xinerama;
}
