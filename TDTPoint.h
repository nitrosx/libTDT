#ifndef TDTPoint
#define TDTPoint

template<typename V>
class TDTPoint 
{

  public:
    void TDTPoint();
    void TDTPoint(double lt, V lv);

    TDTPoint & operator= (const TDTPoint & other)

  private:
    double t; /* timestamp */
    V v;      /* value */

}
#endif
