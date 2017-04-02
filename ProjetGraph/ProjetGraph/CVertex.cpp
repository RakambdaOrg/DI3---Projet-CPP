#include <cstdlib>

#include "CVertex.h"
#include "CException.h"
#include "utils.h"

CVertex::CVertex()
{
	throw CException(MISSING_VERTEX_INDEX_EXCEPTION, (char *) "Use the constructor : CVertex(unsigned int)");
}

CVertex::CVertex(unsigned int uiVertexIndexParam) : uiVertexIndex(uiVertexIndexParam), uiArcInCount(0), uiArcOutCount(0), poARCinList(nullptr), poARCoutList(nullptr)
{
}

CVertex::~CVertex()
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		delete poARCinList[uiIndex];
	free(poARCinList);

	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		delete poARCoutList[uiIndex];
	free(poARCoutList);
}

void CVertex::VERaddArcIn(unsigned int uiFromVertexIndex)
{
	for(int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(uiFromVertexIndex == poARCinList[uiIndex]->ARCgetVertexIndex())
			throw CException(ARC_ALREADY_EXISTING_EXCEPTION, (char *)"This arc is already existing");

	RREALLOC(poARCinList, CArc *, ++uiArcInCount, "Fail realloc VERaddArcOut");
	poARCinList[uiArcInCount - 1] = new CArc(uiFromVertexIndex);
}

void CVertex::VERremoveArcIn(unsigned int uiFromVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(uiFromVertexIndex == poARCinList[uiIndex]->ARCgetVertexIndex())
		{
			delete poARCinList[uiIndex];
			poARCinList[uiIndex] = poARCinList[--uiArcInCount];
			RREALLOC(poARCinList, CArc *, uiArcInCount, "Fail realloc VERremoveArcOut");
			break;
		}
}

void CVertex::VERaddArcOut(unsigned int uiToVertexIndex)
{
	for(int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToVertexIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
			throw CException(ARC_ALREADY_EXISTING_EXCEPTION, (char *)"This arc is already existing");

	RREALLOC(poARCoutList, CArc *, ++uiArcOutCount, "Fail realloc VERaddArcOut");
	poARCoutList[uiArcOutCount - 1] = new CArc(uiToVertexIndex);
}

void CVertex::VERremoveArcOut(unsigned int uiToVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(uiToVertexIndex == poARCoutList[uiIndex]->ARCgetVertexIndex())
		{
			delete poARCoutList[uiIndex];
			poARCoutList[uiIndex] = poARCoutList[--uiArcOutCount];
			RREALLOC(poARCoutList, CArc *, uiArcOutCount, "Fail realloc VERremoveArcOut");
			break;
		}
}

unsigned int CVertex::VERgetVertexIndex()
{
	return uiVertexIndex;
}

void CVertex::VERmodifyArcIn(unsigned int uiLastFromVertexIndex, unsigned int uiNewFromVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcInCount; uiIndex++)
		if(poARCinList[uiIndex]->ARCgetVertexIndex() == uiLastFromVertexIndex){
			poARCinList[uiIndex]->ARCsetVertexIndex(uiNewFromVertexIndex);
			break;
		}
}

void CVertex::VERmodifyArcOut(unsigned int uiLastToVertexIndex, unsigned int uiNewToVertexIndex)
{
	for(unsigned int uiIndex = 0; uiIndex < uiArcOutCount; uiIndex++)
		if(poARCoutList[uiIndex]->ARCgetVertexIndex() == uiLastToVertexIndex){
			poARCoutList[uiIndex]->ARCsetVertexIndex(uiNewToVertexIndex);
			break;
		}
}
