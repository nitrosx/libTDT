#
#include "TDTNotes.h"

/*
 * class constants
 */
TDTNotes::NoteDelimiter  = "\[USERNOTEDELIMITER\]";
TDTNotes::StoreDelimiter = "\[STOREHDRITEM\]";
TDTNotes::RegExpProperty = "NAME=(.*?);.*?VALUE=(.*?);";

/*
 * class constructors
 */
TDTNotes::TDTNotes()
{
}
TDTNotes::TDTNotes(std::string lStore)
{
  this->Extract(lStore);
}

/*
 * destructor
 */
TDTNotes::~TDTNotes()
{
}

/*
 * Clear all properties stored in the map
 */
TDTNotes::ClearAll()
{
  this->cProperties.clear();
}

/*
 * given the string, it extracts all the properties and populate the map
 */
TDTNotes::Extract(std::string lStore)
{
  // set up regex to split string in properties
  std::regex lPropRE(TDTNotes::RegExProperty);
  // regex match results
  std::smatch lPropREM;

  // find properties and values
  if ( std::regex_match(lStore, lPropREM, lPropRE) ) {
    // check if we have two pieces matched by the regex
    if 

  // iterator, split original string at pattern provided by regular expression
  std::regex_iterator<std::string::iterator> lIterProp ( lStore.begin(), lStore.end(), lStoreRE, 1 );
  // iterator end
  std::regex_iterator<std::string::iterator> lIterEnd;
  // loop on every match
  while (lIterProp != lIterEnd ) {
    // extract regex match element
    std::regex_match lMatch  = *lIterProp;
    // check if the length of the match element is correct
    // it has to be 2, where 0 is the all string, 1 is the property name and 2 is the value
    if ( lMatch.size() == 2 ) {
      // extract property name
      std::sub_match lProp = lMatch[1];
      // extract property value
      std::sub_match lValue = lMatch[2];
      // insert property in map 
      this->cProperties.insert(lProp.str(),lValue.str());
    }
  }
  return 1;
}

/*
 * set property value
 * if the property is new, it will be created
 */
TDTNotes::SetProp(std::string iProp, std:string iValue) 
{
  // insert property value
  this->cProperties[lProp] = lValue
  return 1;
}

/*
 * return 1 if the property exists
 */
TDTNotes::Exists(std::string iProp)
{
  // find channel within event
  std::unordered_map<string,string>::const_iterator lPropFound = cProperties.find (iProp);
  // check if we found it
  return ( lPropFound != cProperties.end() );
}

/*
 * get value of the property
 */
TDTNotes::GetProp(std::string iProp)
{
  return this->cProperties[iProp];
}

/*
 * return value of property StoreName, aka event code
 */
TDTNotes::GetCode()
{
  return this->cProperties["StoreName"];
}

/*
 * operator array index, same as GetProp
 */
TDTNotes::operator[](string iProp)
{
  return this->cProperties[iProp];
}

