#include <stdio.h>
#include "twm.h"
#include "screen.h"
#include "xrandr.h"

Bool is_enable_xrandr;

Monitor *xrandr_get_monitor(unsigned int x, unsigned int y) {
  Monitor *ret = NULL;
  if (is_enable_xrandr) {
    XRRScreenResources *res = XRRGetScreenResources(dpy, Scr->Root);
    for (int i = 0; i < res->noutput; i++) {
      XRROutputInfo *info = XRRGetOutputInfo(dpy, res, res->outputs[i]);
      if (info->crtc) {
        XRRCrtcInfo *crtc = XRRGetCrtcInfo(dpy, res, info->crtc);
        if ((x - crtc->x) < crtc->width && (y - crtc->y) < crtc->height) {
          ret = monitor_alloc();
          ret->width = crtc->width;
          ret->height = crtc->height;
          ret->x = crtc->x;
          ret->y = crtc->y;
        }
        XRRFreeCrtcInfo(crtc);
      }
      XRRFreeOutputInfo(info);
      if (ret != NULL) {
        break;
      }
    }
    XRRFreeScreenConfigInfo(res);
  }
  return ret;
}

Bool xrandr_init(void) {
    int major, minor;
    XRRScreenResources *res;
    if (XRRQueryVersion(dpy, &major, &minor)) {
      fprintf(stderr, "[+] XRandR is active: version %d.%d\n", major, minor);
      is_enable_xrandr = TRUE;
    } else {
      fprintf(stderr, "[-] XRandR is not active\n");
      is_enable_xrandr = FALSE;
    }

    return is_enable_xrandr;
}
