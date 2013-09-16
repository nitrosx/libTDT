#include "TDTTank.h"

/*
 * class constants
 */
TDTTank::NHeaders = 200000;

/*
 * constructors
 */
TDTTank::TDTTank()
  : cRoot(""), cTevFilePath(""), cTsqFilePath(""), cTbkFilePath(""), cTdxFilePath(""), cConditions(NULL)
{

}
TDTTank::TDTTank(string lRoot)
  : cConditions(NULL)
{
  // set root path and files names
  SetRoot(lRoot);
}
TDTTank::TDTTank(string lTevFile, string lTsqFile, string lTbkFile, string lTdxFile = "")
  : cRoot(""), cConditions(NULL)
{
  SetFiles(lTevFile, lTsqFile, lTbkFile, lTdxFile);
}
TDTTank::TDTTank(TDTData::tdtFiles* lFiles)
  : cRoot(""), cConditions(NULL)
{
  SetFiles(lFIles);
}
TDTTank::TDTTank(string lRoot,TDTConditions* lConditions)
{
  // set root path and files names
  SetRoot(lRoot);
  // save pointer to conditions
  this.cConditions = lConditions;
}
TDTTank::TDTTank(TDTData::tdtFiles* lFiles,TDTConditions* lConditions)
  : root("")
{
  // set files names
  SetFiles(lFIles);
  // save pointer to conditions
  this.cConditions = lConditions;
}


// destructor
TDTTank::~TDTTank()
{
  // release all the object
  this->ClearAll();
}

/* 
 * clear all the objectes created and all the data loaded
 */
TDTTank::ClearAll()
{
  // release all events objects
  // loop on all the events object
  for ( std::unordered_map<TDTData::tdtChannel,TDTEvent*>::const_iterator lCodeIter = cEvents.begin();
          lCodeIter != cEvents.end();
          ++lCodeIter ) {
    // get pointer to event
    TDTEvent* lEvent = lCodeIter.second;
    // release object
    delete lEvent;
  }
  
  // release all notes objects
  // loop on all the notes
  for ( std::unordered_map<TDTData::tdtChannel,TDTNotes*>::const_iterator lNotesIter = cNotes.begin();
          lNotesIter != cNotes.end();
          ++lNotesIter ) {
    // push pointer to TDTNotes
    TDTNotes* lNotes = lNotesIter.second;
    // release object
    delete lNotes;
  }
  return 1;
}

/* 
 * root property
 * setter
 */
void TDTTank::SetRoot(string lRoot)
{
  // copy the string passed in class property root
  cRoot = lRoot;
  // assigns all the files names too
  cTevFilePath = cRoot + ".tev";
  cTsqFilePath = cRoot + ".tsq";
  cTbkFilePath = cRoot + ".Tbk";
  cTdxFilePath = cRoot + ".Tdx";

  return;
}
/*
 * getter
 */
string TDTTank::GetRoot()
{
  return cRoot;
}


/*
 * files properties
 * setter
 */
void TDTTank::SetTevFile(string lTevFile)
{
  // copy path passed to class property
  cTevFilePath = lTevFile;
  return;
}
void TDTTank::SetTsqFile(string lTsqFile)
{
  // copy path passed to class property
  cTsqFilePath = lTsqFile;
  return;
}
void TDTTank::SetTbkFile(string lTbkFile)
{
  // copy path passed to class property
  cTbkFilePath = lTbkFile;
  return;
}
void TDTTank::SetTdxFile(string lTdxFile)
{
  // copy path passed to class property
  cTdxFilePath = lTdxFile;
  return;
}
void TDTTank::SetFiles(string lTevFile, string lTsqFile, string lTbkFile, string lTdxFile = "")
{
  // copy paths passed to class properties
  cTevFilePath = lTevFile;
  cTsqFilePath = lTsqFile;
  cTbkFilePath = lTbkFile;
  cTdxFilePath = lTdxFile;
  // initialize root to empty string because is not used
  cRoot = "";
  return;
}
void TDTTank::SetFiles(const TDTData::tdtFiles* lFiles)
{
  // copy paths passed to class properties
  cTevFilePath = lFiles->tev;
  cTsqFilePath = lFiles->tsq;
  cTbkFilePath = lFiles->tbk;
  cTdxFilePath = lFiles->tdx;
  // initialize root to empty string because is not used
  cRoot = "";
  return;
}

/*
 * getter
 */
string TDTTank::GetTevFile()
{
  return cTevFilePath;
}
string TDTTank::GetTsqFile()
{
  return cTsqFilePath;
}
string TDTTank::GetTbkFile()
{
  return cTbkFilePath;
}
string TDTTank::GetTdxFile()
{
  return cTdxFilePath;
}
TDTData::tdtFiles* TDTTank::GetFiles()
{
  // instantiate object
  TDTData::tdtFiles* files = new TDTData::tdtFiles;
  // populate file fields
  files->tev = cTevFilePath;
  files->tsq = cTsqFilePath;
  files->tbk = cTbkFilePath;
  files->tdx = cTdxFilePath;
  // return pointer to structure
  return files;
}

/*
 * conditions setter
 */
void TDTTank::SetConditions(TDTConditions* lConditions)
{
  cConditions = lConditions;
}
/* 
 * conditions getter
 */
TDTConditions* TDTTank::GetConditions()
{
  return cConditions;
}

/*
 * return the pointer to the event element from the list of events
 * if it is a new one, instantiate the object and insert it in the list
 */
TDTTank::GetEvent(lCode)
{
  // define pointer to channel
  TDTEvent* lEvent;
  // check if we already have the event in the list
  // define an iterator of the unorderd_map that we use to store pointers to TDTEvent objects
  std::unordered_map<TDTData::tdtCode,TDTEvent*>::const_iterator found = cEvents.find(lCode);
  // check if we found it
  if ( found == cEvents.end() ) {
    // new channel
    lEvent = new TDTEvent(lCode);
    // insert in list of channels
    cChannels.insert( { lCode, lEvent } );
  } else {
    // channel already in the list
    // found->second = pointer to channel instance
    lEvent = found->second;
  }
  return lEvent;
}
TDTTank::GetEvent(lHeader)
{
  // define pointer to channel
  TDTEvent* lEvent;
  // check if we already have the event in the list
  // define an iterator of the unorderd_map that we use to store pointers to TDTEvent objects
  std::unordered_map<TDTData::tdtCode,TDTEvent*>::const_iterator lEventFound = cEvents.find(lHeader.code);
  // check if we found it
  if ( lEventFound == cEvents.end() ) {
    // new channel
    lEvent = new TDTEvent(lHeader);
    // insert in list of channels
    cChannels.insert( { lCode, lEvent } );
  } else {
    // channel already in the list
    // found->second = pointer to channel instance
    lEvent = lEventFound.second;
  }
  return lEvent;
}

/*
 * Read all headers tsq file according to conditions specified if any
 */
TDTTank::ReadHeaders()
{
  // open tsq file
  FILE* lFtsq = fopen(this.cTsqFilePath,"rb");
  // seek position 0
  fseek(lFtsq,0,SEEK_SET);

  // allocate space for raw data
  // NHeaders * the size of the header
  TDTData::tsqHeader* lBuffer = (tsqEventHeader*)malloc(TDTTank::NHeaders*sizeof(TDTData::tsqHeader));
  if ( lBuffer == NULL) {
    return 0;
  }

  // loop and read NHeaders headers until eof
  while( !feof(lFtsq)) {
    // read NHeaders headers in the buffer
    // LNHR = Number of Headers Read
    int lNHR = fread(buffer, sizeof(TDTData::tsqHeader), TDTData::NHeaders, lFtsq);
    // loop on all the headers in the buffer
    for( int lIndex = 0; lIndex < lNHR; lIndex++) {
      // copy current header
      tsqHeader& lHeader = lBuffer[lIndex];
      // check if we have any conditions to be tested
      // if so test code and channel
      if ( cConditions == NULL ||  
           ( cConditions == (TDTData::tdtCode)lHeader.code &&
             cConditions == (TDTData::tdtChannel)lHeader.channel ) ) {
        // no conditions or the header matches the conditions
        // get pointer to correct event
        TDTEvent* lEvent = this.GetEvent(lHeader);
        // add header to event
        lEvent->AddHeader(lHeader);
      }
    }
  }
  // close file
  fclose(lFtsq);
  // return true
  return 1;
}

/*
 * Read event headers from tsq file
 */
TDTTank::ReadHeaders(iCode)
{
  // transfer code to conditions
  if ( cConditions == NULL ) {
    // no conditions class
    // instantiate a new one
    cConditions = new TDTConditions(iCode);
  }
  // reset all conditions
  cConditions->ClearAll();
  // insert event code
  cConditions->AddCode(iCode);

  // call ReadHeaders
  return this.ReadHeaders();
}

/*
 * Read event and channel headers from tsq file
 */
TDTTank::ReadHeaders(iCode,iChannel)
{
  // transfer code to conditions
  if ( cConditions == NULL ) {
    // no conditions class
    // instantiate a new one
    cConditions = new TDTConditions(iCode);
  }
  // reset all conditions
  cConditions->ClearAll();
  // insert event code
  cConditions->AddCode(iCode);
  // insert channel
  cConditions->AddChannel(iChannel);

  // call ReadHeaders
  return this->ReadHeaders();
}

/*
 * Get headers info for all the events
 */
TDTTank::GetHeaders()
{
  // instantiate vector of pointer to TDTEvents
  vector<TDTEvent *> lHeaders = new vector<TDTHeader*>();
  // loop on all the events
  for ( std::unordered_map<TDTData:tdtCode,TDTEvent*>::iterator lCodeIter = cEvents.begin(); 
        lCodeIter != cEvents.end(); 
        ++lCodeIter ) { 

    // get pointer to event
    TDTEvent* lEvent = lCodeIter->second;
    // loop on every channel
    for (std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelIter = lEvent->cChannels.begin();
         lChannelIter != lEvent->cChannels.end();
         ++lChannelIter ) {
      // resize output vector
      lEvent->resize(lEvent->size()+(*lChannelIter)->size);
      // insert pointer to headers in result vector
      lEvent->insert(lEvent->end(),lChannelIter->second->begin(),lChannelIter->second->end());
    }
  }
  return lHeaders;
}
/*
 * Get headers info for the event requested
 */
TDTTank::GetHeaders(TDTData:tdtCode iCode)
{
  // define return variable
  vector<TDTHeader*> lHeaders = NULL;
  // find the event by the code
  std::unordered_map<TDTData::tdtCode,TDTEvent*>::const_iterator lCodeFound = cEvents.find (iCode);
  // check if we found it
  if ( lCodeFound != cEvents.end() ) {
    // code found
    // get pointer to event
    TDTEvent* lEvent = lCodeFound->second;
    // instantiate return vector
    lHeaders = new vector<TDTHeader*>();
    // loop on every channel
    for (std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelIter = lEvent->cChannels.begin();
         lChannelIter != lEvent->cChannels.end();
         ++lChannelIter ) {
      // resize output vector
      lEvent->resize(lEvent->size()+(*lChannelIter)->size);
      // insert
      lEvent->insert(lEvent->end(),lChannelIter->second->begin(),lChannelIter->second->end());
    }
  }
  return lHeaders;
}
/*
 * Get headers info for the event code and channel requested
 */
TDTTank::GetHeaders(TDTData::tdtCode iCode, TDTData::tdtChannel iChannel)
{
  // define return variable
  vector<TDTHeader*> lHeaders = NULL;
  // find the event by the code
  std::unordered_map<TDTData::tdtCode,TDTEvent*>::const_iterator lCodeFound = cEvents.find (iCode);
  // check if we found it
  if ( lCodeFound != cEvents.end() ) {
    // code found
    // get pointer to event
    TDTEvent* lEvent = lCodeFound->second;
    // find channel within event
    std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelFound = lEvents->cChannels.find (iChannel);
    // check if we found it
    if ( lChannelFound != lEvents->cChannels.end() ) {
      // channel found
      // get pointer to channel
      TDTChannel* lChannel = lChannelFound->second;
      // transfer pointer to headers to return vector
      lHeaders = new vector<TDTHeader*>(lChannel->cHeaders.begin(),lChannel->cHeaders.end());
    }
  }
  return lHeaders;
}


/*
 * return the list of events
 */
TDTTank::GetEventsList()
{
  // initialize result vector
  vector<TDTData::tdtCode>* lEvents = new vector<TDTData::tdtCode>(cEvents.size());
  // loop on all the events
  for ( std::unordered_map<TDTData:tdtCode,TDTEvent*>::iterator lCodeIter = cEvents.begin();
        lCodeIter != cEvents.end();
        ++lCodeIter ) {

    // insert event code in vector
    lEvents->push_back(lCodeIter->first);
  }
  // return vector
  return lEvents;
}
/*
 * return the list of channels organized by events
 */
TDTTank::GetChannelsList()
{
  // initialize output map
  unordered_map<TDTData::tdtCode,vector<TDTData::tdtChannel>>* lList = new unordered_map<TDTData::tdtCode,vector<TDTData::tdtChannel>>();
  // loop on all the events
  for ( std::unordered_map<TDTData:tdtCode,TDTEvent*>::iterator lCodeIter = cEvents.begin();
        lCodeIter != cEvents.end();
        ++lCodeIter ) {
 
    // get pointer to event
    TDTEvent* lEvent = lCodeIter->second;
    // loop on every channel
    for ( std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelIter = lEvent->cChannels.begin();
          lChannelIter != lEvent->cChannels.end();
          ++lChannelIter ) {
      // insert new channel for this event
      lList[lCodeIter->first].push_back(lChannelIter->first);
    }
  }
  return lList;
}
/*
 * return the list of channels for the event requested
 */
TDTTank::GetChannelsList(TDTData::tdtCode iCode)
{
  // define return vector
  vector<TDTData::tdtChannel>* lChannels = NULL;
  // find the event by the code
  std::unordered_map<TDTData::tdtCode,TDTEvent*>::const_iterator lCodeFound = cEvents.find (iCode);
  // check if we found it
  if ( lCodeFound != cEvents.end() ) {
    // code found
    // get pointer to event
    TDTEvent* lEvent = lCodeFound->second;
    // instantiate return vector
    lChannels = new vector<TDTData::tdtChannel>(lEvent->cCHannels.size());
    // loop on every channel
    for ( std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelIter = lEvent->cChannels.begin();
          lChannelIter != lEvent->cChannels.end();
          ++lChannelIter ) {
      lChannels->push_back(lChannelIter->first);
    }
  }
  return lChannels;
}

/*
 * Read data for all the channels from tev file for the event specified
 */
TDTTank::ReadData(TDTank::tdtCode iCode)
{
  // find the event by the code
  std::unordered_map<TDTData::tdtCode,TDTEvent*>::const_iterator lCodeFound = cEvents.find (iCode);
  // check if we found it
  if ( lCodeFound != cEvents.end() ) {
    // code found
    // get pointer to event
    TDTEvent* lEvent = lCodeFound->second;
    // loop on every channel
    for ( std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelIter = lEvent->cChannels.begin();
          lChannelIter != lEvent->cChannels.end();
          ++lChannelIter ) {
      // read data on each channel
      lChannelIter->second->ReadData();
    }
  }
  return 1;
}
/*
 * Read data from tev file for the given event and channels
 */
TDTTank::ReadData(TDTTank::tdtCode iCode,vector<TDTTank::tdtChannel> iChannels)
{
  // find the event by the code
  std::unordered_map<TDTData::tdtCode,TDTEvent*>::const_iterator lCodeFound = cEvents.find (iCode);
  // check if we found it
  if ( lCodeFound != cEvents.end() ) {
    // code found
    // get pointer to event
    TDTEvent* lEvent = lCodeFound->second;
    // find channel within event
    std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelFound = lEvents->cChannels.find (iChannel);
    // check if we found it
    if ( lChannelFound != lEvents->cChannels.end() ) {
      // channel found
      // read data for the channel
      lChannelFound->second->ReadData();
    }
  }
  return 1;
}
/*
 * Read data from tev file according to the list of headers given
 * Previously read headers and data are going to be deleted and 
 * resources released
 * the all structure is going to be rebuilt and new object instantiated
 */
TDTTank::ReadData(const vector<tdtHeader> iHeaders)
{
  // remove all the object created before
  this->ClearAll();
  // loop on the headers given
  // instantiates event and channels
  for( int lIndex = 0; lIndex < iHeaders.size(); lIndex++) {
    // copy current header
    tsqHeader& lHeader = iHeaders[lIndex];
    // check if we have any conditions to be tested
    // if so test code and channel
    if ( cConditions == NULL ||  
         ( cConditions == (TDTData::tdtCode)lHeader.code &&
           cConditions == (TDTData::tdtChannel)lHeader.channel ) ) {
      // no conditions or the header matches the conditions
      // get pointer to correct event
      TDTEvent* lEvent = this.GetEvent(lHeader);
      // add header to event
      lEvent->AddHeader(lHeader);
    }
  } 
  // loop on all the event found
  for ( std::unordered_map<TDTData::tdtChannel,TDTEvent*>::const_iterator lCodeIter = cEvents.begin();
          lCodeIter != cEvents.end();
          ++lCodeIter ) {
    // get pointer to event
    TDTEvent* lEvent = lCodeIter->second;
    // loop on every channels for this event
    for ( std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelIter = lEvent->cChannels.begin();
          lChannelIter != lEvent->cChannels.end();
          ++lChannelIter ) {
      // read data on each channel
      lChannelIter->second->ReadData();
    }
  }
  return 1;
}

/*
 * Return timeseries data for specific event and channel
 */
TDTTank::GetData(TDTData::tdtCode lCode,TDTTdata::tdtChannel lChannel)
{
  // find the event by the code
  std::unordered_map<TDTData::tdtCode,TDTEvent*>::const_iterator lCodeFound = cEvents.find (iCode);
  // check if we found it
  if ( lCodeFound != cEvents.end() ) {
    // code found
    // get pointer to event
    TDTEvent* lEvent = lCodeFound->second;
    // find channel within event
    std::unordered_map<TDTData::tdtChannel,TDTChannel*>::const_iterator lChannelFound = lEvents->cChannels.find (iChannel);
    // check if we found it
    if ( lChannelFound != lEvents->cChannels.end() ) {
      // channel found
      // read data for the channel
      return lChannelFound->second->GetData();
    }
  }
  // event,channel not found
  // return null pointer
  return 0X0;
}

/*
 * Read all notes form tbk file
 */
TDTTank::ReadNotes()
{
  // open tbk file
  FILE* lFtbk = fopen(this.cTbkFilePath,"rb");
  // set the file pointer to end of file
  fseek(lFtbk, 0, SEEK_END );
  // get the file size
  int lSize = ftell( lFtbk );
  // return the file pointer to begin of file if you want to read it
  // seek position 0
  fseek(lFtbk,0,SEEK_SET);

  // allocate space for raw data
  // NHeaders * the size of the header
  char* lBuffer = (tsqEventHeader*)malloc(lSize);
  if ( lBuffer == NULL) {
    return 0;
  }

  // read all tbk file in
  // lBytes = # bytes read
  int lBytes = fread(lBuffer, lSize, char, lFtbk);

  // close file
  fclose(lFtsq);

  // notes for the channels are in the second section of the notes file
  // search for the second occurence of the notes delimiter
  char* lBegin = strstr(lBuffer,TDTNotes::NoteDelimiter); // first occurence
  lBegin = strstr(lBegin,TDTNotes::NoteDelimiter);        // second occurence
  lBegin += TDTNotes::NoteDelimiter.str();
  // find end of the section
  char* lEnd = strstr(lBegin,TDTNotes::NoteDelimiter);  // third occurence

  // transfer relevant notes section in a string
  std::string lNotes = new string(lBegin, (size_t)( lEnd - lBegin ));

  // release memory with file content
  free(lBuffer);

  // set up regex to split string in different event stores
  std::regex lStoreRE(TDTNotes::StoreDelimiter);
  // iterator, split original string at pattern provided by regular expression
  std::regex_token_iterator<std::string::iterator> lIterStore ( lNotes.begin(), lNotes.end(), lStoreRE, -1 );
  // iterator end
  std::regex_token_iterator<std::string::iterator> lIterEnd;
  // loop on every stor found
  while ( lIterStore != lIterEnd ) {
    // instantiate a new Notes element with the info extracted
    TDTNotes* lStore = new TDTNotes(*lIterStore);
    // check if we have any conditions to be tested
    // if so test code versus store
    // it's easy to create the store object and delete after, because store object makes it easy to check the store value
    if ( cConditions == NULL ||  
         cConditions == (TDTData::tdtCode)lStore->GetCode() ) {
      // insert object in unordered map
      cNotes.insert( { lStores->GetCode(), lStore } );
    } else {
      // delete object
      delete lStore;
    }
    // next element
    lIterStore++;
  }

  // return true
  return 1;
}
/*
 * Read notes for the requested event
 */
TDTTank::ReadNotes(TDTData::tdtCode iCode)
{
  // transfer code to conditions
  if ( cConditions == NULL ) {
    // no conditions class
    // instantiate a new one
    cConditions = new TDTConditions(iCode);
  }
  // reset all conditions
  cConditions->ClearAll();
  // insert event code
  cConditions->AddCode(iCode);

  // now read notes
  this->ReadNotes();
}

/*
 * Return all the notes loaded from the tbk file
 */
TDTTank::GetNotes()
{
  // instantiate return vector
  std::vector<TDTNotes*>* lNotes = new std::vector<TDTNotes*>;
  // reserve the right size
  lNotes->reserve(this->cNotes.size());
  // loop on all the notes
  for ( std::unordered_map<TDTData::tdtChannel,TDTNotes*>::const_iterator lNotesIter = cNotes.begin();
          lNotesIter != cNotes.end();
          ++lNotesIter ) {
    // push pointer to TDTNotes
    lNotes->push_back(lNotesIter.second());
  }
  // return result vector
  return lNotes
}
/*
 * Return the notes just for the event requested
 */
TDTTank::GetNotes(iCode)
{
  // find channel within event
  std::unordered_map<TDTData::tdtChannel,TDTNotes*>::const_iterator lNotesFound = cNotes.find (iCode);
  // check if we found it
  if ( lNotesFound != cNotes.end() ) {
    // notes found
    // read data for the channel
    return lNotesFound.second;
  }
  // not found
  return 0X0;
}

