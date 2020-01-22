FFLAGS = -I${FASTJET}/include -Wl,-rpath,${FASTJET}/lib -L${FASTJET}/lib -lfastjettools -lfastjet -lm -lfastjetplugins -lsiscone_spherical -lsiscone

PFLAGS = -I${PYTHIA8}/include -L${PYTHIA8}/lib -lpythia8 -ldl

RFLAGS = -pthread -stdlib=libc++ -std=c++11 -m64 -I${ROOTSYS}/include -L${ROOTSYS}/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTDataFrame -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lpthread -stdlib=libc++ -lm -ldl

PROGRAMS = fj_test fj_pythia_test

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS)

fj_test: fj_test.C
	g++ -o fj_test fj_test.C -Wall $(FFLAGS)

fj_pythia_test: fj_pythia_test.C
	g++ -o fj_pythia_test fj_pythia_test.C -Wall $(FFLAGS) $(PFLAGS) $(RFLAGS)

