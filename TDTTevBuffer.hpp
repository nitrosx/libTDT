#ifndef H_TDTTevBuffer
#define H_TDTTevBuffer

#include <cstdio>

class TDTTevBuffer {

  public:
    /*
     * constructor
     * lFid    = file descriptor where we are going to read data from
     * lOffset = position of the chunk of file in bytes
     * lSize   = number of T data to read
     */
    TDTTevBuffer(FILE* lFid, long lOffset, unsigned long lSize):
      cFid(lFid), cOffset(lOffset), cSize(lSize), cElements(0)
    {
    };

    /*
     * destructor
     */
    ~TDTTevBuffer();

    /*
     * Read data from file
     */
    virtual void ReadData();

    /*
     * size of the data
     */
    virtual unsigned long length()
    {
      return cElements;
    }
    /*
     * last element
     */
    virtual unsigned long end() {
      return cElements - 1;
    }

  private:
    // number of elements
    unsigned long cElements = 0;
    // input file descriptor
    FILE * cFid;
    // offset of teh data chunk
    long cOffset;
    // number of elements to read
    unsigned long cSize;

};

#endif
