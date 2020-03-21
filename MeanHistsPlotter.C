// FileOne.root opener

void MeanHistsPlotter()
{

  TFile* file = TFile::Open("MeanHists.root");

  TH1D* hm_0 = (TH1D*)file->Get("mean_one8192");
  cout << hm_0 << endl;
  hm_0->Draw();

  TH1D* hm_1 = (TH1D*)file->Get("mean_two8192");
  cout << hm_1 << endl;
  hm_1->Draw();

  TH1D* hm_2 = (TH1D*)file->Get("mean_three8192");
  cout << hm_2 << endl;
  hm_2->Draw();

  TH1D* hm_3 = (TH1D*)file->Get("mean_four8192");
  cout << hm_3 << endl;
  hm_3->Draw();

  TH1D* hm_4 = (TH1D*)file->Get("mean_five8192");
  cout << hm_4 << endl;
  hm_4->Draw();

  return;
  
}
