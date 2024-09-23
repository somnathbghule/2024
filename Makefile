all: number2word
number2word:number2word.cpp
	g++ -g number2word.cpp -o number2word

run:
	./number2word
clean:
	rm -rf number2word