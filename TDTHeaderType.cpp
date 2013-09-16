#include "TDTHeaderType.h"

/*
 * constructor, no arguments
 */
TDTHeaderType::TDTHeaderType()
  cType(0);
{
}

/*
 * constructor, value to be assigned
 */
TDTHeaderType::TDTHeaderType(long lType):
  cType( lType )
{
}

/*
 * destructor
 */
TDTHeaderType::~TDTHeaderType()
{
}

/*
 * assignment operator
 * you can assign a long and 
 * the class will set its private variable
 */
void TDTHeaderType::operator=(const long lType) {
  // assigned value passed in input to our private value
  cType = lType;
}

/*
 * set value
 */
void TDTHeaderType::Set(long lType) {
  cType = lType;
}

/*
 * get value long
 * return the original long value
 */
long TDTHeaderType::Get() {
  return cType;
}

/*
 * get value string
 * return the string interpretation
 */
string TDTHeaderType::Get() 
{
  // uses the static method to convert to string
  return TDTHeaderType::toString(cType);
}

/*
 * Static method, properties and constants
 *
 * type values
 */
const long TDTHeaderType::Unknown = 0; 
const long TDTHeaderType::StrobePlus = 257;  /* Strobe+ */
const long TDTHeaderType::StrobeMinus = 258; /* Strobe- */
const long TDTHeaderType::Scalar = 513;
const long TDTHeaderType::Stream = 33025;
const long TDTHeaderType::Snip = 33281;
const long TDTHeaderType::Mark = 34817; /* from real data, this is like unknown */
const long TDTHeaderType::HasData = 32768; /* from real data, this is like stream */
/*
 * unorderd map to convert from numeric to string
 */
TDTHeaderType::toString = {
 { TDTHeaderType::Unknown     , "Unknown" },
 { TDTHeaderType::StrobePlus  , "Strobe+" },
 { TDTHeaderType::StrobeMinus , "Strobe-" },
 { TDTHeaderType::Scalar      , "Scalar"  },
 { TDTHeaderType::Stream      , "Stream"  },
 { TDTHeaderType::Snip        , "Snip"    },
 { TDTHeaderType::Mark        , "Unknown" },
 { TDTHeaderType::HasData     , "Stream"  }
};
/*
 * unorderd map to convert from string to numeric
 */
TDTHeaderType::toNum = {
 { "Unknown" , TDTHeaderType::Unknown     },
 { "Strobe+" , TDTHeaderType::StrobePlus  },
 { "STrobe-" , TDTHeaderType::StrobeMinus },
 { "Scalar"  , TDTHeaderType::Scalar      },
 { "Stream"  , TDTHeaderType::Stream      },
 { "Snip"    , TDTHeaderType::Snip        },
 { "Mark"    , TDTHeaderType::Mark        },
 { "HasData" , TDTHeaderType::HasData     }
};

/*
 * returns true if this type has data in the TEV files 
 * and has the offset saved in the header
 * input:
 * - long lType: type field from the header structure
 * output:
 * - bool 
 */
bool TDTHeaderType::HasOffset(long lType) {
  // tdt types that have offset
  // Stream (33025), Snip (33281) and HasData (32768)
  return 
    lType == TDTHeaderType::Stream ||
    lType == TDTHeaderType::Snip   ||
    lType == TDTHeaderType::HasData ;
}

/* instantiate a vector of the correct type given the type code
 * and return the pointer
 *
 * input:
 * - long lType: type field from the header structure
 * output
 * - vector* : pointer to an empty vector structure of the right type
 */
vector* TDTHeaderType::VectorInstance(long lType) {
  // pointer to the vector
  vector* lVector;
  switch (lType) {
    case TDTHeaderFormat::Float:
      lVector = new vector<TDTPoint<float>>;
      break;
    case TDTHeaderFormat::Long:
      lVector = new vector<TDTPoint<long>>;
      break;
    case TDTHeaderFormat::Short:
      lVector = new vector<TDTPoint<short>>;
      break;
    case TDTHeaderFormat::Byte:
      lVector = new vector<TDTPoint<char>>;
      break;
    case TDTHeaderFormat::Double:
      lVector = new vector<TDTPoint<double>>;
      break;
    case TDTHeaderFormat::LongLong:
      lVector = new vector<TDTPoint<long long>>;
      break;
  }
  // return the pointer
  return lVector;
}
