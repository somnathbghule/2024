all: number2word
number2word:number2word.cpp logging.h
	g++ -g -I. number2word.cpp -o number2word

run:
	./number2word
clean:
	rm -rf number2word