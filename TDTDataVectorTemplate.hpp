#ifndef H_TDTDataVectorTemplate
#define H_TDTDataVectorTemplate

#include <vector>
#include "TDTDataVector.hpp"

template<typename D>
  class TDTDataVectorTemplate: public TDTDataVector {

  private:

  public:
    // constructor
    TDTDataVectorTemplate();
    // destructor
    ~TDTDataVectorTemplate();

    // Return vector
    std::vector<D> GetData();

    // internal vector
    std::vector<D> cData;

};

#endif
