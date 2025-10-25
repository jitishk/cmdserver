


server: server.o
	g++ tmp/server.o -o bin/server

server.o: src/server.o
	g++ -c src/server.cc -o tmp/server.o

clean:
	rm tmp/*
	rm bin/*
	
