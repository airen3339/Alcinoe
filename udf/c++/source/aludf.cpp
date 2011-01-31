#include "stdafx.h"
#include <stdlib.h>
#include "ibase.h"
#include "ib_util.h"

#define EXPORT extern "C" __declspec(dllexport)

//*******************************************************
// Maps a UTF8 string to a UTF-16 (wide character) string
static wchar_t *aludf_utf82WideChar(char *str) {
  
  //if str is null return null
  if (!str) {	  
    return NULL;
  } 

  //declaration
  wchar_t *res;
  int len;

  //calculate the len
  len = MultiByteToWideChar(CP_UTF8,                 // __in   UINT CodePage,
                            MB_ERR_INVALID_CHARS,    // __in   DWORD dwFlags, For UTF-8, dwFlags must be set to either 0 or MB_ERR_INVALID_CHARS. Otherwise, the function fails with ERROR_INVALID_FLAGS
                            str,                     // __in   LPCSTR lpMultiByteStr, Pointer to the character string to convert. 
                            -1,                      // __in   int cbMultiByte, Size, in bytes, of the string indicated by the lpMultiByteStr parameter. Alternatively, this parameter can be set to -1 if the string is null-terminated
                            NULL,                    // __out  LPWSTR lpWideCharStr, Optional. Pointer to a buffer that receives the converted string.
                            0);                      // __in   int cchWideChar Size, in characters, of the buffer indicated by lpWideCharStr. If this value is 0, the function returns the required buffer size, in characters, including any terminating null character, and makes no use of the lpWideCharStr buffer.

  // If some error len = 0
  if (len <= 0) {
	  return NULL;
  }

  //get the res
  res = (wchar_t *)malloc((len) * sizeof(wchar_t));
  MultiByteToWideChar(CP_UTF8,                // __in   UINT CodePage,
                      MB_ERR_INVALID_CHARS,   // __in   DWORD dwFlags,
                      str,                    // __in   LPCSTR lpMultiByteStr
                      -1,                     // __in   int cbMultiByte, Size
                      res,                    // __out  LPWSTR lpWideCharStr
                      len);                   // __in   int cchWideChar
  
  //return res
  return res;
  
}

//******************************************************************
// Maps a UTF-16 (wide character) string to a UTF8 character string. 
// The returned string is zero terminated and the pointer should
// be freed by the database (declare UDF with FREE_IT).
static char *aludf_WideChar2utf8(wchar_t *str, int do_ib_util_malloc) {

  //if str is null return null
  if (!str) {	  
    return NULL;
  } 

  //declaration
  char *res;
  int len;

  //calculate the len
  len = WideCharToMultiByte(CP_UTF8,              // __in   UINT CodePage, With UTF8, lpDefaultChar and lpUsedDefaultChar must be set to NULL.
                            WC_ERR_INVALID_CHARS, // __in   DWORD dwFlags,
                            str,                  // __in   LPCWSTR lpWideCharStr, Pointer to the Unicode string to convert.
                            -1,                   // __in   int cchWideChar, Size, in characters, of the string indicated by lpWideCharStr. Alternatively, this parameter can be set set to -1 if the string is null-terminated. If this parameter is -1, the function processes the entire input string, including the terminating null character. Therefore, the resulting character string has a terminating null character, and the length returned by the function includes this character.
                            NULL,                 // __out  LPSTR lpMultiByteStr, Optional. Pointer to a buffer that receives the converted string.
                            0,                    // __in   int cbMultiByte, Size, in bytes, of the buffer indicated by lpMultiByteStr. If this parameter is set to 0, the function returns the required buffer size for lpMultiByteStr and makes no use of the output parameter itself.
                            NULL,                 // __in   LPCSTR lpDefaultChar, For the CP_UTF8 settings for CodePage, this parameter must be set to NULL. Otherwise, the function fails with ERROR_INVALID_PARAMETER.
                            NULL);                // __out  LPBOOL lpUsedDefaultChar For the CP_UTF8 settings for CodePage, this parameter must be set to NULL. Otherwise, the function fails with ERROR_INVALID_PARAMETER.

  // If some error len = 0
  if (len <= 0) {
	  return NULL;
  }

  //get the res
  res = (char *)(do_ib_util_malloc ? ib_util_malloc(len) : malloc(len));
  len = WideCharToMultiByte(CP_UTF8,              // __in   UINT CodePage
                            WC_ERR_INVALID_CHARS, // __in   DWORD dwFlags
                            str,                  // __in   LPCWSTR lpWideCharStr
                            -1,                   // __in   int cchWideChar
                            res,                  // __out  LPSTR lpMultiByteStr
                            len,                  // __in   int cbMultiByte
                            NULL,                 // __in   LPCSTR lpDefaultChar
                            NULL);                // __out  LPBOOL lpUsedDefaultChar
  
  //return res
  return res;

}

//******************************************
// return upper or lower case version of str
// this link http://www.i18nguy.com/unicode/turkish-i18n.html
// is interesting to understand the importance of local in 
// doing lowercase / uppercase. with the icu function
// u_strTolower, when i try to lower the İ i receive as
// the result i̇ (i + the dot) that is not very usefull
// so i decide to use the ms CharUpperBuffW and
// CharLowerBuffW instead (it's return the İ without any
// conversion)
static char *aludf_utf8lowup(char *str, int up) {
  
  //if str is null return null
  if (!str) {
	  return NULL;
  } 

	//declaration
  char *res;
	wchar_t *tmp_widestr;
	
	//init tmp_widestr
	tmp_widestr = aludf_utf82WideChar(str);
	
	//if tmp_widestr is null (bad UTF8 string?) then return NULL
  if (!tmp_widestr) {
	  return NULL;
  } 
	
  //uppercase
  if (up) { 
      
    CharUpperBuffW(tmp_widestr,            // __inout  LPTSTR lpsz  A buffer containing one or more characters to be processed.
                   (DWORD)wcslen(tmp_widestr));   // __in     DWORD cchLength  The size, in characters, of the buffer pointed to by lpsz.
                   
  } 

  //if lowercase
  else {
    
    CharLowerBuffW(tmp_widestr,            // __inout  LPTSTR lpsz  A buffer containing one or more characters to be processed.
                   (DWORD)wcslen(tmp_widestr));   // __in     DWORD cchLength  The size, in characters, of the buffer pointed to by lpsz.

  }

  //init the res
  res = aludf_WideChar2utf8(tmp_widestr, 1);

  //free tmp variables
  free(tmp_widestr);

  //return res
  return res;

}

//******************************************************
void aludf_wideremovemediumdiacriticchar(wchar_t *str) {
	for (wchar_t *p = str; *p; ++p) {
		switch (*p) {
      case 0x0181: *p = 0x0042; break;     //  LATIN CAPITAL LETTER B WITH HOOK -> LATIN CAPITAL LETTER B
      case 0x0182: *p = 0x0042; break;     //  LATIN CAPITAL LETTER B WITH TOPBAR -> LATIN CAPITAL LETTER B
      case 0x0187: *p = 0x0043; break;     //  LATIN CAPITAL LETTER C WITH HOOK -> LATIN CAPITAL LETTER C
      case 0x0110: *p = 0x0044; break;     //  LATIN CAPITAL LETTER D WITH STROKE -> LATIN CAPITAL LETTER D
      case 0x018A: *p = 0x0044; break;     //  LATIN CAPITAL LETTER D WITH HOOK -> LATIN CAPITAL LETTER D
      case 0x018B: *p = 0x0044; break;     //  LATIN CAPITAL LETTER D WITH TOPBAR -> LATIN CAPITAL LETTER D
      case 0x0191: *p = 0x0046; break;     //  LATIN CAPITAL LETTER F WITH HOOK -> LATIN CAPITAL LETTER F
      case 0x0193: *p = 0x0047; break;     //  LATIN CAPITAL LETTER G WITH HOOK -> LATIN CAPITAL LETTER G
      case 0x01E4: *p = 0x0047; break;     //  LATIN CAPITAL LETTER G WITH STROKE -> LATIN CAPITAL LETTER G
      case 0x0126: *p = 0x0048; break;     //  LATIN CAPITAL LETTER H WITH STROKE -> LATIN CAPITAL LETTER H
      case 0x0197: *p = 0x0049; break;     //  LATIN CAPITAL LETTER I WITH STROKE -> LATIN CAPITAL LETTER I
      case 0x0198: *p = 0x004B; break;     //  LATIN CAPITAL LETTER K WITH HOOK -> LATIN CAPITAL LETTER K
      case 0x0141: *p = 0x004C; break;     //  LATIN CAPITAL LETTER L WITH STROKE -> LATIN CAPITAL LETTER L
      case 0x019D: *p = 0x004E; break;     //  LATIN CAPITAL LETTER N WITH LEFT HOOK -> LATIN CAPITAL LETTER N
      case 0x0220: *p = 0x004E; break;     //  LATIN CAPITAL LETTER N WITH LONG RIGHT LEG -> LATIN CAPITAL LETTER N
      case 0x00D8: *p = 0x004F; break;     //  LATIN CAPITAL LETTER O WITH STROKE -> LATIN CAPITAL LETTER O
      case 0x019F: *p = 0x004F; break;     //  LATIN CAPITAL LETTER O WITH MIDDLE TILDE -> LATIN CAPITAL LETTER O
      case 0x01FE: *p = 0x004F; break;     //  LATIN CAPITAL LETTER O WITH STROKE AND ACUTE -> LATIN CAPITAL LETTER O
      case 0x01A4: *p = 0x0050; break;     //  LATIN CAPITAL LETTER P WITH HOOK -> LATIN CAPITAL LETTER P
      case 0x0166: *p = 0x0054; break;     //  LATIN CAPITAL LETTER T WITH STROKE -> LATIN CAPITAL LETTER T
      case 0x01AC: *p = 0x0054; break;     //  LATIN CAPITAL LETTER T WITH HOOK -> LATIN CAPITAL LETTER T
      case 0x01AE: *p = 0x0054; break;     //  LATIN CAPITAL LETTER T WITH RETROFLEX HOOK -> LATIN CAPITAL LETTER T
      case 0x01B2: *p = 0x0056; break;     //  LATIN CAPITAL LETTER V WITH HOOK -> LATIN CAPITAL LETTER V
      case 0x01B3: *p = 0x0059; break;     //  LATIN CAPITAL LETTER Y WITH HOOK -> LATIN CAPITAL LETTER Y
      case 0x01B5: *p = 0x005A; break;     //  LATIN CAPITAL LETTER Z WITH STROKE -> LATIN CAPITAL LETTER Z
      case 0x0224: *p = 0x005A; break;     //  LATIN CAPITAL LETTER Z WITH HOOK -> LATIN CAPITAL LETTER Z
      case 0x0180: *p = 0x0062; break;     //  LATIN SMALL LETTER B WITH STROKE -> LATIN SMALL LETTER B
      case 0x0183: *p = 0x0062; break;     //  LATIN SMALL LETTER B WITH TOPBAR -> LATIN SMALL LETTER B
      case 0x0253: *p = 0x0062; break;     //  LATIN SMALL LETTER B WITH HOOK -> LATIN SMALL LETTER B
      case 0x0188: *p = 0x0063; break;     //  LATIN SMALL LETTER C WITH HOOK -> LATIN SMALL LETTER C
      case 0x0255: *p = 0x0063; break;     //  LATIN SMALL LETTER C WITH CURL -> LATIN SMALL LETTER C
      case 0x0111: *p = 0x0064; break;     //  LATIN SMALL LETTER D WITH STROKE -> LATIN SMALL LETTER D
      case 0x018C: *p = 0x0064; break;     //  LATIN SMALL LETTER D WITH TOPBAR -> LATIN SMALL LETTER D
      case 0x0221: *p = 0x0064; break;     //  LATIN SMALL LETTER D WITH CURL -> LATIN SMALL LETTER D
      case 0x0256: *p = 0x0064; break;     //  LATIN SMALL LETTER D WITH TAIL -> LATIN SMALL LETTER D
      case 0x0257: *p = 0x0064; break;     //  LATIN SMALL LETTER D WITH HOOK -> LATIN SMALL LETTER D
      case 0x0192: *p = 0x0066; break;     //  LATIN SMALL LETTER F WITH HOOK -> LATIN SMALL LETTER F
      case 0x01E5: *p = 0x0067; break;     //  LATIN SMALL LETTER G WITH STROKE -> LATIN SMALL LETTER G
      case 0x0260: *p = 0x0067; break;     //  LATIN SMALL LETTER G WITH HOOK -> LATIN SMALL LETTER G
      case 0x0127: *p = 0x0068; break;     //  LATIN SMALL LETTER H WITH STROKE -> LATIN SMALL LETTER H
      case 0x0266: *p = 0x0068; break;     //  LATIN SMALL LETTER H WITH HOOK -> LATIN SMALL LETTER H
      case 0x0268: *p = 0x0069; break;     //  LATIN SMALL LETTER I WITH STROKE -> LATIN SMALL LETTER I
      case 0x029D: *p = 0x006A; break;     //  LATIN SMALL LETTER J WITH CROSSED-TAIL -> LATIN SMALL LETTER J
      case 0x0199: *p = 0x006B; break;     //  LATIN SMALL LETTER K WITH HOOK -> LATIN SMALL LETTER K
      case 0x0142: *p = 0x006C; break;     //  LATIN SMALL LETTER L WITH STROKE -> LATIN SMALL LETTER L
      case 0x019A: *p = 0x006C; break;     //  LATIN SMALL LETTER L WITH BAR -> LATIN SMALL LETTER L
      case 0x0234: *p = 0x006C; break;     //  LATIN SMALL LETTER L WITH CURL -> LATIN SMALL LETTER L
      case 0x026B: *p = 0x006C; break;     //  LATIN SMALL LETTER L WITH MIDDLE TILDE -> LATIN SMALL LETTER L
      case 0x026C: *p = 0x006C; break;     //  LATIN SMALL LETTER L WITH BELT -> LATIN SMALL LETTER L
      case 0x026D: *p = 0x006C; break;     //  LATIN SMALL LETTER L WITH RETROFLEX HOOK -> LATIN SMALL LETTER L
      case 0x0271: *p = 0x006D; break;     //  LATIN SMALL LETTER M WITH HOOK -> LATIN SMALL LETTER M
      case 0x019E: *p = 0x006E; break;     //  LATIN SMALL LETTER N WITH LONG RIGHT LEG -> LATIN SMALL LETTER N
      case 0x0235: *p = 0x006E; break;     //  LATIN SMALL LETTER N WITH CURL -> LATIN SMALL LETTER N
      case 0x0272: *p = 0x006E; break;     //  LATIN SMALL LETTER N WITH LEFT HOOK -> LATIN SMALL LETTER N
      case 0x0273: *p = 0x006E; break;     //  LATIN SMALL LETTER N WITH RETROFLEX HOOK -> LATIN SMALL LETTER N
      case 0x00F8: *p = 0x006F; break;     //  LATIN SMALL LETTER O WITH STROKE -> LATIN SMALL LETTER O
      case 0x01FF: *p = 0x006F; break;     //  LATIN SMALL LETTER O WITH STROKE AND ACUTE -> LATIN SMALL LETTER O
      case 0x01A5: *p = 0x0070; break;     //  LATIN SMALL LETTER P WITH HOOK -> LATIN SMALL LETTER P
      case 0x02A0: *p = 0x0071; break;     //  LATIN SMALL LETTER Q WITH HOOK -> LATIN SMALL LETTER Q
      case 0x027C: *p = 0x0072; break;     //  LATIN SMALL LETTER R WITH LONG LEG -> LATIN SMALL LETTER R
      case 0x027D: *p = 0x0072; break;     //  LATIN SMALL LETTER R WITH TAIL -> LATIN SMALL LETTER R
      case 0x0282: *p = 0x0073; break;     //  LATIN SMALL LETTER S WITH HOOK -> LATIN SMALL LETTER S
      case 0x0167: *p = 0x0074; break;     //  LATIN SMALL LETTER T WITH STROKE -> LATIN SMALL LETTER T
      case 0x01AB: *p = 0x0074; break;     //  LATIN SMALL LETTER T WITH PALATAL HOOK -> LATIN SMALL LETTER T
      case 0x01AD: *p = 0x0074; break;     //  LATIN SMALL LETTER T WITH HOOK -> LATIN SMALL LETTER T
      case 0x0236: *p = 0x0074; break;     //  LATIN SMALL LETTER T WITH CURL -> LATIN SMALL LETTER T
      case 0x0288: *p = 0x0074; break;     //  LATIN SMALL LETTER T WITH RETROFLEX HOOK -> LATIN SMALL LETTER T
      case 0x028B: *p = 0x0076; break;     //  LATIN SMALL LETTER V WITH HOOK -> LATIN SMALL LETTER V
      case 0x01B4: *p = 0x0079; break;     //  LATIN SMALL LETTER Y WITH HOOK -> LATIN SMALL LETTER Y
      case 0x01B6: *p = 0x007A; break;     //  LATIN SMALL LETTER Z WITH STROKE -> LATIN SMALL LETTER Z
      case 0x0225: *p = 0x007A; break;     //  LATIN SMALL LETTER Z WITH HOOK -> LATIN SMALL LETTER Z
      case 0x0290: *p = 0x007A; break;     //  LATIN SMALL LETTER Z WITH RETROFLEX HOOK -> LATIN SMALL LETTER Z
      case 0x0291: *p = 0x007A; break;     //  LATIN SMALL LETTER Z WITH CURL -> LATIN SMALL LETTER Z
      case 0x025A: *p = 0x0259; break;     //  LATIN SMALL LETTER SCHWA WITH HOOK -> LATIN SMALL LETTER SCHWA
      case 0x0286: *p = 0x0283; break;     //  LATIN SMALL LETTER ESH WITH CURL -> LATIN SMALL LETTER ESH
      case 0x01BA: *p = 0x0292; break;     //  LATIN SMALL LETTER EZH WITH TAIL -> LATIN SMALL LETTER EZH
      case 0x0293: *p = 0x0292; break;     //  LATIN SMALL LETTER EZH WITH CURL -> LATIN SMALL LETTER EZH
      case 0x0490: *p = 0x0413; break;     //  CYRILLIC CAPITAL LETTER GHE WITH UPTURN -> CYRILLIC CAPITAL LETTER GHE
      case 0x0492: *p = 0x0413; break;     //  CYRILLIC CAPITAL LETTER GHE WITH STROKE -> CYRILLIC CAPITAL LETTER GHE
      case 0x0494: *p = 0x0413; break;     //  CYRILLIC CAPITAL LETTER GHE WITH MIDDLE HOOK -> CYRILLIC CAPITAL LETTER GHE
      case 0x0496: *p = 0x0416; break;     //  CYRILLIC CAPITAL LETTER ZHE WITH DESCENDER -> CYRILLIC CAPITAL LETTER ZHE
      case 0x0498: *p = 0x0417; break;     //  CYRILLIC CAPITAL LETTER ZE WITH DESCENDER -> CYRILLIC CAPITAL LETTER ZE
      case 0x048A: *p = 0x0419; break;     //  CYRILLIC CAPITAL LETTER SHORT I WITH TAIL -> CYRILLIC CAPITAL LETTER SHORT I
      case 0x049A: *p = 0x041A; break;     //  CYRILLIC CAPITAL LETTER KA WITH DESCENDER -> CYRILLIC CAPITAL LETTER KA
      case 0x049C: *p = 0x041A; break;     //  CYRILLIC CAPITAL LETTER KA WITH VERTICAL STROKE -> CYRILLIC CAPITAL LETTER KA
      case 0x049E: *p = 0x041A; break;     //  CYRILLIC CAPITAL LETTER KA WITH STROKE -> CYRILLIC CAPITAL LETTER KA
      case 0x04C3: *p = 0x041A; break;     //  CYRILLIC CAPITAL LETTER KA WITH HOOK -> CYRILLIC CAPITAL LETTER KA
      case 0x04C5: *p = 0x041B; break;     //  CYRILLIC CAPITAL LETTER EL WITH TAIL -> CYRILLIC CAPITAL LETTER EL
      case 0x04CD: *p = 0x041C; break;     //  CYRILLIC CAPITAL LETTER EM WITH TAIL -> CYRILLIC CAPITAL LETTER EM
      case 0x04A2: *p = 0x041D; break;     //  CYRILLIC CAPITAL LETTER EN WITH DESCENDER -> CYRILLIC CAPITAL LETTER EN
      case 0x04C7: *p = 0x041D; break;     //  CYRILLIC CAPITAL LETTER EN WITH HOOK -> CYRILLIC CAPITAL LETTER EN
      case 0x04C9: *p = 0x041D; break;     //  CYRILLIC CAPITAL LETTER EN WITH TAIL -> CYRILLIC CAPITAL LETTER EN
      case 0x04A6: *p = 0x041F; break;     //  CYRILLIC CAPITAL LETTER PE WITH MIDDLE HOOK -> CYRILLIC CAPITAL LETTER PE
      case 0x048E: *p = 0x0420; break;     //  CYRILLIC CAPITAL LETTER ER WITH TICK -> CYRILLIC CAPITAL LETTER ER
      case 0x04AA: *p = 0x0421; break;     //  CYRILLIC CAPITAL LETTER ES WITH DESCENDER -> CYRILLIC CAPITAL LETTER ES
      case 0x04AC: *p = 0x0422; break;     //  CYRILLIC CAPITAL LETTER TE WITH DESCENDER -> CYRILLIC CAPITAL LETTER TE
      case 0x04B2: *p = 0x0425; break;     //  CYRILLIC CAPITAL LETTER HA WITH DESCENDER -> CYRILLIC CAPITAL LETTER HA
      case 0x04B3: *p = 0x0425; break;     //  CYRILLIC SMALL LETTER HA WITH DESCENDER -> CYRILLIC CAPITAL LETTER HA
      case 0x0491: *p = 0x0433; break;     //  CYRILLIC SMALL LETTER GHE WITH UPTURN -> CYRILLIC SMALL LETTER GHE
      case 0x0493: *p = 0x0433; break;     //  CYRILLIC SMALL LETTER GHE WITH STROKE -> CYRILLIC SMALL LETTER GHE
      case 0x0495: *p = 0x0433; break;     //  CYRILLIC SMALL LETTER GHE WITH MIDDLE HOOK -> CYRILLIC SMALL LETTER GHE
      case 0x0497: *p = 0x0436; break;     //  CYRILLIC SMALL LETTER ZHE WITH DESCENDER -> CYRILLIC SMALL LETTER ZHE
      case 0x0499: *p = 0x0437; break;     //  CYRILLIC SMALL LETTER ZE WITH DESCENDER -> CYRILLIC SMALL LETTER ZE
      case 0x048B: *p = 0x0439; break;     //  CYRILLIC SMALL LETTER SHORT I WITH TAIL -> CYRILLIC SMALL LETTER SHORT I
      case 0x049B: *p = 0x043A; break;     //  CYRILLIC SMALL LETTER KA WITH DESCENDER -> CYRILLIC SMALL LETTER KA
      case 0x049D: *p = 0x043A; break;     //  CYRILLIC SMALL LETTER KA WITH VERTICAL STROKE -> CYRILLIC SMALL LETTER KA
      case 0x049F: *p = 0x043A; break;     //  CYRILLIC SMALL LETTER KA WITH STROKE -> CYRILLIC SMALL LETTER KA
      case 0x04C4: *p = 0x043A; break;     //  CYRILLIC SMALL LETTER KA WITH HOOK -> CYRILLIC SMALL LETTER KA
      case 0x04C6: *p = 0x043B; break;     //  CYRILLIC SMALL LETTER EL WITH TAIL -> CYRILLIC SMALL LETTER EL
      case 0x04CE: *p = 0x043C; break;     //  CYRILLIC SMALL LETTER EM WITH TAIL -> CYRILLIC SMALL LETTER EM
      case 0x04A3: *p = 0x043D; break;     //  CYRILLIC SMALL LETTER EN WITH DESCENDER -> CYRILLIC SMALL LETTER EN
      case 0x04C8: *p = 0x043D; break;     //  CYRILLIC SMALL LETTER EN WITH HOOK -> CYRILLIC SMALL LETTER EN
      case 0x04CA: *p = 0x043D; break;     //  CYRILLIC SMALL LETTER EN WITH TAIL -> CYRILLIC SMALL LETTER EN
      case 0x04A7: *p = 0x043F; break;     //  CYRILLIC SMALL LETTER PE WITH MIDDLE HOOK -> CYRILLIC SMALL LETTER PE
      case 0x048F: *p = 0x0440; break;     //  CYRILLIC SMALL LETTER ER WITH TICK -> CYRILLIC SMALL LETTER ER
      case 0x04AB: *p = 0x0441; break;     //  CYRILLIC SMALL LETTER ES WITH DESCENDER -> CYRILLIC SMALL LETTER ES
      case 0x04AD: *p = 0x0442; break;     //  CYRILLIC SMALL LETTER TE WITH DESCENDER -> CYRILLIC SMALL LETTER TE
      case 0x04B9: *p = 0x0447; break;     //  CYRILLIC SMALL LETTER CHE WITH VERTICAL STROKE -> CYRILLIC SMALL LETTER CHE
      case 0x047C: *p = 0x0460; break;     //  CYRILLIC CAPITAL LETTER OMEGA WITH TITLO -> CYRILLIC CAPITAL LETTER OMEGA
      case 0x047D: *p = 0x0461; break;     //  CYRILLIC SMALL LETTER OMEGA WITH TITLO -> CYRILLIC SMALL LETTER OMEGA
      case 0x04B0: *p = 0x04AE; break;     //  CYRILLIC CAPITAL LETTER STRAIGHT U WITH STROKE -> CYRILLIC CAPITAL LETTER STRAIGHT U
      case 0x04B1: *p = 0x04AF; break;     //  CYRILLIC SMALL LETTER STRAIGHT U WITH STROKE -> CYRILLIC SMALL LETTER STRAIGHT U
      case 0x04B6: *p = 0x04BC; break;     //  CYRILLIC CAPITAL LETTER CHE WITH DESCENDER -> CYRILLIC CAPITAL LETTER ABKHASIAN CHE
      case 0x04B7: *p = 0x04BC; break;     //  CYRILLIC SMALL LETTER CHE WITH DESCENDER -> CYRILLIC CAPITAL LETTER ABKHASIAN CHE
      case 0x04B8: *p = 0x04BC; break;     //  CYRILLIC CAPITAL LETTER CHE WITH VERTICAL STROKE -> CYRILLIC CAPITAL LETTER ABKHASIAN CHE
      case 0x04BE: *p = 0x04BC; break;     //  CYRILLIC CAPITAL LETTER ABKHASIAN CHE WITH DESCENDER -> CYRILLIC CAPITAL LETTER ABKHASIANCHE
      case 0x04BF: *p = 0x04BC; break;     //  CYRILLIC SMALL LETTER ABKHASIAN CHE WITH DESCENDER -> CYRILLIC CAPITAL LETTER ABKHASIAN CHE
      case 0x04CB: *p = 0x04BC; break;     //  CYRILLIC CAPITAL LETTER KHAKASSIAN CHE -> CYRILLIC CAPITAL LETTER ABKHASIAN CHE
      case 0x04CC: *p = 0x04BC; break;     //  CYRILLIC SMALL LETTER KHAKASSIAN CHE -> CYRILLIC CAPITAL LETTER ABKHASIAN CHE
		}
	}
}

//*************************
//remove accented character
static wchar_t *aludf_wideremovediacritic(wchar_t *str) {
  
	//if str is null then return NULL
  if (!str) {
	  return NULL;
  } 
  
	//get the len_res
	//Returns the number of characters in the translated string, including a terminating null character, if successful
	int len_res = FoldStringW(MAP_COMPOSITE, // __in   DWORD dwMapFlags,
                            str,           // __in   LPCTSTR lpSrcStr,
                            -1,            // __in   int cchSrc,
                            NULL,          // __out  LPTSTR lpDestStr,
                            0);            // __in   int cchDest
	
	//if some error ?
	if (len_res <= 0) {
	  return NULL;
	}

  //init tmp_widestr
	wchar_t *tmp_widestr = (wchar_t *)malloc((len_res) * sizeof(wchar_t));

	//The application can set the parameter cchSrc to any negative value to specify that the source string is null-terminated. 
	//In this case, the function calculates the string length automatically, and null-terminates the mapped string indicated by lpDestStr	  
	FoldStringW(MAP_COMPOSITE,  // __in   DWORD dwMapFlags,
              str,            // __in   LPCTSTR lpSrcStr,
              -1,             // __in   int cchSrc, 
              tmp_widestr,    // __out  LPTSTR lpDestStr,
              len_res);       // __in   int cchDest
	
	//init the res
	wchar_t *res = (wchar_t *)malloc((len_res) * sizeof(wchar_t));
	
	//remove the diacritic
	//this function actually take for true that 1 char = 1 wchar_t
	//but this can be false on some unicode char 
	int i = 0;
	int j = 0;
  int l;
	wchar_t s1[2];
	s1[1] = L'\0';
	while (tmp_widestr[i]) {
		res[j] = tmp_widestr[i];  
		if (str[j] != tmp_widestr[i]) { 
			s1[0] = str[j];
			l = FoldStringW(MAP_COMPOSITE, // __in   DWORD dwMapFlags,
                      s1,            // __in   LPCTSTR lpSrcStr,
                      1,             // __in   int cchSrc,  
                      NULL,          // __out  LPTSTR lpDestStr,
                      0);            // __in   int cchDest
      if (l<=0) { l = 1; }
      i += l;
		}
		else {
			i++;
		}
		j++;
	}

	//null terminate the res
	res[j] = L'\0';
	
	//free the TmpWideStr
	free(tmp_widestr);
	
	//return the res
	return res;
	
}

//**********************************************************************************************
// Expand all ligature characters so that they are represented by their two-character equivalent.
// For example, the ligature 'æ' expands to the two characters 'a' and 'e'.
static wchar_t *aludf_wideexpandligatures(wchar_t *str) {  
	
	//if str is null then return NULL
  if (!str) {
	  return NULL;
  } 
		
	//get the len_res
	//Returns the number of characters in the translated string, including a terminating null character, if successful
	int len_res = FoldStringW(MAP_EXPAND_LIGATURES, // __in   DWORD dwMapFlags,
                            str,                  // __in   LPCTSTR lpSrcStr,
                            -1,                   // __in   int cchSrc,   
                            NULL,                 // __out  LPTSTR lpDestStr,
                            0);	                  // __in   int cchDest
	
	//if some error ?
	if (len_res <= 0){
	  return NULL;
	}
	
	//init the res
	wchar_t *res = (wchar_t *)malloc((len_res) * sizeof(wchar_t));
  
  //The application can set the parameter cchSrc to any negative value to specify that the source string is null-terminated. 
	//In this case, the function calculates the string length automatically, and null-terminates the mapped string indicated by lpDestStr	
	FoldStringW(MAP_EXPAND_LIGATURES,   // __in   DWORD dwMapFlags,
              str,                    // __in   LPCTSTR lpSrcStr,
              -1,                     // __in   int cchSrc,    
              res,                    // __out  LPTSTR lpDestStr,
              len_res);               // __in   int cchDest
	
	//return the res
	return res;
	
}

//*************************************************
static wchar_t *aludf_widenormalize(wchar_t *str) {
	
	//declaration
	wchar_t *res;
  wchar_t *tmpwidestr_nodiacritic; 
  wchar_t *tmpwidestr_ligaturesexpended;

	//if str is null (bad UTF8 string?) then return NULL
  if (!str) {
	  return NULL;
  } 

  //lower the str
  CharLowerBuffW(str,            // __inout  LPTSTR lpsz  A buffer containing one or more characters to be processed.
                 (DWORD)wcslen(str));   // __in     DWORD cchLength  The size, in characters, of the buffer pointed to by lpsz.

  //init tmpwidestr_nodiacritic as str without diacritic
	tmpwidestr_nodiacritic = aludf_wideremovediacritic(str);
	
	//init tmpwidestr_ligaturesexpended as tmpwidestr_nodiacritic with Ligatures expended
	tmpwidestr_ligaturesexpended = aludf_wideexpandligatures(tmpwidestr_nodiacritic);
	
	//init res
	res = (wchar_t *)malloc((wcslen(tmpwidestr_ligaturesexpended) + 1) * sizeof(wchar_t));
		
  //remove all non alpha numeric char from the res
  wchar_t *tmpwidestr = tmpwidestr_ligaturesexpended;
  int i;
  int j = -1;
	for (i = 0; tmpwidestr[i]; i++) { 
		if (IsCharAlphaNumericW(tmpwidestr[i])) { 
			j++;
			res[j] = tmpwidestr[i];  
		}
		else if (
		         (j >= 0) &&        
		         (res[j] != L'-') 
		        ) 
    {  
			j++;
			res[j] = L'-';                    
		}
	}
	while ((j >= 0) && (res[j] == L'-')) { --j; } 
	
	//null terminate the res
	res[j+1] = L'\0';

	//free the tmp
	free(tmpwidestr_nodiacritic);
	free(tmpwidestr_ligaturesexpended);
	
	//remove char like L with bar from res
	aludf_wideremovemediumdiacriticchar(res);

	//return res
	return res;
	
}

//*******************************************
EXPORT char *aludf_utf8normalize(char *str) {
  	
  //declaration
  char *res;
  wchar_t *tmp_widestr1, *tmp_widestr2;  
  
  //init tmp_widestr1 as wchar_t of Str
  tmp_widestr1 = aludf_utf82WideChar(str);
  	
  //if tmp_widestr1 is null (bad UTF8 string?) then return NULL
  if (!tmp_widestr1) {
  	return NULL;
  } 
  		
  //init tmp_widestr2 as normalization of tmp_widestr1
  tmp_widestr2 = aludf_widenormalize(tmp_widestr1);
  	
  //init the res as char of tmp_widestr2
  res = aludf_WideChar2utf8(tmp_widestr2, 1);
  
  //free tmp variable
  free(tmp_widestr1);
  free(tmp_widestr2);
  	
  //return res
  return res;
  
}

//*******************************************
EXPORT char *aludf_utf8lowercase(char *str) {
  return aludf_utf8lowup(str, 0);
}
  
//*******************************************
EXPORT char *aludf_utf8uppercase(char *str) {
  return aludf_utf8lowup(str, 1);
}
  
//****************************************
EXPORT char *aludf_httpencode(char *str) {
	
  static const char hex_str[] = "0123456789ABCDEF";
	char *res =   (char *)ib_util_malloc((long)((strlen(str) * 3) + 1));
	char *p = res;

  for ( ; *str; ++str) {
		
    if (
  			((*str >= 'A') && (*str <= 'Z')) ||
	  		((*str >= 'a') && (*str <= 'z')) ||
		  	((*str >= '0') && (*str <= '9')) ||
			  (*str == '*') ||
  			(*str == '@') ||
	  		(*str == '.') ||
		  	(*str == '_') ||
			  (*str == '-') ||
  			(*str == '$') ||
	  		(*str == '!') ||
		  	(*str == '\'') ||
			  (*str == '(') ||
			  (*str == ')')
		   )
		{ 
      *p++ = *str; 
    }
		
    else if (*str == ' ') {
			*p++ = '+';
		}

		else {
			*p++ = '%';
			*p++ = hex_str[(unsigned char)*str >> 4];
			*p++ = hex_str[(unsigned char)*str & 0xf];
		}

	}

	*p = '\0';

  return res;

}

//******************************************
EXPORT char *aludf_utf8titlecase(char *str){
  	
  //declaration
  char *res;
  wchar_t *tmp_widestr1;  
  
  //init tmp_widestr1 as wchar_t of Str
  tmp_widestr1 = aludf_utf82WideChar(str);
  	
  //if tmp_widestr1 is null (bad UTF8 string?) then return NULL
  if (!tmp_widestr1) {
  	return NULL;
  } 

  //lower the tmp_widestr1
  CharLowerBuffW(tmp_widestr1,                   // __inout  LPTSTR lpsz  A buffer containing one or more characters to be processed.
                 (DWORD)wcslen(tmp_widestr1));   // __in     DWORD cchLength  The size, in characters, of the buffer pointed to by lpsz.

  //upper the first char
  CharUpperBuffW(tmp_widestr1,                   // __inout  LPTSTR lpsz  A buffer containing one or more characters to be processed.
                 1);                             // __in     DWORD cchLength  The size, in characters, of the buffer pointed to by lpsz.
  		  	
  //uppercase all the word
  int i;
	wchar_t s1[2];
	s1[1] = L'\0';
	for (i = 1; tmp_widestr1[i]; i++) { 
    if (
         (          
          (tmp_widestr1[i-1] == L'&') ||
          (tmp_widestr1[i-1] == L' ') ||
          (tmp_widestr1[i-1] == L'-') || 
          (tmp_widestr1[i-1] == L'\'')
         ) 
         &&
         (
          ((tmp_widestr1[i+1] != L' ') || (tmp_widestr1[i-1] == L'&')) && // Agenge L&G Prestige - Maison à Vendre - A Prendre Ou a Laisser          
          (tmp_widestr1[i+1] != L'\'') // Avenue de l'Elysée
         )
       )
    { 
 			s1[0] = tmp_widestr1[i];
      CharUpperBuffW(s1,                   // __inout  LPTSTR lpsz  A buffer containing one or more characters to be processed.
                     1);                   // __in     DWORD cchLength  The size, in characters, of the buffer pointed to by lpsz.  		  	
      tmp_widestr1[i] = s1[0];  
    }
  }
  
  //init the res as char of tmp_widestr2
  res = aludf_WideChar2utf8(tmp_widestr1, 1);
  
  //free tmp variable
  free(tmp_widestr1);
  	
  //return res
  return res;	

}

//********************************************
EXPORT ISC_LONG aludf_zerotoone(ISC_LONG *a) {
	return ((*a == 0) ? 1 : *a);
}