#pragma warning(disable:4267)
#include "str.h"
#include <stdarg.h>
#include <windows.h>

/* is hex char
 */
bool isHexChar(char c)
{
	return (((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) ? true : false;
}

/* is numeric
 */
bool isNumeric(const string &sInput)
{
	int nLen,i = 0;
	
	if ((nLen = (int)sInput.length ()) <= 0)
	{
		return false;
	}
	
	if ('-' == sInput[0])
	{
		i++;
	}
	for (; i<nLen; i++)
	{
		if ((sInput[i] < '0') || (sInput[i] > '9'))
		{
			return false;
		}
	}

	return true;
}

/* is ip
 */
bool isIp(const string& sInput)
{
	int i,nSize;
	vector<string> vecPart;

	/* split input by dot */
	if ((split(sInput, ".", &vecPart) < 0) || (4 != (nSize = (int)vecPart.size())))
	{
		return false;
	}

	/* check part whether number */
	for(i=0; i<nSize; i++)
	{
		if (!isNumeric(vecPart[i]))
		{
			return false;
		}
	}

	return true;
}

/* trim
*/
char *trim(char *szInput, TRIM_FLAG flag)
{
	if (NULL != szInput)
	{
		int i,nLen;
		
		/* trim left */
		nLen = (int)strlen (szInput);
		for (i=0; i<nLen; i++)
		{
			if ((0x09 != szInput[i]) && (0x20 != szInput[i]))
			{
				if (i > 0)
				{
					memcpy (szInput, &szInput[i], nLen - i);
					szInput[nLen-i] = '\0';
				}			
				break;
			}	
		}

		/* if all space */
		if (i >= nLen)
		{
			szInput[0] = '\0';
		}
		else
		{
			/* trim right */
			nLen = (int)strlen (szInput);
			for (i=nLen-1; i>=0; i--)
			{
				if ((0x09 != szInput[i]) && (0x20 != szInput[i]))
				{
					if (i < nLen - 1)
					{
						szInput[i+1] = '\0';
					}			
					break;
				}	
			}
		}
	}
	
	return szInput;
}

/* trim
"\0"   - ASCII 0x0, NULL
"\t"   - ASCII 0x9, 制表符
"\n"   - ASCII 0x10, 新行
"\x0B" - ASCII 0x11, 垂直制表符
"\r"   - ASCII 0x13, 回车

" "    - ASCII 0x20, 空格
*/

bool isInCharList(char chVal, const string &sCharList)
{
	return (sCharList.find_first_of(chVal) != string::npos);
}

bool isEndWith(const string &str, const string &charlist)
{
	if (str.size() == 0) {
		return false;
	}
	return isInCharList(str[str.size() - 1], charlist);
}

string trim(const string& sInput, TRIM_FLAG flag, const string &charlist)
{
	int i,nLen;
	string sOutput = sInput;
	
	/* trim left */
	nLen = (int)sOutput.length ();
	if (flag | TRIM_LFET) {
		for (i=0; i<nLen; i++) {
			if (isInCharList(sOutput[i], charlist)) {
				if (i > 0) {
					sOutput = sOutput.substr (i, nLen - i);
				}			
				break;
			}	
		}
	}
	
	/* trim right */
	if (flag | TRIM_RIGHT) {
		nLen = (int)sOutput.length ();
		for (i=nLen-1; i>=0; i--) {
			if (isInCharList(sOutput[i], charlist)) {
				if (i < nLen - 1) {
					sOutput = sOutput.substr (0, i + 1);
				}			
				break;
			}	
		}
	}

	return sOutput;
}

string ltrim(const string& sInput, const string &charlist)
{
	return trim(sInput, TRIM_LFET, charlist);
}

string rtrim(const string& sInput, const string &charlist)
{
	return trim(sInput, TRIM_RIGHT, charlist);
}

/* lcase
 */

char *lcase(char *szInput)
{
	if (szInput)
	{
		int i,nLen = (int)strlen (szInput);
		
		for (i=0; i<nLen; i++)
		{
			szInput[i] = tolower (szInput[i]);
		}	
	}
	
	return szInput;
}
 /* lcase
 */

string lcase(const string& sInput)
{
	string sOutput = sInput;
	int i,nLen = (int)sOutput.length();
	
	for (i=0; i<nLen; i++)
	{
		sOutput[i] = tolower (sOutput[i]);
	}

	return sOutput;
}

/* ucase
 */
char *ucase(char *szInput)
{
	if (szInput)
	{
		int i,nLen = (int)strlen (szInput);
		
		for (i=0; i<nLen; i++)
		{
			szInput[i] = toupper (szInput[i]);
		}	
	}
	
	return szInput;
}

/* ucase
 */
string ucase(const string& sInput)
{
	string sOutput = sInput;
	int i,nLen = (int)sOutput.length();
	
	for (i=0; i<nLen; i++)
	{
		sOutput[i] = toupper (sOutput[i]);
	}

	return sOutput;
}

/* remove CRLF
*/
char *removeCRLF(char *szLine)
{
	if (NULL != szLine)
	{
		int i,nSize = (int)strlen (szLine);		
		for (i=nSize-1; i>=0; i--)
		{
			if (('\r' != szLine[i]) && ('\n' != szLine[i]))
			{				
				break;	
			}	
		}
		szLine[i+1] = '\0';
	}
	
	return szLine;
}

/* remove CRLF
 */
string removeCRLF(const string& sLine)
{
	string sOutput = sLine;
	int i,nSize = (int)sOutput.length ();
	
	for (i=nSize-1; i>=0; i--)
	{
		if (('\r' != sOutput[i]) && ('\n' != sOutput[i]))
		{			
			break;	
		}	
	}
	sOutput.erase(i+1);
	
	return sOutput;
}


/* dir name
 */
string dirName(const string& sPath)
{
	int i,nLen = (int)sPath.length ();
	
	/* find seperator */
	for (i=nLen-1; i>=0; i--)
	{
		if (('\\' == sPath[i]) || ('/' == sPath[i]))
		{
			break;
		}
	}
	
	return sPath.substr (0, i);
}

/* base name
 */
string baseName(const string& sPath)
{
	int i,nLen = (int)sPath.length ();
	
	/* find seperator */
	for (i=nLen-1; i>=0; i--)
	{
		if (('\\' == sPath[i]) || ('/' == sPath[i]))
		{
			break;
		}
	}
	
	return sPath.substr (i + 1);
}

/* prefix name
 */
string prefixName(const string& sFileName)
{
	int nPos;
	string sBaseName;
	
	sBaseName = baseName (sFileName);
	if ((nPos = (int)sBaseName.find_last_of ('.')) < 0)
	{
		return sBaseName;
	}
	
	return sBaseName.substr(0, nPos);
}

/* suffix name
 */
string suffixName(const string& sFileName)
{
	int nPos;
	string sBaseName;
	
	sBaseName = baseName (sFileName);
	if ((nPos = (int)sBaseName.find_last_of ('.')) < 0)
	{
		return "";
	}
	
	return sBaseName.substr(nPos);
}

/* replace all
 */
string replaceall(const string& sInput,const string& sOld,const string& sNew)
{
	string sOutput;
	int nPosFind,nPosBeg = 0,nLenOld = (int)sOld.length ();
	
	/* find old */
	while ((nPosFind = (int)sInput.find (sOld, nPosBeg)) >= 0)
	{
		/* concat context */
		if (nPosFind - nPosBeg > 0)
		{
			sOutput += 	sInput.substr (nPosBeg, nPosFind - nPosBeg);
		}
		/* concat new */
		sOutput += sNew;
		
		/* move pos */
		nPosBeg = nPosFind + nLenOld; 
	}
	
	/* remain */
	if (nPosBeg < (int)sInput.length ())
	{
		sOutput += sInput.substr (nPosBeg);
	}
	
	return sOutput;
}

/* format
 */
string format(const char *format,...)
{
	va_list vl;
	char szBuffer[1024] = {0};
	
	/* format */
	va_start (vl,format);
	vsprintf_s(szBuffer, 1024, format, vl);
	va_end (vl);
	
	return szBuffer;	
}

/* format path
 */
string formatPath(const string& sInputPath)
{
	int i,nSize,nLen;	
	vector<string> vecParts;
	string sLinuxPath,sTempPath;
	
	/* replace separator from window to linux */
	sTempPath = replaceall(sInputPath, "\\", "/");
	if ((sTempPath.length() > 0) && ('/' == sTempPath[0]))
	{
		sLinuxPath = "/";
	}
	
	/* merge repeat separator */
	split(sTempPath, "/", &vecParts);
	nSize = (int)vecParts.size();
	for (i=0; i<nSize; i++)
	{
		if (trim(vecParts[i]).length() > 0)
		{
			sLinuxPath += vecParts[i] + "/";
		}
	}
	
	/* erase last separator */
	nLen = (int)sLinuxPath.length();
	if ('/' == sLinuxPath[nLen-1])
	{
		sLinuxPath.erase(nLen - 1);
	}
	
	return sLinuxPath;
}

/* split
 */
int split(const string& sInput,const string& sSeparator,vector<string> *pvec)
{
	int nLen,nFindPos,nBegPos = 0;
	
	/* check cond */
	if (((nLen = (int)sSeparator.length ()) <= 0) || (NULL == pvec))
	{
		return -1;	
	}
	pvec->clear ();
	
	/* split with trim */
	while ((nFindPos = (int)sInput.find (sSeparator, nBegPos)) >= 0)
	{
		pvec->push_back (sInput.substr (nBegPos, nFindPos - nBegPos));
		nBegPos = nFindPos + nLen;
	}
	if (nBegPos < (int)sInput.size ())
	{
		pvec->push_back (sInput.substr (nBegPos));
	}
	else
	{
		pvec->push_back("");
	}
	
	return int(pvec->size());
}

/* split
 */
int split(const string& sInput,const string& sSeparator,bool bTrim,bool bFilterEmpty,vector<string> *pvec)
{
	/* split line */
	if (split(sInput, sSeparator, pvec) < 0)
	{
		return -1;
	}

	/* filter empty parts */
	if (bTrim || bFilterEmpty)
	{
		vector<string>::iterator it = pvec->begin();

		while(it != pvec->end())
		{
			/* trim */
			if (bTrim)
			{
				*it = trim(*it);
			}
			
			/* filter empty */
			if (bFilterEmpty && (it->length() <= 0))
			{
				it=pvec->erase(it);
			}
			else
			{
				++it;
			}
		}
	}


	return int(pvec->size());
}

/* find pattern strings
 */
int findPatternStrings(const string& sInput,const string& sPatternBeg,const string& sPatternEnd,map<int,string> *pmapReturn)
{
	int nFindPos[2],nBeginPos = 0;

	/* check params */
	if (NULL == pmapReturn)
	{
		return -1;
	}
	
	pmapReturn->clear ();
	while ((nFindPos[0] = (int)sInput.find(sPatternBeg, nBeginPos)) >= 0)
	{
		nBeginPos = nFindPos[0] + (int)sPatternBeg.length();		
		if ((nFindPos[1] = (int)sInput.find(sPatternEnd, nBeginPos)) < 0)
		{
			return -2;
		}
		nBeginPos = nFindPos[1] + (int)sPatternEnd.length();
		pmapReturn->insert(pair<int,string>(nFindPos[0], sInput.substr(nFindPos[0], nBeginPos - nFindPos[0])));
	}

	return int(pmapReturn->size());
}


/* convert string to wstring
 */
wstring string2wstring(const string& sInput){
	int nLen;
	wstring wsOutput;
	WCHAR *pwszOutput = NULL;

	/* get length */
	if ((nLen = MultiByteToWideChar(CP_ACP, 0, sInput.c_str(), (int)sInput.size(), NULL, 0)) <= 0){
		return wsOutput;
	}

	/* new output buffer */
	if (NULL == (pwszOutput = new WCHAR[nLen + 1])){
		return wsOutput;
	}

	/* convert code */
	if (0 == MultiByteToWideChar(CP_ACP, 0, sInput.c_str(), (int)sInput.size(), pwszOutput, nLen)){
		delete[] pwszOutput;
		return wstring();
	}

	/* assign variable */
	wsOutput.assign(pwszOutput, nLen);

	/* delete output buffer */
	delete[] pwszOutput;

	return wsOutput;
}

/* convert wstring to string
 */
string wstring2string(const wstring& wsInput){
	int nLen;
	string sOutput;
	CHAR *pszOutput = NULL;

	/* get length */
	if ((nLen = WideCharToMultiByte(CP_ACP, 0, wsInput.c_str(), (int)wsInput.size(), NULL, 0, NULL, NULL)) <= 0){
		return sOutput;
	}

	/* new output buffer */
	if (NULL == (pszOutput = new CHAR[nLen + 1])){
		return sOutput;
	}

	/* convert code */
	if (0 == WideCharToMultiByte(CP_ACP, 0, wsInput.c_str(), (int)wsInput.size(), pszOutput, nLen, NULL, NULL)){
		delete[] pszOutput;
		return sOutput;
	}

	/* assign variable */
	sOutput.assign(pszOutput, nLen);

	/* delete output buffer */
	delete[] pszOutput;

	return sOutput;
}



