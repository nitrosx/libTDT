#ifndef TDTConditions
#define TDTConditions

#include "TDTData.h"

/*
 * class TDTConditions
 * 
 * this class is used to decide which headers load from TDT files
 * The following properties can be defined
 * - event codes
 * - channel
 *
 */
class TDTConditions {

  public:
    /*
     * constructor
     *
     *
     * first constructor instantiate an empty object
     */
    TDTConditions();
    /*
     * this constructor insert a specific code event as condition
     */
    TDTConditions(TDTData::tdtCode lCode);
    /*
     * this constructor insert a specific channel as condition
     */
    TDTConditions(TDTData::tdtChannel lChannel);
    /*
     * deconstructor
     */
    ~TDTConditions();

    /*
     * Add a new code to the conditions list
     */
    void AddCode(TDTData::tdtCode lCode);

    /*
     * Add a new channel to the conditions list
     */
    void AddChannel(TDTData::tdtChannel lChannel);
  
    /*
     * return the list of event codes selected
     */
    vector<TDTData::tdtCode>* GetCodes();

    /*
     * return the list of channels selected
     */
    vector<TDTData::tdtChannel>* GetChannels();

    /*
     * comparison operators
     */
    bool operator ==(TDTData::tdtCode lCode);
    bool operator ==(TDTData::tdtChannel lChannel);

    /*
     * check both code and channel
     */
    bool Check(TDTData::tdtCode lCode, TDTData:tdtChannel lChannel);

    /*
     * find the code or channel requested in the list
     */
    bool Find(TDTData::tdtCode lCode);
    bool Find(TDTData::tdtChannel lChannel);

    /*
     * clear all the conditions inserted
     */
    void ClearAll();

  private:

    /*
     * list of event codes
     * internally we an undorderd_map
     * it makes it easier to search and compare
     */
    std::set<TDTData::tdtCode> cCodes;

    /*
     * list of channels
     */
    std::set<TDTData::tdtChannel> cChannels;

}
#endif
