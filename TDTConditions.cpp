#include "TDTConditions.h"

/*
 * class TDTConditions
 * 
 * this class is used to decide which headers load from TDT files
 * The following properties can be defined
 * - event codes
 * - channel
 *
 */

/*
 * constructor
 *
 *
 * first constructor instantiate an empty object
 */
TDTConditions::TDTConditions()
{
}
/*
 * this constructor insert a specific code event as condition
 */
TDTConditions::TDTConditions(TDTData::tdtCode const& lCode)
{
  // insert code in list
  cCodes.insert( lCode );
}
/*
 * this constructor insert a specific channel as condition
 */
TDTConditions::TDTConditions(TDTData::tdtChannel const& lChannel)
{
  // insert channel in list
  cChannels.insert( lChannel );
}
/*
 * deconstructor
 */
TDTConditions::~TDTConditions()
{
}

/*
 * Add a new code to the conditions list
 */
int TDTConditions::AddCode(TDTData::tdtCode const& lCode)
{
  // check if the code is already in list
  if ( !Find(lCode) ) {
    // new code
    // insert in list
    cCodes.insert( lCode );
  }
  // return number od codes in cCodes
  return cCodes.size();
}

/*
 * Add a new channel to the conditions list
 */
int TDTConditions::AddChannel(TDTData::tdtChannel const& lChannel)
{
  // check if the channel is already in list
  if ( !(lChannel) ) {
    // new channel
    // insert in list
    cChannels.insert(lChannel);
  }
  // return number of channels in cChannels
  return cChannels.size();
}
   

/*
 * return the list of event codes selected
 */
std::vector<std::string> TDTConditions::GetCodes()
{
  // instantiate vector for codes and copies all the values from codes set
  std::vector<std::string> lCodes(cCodes.begin(),cCodes.end());
  // return pointer to vector
  return lCodes;
}

/*
 * return the list of channels selected
 */
std::vector<TDTData::tdtChannel> TDTConditions::GetChannels()
{
  // instantiate vector for channels and copies all the values from channels set
  std::vector<TDTData::tdtChannel> lChannels(cChannels.begin(),cChannels.end());
  // return pointer to vector
  return lChannels;
}

/*
 * comparison operators
 */
bool TDTConditions::operator ==(TDTData::tdtCode const& lCode)
{
  // check if we have any code
  // if we do find the code in the list
  // if we do not have any element, return true by default
  return ( cCodes.size() == 0 || Find(lCode) );
}
bool TDTConditions::operator ==(TDTData::tdtChannel const& lChannel)
{
  // check if we have any channel in list
  // if we do, find the channel requested in the list
  // if we do not have any element, return true by default
  return ( cChannels.size() == 0 || Find(lChannel) );
}

/*
 * check both code and channel
 */
bool TDTConditions::Check(TDTData::tdtCode const& lCode, TDTData::tdtChannel const& lChannel)
{
  // check if the code and the channel requested are in the list of conditions
  return ( Find(lCode) && Find(lChannel) );
}

/*
 * find the code or channel requested in the list
 */
bool TDTConditions::Find(TDTData::tdtCode const& lCode)
{
  // instantiate an iterator and use the find function from unordered_map
  std::set<std::string>::const_iterator found = cCodes.find(lCode);
  // return one if found
  return !( found == cCodes.end() );
}
bool TDTConditions::Find(TDTData::tdtChannel const& lChannel)
{
  // instantiate an iterator and use the find function from unordered_map
  std::set<TDTData::tdtChannel>::const_iterator found = cChannels.find(lChannel);
  // return one if found
  return !( found == cChannels.end() );
}

/*
 * remove all conditions from lists
 */
void TDTConditions::ClearAll()
{
  // clear code list
  cCodes.clear();
  // clear channel list
  cChannels.clear();
}

