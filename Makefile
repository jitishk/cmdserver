
ODIR := obj
BDIR := bin
SDIR := src
IDIR := inc
CC_VER := c++23

COPTS := -std=$(CC_VER) 
CFLAGS := -g
CC := g++

SERVER_SRCS := server.cc message.cc
CLIENT_SRCS := client.cc
LIBCHANNEL_SRCS := channel.cc rx.cc tx.cc

all: jserver jclient

jserver: $(addprefix $(ODIR)/, $(SERVER_SRCS:.cc=.o))
	$(CC) $(CC_FLAGS) $(COPTS) $? -o $(BDIR)/$@

jclient: $(addprefix $(ODIR)/, $(CLIENT_SRCS:.cc=.o))
	$(CC) $(CFLAGS) $(COPTS) $? -o $(BDIR)/$@


$(ODIR)/libchannel.so: $(addprefix $(ODIR)/, $(LIBCHANNEL_SRCS:.cc=.o))
	gcc -shared $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.cc
	$(CC) $(CFLAGS) $(COPTS) -I$(IDIR) -fPIC -c $< -o $@

%.cc:
	# echo $@

channel.so: $(SDIR)/

.PHONY: all

obj bin:
	mkdir -p $@

clean:
	@rm -f $(ODIR)/* $(BDIR)/* # 2>/dev/null
	
