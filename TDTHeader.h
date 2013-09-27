#ifndef H_TDTHeader
#define H_TDTHeader

#include "TDTData.hpp"
#include <vector>

class TDTHeader {

  public:
    // constructor
    TDTHeader();
    TDTHeader(TDTData::tsqHeader const &lHeader);
    // deconstructor
    ~TDTHeader();

    // getter method
    TDTData::tsqHeader Get();

    // given the fid for the teq file
    // reads the data from the appropriate block
    void* ReadData(FILE* fid = void);
    
    // get value from the offset value
    double GetValue();

    // get data
    std::vector* GetData(FILE* fid = void);

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
    TDTData::tsqHeader cHeader;

}

#endif

