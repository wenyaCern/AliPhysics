#ifndef AliPMDpPbAnalysisTaskData_cxx
#define AliPMDpPbAnalysisTaskData_cxx

//PMD pA data analysis
//Author: Abhi Modak (abhi.modak@cern.ch)
//Co-Authors: Sudipan De (Sudipan.De@cern.ch) and Sidharth Kumar Prasad (sidharth.kumar.prasad@cern.ch)
//Taken the help from the code: alisw/AliPhysics/PWGLF/FORWARD/photons/AliAnalysisTaskPMD.h

class TH1F;
class TH2F;
class TString;
class TNtuple;
class TArrayF;
class AliESDEvent;
class AliESDPmdTrack;
class AliHeader;
class TParticle;
class AliMultSelection;
class AliVEvent;

#include "AliAnalysisTaskSE.h"

class AliPMDpPbAnalysisTaskData : public AliAnalysisTaskSE {
 public:
 AliPMDpPbAnalysisTaskData() : AliAnalysisTaskSE(),
    fESD(0), 
    fEsdV0(0),
    fOutputList(0),
    fCentEstimator(0),
    fTrigSel(0),
    fHistClsXYPre(0),
    fHistClsXYCpv(0),
    fHistVtxZ(0),
    fHistTotEvent(0),
    fHistEtaCut1(0),
    fHistEtaCut2(0),
    fHistNcellCut1(0),
    fHistNcellCut2(0),
    ntMeas1(0),
    ntMeas2(0),
    ntCent(0),
    ntCorr(0){
  }
  
  AliPMDpPbAnalysisTaskData(const char *name);
  virtual ~AliPMDpPbAnalysisTaskData(){}
  
  virtual void UserCreateOutputObjects();
  virtual void UserExec(Option_t *option);
  virtual void Terminate(Option_t *);
  void SetTrigger(const char* trigger){
    fTrigSel = trigger;
  };
  void SetCentralityEstimator(const char* Estimator){
    fCentEstimator = Estimator;
  };
  
 private:
  AliESDEvent *fESD;
  AliESDVZERO *fEsdV0;
  TList       *fOutputList;
  TNtuple     *ntMeas1;
  TNtuple     *ntMeas2;
  TNtuple     *ntCent;
  TNtuple     *ntCorr;
  TH1F        *fHistTotEvent;
  TH2F        *fHistClsXYPre;
  TH2F        *fHistClsXYCpv;
  TH1F        *fHistVtxZ;
  TH1F        *fHistEtaCut1;
  TH1F        *fHistEtaCut2;
  TH1F        *fHistNcellCut1;
  TH1F        *fHistNcellCut2;
  TString     fCentEstimator;
  TString     fTrigSel;

  AliPMDpPbAnalysisTaskData(const AliPMDpPbAnalysisTaskData&);
  AliPMDpPbAnalysisTaskData& operator = (const AliPMDpPbAnalysisTaskData&);

  ClassDef(AliPMDpPbAnalysisTaskData, 1);
};

#endif
