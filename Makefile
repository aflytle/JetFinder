FFLAGS = -I/opt/fastjet-3.3.3/fastjet-install/include -Wl,-rpath,/opt/fastjet-3.3.3/fastjet-install/lib -L/opt/fastjet-3.3.3/fastjet-install/lib -lfastjettools -lfastjet -lm -lfastjetplugins -lsiscone_spherical -lsiscone

PFLAGS = -I/opt/pythia8240/include -L/opt/pythia8240/lib -lpythia8 -ldl

RFLAGS = -pthread -stdlib=libc++ -std=c++11 -m64 -I/opt/root/include -L/opt/root/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTDataFrame -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lpthread -stdlib=libc++ -lm -ldl

PROGRAMS = fj_test fj_pythia_test

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS)

fj_test: fj_test.C
	g++ -o fj_test fj_test.C $(FFLAGS)

fj_pythia_test: fj_pythia_test.C
	g++ -o fj_pythia_test fj_pythia_test.C $(FFLAGS) $(PFLAGS) $(RFLAGS)

