#if !defined (STR_H__20170522)
#define STR_H__20170522

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace cbl {

//�ж�c�Ƿ���16�����ַ�
bool isHex(char c);

//�ж�szInput�Ƿ���16�����ַ���
bool isHex(const char *szInput);

//�ж�szInput�Ƿ���16�����ַ���
bool isHex(const string &sInput);

//�ж�szInput�Ƿ��Ǵ������ַ���
bool isNumeric(const char *szInput);

//�ж�szInput�Ƿ��Ǵ������ַ���
bool isNumeric(const string &sInput);

//��szInput�ַ���ת��ȫСд
char* lcase(char *szInput);

//��szInput�ַ���ת��ȫСд
string lcase(const string &sInput);

//��szInput�ַ���ת��ȫ��д
char* ucase(char *szInput);

//��szInput�ַ���ת��ȫ��д
string ucase(const string &sInput);

char *removeCRLF(char *szLine);
string removeCRLF(const string& sLine);

//ȥ��szInput�����ҿհ��ַ�
char* trim(char *szInput);

//ȥ��szInput�����ҿհ��ַ�
string trim(const string &sInput);

//����·���ַ����е�Ŀ¼����
string dirName(const string &sPath);

//����·���ַ����еĲ���Ŀ¼������
string baseName(const string &sPath);

//�����ļ�����������׺
string prefixName(const string &sFileName);

//�����ļ���׺����
string suffixName(const string& sFileName);

//��sInput�ַ����е�����sOld�Ӵ��滻��sNew�Ӵ�
string replaceall(const string &sInput, const string &sOld, const string &sNew);

//���ظ�ʽ���ַ���
string format(const char *fmt,...);

//��sInput�ַ�����sSeparator���зָ����pvec���ɹ����طָ�ĸ�����ʧ�ܷ��ظ���
int split(const string &sInput, const string &sSeparator, vector<string> *pvec);

//��sInput�ַ�����sSeparator���зָ����pvec���ɹ����طָ�ĸ�����ʧ�ܷ��ظ���������һ����������ȥ���հ׺͹��˿մ���ѡ��
int split(const string &sInput, const string &sSeparator, bool bTrim, bool bFilterEmpty, vector<string> *pvec);

//split�ķ���������Ѷ���Ӵ��ϲ���һ���µ��ַ���
string concat(const vector<string> &vecInput, const string &sSeparator);

} 

#endif
