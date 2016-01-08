CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = a4q1
OBJECTS = a4q1.o expression.o unary.o binary.o integer.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
