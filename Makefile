
ODIR := obj
BDIR := bin
SDIR := src
IDIR := inc
CC_VER := c++23

COPTS := -std=$(CC_VER) 
CFLAGS := -g
CC := g++

SERVER_SRCS := server.cc rx.cc
CLIENT_SRCS := client.cc tx.cc

all: jserver jclient

jserver: $(addprefix $(ODIR)/, $(SERVER_SRCS:.cc=.o))
	$(CC) $(CC_FLAGS) $(COPTS) $? -o $(BDIR)/$@

jclient: $(addprefix $(ODIR)/, $(CLIENT_SRCS:.cc=.o))
	$(CC) $(CFLAGS) $(COPTS) $? -o $(BDIR)/$@

$(ODIR)/%.o: $(SDIR)/%.cc
	$(CC) $(CFLAGS) $(COPTS) -I$(IDIR) -c $< -o $@

%.cc:
	# echo $@

.PHONY: all

obj bin:
	mkdir -p $@

clean:
	@rm -f $(ODIR)/* $(BDIR)/* # 2>/dev/null
	
