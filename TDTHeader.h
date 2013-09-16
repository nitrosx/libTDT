#ifndef TDTHeader
#define TDTHeader

#include "TDTData.h"

class TDTHeader {

  public:
    // constructor
    void TDTHeader();
    void TDTHeader(tsqHeader const &lHeader);
    // deconstructor
    void ~TDTHeader();

    // getter method
    tsqHeader Get();

    // given the fid for the teq file
    // reads the data from the appropriate block
    vector* ReadData(FILE* fid = void);
    
    // get value from the offset value
    double GetValue();

    // get data
    vector* GetData(FILE* fid = void);

    // get the entire structure
    tsqHeader Get();

    // return event type according to TDT
    long Type();
    string Type();

    // return data format aka data type
    long Format();
    string Format();

  private:

    /* 
     * header data
     */
    tsqHeader cHeader;

}

#endif

