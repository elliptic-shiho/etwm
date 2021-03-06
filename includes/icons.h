/*
 *
Copyright (c) 1989  X Consortium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from the X Consortium.
 * */

/**********************************************************************
 *
 * $XConsortium: icons.h,v 1.5 94/04/17 20:38:14 jim Exp $
 *
 * Icon releated definitions
 *
 * 10-Apr-89 Tom LaStrange        Initial Version.
 *
 **********************************************************************/

#ifndef ICONS_H
#define ICONS_H
#include "twm.h"

typedef struct IconRegion {
  struct IconRegion	*next;
  int			x, y, w, h;
  int			grav1, grav2;
  int			stepx, stepy;	/* allocation granularity */
  struct IconEntry	*entries;
} IconRegion;

typedef struct IconEntry {
  struct IconEntry	*next;
  int			x, y, w, h;
  TwmWindow		*twm_win;
  short 		used;
} IconEntry;

extern void IconDown(TwmWindow *);
extern void IconUp (TwmWindow *);
extern void CreateIconWindow(TwmWindow *, int, int);
extern void AddIconRegion(char *, int, int, int, int);

#endif /* ICONS_H */
