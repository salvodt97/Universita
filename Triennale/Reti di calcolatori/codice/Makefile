# Compiler paths and executables
CC       = gcc

# Options
CFLAGS   = -Wall
LDFLAGS  = -lpthread

TARGETS = ClientUDP ServerUDP ServerTCP ClientTCP ServerTCPc ServerTCPmt ServerTCPmth
OBJECTS = server_main.o server_util.o

# Targets
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

ServerTCPmth: ServerTCPmth.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm $(TARGETS)



