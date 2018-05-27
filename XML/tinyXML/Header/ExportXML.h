#ifndef ExportXML_H
#define ExportXML_H


#include "tinyxml.h"
#include "ReadTreeFile.h"



class ExportXML
{
public:
	ExportXML();
	~ExportXML();

	//CraeteBodyXMl
	//CreateConnectionXMl
	//
	int InitXML();
	int SaveXML(const std::string strXmlName);
	int WriteComponent(Inertia * ipobjInertia, ProCharPath chrMassUnit, ProCharPath chrLengthUnit);
	int WriteConnection(Connection * ipobjConnection, ConnDtl * ipobjConnDtl, ProCharPath chrLengthUnit);
	int GetConnectionTypeText(ConnDtl * ipobjConnDtl, ProCharPath chrConnType);
	int WriteBodyRef(ProCharName chrBodyRef, ProCharName chrBody, TiXmlElement * xmlJointName, ProVector vctBodyVector, ProCharPath chrLengthUnit);
	int AddActionRefVector(ProCharLine chrType, TiXmlElement *xmlBdyRef, ProVector objVector);

private:
	TiXmlElement * _xmlComponent;
	TiXmlElement * _xmlConnection;
	TiXmlDocument _xmlOutputXML;

};

#endif