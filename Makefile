CC        := gcc
LD        := gcc
YACC      := bison -y
LEX       := flex -l
DFLAGS    := -g -O2 -fno-strict-aliasing 
YFLAGS    := -d
LDFLAGS   := -lXmu -lXt -lSM -lICE -lXext -lX11 -lXt -lSM -lICE -lXext -lX11 -lXinerama
CFLAGS    := -Dlinux -D__amd64__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -DFUNCPROTO=15 -DNARROWPROTO -std=c11 -Iincludes/
TARGET    := twm
OBJS      := gram.o lex.o deftwmrc.o add_window.o gc.o list.o twm.o parse.o menus.o events.o resize.o util.o version.o iconmgr.o cursor.o icons.o session.o accessible_addr.o xinerama.o
MV				:= mv
RM				:= rm
ASTYLE    := astyle

vpath %.c src/
vpath %.y src/
vpath %.l src/
vpath %.o bin/
vpath %.h includes/

all: bin/$(TARGET)


bin/$(TARGET): $(OBJS)
	$(LD) $(DFLAGS) -o $@ $(addprefix bin/,$(OBJS)) $(LDFLAGS) 

%.o: %.c includes/*.h
	$(CC) $(DFLAGS) $(CFLAGS) -c -o bin/$@ $<

src/gram.c: gram.y
	$(YACC) $(YFLAGS) $<
	$(MV) y.tab.c $@
	@if [ -f y.tab.h ]; then set -x; $(MV) y.tab.h includes/gram.h; \
	else exit 0; fi

src/lex.c: lex.l
	$(LEX) $<
	$(MV) lex.yy.c $@

src/deftwmrc.c:  system.twmrc
	$(RM) -f $@
	echo '/* ' >>$@
	echo ' * This file is generated automatically from the default' >>$@
	echo ' * twm bindings file system.twmrc by the twm Imakefile.' >>$@
	echo ' */' >>$@
	echo '' >>$@
	echo 'char *defTwmrc[] = {' >>$@
	sed -e '/^#/d' -e 's/"/\\"/g' -e 's/^/    "/' -e 's/$$/",/' \
		system.twmrc >>$@
	echo '    (char *) 0 };' >>$@

.PHONY: clean
clean:
	$(RM) -f bin/*
	$(RM) -f includes/gram.h
	$(RM) -f src/gram.c
	$(RM) -f src/lex.c
	$(RM) -f src/deftwmrc.c

.PHONY: format
format:
	$(ASTYLE) --mode=c -s2 -n -j -W3 -k3 -A2 src/*.c includes/*.h
