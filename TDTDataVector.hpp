#ifndef H_TDTDataVector
#define H_TDTDataVector

#include <vector>

class TDTDataVector {

  private:

  public:
    // constructor
    TDTDataVector();
    // destructor
    ~TDTDataVector();

    // Return vector
    virtual std::vector<int> GetData();

    // internal vector
    std::vector<int> cData;

};

#endif
