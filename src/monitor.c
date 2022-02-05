#include <stdlib.h>
#include <string.h>
#include "monitor.h"

Monitor *monitor_alloc(void) {
  Monitor *ret = (Monitor*) malloc(sizeof(Monitor));
  if (ret == NULL) {
    return NULL;
  }
  memset(ret, 0, sizeof(Monitor));
  return ret;
}

void monitor_free(const Monitor * const ptr) {
  free(ptr);
}
