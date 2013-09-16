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
TDTConditions::

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
TDTConditions::TDTConditions(TDTData::tdtCode lCode)
{
  // insert code in list
  cCodes.insert( {{lCode,1}} );
}
/*
 * this constructor insert a specific channel as condition
 */
TDTConditions::TDTConditions(TDTData::tdtChannel lChannel)
{
  // insert channel in list
  cChannels.insert( {{lChannel,1}} );
}
/*
 * deconstructor
 */
~TDTConditions()
{
}

/*
 * Add a new code to the conditions list
 */
TDTConditions::AddCode(TDTData::tdtCode lCode)
{
  // check if the code is already in list
  if ( !this.Find(lCode) ) {
    // new code
    // insert in list
    this.cCode.insert( {{lCode,1}} );
  }
}

/*
 * Add a new channel to the conditions list
 */
TDTConditions::AddChannel(TDTData::tdtChannel lChannel)
{
  // check if the channel is already in list
  if ( !this.Find(lChannel) ) {
    // new channel
    // insert in list
    this.cChannels.insert( {{lChannel,1}} );
  }
}
   

/*
 * return the list of event codes selected
 */
vector<TDTData::tdtCode>* TDTConditions::GetCodes()
{
  // instantiate vector for codes and copies all the values from codes set
  std::vector<TDTData::tdtCodes>* lCodes = new std::vector<TDTData::tdtCode>(this.cCodes.begin(),this.cCodes.end());
  // instantiate vector for codes
//  std::vector<TDTData::tdtCode>* lCodes;
  // fix the size
//  lCodes->reserve(this.cCodes.size());
  // transfer codes from map
//  for(auto item : this.cCodes) {
//    lCodes->push_back(item.first);
//  } 
  // return pointer to vector
  return lCodes;
}

/*
 * return the list of channels selected
 */
vector<TDTData::tdtChannel>* TDTConditions::GetChannels()
{
  // instantiate vector for channels and copies all the values from channels set
  std::vector<TDTData::tdtChannel>* lChannels = new std::vector<TDTData::tdtChannel>(this.cChannels.begin(),this.cChannels.end());
  // fix the size
//  lChannels->reserve(this.cChannels.size());
  // transfer channels from map
//  for(auto item : this.cChannels) {
//    lChannels->push_back(*item);
//  }
  // return pointer to vector
  return lChannels;
}

/*
 * comparison operators
 */
bool TDTConditions::operator ==(TDTData::tdtCode lCode)
{
  // check if we have any code
  // if we do find the code in the list
  // if we do not have any element, return true by default
  return ( this.cCodes.size() == 0 || this.Find(lCode) );
}
bool TDTConditions::operator ==(TDTData::tdtChannel lChannel)
{
  // check if we have any channel in list
  // if we do, find the channel requested in the list
  // if we do not have any element, return true by default
  return ( this.cChannels.size() == 0 || this.Find(lChannel) );
}

/*
 * check both code and channel
 */
bool TDTConditions::Check(TDTData::tdtCode lCode, TDTData:tdtChannel lChannel)
{
  return ( this.Find(lCode) && this.Find(lChannel) );
}

/*
 * find the code or channel requested in the list
 */
bool TDTConditions::Find(TDTData::tdtCode lCode)
{
  // instantiate an iterator and use the find function from unordered_map
  std::set<iTDTData::tdtCode>::const_iterator found = this.cCodes.find (lCode);
  // return one if found
  return !( found == mymap.end() );
}
bool TDTConditions::Find(TDTData::tdtChannel lChannel)
{
  // instantiate an iterator and use the find function from unordered_map
  std::set<iTDTData::tdtChannel>::const_iterator found = this.cCodes.find (lChannel);
  // return one if found
  return !( found == mymap.end() );
}

/*
 * remove all conditions from lists
 */
TDTConditions::ClearAll()
{
  // clear code list
  this.cCodes.erase(this.cCodes.begin(),this.cCodes.end());
  // clear channel list
  this.cChannels.erase(this.cChannels.begin(),this.cChannels.end());
}

