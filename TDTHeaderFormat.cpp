
#include "TDTHeaderFormat.h"

/*
 * constructor, no arguments
 */
TDTHeaderFormat::TDTHeaderFormat()
  cFormat(0);
{
}

/*
 * constructor, value to be assigned
 */
TDTHeaderFormat::TDTHeaderFormat(long lFormat):
  cFormat( lFormat )
{
}

/*
 * destructor
 */
TDTHeaderFormat::~TDTHeaderFormat()
{
}

/*
 * assignment operator
 * you can assign a long and 
 * the class will set its private variable
 */
void TDTHeaderFormat::operator=(const long lFormat) {
  // assigned value passed in input to our private value
  cFormat = lFormat;
}

/*
 * set value
 */
void TDTHeaderFormat::Set(long lFormat) {
  cFormat = lFormat;
}

/*
 * get value long
 * return the original long value
 */
long TDTHeaderFormat::Get() {
  return cFormat;
}
/*
 * get value string
 * return the string interpretation
 */
string TDTHeaderFormat::Get() 
{
  // uses the static method to convert to string
  return TDTHeaderFormat::toString(cFormat);
}

/*
 * Static method, properties and constants
 *
 * format values
 */
const long TDTHeaderFormat::Float    = 0;
const long TDTHeaderFormat::Long     = 1;
const long TDTHeaderFormat::Short    = 2; 
const long TDTHeaderFormat::Byte     = 3;
const long TDTHeaderFormat::Double   = 4;
const long TDTHeaderFormat::LongLong = 5;
/*
 * unorderd map to convert from numeric to C type
 */
TDTHeaderFormat::toCType = {
  { TDTHeaderFormat::Float    , "float"    },
  { TDTHeaderFormat::Long     , "long"     },
  { TDTHeaderFormat::Short    , "short"    },
  { TDTHeaderFormat::Byte     , "char"     },
  { TDTHeaderFormat::Double   , "double"   },
  { TDTHeaderFormat::LongLong , "long long" }
}
/*
 * unorderd map to convert from numeric to Matlab Mex type
 */
TDTHeaderFormat::toMexType = {
  { TDTHeaderFormat::Float    , "MexFloat"  },
  { TDTHeaderFormat::Long     , "MexInt32"  },
  { TDTHeaderFormat::Short    , "MexInt16"  },
  { TDTHeaderFormat::Byte     , "MexInt8"   },
  { TDTHeaderFormat::Double   , "MexDouble" },
  { TDTHeaderFormat::LongLong , "MexInt64"  }
}
/*
 * unorderd map to convert from string to numeric
 */
TDTHeaderFormat::toNum = {
  { "float"     , TDTHeaderFormat::Float    },
  { "long"      , TDTHeaderFormat::Long     },
  { "short"     , TDTHeaderFormat::Short    },
  { "char"      , TDTHeaderFormat::Byte     },
  { "double"    , TDTHeaderFormat::Double   },
  { "longlong"  , TDTHeaderFormat::LongLong },
  { "MexFloat"  , TDTHeaderFormat::Float    },
  { "MexInt16"  , TDTHeaderFormat::Long     },
  { "MexInt16"  , TDTHeaderFormat::Short    },
  { "MexInt8"   , TDTHeaderFormat::Byte     },
  { "MexDouble" , TDTHeaderFormat::Double   },
  { "MexInt64"  , TDTHeaderFormat::LongLong }
}

