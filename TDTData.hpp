#ifndef H_TDTData
#define H_TDTData

#include <string>

namespace TDTData {

  /*
   * tdt data type
   */
  typedef char           tdtCode [4];    /* Event code */
  typedef unsigned short tdtChannel; /* Event channel */



  /*
   * files names structure
   */
  struct tdtFiles {
    std::string tev;
    std::string tsq;
    std::string tbk;
    std::string tdx;
  };


  /*
   * tsq header structure
   */
  struct tsqHeader {
    long           size;      /* number of longs to be read from tev file, if any */
    long           type;      /* event type: snip, pdec, epoc etc */
    long           code;      /* event name: must be 4 chars, cast as a long */
    unsigned short channel;   /* data acquisition channel */
    unsigned short sortcode;  /* sort code for snip data */
    double         timestamp; /* time offset when even occurred */
    union {
      long long    ev_offset; /* data offset in the TEV file */
      double       strobe;    /* raw data value */
    };
    long           format;    /* data format of event: byte, short, float(usually), double */
    float          frequency; /* sampling frequency */
  };

};
#endif
