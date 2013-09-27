#ifndef H_TDTConditions
#define H_TDTConditions

#include "TDTData.hpp"
#include <vector>
#include <set>

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
    TDTConditions(TDTData::tdtCode const& lCode);
    /*
     * this constructor insert a specific channel as condition
     */
    TDTConditions(TDTData::tdtChannel const& lChannel);
    /*
     * deconstructor
     */
    ~TDTConditions();

    /*
     * Add a new code to the conditions list
     */
    int AddCode(TDTData::tdtCode const& lCode);

    /*
     * Add a new channel to the conditions list
     */
    int AddChannel(TDTData::tdtChannel const& lChannel);
  
    /*
     * return the list of event codes selected
     */
    std::vector<std::string> GetCodes();

    /*
     * return the list of channels selected
     */
    std::vector<TDTData::tdtChannel> GetChannels();

    /*
     * comparison operators
     */
    bool operator ==(TDTData::tdtCode const& lCode);
    bool operator ==(TDTData::tdtChannel const& lChannel);

    /*
     * check both code and channel
     */
    bool Check(TDTData::tdtCode const& lCode, TDTData::tdtChannel const& lChannel);

    /*
     * find the code or channel requested in the list
     */
    bool Find(TDTData::tdtCode const& lCode);
    bool Find(TDTData::tdtChannel const& lChannel);

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
    std::set<std::string> cCodes;

    /*
     * list of channels
     */
    std::set<TDTData::tdtChannel> cChannels;

};
#endif
