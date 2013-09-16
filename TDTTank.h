#ifndef TDTTank
#define TDTTank

#
#include <string>


class TDTTank {

  public:
    // constructor
    void TDTTank();
    void TDTTank(string lRoot);
    void TDTTank(string lTevFile, string lTsqFile, string lTbkFile, string lTdxFile = "")
    void TDTTank(TDTData::tdtFiles* lFiles);
    void TDTTank(string lRoot,TDTConditions* lConditions);
    void TDTTank(TDTData::tdtFiles* lFiles,TDTConditions* lConditions);

    // destructur
    void ~TDTTank();

    /*
     * Clear all the data loaded from the tank
     */
    bool ClearAll();

    /*
     * Read all headers from tsq file
     */
    bool ReadHeaders();
    /*
     * Read event headers from tsq file
     */
    bool ReadHeaders(TDTTank::tdtCode iCode);
    /*
     * Read event and channel headers from tsq file
     */
    bool ReadHeaders(TDTTank::tdtCode iCode, TDTTank::tdtChannel iChannel);
    /*
     * Get headers info for all the events
     */
    vector<TDTHeader*> GetHeaders();
    /*
     * Get headers info for the event code requested
     */
    vector<TDTHeader*> GetHeaders(TDTData::tdtCode iCode);
    /*
     * Get headers info for the event code and channel requested
     */
    vector<TDTHeader*> GetHeaders(TDTData::tdtCode iCode, TDTData::tdtChannel iChannel);

    /*
     * Read all notes form tbk file
     */
    bool ReadNotes();
    /*
     * Read notes for the requested event
     */
    bool ReadNotes(TDTData::tdtCode iCode);
    /*
     * Return all the notes loaded from the tbk file
     */
    vector<TDTNotes*>* GetNotes();
    /*
     * Return the notes just for the event requested
     */
    TDTNotes* GetNotes(TDTData::tdtCode iCode);

    /*
     * Read data for all the channels from tev file for the event specified
     */
    bool ReadData(TDTTank::tdtCode iCode);
    /*
     * Read data from tev file for the given event and channels
     */
    bool ReadData(TDTTank::tdtCode iCode,vector<TDTTank::tdtChannel> iChannels);
    /*
     * Read data from tev file according to the list of headers given
     */
    bool ReadData(vector<tdtHeader> iHeaders);
    /*
     * Return time series data for specific event and channel
     */
    TDTtsData* GetData(TDTank::tdtCode iCode,TDTTank::tdtChannel iChannel);

    /* 
     * root property
     * setter
     */
    bool SetRoot(string root);
    /*
     * getter
     */
    string GetRoot();

    /*
     * files properties
     * setter
     */
    void SetTevFile(string lTevFile);
    void SetTsqFile(string lTsqFile);
    void SetTbkFile(string lTbkFile);
    void SetTdxFile(string lTdxFile);
    void SetFiles(string lTevFile, string lTsqFile, string lTbkFile, string lTdxFile);
    void SetFiles(TDTData::tdtFiles* lFiles);
    /*
     * getter
     */
    string GetTevFile();
    string GetTsqFile();
    string GetTbkFile();
    string GetTdxFile();
    TDTData::tdtFiles* GetFiles();

    /*
     * conditions setter
     */
    void SetConditions(TDTConditions* lConditions);
    /*
     * conditions getter
     */
    TDTConditions* GetConditions();

    /*
     * return the list of events
     */
    vector<TDTData::tdtCode>* GetEventsList();
    /*
     * return the list of channels organized by events
     */
    unordered_map<TDTData::tdtCode,vector<TDTData::tdtChannel>>* GetChannelsList();
    /*
     * return the list of channels for the event requested
     */
    vector<TDTData::tdtChannel>* GetChannelsList(TDTData::tdtCode iCode);


    /*
     * vector of events
     */
    std::unordered_map<TDTData::tdtCode,TDTEvent*> cEvents;

    /*
     * unordered map of notes
     */
    std::unordered_map<TDTData::tdtCode,TDTNotes*> cNotes;

  protected:


  private:
    /*
     * find the right element in the list of channels and returns pointer
     * if it is not found, it gets in serted
     */
    TDTEvents* GetEvent(TDTData::tdtCode lCode);
    TDTEvents* GetEvent(TDTData::tsqHeader lHeader);

    /*
     * root file path
     * it's the file names without extensions
     * it's not mandatory
     */
    string cRoot;
    /*
     * tev file path
     * it's the file containing the event data
     */
    string cTevFilePath;
    /*
     * tsq file path
     * it's the file containing the event headers
     */
    string cTsqFilePath;
    /*
     * tbk file path
     * it's the file containing the notes for this recording
     */
    string cTbkFilePath;
    /*
     * tdx file path
     * not sure what it contains
     */
    string cTdxFilePath;

    /*
     * conditions for filtering headers
     */
    TDTConditions* cConditions;


    /*
     * number of header to be read simultaneusly
     */
    static int NHeaders;

}
#endif
