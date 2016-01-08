CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = a4q3
OBJECTS = main.o textprocess.o echo.o decorator.o count.o allcaps.o dropfirst.o doublewords.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
