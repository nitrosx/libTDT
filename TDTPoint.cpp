#include "TDTPoint.h"

template<typename V>
  TDTPoint::TDTPoint():
    t(0) v(0) {};

template<typename V>
  TDTPoint::TDTPoint(doublie lt, V lv):
    t(lt) v(lv) {};

template<typename V>
  TDTPoint::operator=(const TDTPoint & other)
  {
    t = other.t();
    v = other.v()
  }

