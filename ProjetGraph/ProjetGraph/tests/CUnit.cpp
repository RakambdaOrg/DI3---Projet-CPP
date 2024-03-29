#include <iostream>
#include "CUnit.h"
#include "CExceptionUnit.h"
#include "CArcUnit.h"
#include "CVertexUnit.h"
#include "CGraphUnit.h"
#include "CGraphParserUnit.h"
#include "CHashMapUnit.h"
#include "../CException.h"
#include "CGraphToolboxUnit.h"

void CUnit::UNITassertError(const char * pcMessage)
{
	perror(pcMessage);
	perror("\n");
#ifdef _MSC_VER
	throw CException(0, (char *) "BREAKPOINT UNIT TESTS");
#else
	raise(SIGINT);
#endif
	exit(EXIT_FAILURE);
}

void CUnit::UNITlaunchTests()
{
	std::cout << "Starting CException tests..." << std::endl;
	CExceptionUnit::EXUnitTests();
	std::cout << "CException OK" << std::endl << std::endl;
	
	std::cout << "Starting CHashMap tests..." << std::endl;
	CHashMapUnit::HMPUnitTest();
	std::cout << "CHashMap OK" << std::endl << std::endl;
	
	std::cout << "Starting CArc tests..." << std::endl;
	CArcUnit::ARCUnitTests();
	std::cout << "CArc OK" << std::endl << std::endl;
	
	std::cout << "Starting CVertex tests..." << std::endl;
	CVertexUnit::VERUnitTest();
	std::cout << "CVertex OK" << std::endl << std::endl;
	
	std::cout << "Starting CGraphParser tests..." << std::endl;
	CGraphParserUnit::PGRAUnitTests();
	std::cout << "CGraphParser OK" << std::endl << std::endl;
	
	std::cout << "Starting CGraph tests..." << std::endl;
	CGraphUnit::GRAUnitTests();
	std::cout << "CGraph OK" << std::endl << std::endl;
	
	std::cout << "Starting CGraphToolbox tests..." << std::endl;
	CGraphToolboxUnit::GRTUnitTests();
	std::cout << "CGraphToolbox OK" << std::endl << std::endl;
}
