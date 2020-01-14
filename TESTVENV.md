title: Necessary Packages
date: 2020/01/14
----------

From Pythia: #include "Pythia8/Pythia.h"
From Fastjet: #include "fastjet/ClusterSequence.hh"
From Root: TROOT.h, TH1D.h, TProfile.h, TFile.h

namespaces: fastjet, pythia

pythia methods used: .readstring(), .init(), .next(), .isFinal(), .push_back(), .stat()   
fastjet methods used: (function)JetDefinition, (function)ClusterSequence, PsuedoJet