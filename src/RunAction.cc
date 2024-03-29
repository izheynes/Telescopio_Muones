#include "RunAction.hh"

RunAction::RunAction(){}
RunAction::~RunAction(){}

void RunAction::BeginOfRunAction(const G4Run*){
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man -> SetDefaultFileType("csv");
    man -> OpenFile("Histograma.csv");

    man -> CreateNtuple("Hits", "Hits");
	man -> CreateNtupleIColumn("fEvent");
    man -> CreateNtupleIColumn("plane");
    man -> CreateNtupleIColumn("strip");
	man -> CreateNtupleDColumn("fX");
	man -> CreateNtupleDColumn("fY");
    man -> CreateNtupleDColumn("fZ");
    man -> CreateNtupleDColumn("energy");
	man -> FinishNtuple(0);

}

void RunAction::EndOfRunAction(const G4Run*){
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man -> Write();
    man -> CloseFile();

}
