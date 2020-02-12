//GUDHI

#include <gudhi/Rips_complex.h>
#include <gudhi/Simplex_tree.h>
#include <gudhi/distance_functions.h>

//MISC C++

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

//ROOT

#include "TROOT.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TFile.h"
#include <time.h>
#include <chrono>
#include <ctime>

//Pythia

#include "Pythia8/Pythia.h"

//Fastjet

#include "fastjet/ClusterSequence.hh"




using namespace fastjet;
using namespace Pythia8;
using namespace std;


const double pi = 3.14159265358979323;

int main()
{


  // initialize a new ROOT histogram to fill with the loop
  // keeping this to compare with TDA
  TH1D* pTr = new TH1D("pTr", "Transverse Momentum", 100, 0, 100);
  //  TH1D* pTj = new TH1D("pTj", "Jet Transverse Momentum", 100, 0, 100);


  // Generator. Process selection. LHC initialization.
  Pythia pythia;
  pythia.readString("Beams:eCM = 8000.");
  pythia.readString("HardQCD:all = on");
  pythia.readString("PhaseSpace:pTHatMin = 20.");
  pythia.init();

  
  //vectors for visualization
  //  std::vector<double> xList;
  //std::vector<double> yList;
  //std::vector<double> zList;

  //creation of data file
  string file_name_1;
  string file_name_2;
  string file_type;
  time_t curr_time;
  tm * curr_tm;
  char date_string_1[300];
  char date_string_2[300];
  time (&curr_time);
  curr_tm = localtime(&curr_time);
  strftime(date_string_1, 50, "./CollisionDataFiles/Collision-%F_%T", curr_tm);
  strftime(date_string_2, 50, "/.CollisionDataFiles/Persistence_max-%Y-%m-%d_%H-%M", curr_tm);
  file_type = ".txt"; 
  file_name_1 = date_string_1 + file_type;
  file_name_2 = date_string_2 + file_type;
  ofstream file_1_(file_name_1); //later we need to prepend the particle count
  ofstream file_2_(file_name_2);
  
  //creating vector for TDA
  using Point = std::vector<double>;
  std::vector<Point> pointset;


  // -------------------
  // --- Main event loop
  // -------------------
  for ( int iEvent = 0; iEvent < 2; ++iEvent )
    {

      // --- get ready for the next event
      if ( !pythia.next() ) continue;

      // --- generate the event
      Event& event = pythia.event;

      // --- make the object for FastJet
      vector<PseudoJet> particles;

      // --- loop over the particles in the event
      for (int i = 0; i < event.size(); ++i)
        {
          // Particle object contains various particle-based information
          Particle& p = event[i];

          if ( !p.isFinal() ) continue; // only want final state particles
          // --- these may be useful at a later time
          // bool charge = p.isCharged();
          // double phi = p.phi();
          // double eta = p.eta();
          double pT  = p.pT();
	  pTr->Fill( pT );
	  
          // --- double check these
          double px = p.px();
          double py = p.py();
          double pz = p.pz();
	  double E = p.e();

	  //Writes to file being used for homology
	  //file_ << px << " " << py << " " << pz << endl;

	  
          // add the particles to the FastJet PseudoJet object
          particles.push_back( PseudoJet(px, py, pz, E) );
	  
	  //add particles to TDA vector
	  pointset.push_back( {px, py, pz} );
	  
	  //add particles to visualiztion vectors
	  //xList.push_back(px);
	  //yList.push_back(py);
	  //zList.push_back(pz);
	  file_1_ << px << " " << py << " " << pz << endl; 
	} // end loop over particles
    }

  // end first half, start function for GUDHI

      
  // Type definitions
  using Simplex_tree = Gudhi::Simplex_tree<Gudhi::Simplex_tree_options_fast_persistence>;
  using Filtration_value = Simplex_tree::Filtration_value;
  using Rips_complex = Gudhi::rips_complex::Rips_complex<Filtration_value>;

  //Print a nice visualization to go with the TDA
  //
  //Fisrt convert vectors to arrays
  //double arrX[xList.size()];
  //std::copy(xList.begin(), xList.end(), arrX);
  //double arrY[yList.size()];
  //std::copy(yList.begin(), yList.end(), arrY);
  //double arrZ[zList.size()];
  //std::copy(zList.begin(), zList.end(), arrZ);
  //now draw the graph
  //TGraph* g = new TGraph(xList.size(), arrX, arrY, arrZ);
  //g->Draw("p");//   p argument makes this a point cloud


    
  // Once we have the above 'pointset' vector, we can
  // move into creating a rips complex.
  // We do this by setting a threshold for dist.,
  // then using the Rips_complex generator from
  // GUDHI.

  double threshold = 1.0; // WE NEED TO CHOOSE A
  // GOOD VALUE FOR THIS
  Rips_complex rips_complex_from_points(pointset, threshold, Gudhi::Euclidean_distance());

  Simplex_tree stree;
  rips_complex_from_points.create_complex(stree, 2);

  
  
  // Now we have a skeleton complex and
  // Can display info about the complex
  // and the data set, such as
  // number of simplices, number of
  // vertices, edges, etc.
  std::cout << "Dimension  " << stree.dimension() <<
    "  Num Simplices  " << stree.num_simplices()<< " Num Vertices  " << stree.num_vertices() << std::endl;

  //Tomorrow I will ad the info to make this a
  //Persistence or .per file. The
  //most useful example is at
  //https://gudhi.inria.fr/doc/latest/_rips_complex_2example_one_skeleton_rips_from_points_8cpp-example.html
  
  //file_.close();
      
  return 0;
      
}
