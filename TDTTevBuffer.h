#ifndef TDTTevBuffer
#define TDTTevBuffer

template<typedef D>
  class TDTTevBuffer {

    public:
      /*
       * constructor
       * lFid    = file descriptor where we are going to read data from
       * lOffset = position of the chunk of file in bytes
       * lSize   = number of T data to read
       */
      void TDTTevBuffer(FILE* lFid, long lOffset, unsigned long lSize):
        cFid(lFid), cOffset(lOffset), cSize(lSize), cElements(0)
      {
      };
      /*
       * destructor
       */
      void ~TDTTevBuffer()
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
        cBuffer = (T*)malloc(sizeof(D)*cSize);

        /*
         * position file pointer on right position
         */
        fseek(
          fid,       /* file descriptor */
          cOffest,   /* start position in the file of the data */
          SEEK_SET); /* starting from the beginning of the file */

        /*
         * read data from file and place them in cBuffer
         */
        cElements = fread(
          (D*)cBuffer, /* buffer where to store the data read */
          sizeof(D),   /* dimension in bytes of the type of data */
          lSize,       /* number of data unit to read */
          fid);        /* file descriptor */
      }

      /*
       * return iterator for this class
       */
      TDTTevBuffer::Iterator* Iterator() {
        return new TDTTevBuffer::Iterator(this);
      }
      /*
       * begin of the iterator
       */
      TDTTevBuffer::Iterator* begin()
      {
        return Iterator();
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
       * TDTTevBuffer iterator
       */
      class Iterator
      {

          const TDTTevBuffer* cBuffer;
          unsigned long cIndex;

        public:
          /*
           * constructor
           */
          Iterator(const TDTTevBuffer &lBuffer): cBuffer(lBuffer)
          {
            cIndex = 0;
          }
          /*
           * ++ operator
           */
          self_type operator++() 
          { 
            // incrememnt the index
            cIndex++;
            // return itself
            return *this; 
          }
          /*
           * reference operator
           * return data at index of the array
           */
          <D> operator*() 
          { 
            return cBuffer->[cIndex]; 
          }
          /*
           * pointer operator
           */
          TDTTevBuffer* operator->() 
          { 
            return cBuffer; 
          }
          /*
           * equality operator with another iterator
           */
          bool operator==(const TDTTevBuffer::Iter& oIter) 
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
          bool operator!=(const TDTTevBuffer::Iter& oIter) 
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
      friend class TDTTevBufferIterator;

    private:
      // array where we store the data read from file
      D* cBuffer;
      // number of elements
      unsigned long cElements = 0;
      // input file descriptor
      FILE * fid;
      // offset of teh data chunk
      long lOffset;
      // number of elements to read
      unsigned long lSize;

  };



#endif
