# JetFinder
title: JetFinder Readme
date: 2020/01/13
__________
Here is the new repo Readme for fastjet and pythia, and TDA test projects. <br />
short-example: compiles and executes the fastjet test example<br />
fj_test.C: an abortive test at a Pythia event loop<br />
fj_pythia_test.C: a complete loop up to two events, using methods listed in the virtual environment file.<br />
JetHistFileOpener.C: Reads (and opens objects inside of) TFile produced by fj_pythia_test (both objects are histograms, one for the transverse momentum by particle, and the other by jet) <br /> 
makefile: automatically compiles files upon edit

For Ripser related things, we have a Python implementation of ripser for quick
visualization, and a ripser git clone which allows us to produce the actual values.
<br />

To download Ripser, go to its git page, and follow the instructions there: https://\
github.com/Ripser/ripser
<br />

For ripser, we will define an absolute filepath for each use, and keep it in a near\
by directory, for ease of maintenance.
<br />

Ripser runs roughly 40x faster than GUDHI, but specializes only in rips persistence\
.<br />
For syntax, we call the executable on a data file, and print the output to a new fi\
le of our choosing. <br />
See: runRipser.bash<br />

We will also use <br />

GUDHI:<br />

http://gudhi.gforge.inria.fr/doc/latest/index.html<br />

ROOT:<br />

https://root.cern.ch/<br />

PYTHIA(ver 8240):<br />

http://home.thep.lu.se/~torbjorn/Pythia.html<br />

FASTJET:<br />

http://fastjet.fr/<br />


Fastjet interfaces with ROOT and Pythia, which are specifically designed for High Energy Physics. The two topological packages are our main concern, as they are generalized for any type of data analysis. 