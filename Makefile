output: fj_test.o fj_pythia_test.o
	g++ fj_test.o fj_pythia_test.o -o output

fj_test.o: fj_test.C
	g++ -c fj_test.C 'fastjet-config -cxxflags --libs --plugin' 

fj_pythia_test.o: fj_pythia_test.C
	g++ -c fj_pythia_test.C -std=c++11 -Wall -Wshadow 'fastjet-config --cxxflags --libs --plugins' 'root-config --libs' -I$Rootsys/include -I$Pythia8/include -l Pythia8 -L $PYTHIA8/lib

clean:
	rm *.o output
