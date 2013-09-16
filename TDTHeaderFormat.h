#ifndef TDTHeaderFormat
#define TDTHeaderFormat

class TDTHeaderFormat {

  public:
    // constructor
    void TDTHeaderFormat();
    void TDTHeaderFormat(long lFormat);
    // destructor
    void ~TDTHeaderFormat()

    // assignment operator
    // you can assign a long and 
    // the class will set its internal variable
    void operator=(const long lFormat);

    // set value
    void Set(long lFormat);

    // get value
    // return the original long value
    long Get();
    // return the string interpretation
    string Get();

    /*
     * Static method, properties and constants
     *
     * format values
     */
    static const long Float;
    static const long Long;
    static const long Short;
    static const long Byte;
    static const long Double;
    static const long LongLong;
    /*
     * unorderd map to convert from numeric to C type
     */
    static unorderd_map<long, string> toCType;
    /*
     * unorderd map to convert from numeric to Matlab Mex type
     */
    static unorderd_map<long, string> toMexType;
    /*
     * unorderd map to convert from string to numeric
     */
    static unorderd_map<string, long> toNum;

  private:
    // type
    long cFormat = 0;

  protected:


}
#endif
