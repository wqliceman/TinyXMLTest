#include "tinyxml.h"
#include <iostream>
#include <string>

using namespace std;
int stdout_Attribute(TiXmlElement *pElement);

int main()
{
	TiXmlDocument *pdoc = new TiXmlDocument();
	if(NULL == pdoc)
		return -1;
	TiXmlDeclaration *pDec = new TiXmlDeclaration("1.0", "StandAlone","EnCoding");
	if(NULL == pDec)
		return -1;

	pdoc->LinkEndChild(pDec);

	TiXmlElement *pRoot = new TiXmlElement("MyApp");
	if(NULL == pRoot)
		return -1;
	pdoc->LinkEndChild(pRoot);


	TiXmlElement *pName = new TiXmlElement("Name");
	if(NULL == pName)
		return -1;
	pRoot->LinkEndChild(pName);

	TiXmlText *ptext = new TiXmlText("wqliceman");
	if(NULL == ptext)
		return -1;
	pName->LinkEndChild(ptext);
	//////////////////////////////////////////////////////////////////////////
	TiXmlComment *pComm = new TiXmlComment("this is a position node and his attribute");
	pRoot->LinkEndChild(pComm);
	
	//////////////////////////////////////////////////////////////////////////
	TiXmlElement *pPos = new TiXmlElement("Position");
	pPos->SetAttribute("x", 200);
	pPos->SetAttribute("y", 400);
	pPos->SetAttribute("Value","This");
	
	pRoot->LinkEndChild(pPos);
	stdout_Attribute(pPos);
	//////////////////////////////////////////////////////////////////////////

	TiXmlNode *pNode = pdoc->FirstChild();
	TiXmlDeclaration *pDecGet = pNode->ToDeclaration();
	cout<<pDecGet->Version()<<ends
		<<pDecGet->Standalone()<<ends
		<<pDecGet->Encoding()<<endl;
	
	pdoc->Print();
	pdoc->SaveFile("text.xml");

	return 0;
}

int stdout_Attribute(TiXmlElement *pElement)
{
	TiXmlAttribute *pAttr = pElement->FirstAttribute();
	int nCount = 0;

	while(pAttr)
	{
		cout<<pAttr->Name()<<" : "<< pAttr->Value()<<endl;
		nCount++;
		pAttr = pAttr->Next();
	}
	
	return nCount;
}