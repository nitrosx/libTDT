#ifndef TDTTank
#define TDTTank
#include <iostream>
#include <string>

typedef int TDTConditions;

class TDTTank 
{

  private:

    /*
     * root file path
     * it's the file names without extensions
     * it's not mandatory
     */
    std::string cRoot;
    /*
     * tev file path
     * it's the file containing the event data
     */
    std::string cTevFilePath;
    /*
     * tsq file path
     * it's the file containing the event headers
     */
    std::string cTsqFilePath;
    /*
     * tbk file path
     * it's the file containing the notes for this recording
     */
    std::string cTbkFilePath;
    /*
     * tdx file path
     * not sure what it contains
     */
    std::string cTdxFilePath;

    /*
     * conditions for filtering headers
     */
    TDTConditions* cConditions;


    /*
     * number of header to be read simultaneusly
     */
    static int cNHeaders;

  public:
    // constructor
    TDTTank();
    TDTTank(std::string lRoot);
    TDTTank(std::string lTevFile, std::string lTsqFile, std::string lTbkFile, std::string lTdxFile = "");
    TDTTank(TDTData::tdtFiles* lFiles);
    TDTTank(std::string lRoot,TDTConditions* lConditions);
    TDTTank(TDTData::tdtFiles* lFiles,TDTConditions* lConditions);

    // destructur
    ~TDTTank();

};

TDTTank::cNHeaders = 200000;
/*
 * constructors
 */
TDTTank::TDTTank() :
  cRoot(""), cTevFilePath(""), cTsqFilePath(""), cTbkFilePath(""), cTdxFilePath(""), cConditions(0X0)
{

}
TDTTank::TDTTank(string lRoot)
  : cConditions(0x0)
{
  // set root path and files names
  SetRoot(lRoot);
}
TDTTank::TDTTank(string lTevFile, string lTsqFile, string lTbkFile, string lTdxFile = "")
  : cRoot(""), cConditions(NULL)
{
  SetFiles(lTevFile, lTsqFile, lTbkFile, lTdxFile);
}
TDTTank::TDTTank(TDTData::tdtFiles* lFiles)
  : cRoot(""), cConditions(NULL)
{
  SetFiles(lFIles);
}
TDTTank::TDTTank(string lRoot,TDTConditions* lConditions)
{
  // set root path and files names
  SetRoot(lRoot);
  // save pointer to conditions
  this.cConditions = lConditions;
}
TDTTank::TDTTank(TDTData::tdtFiles* lFiles,TDTConditions* lConditions)
  : root("")
{
  // set files names
  SetFiles(lFIles);
  // save pointer to conditions
  this.cConditions = lConditions;
}


// destructor
TDTTank::~TDTTank()
{
  // release all the object
//  this->ClearAll();
}

#endif
