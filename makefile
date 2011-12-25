CXX = g++
CXXFLAGS = -L/usr/lib/ -lboost_filesystem -lboost_system -W -Wall -v

# compile !
all: main.o
	$(CXX) $< -o prg $(CXXFLAGS) 
 
#%.o: %.cpp
main.o: main_pschmitt.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)
 
# remove .o temp files
clean:
	rm -rf *.o
 
# Remove everything, except sources
mrproper: clean
	rm -rf Programme
