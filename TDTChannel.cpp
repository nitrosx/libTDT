
#include "TDTChannel.h"


/*
 * constructor, with only channel
 */
TDTChannel::TDTChannel(unsigned short lChannel):
 cChannel(lChannel)
{
  // common values for all the event headers in this channel
  cSize = 0;
  cSizeValid = 0;
  cType = 0;
  cTypeValid = 0;
  cFormat = 0;
  cFormatValid = 0;
  cFrequency = 0;
  cFrequencyValid = 0;
  cTrackValues = 0;

  cData = std::nullprt;
}

/*
 * constructor with all the values
 */
TDTChannel::TDTChannel(tsqHeader lHeader)
{
  // assign channel number
  cChannel = lHeader.channel;
  // common values for all the event headers in this channel
  cSize = lHeader.size;
  cSizeValid = 1;
  cType = lHeader.type;
  cTypeValid = 1;
  cFormat = lHeader.format;
  cFormatValid = 1;
  cFrequency = lHeader.frequency;
  cFrequencyValid = 1;
  cTrackValues = 1;

  cData = std::nullptr;
}
/*
 * destructor
 */
TDTChannel::~TDTChannel()
{
}

/*
 * Add event header to the list
 */
TDTChannel::AddHeader(tsqHeader lHeader) 
{
  // check if we need to keep track of the values
  if ( cTrackValues ) {
    // alright check if this header is consistent with previous values
    cSizeValid = cSizeValid && ( cSize == lHeader.size );
    cTypeValid = cTypeValid && ( cType == lHeader.type );
    cFormatValid = cFormatValid && ( cFormat == lHeader.format );
    cFrequencyValid = cFrequencyValid && ( cFrequency == lHeader.frequency );
  }
  
  // insert header in vector
  cHeaders->emplace_back(lHeaders);
}

/* 
 * read data from tev file according to headers
 */
TDTChannel::ReadData(FILE *tev)
{
  // check if we have a type 
  if ( cTypeValid ) {
    // instantiate the vector to contain all the data
    cData = TDTHeaderType::VectorInstance(cType);
    // local vector to save results
    vector* lData;
  
    // given that we do not know which type ofr data we have 
    // read data for all the headers in 
    for (vector<TDTHeader*>::iterator it = cHeaders->begin(); it != cHeaders->end(); it++)
    {
      // read data from header and get them in a vector
      lData = (*it)->GetData(tev);
      // append data retruned at the end of our data
      cData->insert(cData->end(),lData->begin(),lData->end());
    }
  }
}


/*
 * return channel data
 */
TDTChannel::GetData()
{
  return cData;
}

