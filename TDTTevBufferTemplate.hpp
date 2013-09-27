#ifndef H_TDTTevBufferTemplate
#define H_TDTTevBufferTemplate

#include <algorithm>
#include <cstdlib>
#include "TDTTevBuffer.hpp"

template<typename D>
  class TDTTevBufferTemplate: public TDTTevBuffer {

    public:
      /*
       * constructor
       * lFid    = file descriptor where we are going to read data from
       * lOffset = position of the chunk of file in bytes
       * lSize   = number of T data to read
       */
      TDTTevBufferTemplate(FILE* lFid, long lOffset, unsigned long lSize):
        TDTTevBuffer(lFid, lOffset, lSize, 0)
      {
      };
      /*
       * destructor
       */
      ~TDTTevBufferTemplate()
      {
      };

      /*
       * Read data from file
       */
      void ReadData() {
        /*
         * allocate memory for the array
         * dimension = size of T * size of the chunk to be read
         */
        cBuffer = (D*) malloc (cSize*sizeof(D));

        /*
         * position file pointer on right position
         */
        fseek(
          cFid,       /* file descriptor */
          cOffset,   /* start position in the file of the data */
          SEEK_SET); /* starting from the beginning of the file */

        /*
         * read data from file and place them in cBuffer
         */
        cElements = fread(
          (D*)cBuffer, /* buffer where to store the data read */
          sizeof(D),   /* dimension in bytes of the type of data */
          cSize,       /* number of data unit to read */
          cFid);        /* file descriptor */
      }

      /*
       * size of the data
       */
      unsigned long length()
      {
        return cElements;
      }
      /*
       * last element
       */
      unsigned long end() {
        return cElements - 1;
      }

      /*
       * TDTTevBufferTemplate iterator
       */
      class Iterator {

          const D* cBufferBegin;
          unsigned long cIndex;
          unsigned long cBufferSize;

        public:
          /*
           * constructor
           */
          Iterator(const D* &lBuffer, unsigned long lSize):
            cBufferBegin(lBuffer), cBufferSize(lSize)
          {
            cIndex = 0;
          }
          /*
           * destructor
           */
          ~Iterator()
          {
          }
          /*
           * ++ operator
           */
          Iterator& operator++() 
          { 
            // check if we are at the end
            
            // incrememnt the index
            cIndex++;
            // return itself
            return *this; 
          }
          /*
           * reference operator
           * return data at index of the array
           */
          D& operator*() 
          { 
            // define temporery pointer to buffer
            D* lBuffer;
            // initialize to current element pointed by index
            lBuffer = cBufferBegin + sizeof(D)*std::min(cIndex,(cBufferSize-1));
            return (*lBuffer); 
          }
          /*
           * pointer operator
           */
          D* operator->() 
          { 
            return cBuffer; 
          }
          /*
           * equality operator with another iterator
           */
          bool operator==(const TDTTevBufferTemplate::Iterator& oIter) 
          { 
            return cIndex == oIter.cIndex; 
          }
          /*
           * equality operator with unsigned long
           */
          bool operator==(const unsigned long oIter) 
          { 
            return cIndex == oIter;
          }
          /*
           * inequality operator
           */
          bool operator!=(const TDTTevBufferTemplate::Iterator& oIter) 
          { 
            return cIndex != oIter.cIndex; 
          }
          /*
           * inequality operator with interger
           */
          bool operator!=(const unsigned long oIter) 
          { 
            return cIndex != oIter; 
          }

      };
      // iterator
      //friend class TDTTevBufferTemplate::Iterator;

      /*
       * begin of the iterator
       */
      Iterator begin()
      {
        return Iterator();
      }

    private:
      // array where we store the data read from file
      D* cBuffer;
      // number of elements
      //unsigned long cElements = 0;
      // input file descriptor
      //FILE * fid;
      // offset of teh data chunk
      //long lOffset;
      // number of elements to read
      //unsigned long lSize;

  };

#endif
