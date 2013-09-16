#ifndef TDTHeaderType
#define TDTHeaderType



class TDTHeaderType {

  public:
    // constructor
    void TDTHeaderType();
    void TDTHeaderTYpe(long lType);
    // destructor
    void ~TDTHeaderType()

    // assignment operator
    // you can assign a long and 
    // the class will set its internal variable
    void operator=(const long lType);

    // set value
    void Set(long lType);

    // get value
    // return the original long value
    long Get();
    // return the string interpretation
    string Get();

    /*
     * Static method, properties and constants
     *
     * type values
     */
    static const long Unknown;
    static const long StrobePlus; /* Strobe+ */
    static const long StrobeMinus; /* Strobe- */
    static const long Scalar;
    static const long Stream;
    static const long Snip
    static const long Mark;
    static const long HasData;
    /*
     * unorderd map to convert from numeric to string
     */
    static unorderd_map<long, string> toString;
    /*
     * unorderd map to convert from string to numeric
     */
    static unorderd_map<string, long> toNum;

    /*
     * returns true if the type passed has an offset,
     * flase owtherwise
     */
    static bool TDTHeaderType::HasOffset(long lType);

    /* 
     * instantiate a vector of the correct type given the type code
     * and return the pointer
     */
    static vector* TDTHeaderType::VectorInstance(long lType);

  private:
    // type
    long cType = 0;

  protected:


}
#endif
