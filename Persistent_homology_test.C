//This upper script is pulled from the script
//Rips_complex/example_one_skeleton_rips
//from Gudhi's sample library
//
//Pulled into project Jet_Finder
//Aidan Lytle, 02/03/2020

#include <gudhi/Simplex_tree.h>
#include <gudhi/Rips_complex.h>
#include <gudhi/distance_functions.h>

#include <iostream>
#include <string>
#include <vector>
#include <limits> // for std::numeric_limits

int main(){
  // Type definitions
  using Simplex_tree = Gudhi::Simplex_tree<>;
  using Filtration_value = Simplex_tree::Filtration_value;
  using Rips_complex = Gudhi::rips_complex::Rips_complex<Filtration_value>;
  using Distance_matrix = std::vector<std::vector<Filtration_value>>;

  Distance_matrix distances;
  distances.push_back({});
  distances.push_back({0.94});
  distances.push_back({0.77,0.26});
  distances.push_back({0.99,0.99,0.28});
  distances.push_back({0.11, 0.39, 0.97, 0.30});

  //Init of a rips complex from points
  double threshold = 1.0;
  Rips_complex
    rips_complex_from_points(distances,threshold);

  Simplex_tree stree;

  rips_complex_from_points.create_complex(stree,1);

  //Display info about rips complex (one skeleton)
  cout<<"dimension"<<stree.dimension<<
    " - " << stree.num_simplices() << "simplices" <<
    stree.num_vertices() << "vertices." << std::endl;

  return 0
    }
