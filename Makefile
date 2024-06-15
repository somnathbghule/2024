SOURCE=concepts.cpp s_vector.cpp
EXE=concepts
all: ${EXE}
${EXE}:${SOURCE} *.h
	g++ -g -I. ${SOURCE} -o ${EXE}

run:
	@./${EXE}
clean:
	rm -rf ${EXE}