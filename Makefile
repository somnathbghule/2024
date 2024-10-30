all: ls
ls:ls.c logging.h
	g++ -g -I. ls.c -o ls

run:
	./ls
clean:
	rm -rf ls