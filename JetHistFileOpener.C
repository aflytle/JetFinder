//JetHistFile root opener

void JetHistFileOpener()
{
  TFile* file = TFile::Open("testout.root");

  TProfile* pTr = (TProfile*)file->Get("pTr");
  cout << pTr << endl;
  pTr->Draw();

  TProfile* pTj = (TProfile*)file->Get("pTj");
  cout << pTj << endl;
  pTj->Draw();

}
