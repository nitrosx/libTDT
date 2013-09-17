#ifndef TDTTsData
#define TDTTdData

class TDTTsData {

  public:

    /*
     * constructor
     */
    void TDTTsData();

    /*
     * desctructor
     */
    void ~TDTTsData();

    /*
     * Insert time series point
     */
    virtual void Insert(double t);

    /*
     * return time serie in a vector
     */
    virtual vector<double> GetVector();

    /*
     * return time point at given time
     */
    virtual double GetPoint();

    /* 
     * operator +
     */
    virtual const TDTTsData operator+(const TDTTsData &rhs);

    /*
     * vector or point ordered by time
     * we use map, so we can retrieve the points in the right order
     */
    map<double,double> timeserie;

  private:


}

#endif
