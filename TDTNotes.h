#ifndef TDTNotes
#define TDTNotes

#include <std::string>


class TDTNotes {

  public:

    /*
     * constructors
     */
    TDTNotes();
    TDTNotes(std::string iStore);

    /*
     * distructor
     */
    ~TDTnotes();

    /* 
     * clear all properties in this notes
     */
    bool ClearAll();

    /*
     * extract info from string and populate 
     */
    bool Extract(std::string iStore);

    /*
     * set single pair property/value 
     */
    bool SetProp(std::string iProp, std::string iValue);

    /*
     * check if property exists
     */
    bool Exists(std:string iProp);

    /*
     * return value of the single property
     */
    std::string GetProp(std::string iProp);

    /*
     * return code of this store
     */
    std::string GetCode();

    /*
     * array subscript operator to retrieve properties value
     */
    std::string operator[](std::string iProp);

    /*
     * data structure containing pairs key/value
     */
    std::unordered_map<std::string,std::string> cProperties;

    /*
     * constants
     */
    static std::string NoteDelimiter;
    static std::string StoreDelimiter;
    static std::string RegExpProperty;

  protected:

  private:

}
#endif
