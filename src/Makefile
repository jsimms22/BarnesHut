SRC= forcePairs.cpp body.cpp quadTree.cpp
CXX = g++
CXXFLAGS = -O3 -Wall
LFLAGS = 

OBJS = $(SRC:.cpp=.o)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $(<) -o $(@)

EXE = serial

all: $(EXE)

$(EXE): $(OBJS)
		$(CXX) -o $@ $^ $(LFLAGS)

%.o: %.cpp *.h
		$(CXX) -o $@ -c $< $(CXXFLAGS)

depend:
		makedepend -- $(CXXFLAGS) -- $(SRC)

strip: $(EXE)
		strip --strip-all $(EXE)

clean:
	rm -f *.o $(EXE) *.stdout *.txt
