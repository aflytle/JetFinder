//script to plot histograms of mean lifetimes

#include <iostream>
#include <fstream>

using namespace std;

void MeanHists()
{
  //8192 GeV lifetime histogram
  TH1D* mean_one8192 = new TH1D("mean_one8192", "Lifetime 1 (8192)", 100, 0, 1400);
  TH1D* mean_two8192 = new TH1D("mean_two8192", "Lifetime 2 (8192)", 100, 0, 900);
  TH1D* mean_three8192 = new TH1D("mean_three8192", "Lifetime 3 (8192)", 100, 0, 600);
  TH1D* mean_four8192 = new TH1D("mean_four8192", "Lifetime 4 (8192)", 100, 0, 500);
  TH1D* mean_five8192 = new TH1D("mean_five8192", "Lifetime 5 (8192)", 100, 0, 300);

  //2048 GeV lifetime histograms
  //TH1D* mean_one2048 = new TH1D("mean_one2048", "Lifetime 1 (2048)", 100, 0, 900);
  //TH1D* mean_two2048 = new TH1D("mean_two2048", "Lifetime 2 (2048)", 100, 0, 400);
  //TH1D* mean_three2048 = new TH1D("mean_three2048", "Lifetime 3 (2048)", 100, 0, 300);
  //TH1D* mean_four2048 = new TH1D("mean_four2048", "Lifetime 4 (2048)", 100, 0, 200);
  //TH1D* mean_five2048 = new TH1D("mean_five2048", "Lifetime 5 (2048)", 100, 0, 100);

  //512 GeV lifetime histograms
  //TH1D* mean_one512 = new TH1D("mean_one512", "Lifetime 1 (512)", 100, 0, 900);
  //TH1D* mean_two512 = new TH1D("mean_two512", "Lifetime 2 (512)", 100, 0, 400);
  //TH1D* mean_three512 = new TH1D("mean_three512", "Lifetime 3 (512)", 100, 0, 300);
  //TH1D* mean_four512 = new TH1D("mean_four512", "Lifetime 4 (512)", 100, 0, 200);
  //TH1D* mean_five512 = new TH1D("mean_five512", "Lifetime 5 (512)", 100, 0, 100);

  //128 GeV lifetime histograms
  //TH1D* mean_one128 = new TH1D("mean_one128", "Lifetime 1 (128)", 100, 0, 900);
  //TH1D* mean_two128 = new TH1D("mean_two128", "Lifetime 2 (128)", 100, 0, 400);
  //TH1D* mean_three128 = new TH1D("mean_three128", "Lifetime 3 (128)", 100, 0, 300);
  //TH1D* mean_four128 = new TH1D("mean_four128", "Lifetime 4 (128)", 100, 0, 200);
  //TH1D* mean_five128 = new TH1D("mean_five128", "Lifetime 5 (128)", 100, 0, 100);

  ifstream f8192;
  //ifstream f2048;
  //ifstream f512;
  //ifstream f128;

  f8192.open("MeanVals/8192mean_points.txt", ios::in);
  //f2048.open("MeanVals/2048mean_points.txt", ios::in);
  //f512.open("MeanVals/512mean_points.txt", ios::in);
  //f128.open("MeanVals/128mean_points.txt", ios::in);

  //std::set<std::ifstream> setOfFiles = {f8192, f2048, f512, f128};
  //std::set<std::ifstream>::iterator it = setOfFiles.begin();
  
  vector<double> row;
  string line, temp, val;
  //while (it != setOfFile.end())
  //{
  while (getline(f8192, line, '\n'))
  //{
    {
      row.clear();
      
      stringstream s(line);

      while (getline(s, val, ','))
	{
	  row.push_back(stoi(val));
	}

      mean_one8192->Fill(row[1]);
      mean_two8192->Fill(row[2]);
      mean_three8192->Fill(row[3]);
      mean_four8192->Fill(row[4]);
      mean_five8192->Fill(row[5]);
    }
  TFile* HistFile = new TFile("MeanHists.root", "recreate");
  HistFile->cd();
  mean_one8192->Write();
  mean_two8192->Write();
  mean_three8192->Write();
  mean_four8192->Write();
  mean_five8192->Write();

  mean_one8192->Draw();
  mean_two8192->Draw();
  mean_three8192->Draw();
  mean_four8192->Draw();
  mean_five8192->Draw();
  
  double a = mean_one8192->GetStdDev();
  double b = mean_two8192->GetStdDev();
  double c = mean_three8192->GetStdDev();
  double d = mean_four8192->GetStdDev();
  double e = mean_five8192->GetStdDev();

  gStyle->SetOptStat("nemsk");
  
  
}
