#ifndef __MONITOR_H__
#define __MONITOR_H__

typedef struct {
  int width, height;
  int x, y;
} Monitor;

Monitor *monitor_alloc(void);
void monitor_free(const Monitor * const ptr);

#endif /* End of __MONITOR_H__ */
