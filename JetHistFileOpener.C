//JetHistFile root opener

void JetHistFileOpener()
{
  TFile* file = TFile::Open("testout.root");

  TH1D* pTr = (TH1D*)file->Get("pTr");
  cout << pTr << endl;
  pTr->Draw();

  TH1D* pTj = (TH1D*)file->Get("pTj");
  cout << pTj << endl;
  pTj->Draw();

}
