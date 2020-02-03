FFLAGS = `fastjet-config --cxxflags --libs --plugins`

PFLAGS = `pythia8-config --cxxflags --libs`

RFLAGS = `root-config --cflags --libs`

GFLAGS = -std=c++14 -I${GUDHI}/include

PROGRAMS = fj_test fj_pythia_test persistent_homology_test ripsComplexWriter_01

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS)

fj_test: fj_test.C
	g++ -o fj_test fj_test.C -Wall $(FFLAGS)

fj_pythia_test: fj_pythia_test.C
	g++ -o fj_pythia_test fj_pythia_test.C -Wall $(FFLAGS) $(PFLAGS) $(RFLAGS)

persistent_homology_test: persistent_homology_test.C
	g++ -o persistent_homology_test persistent_homology_test.C -Wall $(GFLAGS)

ripsComplexWriter_01: ripsComplexWriter_01.C
	g++ -o ripsComplexWriter_01 ripsComplexWriter_01.C -Wall $(GFLAGS)
