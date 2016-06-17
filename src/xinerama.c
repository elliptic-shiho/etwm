#include <stdio.h>
#include "twm.h"
#include "xinerama.h"

Bool is_enable_xinerama;

int get_display_number_from_coordinate(unsigned int x, unsigned int y) {
  int i, ret = -1;
  if (is_enable_xinerama) {
    XineramaScreenInfo *info = get_screen_info();
    int n = get_screen_count();
    for (i = 0; i < n; i++) {
      XineramaScreenInfo *inf = &info[i];
      if ((x - inf->x_org) < inf->width && (y - inf->y_org) < inf->height) {
        ret = i;
        break;
      }
    }
    XFree(info);
  }
  return ret;
}

int get_screen_width(int screen_id) {
  int n, i, ret = -1;
  if (is_enable_xinerama) {
    XineramaScreenInfo *info = get_screen_info();
    ret = info[screen_id].width;
    XFree(info);
  }
  return ret;
}

int get_screen_height(int screen_id) {
  int n, i, ret = -1;
  if (is_enable_xinerama) {
    XineramaScreenInfo *info = get_screen_info();
    ret = info[screen_id].height;
    XFree(info);
  }
  return ret;
}

int get_screen_org_x(int screen_id) {
  int n, i, ret = -1;
  if (is_enable_xinerama) {
    XineramaScreenInfo *info = get_screen_info();
    ret = info[screen_id].x_org;
    XFree(info);
  }
  return ret;
}

int get_screen_org_y(int screen_id) {
  int n, i, ret = -1;
  if (is_enable_xinerama) {
    XineramaScreenInfo *info = get_screen_info();
    ret = info[screen_id].y_org;
    XFree(info);
  }
  return ret;
}

int get_screen_count(void) {
  int n;
  if (is_enable_xinerama) {
    XineramaScreenInfo *info;
    XineramaQueryScreens(dpy, &n);
    return n;
  }
  return -1;
}

XineramaScreenInfo *get_screen_info(void) {
  int n;
  if (is_enable_xinerama) {
    XineramaScreenInfo *info;
    return XineramaQueryScreens(dpy, &n);
  }
  return NULL;
}

void init_xinerama(void) {
  if (XineramaIsActive(dpy)) {
    int major, minor;
    XineramaQueryVersion(dpy, &major, &minor);
    fprintf(stderr, "[+] Xinerama is active: version %d.%d\n", major, minor);
    is_enable_xinerama = True;
  } else {
    fprintf(stderr, "[-] Xinerama is not active\n");
    is_enable_xinerama = False;
  }
}
