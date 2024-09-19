all: number2word
number2word:
	g++ number2word.cpp -o number2word && ./number2word && make clean

clean:
	rm -rf number2word