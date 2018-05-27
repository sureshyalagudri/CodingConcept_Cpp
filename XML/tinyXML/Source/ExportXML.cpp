#include "ExportXML.h"
#include "ErrorLog.h"
#include "ProMdlUnits.h"
#include "ProMdl.h"

ExportXML::ExportXML()
{
	_xmlComponent=NULL;
	_xmlConnection=NULL;
}

ExportXML::~ExportXML()
{
}


/*===========================================================================*\
Function    :   InitXML
Input       :	TiXmlDocument - Tiny xml document  
Output      :	
Returns     :   int
Purpose     :	Initializes the XML file 
Date		:	21/01/2014
Author		:	Suresh
\*===========================================================================*/
int ExportXML::InitXML()
{
	ErrorLog::WriteInt("ExportXML::InitXML---> In",0);

	//Declare XML file 
	TiXmlDeclaration* xmlDecl = new TiXmlDeclaration( "1.0", "", "" );
	_xmlOutputXML.LinkEndChild(xmlDecl);

	//Add Linkage element 
	TiXmlElement* elmLinkage = new TiXmlElement( "Linkage" );
	_xmlOutputXML.LinkEndChild(elmLinkage);

	//Add Linkage element 
	TiXmlElement * elmExpress = new TiXmlElement("Expressions");
	elmLinkage->LinkEndChild(elmExpress); 

	//Add Linkage element 
	TiXmlElement * elmPExpress = new TiXmlElement("ParameterExpressions");
	elmLinkage->LinkEndChild(elmPExpress);

	//Add Linkage element 
	_xmlComponent = new TiXmlElement("Components");
	elmLinkage->LinkEndChild(_xmlComponent);

	//Add Linkage element 
	_xmlConnection = new TiXmlElement("Connections");
	elmLinkage->LinkEndChild(_xmlConnection);

	//Get MDL Unit 

	ErrorLog::WriteInt("ExportXML::InitXML---> Out",0);
	return 0;
}
/*===========================================================================*\
Function    :   SaveXML
Input       :	Inertia *  - Inertia object
Output      :	
Returns     :   int
Purpose     :	Writes a components to an xml element 
Date		:	21/01/2014
Author		:	Suresh
\*===========================================================================*/
int ExportXML::WriteComponent(Inertia * ipobjInertia, ProCharPath chrMassUnit, ProCharPath chrLengthUnit)
{
	ErrorLog::WriteInt("ExportXML::WriteComponent---> In",0);
	
	TiXmlElement * pXmlElem;
	
	//If its a Ground than Ground element else RigidBody element 
	if(strcmpi(ipobjInertia->bdyName, _pchrGround)==0)
	{
		pXmlElem = new TiXmlElement("Ground");  
	}
	else
	{
		pXmlElem = new TiXmlElement("RigidBody");
	}
	
	//Add name 
	pXmlElem->SetAttribute("name",ipobjInertia->bdyName); 
	_xmlComponent->LinkEndChild(pXmlElem); 

	//*********************************CG***************************************************//
	TiXmlElement * xmlCGElem = new TiXmlElement("CG");
	pXmlElem->LinkEndChild(xmlCGElem);

	TiXmlElement * xmlPoint = new TiXmlElement("Point");
	xmlCGElem->LinkEndChild(xmlPoint);


	//Write X values 
	TiXmlElement * xmlX = new TiXmlElement("x");
	xmlPoint->LinkEndChild(xmlX);
	TiXmlElement * xmlXVal = new TiXmlElement("value");
	xmlX->LinkEndChild( xmlXVal); 
	xmlXVal->LinkEndChild(new TiXmlText(ipobjInertia->COGX)); 
	TiXmlElement * xmlXUnit = new TiXmlElement("unit");
	xmlX->LinkEndChild( xmlXUnit);
	xmlXUnit->LinkEndChild(new TiXmlText(chrLengthUnit)); 

	//Write Y values 
	TiXmlElement * xmlY = new TiXmlElement("y");
	xmlPoint->LinkEndChild(xmlY);
	TiXmlElement * xmlYVal = new TiXmlElement("value");
	xmlY->LinkEndChild( xmlYVal); 
	xmlYVal->LinkEndChild(new TiXmlText(ipobjInertia->COGY)); 
	TiXmlElement * xmlYUnit = new TiXmlElement("unit");
	xmlY->LinkEndChild( xmlYUnit);
	xmlYUnit->LinkEndChild(new TiXmlText(chrLengthUnit)); 

	//Write Y values 
	TiXmlElement * xmlZ = new TiXmlElement("z");
	xmlPoint->LinkEndChild(xmlZ);
	TiXmlElement * xmlZVal = new TiXmlElement("value");
	xmlZ->LinkEndChild( xmlZVal); 
	xmlZVal->LinkEndChild(new TiXmlText(ipobjInertia->COGZ)); 
	TiXmlElement * xmlZUnit = new TiXmlElement("unit");
	xmlZ->LinkEndChild( xmlZUnit);
	xmlZUnit->LinkEndChild(new TiXmlText(chrLengthUnit)); 

	//Write Mass values to CG
	TiXmlElement * xmlMassElem = new TiXmlElement("Mass");
	xmlCGElem->LinkEndChild(xmlMassElem);
	//Write Mass Value
	TiXmlElement * xmlMassValue = new TiXmlElement("value");
	xmlMassElem->LinkEndChild(xmlMassValue);
	xmlMassValue->LinkEndChild(new TiXmlText(ipobjInertia->Mass));
	
	//Write Mass util Value
	TiXmlElement * xmlMassUnitElem = new TiXmlElement("unit");
	xmlMassElem->LinkEndChild(xmlMassUnitElem);
	xmlMassUnitElem->LinkEndChild(new TiXmlText(chrMassUnit));
	//*********************************CG***************************************************//

	//*****************************InertiaMatrix********************************************//
	TiXmlElement * xmlInertiaMatrx = new TiXmlElement("InertiaMatrix");
	pXmlElem->LinkEndChild(xmlInertiaMatrx);

	ProCharPath chrInertiaUnit;
	strcpy(chrInertiaUnit, chrMassUnit);
	strcat(chrInertiaUnit, "*");
	strcat(chrInertiaUnit, chrLengthUnit);
	strcat(chrInertiaUnit, "^2");

	//Add I11 value
	TiXmlElement *InertI11 = new TiXmlElement("i11"); 
	xmlInertiaMatrx->LinkEndChild(InertI11); 
	TiXmlElement *I11Val = new TiXmlElement("value");
	InertI11->LinkEndChild(I11Val);
	I11Val->LinkEndChild(new TiXmlText(ipobjInertia->I11));  
	TiXmlElement *I11UnitElem = new TiXmlElement("unit");
	InertI11->LinkEndChild(I11UnitElem); 
	I11UnitElem->LinkEndChild(new TiXmlText(chrInertiaUnit));

	//Add I12 value
	TiXmlElement *InertI12 = new TiXmlElement("i12"); 
	xmlInertiaMatrx->LinkEndChild(InertI12); 
	TiXmlElement *I12Val = new TiXmlElement("value");
	InertI12->LinkEndChild(I12Val);
	I12Val->LinkEndChild(new TiXmlText(ipobjInertia->I12));  
	TiXmlElement *I12UnitElem = new TiXmlElement("unit");
	InertI12->LinkEndChild(I12UnitElem); 
	I12UnitElem->LinkEndChild(new TiXmlText(chrInertiaUnit));

	//Add I13 value
	TiXmlElement *InertI13 = new TiXmlElement("i13"); 
	xmlInertiaMatrx->LinkEndChild(InertI13); 
	TiXmlElement *I13Val = new TiXmlElement("value");
	InertI13->LinkEndChild(I13Val);
	I13Val->LinkEndChild(new TiXmlText(ipobjInertia->I13));  
	TiXmlElement *I13UnitElem = new TiXmlElement("unit");
	InertI13->LinkEndChild(I13UnitElem); 
	I13UnitElem->LinkEndChild(new TiXmlText(chrInertiaUnit));

	//Add I22 value
	TiXmlElement *InertI22 = new TiXmlElement("i22"); 
	xmlInertiaMatrx->LinkEndChild(InertI22); 
	TiXmlElement *I22Val = new TiXmlElement("value");
	InertI22->LinkEndChild(I22Val);
	I22Val->LinkEndChild(new TiXmlText(ipobjInertia->I22));  
	TiXmlElement *I22UnitElem = new TiXmlElement("unit");
	InertI22->LinkEndChild(I22UnitElem); 
	I22UnitElem->LinkEndChild(new TiXmlText(chrInertiaUnit));

	//Add I23 value
	TiXmlElement *InertI23 = new TiXmlElement("i23"); 
	xmlInertiaMatrx->LinkEndChild(InertI23); 
	TiXmlElement *I23Val = new TiXmlElement("value");
	InertI23->LinkEndChild(I23Val);
	I23Val->LinkEndChild(new TiXmlText(ipobjInertia->I23));  
	TiXmlElement *I23UnitElem = new TiXmlElement("unit");
	InertI23->LinkEndChild(I23UnitElem); 
	I23UnitElem->LinkEndChild(new TiXmlText(chrInertiaUnit));

	//Add I33 value
	TiXmlElement *InertI33 = new TiXmlElement("i33"); 
	xmlInertiaMatrx->LinkEndChild(InertI33); 
	TiXmlElement *I33Val = new TiXmlElement("value");
	InertI33->LinkEndChild(I33Val);
	I33Val->LinkEndChild(new TiXmlText(ipobjInertia->I33));  
	TiXmlElement *I33UnitElem = new TiXmlElement("unit");
	InertI33->LinkEndChild(I33UnitElem); 
	I33UnitElem->LinkEndChild(new TiXmlText(chrInertiaUnit));

	//*****************************InertiaMatrix********************************************//

	ErrorLog::WriteInt("ExportXML::WriteComponent---> Out",0);
	return 0;
}

/*===========================================================================*\
Function    :   SaveXML
Input       :	  
Output      :	
Returns     :   int
Purpose     :	Saves the XMl file
Date		:	21/01/2014
Author		:	Suresh
\*===========================================================================*/
int ExportXML::WriteConnection(Connection * ipobjConnection, ConnDtl * ipobjConnDtl, ProCharPath chrLengthUnit)
{
	ErrorLog::WriteInt("ExportXML::WriteConnection---> In",0);
	
	//Write connection data 
	//Get connection Type
	ProCharPath chrConnType;
	GetConnectionTypeText(ipobjConnDtl, chrConnType);

	TiXmlElement * xmlJointName = new TiXmlElement(chrConnType); 
	_xmlConnection->LinkEndChild(xmlJointName);
	xmlJointName->SetAttribute("name",ipobjConnection->ConnectionName); 

	//Write Bodyref1 value
	WriteBodyRef("BodyRef_1", ipobjConnection->BodyFrom, xmlJointName, ipobjConnDtl->VectorFrom, chrLengthUnit);

	//Write Bodyref2 value 
	WriteBodyRef("BodyRef_2", ipobjConnection->BodyTo, xmlJointName, ipobjConnDtl->VectorTo, chrLengthUnit);

	ErrorLog::WriteInt("ExportXML::WriteConnection---> Out",0);
	return 0;
}
/*===========================================================================*\
Function    :   WriteBodyRef
Input       :	ProCharName - name  , TiXmlElement * - element ,ProVector - Ref point
Output      :	
Returns     :   int
Purpose     :	Returns the connection string as per the type 
Date		:	21/01/2014
Author		:	Suresh
\*===========================================================================*/
int ExportXML::WriteBodyRef(ProCharName chrBodyRef, ProCharName chrBody, TiXmlElement * xmlJointName, ProVector vctBodyVector, ProCharPath chrLengthUnit)
{
	ErrorLog::WriteInt("ExportXML::WriteBodyRef---> In",0);

	//Writing body details
	TiXmlElement *xmlBdyRef = new TiXmlElement(chrBodyRef);
	xmlJointName->LinkEndChild(xmlBdyRef);
	TiXmlElement *xmlBdy1Identifier = new TiXmlElement("Identifier");
	xmlBdyRef->LinkEndChild( xmlBdy1Identifier);
	xmlBdy1Identifier->LinkEndChild(new TiXmlText(chrBody));

	//Add point value
	TiXmlElement *xmlBdyRef1Point = new TiXmlElement("Point");
	xmlBdyRef->LinkEndChild(xmlBdyRef1Point);

	//Write X value
	TiXmlElement *xmlBdyRef1PntX = new TiXmlElement("x");
	xmlBdyRef1Point->LinkEndChild(xmlBdyRef1PntX);

	TiXmlElement *xmlBdyRef1Xval = new TiXmlElement("value");
	xmlBdyRef1PntX->LinkEndChild(xmlBdyRef1Xval);
	ostringstream strBdy1Xval;
	strBdy1Xval<<vctBodyVector[0];
	xmlBdyRef1Xval->LinkEndChild(new TiXmlText(strBdy1Xval.str().c_str()));
	TiXmlElement *xmlBdyRef1Xunit = new TiXmlElement("unit");
	xmlBdyRef1PntX->LinkEndChild(xmlBdyRef1Xunit);
	xmlBdyRef1Xunit->LinkEndChild(new TiXmlText(chrLengthUnit));

	//Write Y value
	TiXmlElement *xmlBdyRef1PntY = new TiXmlElement("y");
	xmlBdyRef1Point->LinkEndChild(xmlBdyRef1PntY);

	TiXmlElement *xmlBdyRef1Yval = new TiXmlElement("value");
	xmlBdyRef1PntY->LinkEndChild(xmlBdyRef1Yval);
	ostringstream strBdy1Yval;
	strBdy1Yval<<vctBodyVector[1];
	xmlBdyRef1Yval->LinkEndChild(new TiXmlText(strBdy1Yval.str().c_str()));
	TiXmlElement *xmlBdyRef1Yunit = new TiXmlElement("unit");
	xmlBdyRef1PntY->LinkEndChild(xmlBdyRef1Yunit);
	xmlBdyRef1Yunit->LinkEndChild(new TiXmlText(chrLengthUnit));

	//Write Z value
	TiXmlElement *xmlBdyRef1PntZ = new TiXmlElement("z");
	xmlBdyRef1Point->LinkEndChild(xmlBdyRef1PntZ);

	TiXmlElement *xmlBdyRef1Zval = new TiXmlElement("value");
	xmlBdyRef1PntZ->LinkEndChild(	xmlBdyRef1Zval);
	ostringstream strBdy1Zval;
	strBdy1Zval<<vctBodyVector[2];
	xmlBdyRef1Zval->LinkEndChild(new TiXmlText(strBdy1Zval.str().c_str()));
	TiXmlElement *xmlBdyRef1Zunit = new TiXmlElement("unit");
	xmlBdyRef1PntZ->LinkEndChild(xmlBdyRef1Zunit);
	xmlBdyRef1Zunit->LinkEndChild(new TiXmlText(chrLengthUnit));

	//Add Action vector 
	ProVector objAVector;
	objAVector[0]= 0;
	objAVector[1]= 0;
	objAVector[2]= 1;
	AddActionRefVector("ActionVector", xmlBdyRef, objAVector);

	//ProVector objVector
	ProVector objRVector;
	objRVector[0]= 1;
	objRVector[1]= 0;
	objRVector[2]= 0;
	AddActionRefVector("ReferenceVector", xmlBdyRef, objRVector);

	ErrorLog::WriteInt("ExportXML::WriteBodyRef---> Out",0);
	return 0;
}
/*===========================================================================*\
Function    :   AddActionRefVector
Input       :	ProCharLine -  Action or erference , TiXmlElement *  -element , 
				ProVector Action or Reference vector
Output      :	
Returns     :   int
Purpose     :	To write Action or Reference Vector
Date		:	21/01/2014
Author		:	Suresh
\*===========================================================================*/
int ExportXML::AddActionRefVector(ProCharLine chrType, TiXmlElement *xmlBdyRef, ProVector objVector)
{
	ErrorLog::WriteInt("ExportXML::AddActionRefVector---> In",0);
	
	TiXmlElement *bdy1ActVectElem = new TiXmlElement(chrType);
	xmlBdyRef->LinkEndChild(bdy1ActVectElem);

	TiXmlElement *bdy1ActVectXElem = new TiXmlElement("x");
	bdy1ActVectElem->LinkEndChild(bdy1ActVectXElem);

	ostringstream ostrActVectBdy1X;
	ostrActVectBdy1X<<objVector[0];
	bdy1ActVectXElem->LinkEndChild(new TiXmlText(ostrActVectBdy1X.str().c_str()));

	TiXmlElement *bdy1ActVectYElem = new TiXmlElement("y");
	bdy1ActVectElem->LinkEndChild(bdy1ActVectYElem);
	ostringstream ostrActVectBdy1Y;
	ostrActVectBdy1Y<<objVector[1];
	bdy1ActVectYElem->LinkEndChild(new TiXmlText(ostrActVectBdy1Y.str().c_str()));

	TiXmlElement *bdy1ActVectZElem = new TiXmlElement("z");
	bdy1ActVectElem->LinkEndChild(bdy1ActVectZElem);
	ostringstream ostrActVectBdy1Z;
	ostrActVectBdy1Z<<objVector[2];
	bdy1ActVectZElem->LinkEndChild(new TiXmlText(ostrActVectBdy1Z.str().c_str()));

	TiXmlElement *bdy1ActVectXValElem = new TiXmlElement("x_val");
	bdy1ActVectElem->LinkEndChild(bdy1ActVectXValElem);
	bdy1ActVectXValElem->LinkEndChild(new TiXmlText(ostrActVectBdy1X.str().c_str()));

	TiXmlElement *bdy1ActVectYValElem = new TiXmlElement("y_val");
	bdy1ActVectElem->LinkEndChild(bdy1ActVectYValElem);
	bdy1ActVectYValElem->LinkEndChild(new TiXmlText(ostrActVectBdy1Y.str().c_str()));

	TiXmlElement *bdy1ActVectZValElem = new TiXmlElement("z_val");
	bdy1ActVectElem->LinkEndChild(bdy1ActVectZValElem);
	bdy1ActVectZValElem->LinkEndChild(new TiXmlText(ostrActVectBdy1Z.str().c_str()));

	ErrorLog::WriteInt("ExportXML::AddActionRefVector---> Out",0);
	return 0;
}

/*===========================================================================*\
Function    :   GetConnectionTypeText
Input       :	ConnDtl*  
Output      :	ProCharPath - Connection string to write into XML file
Returns     :   int
Purpose     :	Returns the connection string as per the type 
Date		:	21/01/2014
Author		:	Suresh
\*===========================================================================*/
int ExportXML::GetConnectionTypeText(ConnDtl * ipobjConnDtl, ProCharPath chrConnType)
{
	ErrorLog::WriteInt("ExportXML::GetConnectionTypeText---> In",0);

	switch(ipobjConnDtl->Type)
	{
	case PRO_ASM_SET_TYPE_PIN:
		strcpy(chrConnType, "HingeJoint"); 
		break;
	case PRO_ASM_SET_TYPE_SLIDER:
		strcpy(chrConnType, "HingeJoint"); 
		break;
	case PRO_ASM_SET_TYPE_CYLINDRICAL:
		strcpy(chrConnType, "CylindricalJoint"); 
		break;
	case PRO_ASM_SET_TYPE_PLANAR:
		break;
	case PRO_ASM_SET_TYPE_BALL:
		break;
	case PRO_ASM_SET_TYPE_WELD:
		break;
	case PRO_ASM_SET_TYPE_BEARING:
		break;
	case PRO_ASM_SET_TYPE_GENERAL:
		break;
	case PRO_ASM_SET_TYPE_6DOF:
		break;
	case PRO_ASM_SET_TYPE_SLOT:
		break;
		//case PRO_ASM_SET_TYPE_GIMBAL:
		//		break;
	case PRO_ASM_SET_TYPE_FIXED:
		strcpy(chrConnType, "RigidJoint"); 
		break;
	default:
		strcpy(chrConnType, "UserDefinedJoint"); 
		break;
	}
	ErrorLog::WriteInt("ExportXML::GetConnectionTypeText---> Out",0);
	return 0;
}
/*===========================================================================*\
Function    :   SaveXML
Input       :	  
Output      :	
Returns     :   int
Purpose     :	Saves the XMl file
Date		:	21/01/2014
Author		:	Suresh
\*===========================================================================*/
int ExportXML::SaveXML(const std::string strXmlName)
{
	ErrorLog::WriteInt("ExportXML::SaveXML---> In",0);

	//Save xml 
	_xmlOutputXML.SaveFile(strXmlName);
	
	ErrorLog::WriteInt("ExportXML::SaveXML---> Out",0);
	return 0;
}