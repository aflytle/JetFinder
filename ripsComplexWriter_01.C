#include <gudhi/Rips_complex.h>
#include <gudhi/Simplex_tree.h>
#include <gudhi/distance_functions.h>

#include <iostream>
#include <ifstream>
#include <string>
#include <vector>
#include <limits>


int main() {
  // --- First thing: open file for read/write
  ifstream file_;
  file_.open("particle_data_03_02_2020.off");
  
  
  // Type definitions
  using Point = std::vector<double>;
  using Simplex_tree = Gudhi::Simplex_tree<Gudhi::Simplex_tree_options_fast_persistence>;
  using Filtration_value = Simplex_tree::Filtration_value;
  using Rips_complex = Gudhi::rips_complex::Rips_complex<Filtration_value>;

  // --- create vector from lines of .off
  std::vector<Point> points;

  // specify type we are looking for
  float a, b, c;

  //read line by line
  while (infile >> a >> b >> c)
  {
    points.push_back({a,b,c});
  }

  // Once we have the above vector, we can
  // move into creating a rips complex.
  // We do this by setting a threshold for dist.,
  // then using the Rips_complex generator from
  // GUDHI.

  double threshold = 12.0; // WE NEED TO CHOOSE A
  // GOOD VALUE FOR THIS
  Rips_complex rips_complex_from_points(points, threshold, Gudhi::Euclidean_distance());

  Simplex_tree stree;
  rips_complex_from_points.create_complex(stree, 1);

  // Now we have a skeleton complex and
  // Can display info about the complex
  // and the data set, such as
  // number of simplices, number of
  // vertices, edges, etc.
  cout << "Dimension  " << stree.dimension() <<
    "  Num Simplices  " << stree.num_simplices()<< " Num Vertices  " << stree.num_vertices() << endl;

  //Tomorrow I will ad the info to make this a
  //Persistence or .per file. The
  //most useful example is at
  //https://gudhi.inria.fr/doc/latest/_rips_complex_2example_one_skeleton_rips_from_points_8cpp-example.html
  
  file_.close();
  return 0
}
