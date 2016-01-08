CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = flood
OBJECTS = main.o cell.o controller.o game.o view.o graphicdisplay.o textdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
