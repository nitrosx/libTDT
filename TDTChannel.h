#ifndef TDTChannel
#define TDTChannel

#include "TDTData.hpp"
#include "TDTHeader.h"

class TDTChannel {

  public:
    // constructors
    void TDTChannel();
    void TDTChannel(unsigned short lChannel);
    void TDTChannel(tsqHeader lHeader);
    // destructor
    void ~TDTChannel()

    /*
     * Add event header to the list
     */
    void AddHeader(tsqHeader* lHeader);

    /* 
     * read data from tev file according to headers
     */
    void ReadData(FILE *tev);

    /*
     * return channel data
     */
    vector* GetData();

    /*
     * list of each single event found for this channel
     */
    vector<TDTHeader*> cHeaders;

    /*
     * vector of values for this channel
     */
    vector* cData;
     

  private:
   
    /*
     * channel info
     *
     * - channel   : channel number
     * - size      : size in long of the chunk of data that we need to read from tev file
     * - frequency : sample frequency
     * - format    : data format
     */
    unsigned short cChannel;
    long           cSize;
    bool           cSizeValid;
    long           cType;
    bool           cTypeValid;
    long           cFormat;
    bool           cFormatValid;
    double         cFrequency;
    bool           cFrequencyValid;

    bool           cTrackValues;    
}
#endif
