#include "CVertexUnit.h"
#include "../CException.h"
#include "CUnit.h"
#include "../CVertex.h"

void CVertexUnit::VERUnitTest()
{
	VERUnitTestConstructorGetSet();
	VERUnitTestArcIn();
	VERUnitTestArcOut();
	VERUnitTestOperators();
}

void CVertexUnit::VERUnitTestConstructorGetSet()
{
	/* Test empty constructor, shouldn't be used */
	try
	{
		CVertex();
		CUnit::UNITassertError("ASSERT VERTEX A1");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != MISSING_VERTEX_INDEX_EXCEPTION)
			CUnit::UNITassertError("ASSERT VERTEX A2");
	}
	
	/* Test confort constructor & index getter */
	CVertex oVERvertex1 = CVertex(5);
	CVertex oVERvertex2 = CVertex(15);
	
	if(oVERvertex1.VERgetVertexIndex() != 5 || oVERvertex2.VERgetVertexIndex() != 15)
		CUnit::UNITassertError("ASSERT VERTEX A3");
}

void CVertexUnit::VERUnitTestArcIn()
{
	/* Test add arcIn */
	CVertex oVERvertex = CVertex(0);
	
	oVERvertex.VERaddArcIn(10);
	if(!oVERvertex.VERhasIndexIn(10) || oVERvertex.VERgetArcInCount() != 1)
		CUnit::UNITassertError("ASSERT VERTEX B1");
	
	/* Test adding duplicate */
	try
	{
		oVERvertex.VERaddArcIn(10);
		CUnit::UNITassertError("ASSERT VERTEX B2");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != DUPLICATE_ARC_EXCEPTION)
			CUnit::UNITassertError("ASSERT VERTEX B3");
	}
	
	/* Test removing arcIn */
	oVERvertex.VERremoveArcIn(10);
	if(oVERvertex.VERhasIndexIn(10) || oVERvertex.VERgetArcInCount() != 0)
		CUnit::UNITassertError("ASSERT VERTEX B4");
	
	/* Test removing unknown arcIn */
	oVERvertex.VERremoveArcIn(99);
	
	/* Test modifying existing arcIn */
	oVERvertex.VERaddArcIn(15);
	oVERvertex.VERmodifyArcIn(15, 30);
	if(oVERvertex.VERhasIndexIn(15) || !oVERvertex.VERhasIndexIn(30) || oVERvertex.VERgetArcInCount() != 1)
		CUnit::UNITassertError("ASSERT VERTEX B5");
	
	/* Test modifying unknown arcIn */
	oVERvertex.VERmodifyArcIn(15, 20);
	if(oVERvertex.VERhasIndexIn(15) || oVERvertex.VERhasIndexIn(20))
		CUnit::UNITassertError("ASSERT VERTEX B6");
}

void CVertexUnit::VERUnitTestArcOut()
{
	/* Test add arcOut */
	CVertex oVERvertex = CVertex(0);
	
	oVERvertex.VERaddArcOut(10);
	if(!oVERvertex.VERhasIndexOut(10) || oVERvertex.VERgetArcOutCount() != 1)
		CUnit::UNITassertError("ASSERT VERTEX C1");
	
	/* Test adding duplicate */
	try
	{
		oVERvertex.VERaddArcOut(10);
		CUnit::UNITassertError("ASSERT VERTEX C2");
	}
	catch(CException const &oEXexception)
	{
		if(oEXexception.EXgetExceptionID() != DUPLICATE_ARC_EXCEPTION)
			CUnit::UNITassertError("ASSERT VERTEX C3");
	}
	
	/* Test removing arcOut */
	oVERvertex.VERremoveArcOut(10);
	if(oVERvertex.VERhasIndexOut(10) || oVERvertex.VERgetArcOutCount() != 0)
		CUnit::UNITassertError("ASSERT VERTEX C4");
	
	/* Test removing unknown arcOut */
	oVERvertex.VERremoveArcOut(99);
	
	/* Test modifying existing arcOut */
	oVERvertex.VERaddArcOut(15);
	oVERvertex.VERmodifyArcOut(15, 30);
	if(oVERvertex.VERhasIndexOut(15) || !oVERvertex.VERhasIndexOut(30) || oVERvertex.VERgetArcOutCount() != 1)
		CUnit::UNITassertError("ASSERT VERTEX C5");
	
	/* Test modifying unknown arcOut */
	oVERvertex.VERmodifyArcOut(15, 20);
	if(oVERvertex.VERhasIndexOut(15) || oVERvertex.VERhasIndexOut(20))
		CUnit::UNITassertError("ASSERT VERTEX C6");
}

void CVertexUnit::VERUnitTestOperators()
{
	CVertex * poVERvertex1 = new CVertex(15);
	poVERvertex1->VERaddArcIn(13);
	poVERvertex1->VERaddArcIn(14);
	poVERvertex1->VERaddArcOut(13);
	
	CVertex oVERvertex2 = CVertex(2);
	oVERvertex2 = *poVERvertex1;
	if(oVERvertex2.VERgetVertexIndex() != 15 || !oVERvertex2.VERhasIndexIn(13) || !oVERvertex2.VERhasIndexIn(14) || !oVERvertex2.VERhasIndexOut(13))
		CUnit::UNITassertError("ASSERT VERTEX D1");
	
	delete poVERvertex1;
	
	oVERvertex2.VERaddArcIn(16);
	oVERvertex2.VERaddArcOut(17);
	
	oVERvertex2.VERremoveArcIn(16);
	oVERvertex2.VERremoveArcIn(17);
	
	CVertex oVERvertex3 = CVertex(oVERvertex2);
	if(oVERvertex3.VERgetVertexIndex() != 15 || !oVERvertex3.VERhasIndexIn(13) || !oVERvertex3.VERhasIndexIn(14) || !oVERvertex3.VERhasIndexOut(13))
		CUnit::UNITassertError("ASSERT VERTEX D2");
}
