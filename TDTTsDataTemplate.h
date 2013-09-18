#ifndef TDTTsDataTemplate
#define TDTTdDataTemplate

#include "TDTTsData.h"

template< typedef D >
  class TDTTsDataTemplate: public TDTTsData {
    /*
     * this template provide a way to store a timeseries with time and value of different size
     * it provides:
     * - polymorphism capabilities
     * - addition operator: adds point in the second operand in to the first
     */

    public: 
      
      /*
       * constructor
       */
      void TDTTsDataTemplate();
      void TDTTsDataTemplate(map<double,D> iTimeserie);

      /*
       * desctructor
       */
      void ~TDTTsData();

      /*
       * Insert time series point
       * t = time
       * v = value
       */
      void Insert(double t, D v);

      /*
       * return time serie in a vector
       */
      vector<TDTPoint<D>> GetVector();

      /*
       * return time point at given time
       */
      D GetPoint(double t);

      /* 
       * operator +
       */
      TDTTsDataTemplate< D >& operator+(const TDTTsDataTemplate< D > &iTsData);

      /*
       * operator =
       */
      TDTTsDataTemplate< D >& operator=(const TDTTsDataTemplate< D > &iTsData);
      /*
       * vector or point ordered by time
       * we use map, so we can retrieve the points in the right order
       */
      map<double,D> cTimeserie;

    private:

  }
  // end class template

/*
 * function definitions
 */
/*
 * constructor, no argument
 */
template< typedef D >
  TDTTsDataTemplate< D >::TDTTsDataTemplate()
  {
   
  }

/*
 * constructor with timeserie map
 */
template< typedef D >
  TDTTsDataTemplate< D >::TDTTsDataTemplate(map<double,D> iTimeserie)
  {
    // transfer values from input timeseries 
    cTimeseries = iTimeserie;

  }

/*
 * deconstructor
 */
template< typedef D >
  TDTTsDataTemplate< D >::~TDTTsDataTemplate()
  {
    cTimeserie.clear;
  }

/*
 * insert single element in timeserie
 */
template< typedef D >
  TDTTsDataTemplate< D >::Insert(double t, D v)
  {
    cTimeserie[t] = v;
  }

/*
 * transfer all map pair in a vector of points
 */
template< typedef D >
  TDTTsDataTemplate< D >::GetVector()
  {
    // definition of single point
    TDTPoint<D> lPoint;
    // result vector
    vector<TDTPoint<d>> lTs;
    // loop on all the values in the map
    for( map<double,D>::const_iterator lIterTs = cTimeserie.begin(); lIterTs != cTimeserie.end(); ++lIterTs ) {
      // transfer time and value in point structure
      lPoint = { lIterTs->first, lIterTs->second };
      // append point at the end of the vector
      lTs.push_back(lPoint);
    }
    // return vector
    return lTs;
  }

/*
 * return single value given time
 */
template< typedef D >
  TDTTsDataTemplate< D >::GetPoint(double t)
  {
    return cTimeserie[t];
  }

/*
 * operator +
 */
template< typedef D >
  TDTTsDataTemplate< D >::operator+(const TDTsDataTemplate< D > iTsData)
  {
    // insert all the element of timeserie in iData to our internal map
    cTimeserie.insert(iTsData.cTimeserie.begin(),iTsData.cTimeserie.end());
    // return us
    return *this;
  }

/*
 * operator =
 */
template< typedef D >
  TDTTsDataTemplate< D >::operator=(const TDTTsDataTemplate< D > iTsData)
  {
    // remove all the item in our map
    cTImeserie.clear();
    // transfer all items of iData map to our map
    cTimeserie=iTsData.cTimeserie;
    // return 
    return *this;
  }
#endif
