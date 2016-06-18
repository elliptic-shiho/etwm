#include "accessible_addr.h"

int is_accessible_address(void *p) {
  jmp_buf jbuf;
  int flag = 0;
  int a;
  void handler(int x) {
    longjmp(jbuf, 1);
    return;
  }

  if (setjmp(jbuf) == 0) {
    signal(SIGSEGV, handler);

    a = *((int *)p);

  } else {
    flag = 1;
  }
  signal(SIGSEGV, SIG_DFL);
  return !flag;
}
