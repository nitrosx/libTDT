#ifndef TDTTank_H
#define TDTTank_H

#include <string>

class TDTTank 
{

  private:
    std::string cRoot;

  public:
    // constructor
    TDTTank();
    TDTTank(std::string lRoot);

    // destructur
    ~TDTTank();

};
#endif

