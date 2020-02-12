title: Necessary Packages <br />
date: 2020/01/24 <br />

----------

From Pythia: #include "Pythia8/Pythia.h" <br />
From Fastjet: #include "fastjet/ClusterSequence.hh" <br />
From Root: TROOT.h, TH1D.h, TProfile.h, TFile.h <br />

necessary environment variables in bashrc <br />
(they are currently all in filepath /opt/<package_name>

$PYTHIA8
$ROOT
$FASTJET

namespaces: fastjet, pythia

fastjet methods used: (function)JetDefinition, (function)ClusterSequence, PsuedoJet, .pT() (for jet objects)<br />
Pythia methods used: event, readString, init, event.size <br />
<br />
Both Pythia and Fastjet have methods for transverse momentum and momentum, and this will be useful for later comparison.

----------

For Ripser related things, we have a Python implementation of ripser for quick
visualization, and a ripser git clone which allows us to produce the actual values.
<br />

To download Ripser, go to its git page, and follow the instructions there: https://github.com/Ripser/ripser
<br />

For ripser, we will define an absolute filepath for each use, and keep it in a nearby directory, for ease of maintenance.
<br />

Ripser runs roughly 40x faster than GUDHI, but specializes only in rips persistence.<br />
For syntax, we call the executable on a data file, and print the output to a new file of our choosing. <br />
See: runRipser.bash<br />

