#ifndef TDTEvent
#define TDTEvent

#include "TDTData.hpp"
#include "TDTChannel.h"

/*
 * class TDTEvent
 * 
 * represent one event found in the tsq file
 * it includes all the properties that are common to all the event headers
 *
 */
class TDTEvent {

  public:
    /*
     * constructor
     */
    TDTEvent(TDTData::tdtCode lCode);
    TDTEvent(TDTData::tsqHeader lHeader);
    /*
     * deconstructor
     */
    ~TDTEvent();

    /*
     * Add passed header to proper channel
     */
    void AddHeader(TDTData::tsqHeader lHeader);
   
    /*
     * return a list of channels
     */
    vector<TDTData::tdtChannel>* GetChannelsList();

    /*
     * list of channels
     */
    unordered_map<TDTData::tdtChannel,TDTChannel*> cChannels;

  private:

    /*
     * properties of the event
     *
     * - code      (4 chars string)
     * - size      (long aka 4 bytes, longs to read in the tev file)
     * - type      (long, numeric event code)
     * - format    (long, type of data to be read from tev file)
     * - frequency (double, sampling frequency)
     * - sort      (unsigned short, sort code)
     */
    char[4]        cCode;
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
