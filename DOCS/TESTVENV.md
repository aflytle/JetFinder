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
Both Pythia and Fastjet have methods for transverse momentum and momentum, and this 
