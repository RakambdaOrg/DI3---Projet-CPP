cmake_minimum_required(VERSION 3.7)
project(ProjetMatrice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ProjetMatrice/ProjetMatrice.cpp

        ProjetMatrice/CException.cpp ProjetMatrice/CException.h
        ProjetMatrice/tests/CExceptionUnit.cpp ProjetMatrice/tests/CExceptionUnit.h

        ProjetMatrice/CMatrix.h
        ProjetMatrice/tests/CMatrixUnit.cpp ProjetMatrice/tests/CMatrixUnit.h

        ProjetMatrice/CSquareMatrix.h
        ProjetMatrice/tests/CSquareMatrixUnit.cpp ProjetMatrice/tests/CSquareMatrixUnit.h

        ProjetMatrice/CMatrixParser.cpp ProjetMatrice/CMatrixParser.h
        ProjetMatrice/tests/CMatrixParserUnit.cpp ProjetMatrice/tests/CMatrixParserUnit.h

        ProjetMatrice/utils.h
        ProjetMatrice/tests/CUnit.cpp ProjetMatrice/tests/CUnit.h
        )
add_executable(ProjetMatrice ${SOURCE_FILES})
