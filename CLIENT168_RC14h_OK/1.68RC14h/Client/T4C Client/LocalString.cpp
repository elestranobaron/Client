#include "pch.h"
#include <windows.h>
#include "LocalString.h"
#include "Global.h"
#include "PowerDebug.h"
#include "TFCPlayer.h"
#include <string>


// Global var.
LocalString g_LocalString;

//*********************************************************************************
LocalString::LocalString( void )
/**********************************************************************************
 * Constructor
 */
{
// Constructor
	dwStringNb   = 0;
	InitializeCriticalSection(&csLanguageLock);
	bCreated = false;
}
		
//*********************************************************************************
LocalString::~LocalString( void )
/**********************************************************************************
 * Destructor
 */
{
// Destructor
	DeleteCriticalSection(&csLanguageLock);
	Release(); 
}

//*********************************************************************************
void LocalString::Create(  int dwLanguage )
/**********************************************************************************
 * Open the Local String file (currently a .txt) and copy all the string into memory.
 */
{
// Open Local String file and put all string into memory.
    LanguageString.resize( 2000 );
    bHotKey.resize( 2000 );

    UINT i;
    for( i = 0; i < LanguageString.size(); i++ ){
        bHotKey[ i ] = 0;
        LanguageString[ i ] = 0;
    }

	LoadAllStrings(dwLanguage);

	bCreated = true;
}

//*********************************************************************************
void LocalString::Release( void )
/**********************************************************************************
 * Close the Local String file and release all the memory.
 */
{
// Close the Local String file.
   //if (LanguageFile) {
   //	fclose(LanguageFile);
   //  LanguageFile = NULL;
   //}
   for (unsigned int i = 0; i < dwStringNb; i++) {
      delete LanguageString[i];
   }
   dwStringNb = NULL;
}

//*********************************************************************************
char *LocalString::operator []
/**********************************************************************************
 * Get a string from an ID
 */
(
 unsigned int l                 // ID of the string
)
//*********************************************************************************
{
// Return a String
   if (bCreated) {
      if (l <= dwStringNb) {
	     return LanguageString[l-1];
	  } else {
		 return LanguageString[dwStringNb-1];
	  }
   } else {
	   return "Localized String not Initialized.";
   }
}


#include "EncRandom.h"
#define TABLE_SIZE 7823
namespace t4csvr
{
   class RandomTable{ 
    public:
        RandomTable()
        {
           RandomTableSize = TABLE_SIZE;
            rnd.SetSeed( 11677 );
            int i;
            for( i = 0; i < RandomTableSize; i++ )
            {
                lpRandomTable[ i ] = rnd( 0, 255 );
            }
        }

        char GetChar( long nPos )
        {
            int dwVal = nPos % RandomTableSize;
            return lpRandomTable[ dwVal ];
        }
    
    private:
        int RandomTableSize;
        char  lpRandomTable[ TABLE_SIZE ];
        t4csvr::Random rnd;
    };
}

//*********************************************************************************
void LocalString::LoadAllStrings(  int dwLanguage )
/**********************************************************************************
* Load all the string from the Local String file into memory.
*/
{
   dwStringNb = 0;
   
   char buf[ 256 ];
   char lngFile[ _MAX_PATH ];

   if(dwLanguage == 0)
      sprintf( lngFile, "English.elng");
   else if(dwLanguage == 1)
      sprintf( lngFile, "French.elng");
   else
      sprintf( lngFile, "English.elng");
   
   FILE *f = fopen( lngFile, "rb" );
   
   // If we couldn't load the language file
   if( f == NULL )
      f = fopen( "English.elng", "rb" );
   if (f == NULL) 
   {
      LanguageString[0] = new char [40];
      strcpy(LanguageString[0], "Cannot open language file: English.elng");
      dwStringNb = 1;
      return;
   }
   
   fseek(f, 0, SEEK_END);
   int sizeBuf = ftell(f);
   char *fulBuf = new char [sizeBuf];
   fseek(f, 0, SEEK_SET);
   fread(fulBuf, 1, sizeBuf, f);  
   fclose(f);
   int iCur = 0;
    
   // Decryption 
   t4csvr::RandomTable cRandomTable;
   for (int i = 0; i < sizeBuf; i++) {
      fulBuf[i] = cRandomTable.GetChar(i + 1 ) ^ (char)fulBuf[i];
   }

   
   DWORD lineCount = 0;
   int ch = fulBuf[iCur++];
   if( iCur >= sizeBuf )
   {
      OutputDebugString( "\r\nEmpty file " );
      OutputDebugString( lngFile );
      if(fulBuf)
         delete []fulBuf;
      return;
   }
   
   do{
      // If a string ID was found.
      if( ch == '[' )
      {
         DWORD id = 0;
         
         // Get the file Id
         while( 1 )
         {
            ch = fulBuf[iCur++];
            if( ch == ']' )
            {
               break;
            }else if( iCur >= sizeBuf )
            {
               OutputDebugString( "\r\nEnd of file reached querying Id in file " );
               OutputDebugString( lngFile );
               if(fulBuf)
                  delete []fulBuf;
               return;
            }
            
            if( !isdigit( ch ) )
            {
               OutputDebugString( "\r\nUndefined character in ID on line " );
               OutputDebugString( itoa( lineCount, buf, 10 ) );
               if(fulBuf)
                  delete []fulBuf;
               return;
            }
            else
            {
               id *= 10;
               id += ch - '0';
            }
         }
         if( id == 0 )
         {
            OutputDebugString( "\r\nInvalid ID 0 on line " );
            OutputDebugString( itoa( lineCount, buf, 10 ) );
            if(fulBuf)
               delete []fulBuf;
            return;
         }
         
         // While we didn't find another ID.
         std::string str;
         do
         {                
            // Search for an opening quote
            do
            {
               ch = fulBuf[iCur++];
               if( ch == '[' )
               {
                  break;
               }
               if( iCur >= sizeBuf )
               {
                  break;
               }
               if( ch != '\r' && ch != '\n' && ch != '\t' && ch != ' ' && ch != '\"' )
               {
                  OutputDebugString( "\r\nInvalid character found looking for string on line " );
                  OutputDebugString( itoa( lineCount, buf, 10 ) );
                  if(fulBuf)
                     delete []fulBuf;
                  return;
               }
               if( ch == '\r' )
               {
                  lineCount++;
               }
            }while( iCur < sizeBuf && ch != '\"' );
            
            if( ch == '[' )
            {
               break;
            }
            
            // Get the string.
            ch = fulBuf[iCur++];
            while( iCur < sizeBuf && ch != '\"' )
            {
               bool getnext = true;
               // Conversions
               switch( ch )
               {
               case '\\': str += '\"'; break;
               case '_':
                  ch = fulBuf[iCur++];
                  bHotKey[ id ] = ch;
                  str += ch;
                  break;
               case '<': 
                  ch = fulBuf[iCur++];
                  if( ch == '>' ){
                     getnext = true;
                     str += "\r\n";
                  }
                  else
                  {
                     str += '<';
                     getnext = false;
                  }
                  break;
               case '\n':
               case '\r':
                  OutputDebugString( "\r\nEnd-of-line character found parsing string on line " );
                  OutputDebugString( itoa( lineCount, buf, 10 ) );
                  if(fulBuf)
                     delete []fulBuf;
                  return;
               default:
                  str += ch;
                  break;
               }
               
               if( getnext )
               {
                  ch = fulBuf[iCur++];
               }
            };
         }while( ch != '[' && iCur < sizeBuf );
         
         LanguageString[ id - 1 ] = new char [ str.size() + 1 ];
         strcpy( LanguageString[ id - 1 ], str.c_str() );
         
         if( dwStringNb < id ){
            dwStringNb = id;
         }
         
         //OutputDebugString( "\r\nString " );
         //OutputDebugString( itoa( id, buf, 10 ) );
         //OutputDebugString( " is: " );
         //OutputDebugString( LanguageString[ id - 1 ] );
         
        }
        else
        {
           if(iCur < sizeBuf)
           {
              ch = fulBuf[iCur];
              iCur++;
           }

        }
    }while( iCur < sizeBuf  );
    if(fulBuf)
      delete []fulBuf;
}



//*********************************************************************************
char LocalString::GetHotKey
/**********************************************************************************
 * Get the hotkey of a string from a string ID.
 * 
 * @REMARK A hotkey is a letter in the string that begins with a _ like in
 * _Example, E is the hotkey.
 */
(
 int l                          // ID of the string
)
//*********************************************************************************
{
   if (bCreated) {
      if ((DWORD)l <= dwStringNb) {
        return bHotKey[l];
	  } else {
        return bHotKey[dwStringNb];
	  }
   } else {
	   return 'L';
   }
}

void LocalString::CannotParse(void) {
   Release();
   LanguageString[0] = new char [250];
   sprintf(LanguageString[0], "Error in parsing file: %s.elng", Player.szLanguage);
   dwStringNb = 1;
}