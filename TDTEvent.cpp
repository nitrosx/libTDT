
#include "TDTEvent.h"

/*
 * constructor with code only
 */
TDTEvent::TDTEvent(TDTData:tdtCode lCode):
  cCode(lCode) 
{
  cSize           = 0;
  cSizeValid      = 0;
  cType           = 0;
  cTypeValid      = 0;
  cFormat         = 0;
  cFormatValid    = 0;
  cFrequency      = 0;
  cFrequencyValid = 0;
  cTrackValues    = 0;
}
/*
 * constructor with all tsq header
 */
TDTEvent::TDTEvent(tsqHeader lHeader)
{
  cCode           = lHeader.code;
  cSize           = lHeader.size;
  cSizeValid      = 1;
  cType           = lHeader.type;
  cTypeValid      = 1;
  cFormat         = lHeader.format;
  cFormatValid    = 1;
  cFrequency      = lHeader.frequency;
  cFrequencyValid = 1;
  cTrackValues    = 1;
}

/*
 * deconstructor
 */
TDTEvent::~TDTEvent()
{
}

/*
 * Add passed header to proper channel
 */
TDTEvent::AddHeader(tsqHeader lHeader)
{
  // check if we are tracking values
  if ( cTrackValues ) {
    cSizeValid = cSizeValid && ( cSize == lHeader.size);
    cTypeValid = cTypeValid && ( cType == lHeader.type);
    cFormatValid = cFormatValid && ( cFormat == lHeader.format);
    cFrequencyValid = cFrequencyValid && ( cFrequency == lHeader.frequency);
  }
  // get the channel from the header
  TDTData::tdtChannel lCN = lHeader.channel;
  // check if we already have the channel defined
  // define an iterator of the unorderd_map that we use to store pointers to TDTChannel objects
  std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator found = cChannels.find(lCN);
  // check if we found it
  if ( found == cChannels.end() ) {
    // new channel
    TDTChannel* lChannel = new TDTChannel(lHeader);
    // insert in list of channels
    cChannels.insert( { lNumber, lChannel } );
  } else {
    // channel already in the list
    // found->second = pointer to channel instance
    found->second->AddHeader(lHeader);
  }
}

/*
 * Return the list of channels that we have in memory for this event
 */
TDTEvent::GetChannelsList()
{
  // instantiate new vector for the keys (that are the channels)
  vector<TDTData:tdtChannel>* list = new vector<TDTData:tdtChannel>;
  // size it appropriately
  list->reserve(cChannels.size());
  // loops on every element in channels and extract keys
  for( auto item : cChannel) {
    // insert key
    list->push_back(item->first);
  }
  // sort vector
  std::sort(list->begin(),list->end());
  // return poitner to vector
  return list;
}

