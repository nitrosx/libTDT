
#include "TDTHeader.h"
#include "TDTPoint.h"
#include "TDTHeaderType.h"
#include "TDTHeaderFormat.h"

/*
 * constructor, no arguments
 */
TDTHeader::TDTHeader()
{
  // assign empty structure to header
  cHeader = { -1, -1, 0, 0, 0, 0.0, -1, -1, 0.0};
}

/*
 * constructor, header structure in input
 */
TDTHeader::TDTHeader(long const &lHeader):
  cHeader = lHeader ;
{
}

/*
 * destructor
 */
TDTHeader::~TDTHeader()
{
}


/*
 * getter method
 * output:
 * - tsqHeader
 */
tsqHeader TDTHeader::Get()
{
  return cHeader;
}

/*
 * given the fid for the teq file
 * reads the data from the appropriate block
 * it works only for header types: Stream, Snip and HasData
 * input:
 * - FILE* file descriptor
 * output:
 * - vector* vector of data points
 */
vector* ReadData(FILE* fid = void)
{
  // buffer to read from the file
  TDTHeaderFormat* lBuffer;
  // pointer to a vector of correctly typed TDTPoints
  // this vector will hold the points (time,value)
  vector* lVector = TDTHeaderType::VectorInstance(cHeader->type);
  // buffer iterator
  TDTTevFormat::Iterator* lBi;
  // reads data from file
  // instantiate the buffer object with the correct data type
  switch (cHeader.format) {
    case TDTHeaderFormat::Float:
      lBuffer = new TDTTevBuffer<float>(fid,cHeader.offset,(unsigned long)cHeader.size);
      break;
    case TDTHeaderFormat::Long:
      lBuffer = new TDTTevBuffer<long>(fid,cHeader.offset,(unsigned long)cHeader.size);
      break;
    case TDTHeaderFormat::Short:
      lBuffer = new TDTTevBuffer<short>(fid,cHeader.offset,(unsigned long)cHeader.size);
      break;
    case TDTHeaderFormat::Byte:
      lBuffer = new TDTTevBuffer<char>(fid,cHeader.offset,(unsigned long)cHeader.size);
      break;
    case TDTHeaderFormat::Double:
      lBuffer = new TDTTevBuffer<double>(fid,cHeader.offset,(unsigned long)cHeader.size);
      break;
    case TDTHeaderFormat::LongLong:
      lBuffer = new TDTTevBuffer<long long>(fid,cHeader.offset,(unsigned long)cHeader.size);
      break;
  }
  // reads the chunk
  lBuffer->ReadData();
  // transfer in vector of points
  // value timestamp
  double lTimestamp = cHeader.timestamp;
  // time delta between iteration
  double lTimeDelta = 1.0/cHeader.frequency;
  // use buffer iterator
  for ( lBi = lBuffer.begin(); lBi != lBuffer.end(); lBi++) {
    // append timestamp, value read at the end of the vector
    lVector->emplace_back(lTimestamp,*lBi);
    // update timestamp
    lTimestamp +=  lTimeDelta;
  }
  // release lBuffer and iterator;
  delete lBi;
  delete lBuffer;
  // return vector
  return lVector;
}

/*
 * get just the value from the offset/strobe field
 * it works only for event type: Strobe-/+, Scalar, Mark
 * input:
 * - none
 * output:
 * - double value
 */
double Value()
{
 return cHeader.strobe; 
}

/*
 * get data
 * return back a vectors of all the header type
 * input:
 * - FILE* file descriptor if needed
 * output:
 * - vector* vectors of values
 */
vector* TDTHeader::GetData(FILE* fid = void)
{
  // based on the type of data, 
  // we need to return the value that we have here 
  // or read from the file
  // 
  // data that has data in the tev file
  // Stream (33025), Snip (33281) and HasData (32768)

  vector* lVector;
  
  if ( TDTHeaderType::HasOffset(cHeader.type) ) {
    // returns vector with data read from tev file
    lVector = ReadData(fid);
  } else {
    // using file stored in strobe
    lVector = new vector<TDTPoint<double>>
    lVector->emplace_back(cHeader.timestamp,cHeader.strobe);
  }
  return lVector;
}

// get the entire structure
tsqHeader TDTHeader::Get()
{
  return cHeader;
}

// return event type according to TDT
// return the numeric value
long TDTHeader::Type()
{
  return cHeader.type;
}
// return the string description
string TDTHeader::Type()
{
  // calls static method of TDTHeaderType 
  return TDTHeaderType::toString(cHeader.type);
}

// return data format aka data type
long TDTHeader::Format()
{
  return cHeader.format;
}
// return the string
string TDTHeader::Format()
{
  // calls static method of TDTHeaderFormat
  return TDTHeaderFormat::toString(cHeader.format);
}

