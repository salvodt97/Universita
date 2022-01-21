# MinGW Compiler paths and executables
GWDIR    = /usr/i586-mingw32msvc
LIBS     = -L"$(GWDIR)/lib"
INCS     = -I"$(GWDIR)/include" 
CC       = i586-mingw32msvc-gcc

# Options
CFLAGS = -Wall -D_WIN32_WINNT=0x0501 $(INCS)
LDFLAGS  = $(GWDIR)/lib/libws2_32.a

# Targets
all: ClientUDP_winsock.exe ServerUDP_winsock.exe

%.exe: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm *.exe



