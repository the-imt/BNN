/**********************************************************************
 * bnn_test.cpp
 * 
 * Entry point and manager for BNN's test framework.
 * 
 * 
 * Copyright (c) 2024, Colin Wass
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 * the following conditions are met:

 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the
 * following disclaimer.

 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 * following disclaimer in the documentation and/or other materials provided with the distribution.

 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
 * promote products derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * 
 **********************************************************************/
 
 
#include "bnn_test.h"

int main(int argc, char* argv[])  {
		
		// Matrices and vectors needed for testing
		
		Eigen::Matrix<float, 2, 1> testVec20(0.0, 0.0);
		Eigen::Matrix<float, 2, 1> testVec21(1.0, 0.0);
		Eigen::Matrix<float, 2, 1> testVec22(0.0, 1.0);
		Eigen::Matrix<float, 2, 1> testVec23(1.0, 1.0);
		
		Eigen::Matrix<float, 4, 1> testVec40(0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 4, 1> testVec41(0.0, 0.0, 0.0, 1.0);
		Eigen::Matrix<float, 4, 1> testVec42(0.0, 0.0, 1.0, 0.0);
		Eigen::Matrix<float, 4, 1> testVec43(0.0, 0.0, 1.0, 1.0);
		Eigen::Matrix<float, 4, 1> testVec44(0.0, 1.0, 0.0, 0.0);
		Eigen::Matrix<float, 4, 1> testVec45(0.0, 1.0, 0.0, 1.0);
		Eigen::Matrix<float, 4, 1> testVec46(0.0, 1.0, 1.0, 0.0);
		Eigen::Matrix<float, 4, 1> testVec47(0.0, 1.0, 1.0, 1.0);
		Eigen::Matrix<float, 4, 1> testVec48(1.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 4, 1> testVec49(1.0, 0.0, 0.0, 1.0);
		Eigen::Matrix<float, 4, 1> testVec410(1.0, 0.0, 1.0, 0.0);
		Eigen::Matrix<float, 4, 1> testVec411(1.0, 0.0, 1.0, 1.0);
		Eigen::Matrix<float, 4, 1> testVec412(1.0, 1.0, 0.0, 0.0);
		Eigen::Matrix<float, 4, 1> testVec413(1.0, 1.0, 0.0, 1.0);
		Eigen::Matrix<float, 4, 1> testVec414(1.0, 1.0, 1.0, 0.0);
		Eigen::Matrix<float, 4, 1> testVec415(1.0, 1.0, 1.0, 1.0);
		
		// only test a sample, if needed we can change this to all or whatever
		
		Eigen::Matrix<float, 6, 1> testVec30(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec31(1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec32(0.0, 1.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec33(1.0, 1.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec34(0.0, 1.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec35(0.0, 1.0, 1.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec36(0.0, 0.0, 1.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec37(1.0, 1.0, 1.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec38(0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec39(1.0, 0.0, 0.0, 1.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec310(0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec311(1.0, 1.0, 0.0, 0.0, 0.0, 1.0);
		Eigen::Matrix<float, 6, 1> testVec312(0.0, 1.0, 0.0, 1.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec313(0.0, 1.0, 1.0, 1.0, 0.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec314(0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
		Eigen::Matrix<float, 6, 1> testVec315(1.0, 1.0, 1.0, 0.0, 0.0, 1.0);
		
		Eigen::Matrix<float, 10, 1> testVec101(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec102(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec103(1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec104(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec105(0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec106(0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec107(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
		Eigen::Matrix<float, 10, 1> testVec108(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec109(0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
		Eigen::Matrix<float, 10, 1> testVec1010(0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec1011(0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec1012(0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec1013(1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0);
		Eigen::Matrix<float, 10, 1> testVec1014(1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0);
		Eigen::Matrix<float, 10, 1> testVec1015(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
		Eigen::Matrix<float, 10, 1> testVec1016(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		Eigen::Matrix<float, 10, 1> testVec1017(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		
		
		// Start at the beginning
		
		std::cout << "starting testing of BNNs, expected output in braces." << std::endl;
		
		std::cout << std::endl << " open with simple compares/XOR." << std::endl << std::endl;
		std::cout << "1 - 1:   testing 0.0 == 0.0 (0):  " << tester.testEqual(0.0, 0.0) << std::endl;
		std::cout << "1 - 2:   testing 1.0 == 0.0 (1): " << tester.testEqual(1.0, 0.0) << std::endl;
		std::cout << "1 - 3:   testing 0.0 == 1.0 (1):  " << tester.testEqual(0.0, 1.0) << std::endl;
		std::cout << "1 - 4:   testing 1.0 == 1.0 (0):  " << tester.testEqual(1.0, 1.0) << std::endl;
		std::cout << std::endl;
		std::cout << "2 - 1:   testing compare 2 elements, 0.0, 0.0 and 0.0, 0.0 (0):  " << tester.compare2Vectors(testVec20, testVec20) << std::endl;
		std::cout << "2 - 2:   testing compare 2 elements, 0.0, 0.0 and 1.0, 0.0 (1):  "<< tester.compare2Vectors(testVec20, testVec21) << std::endl;
		std::cout << "2 - 3:   testing compare 2 elements, 1.0, 0.0 and 0.0, 0.0 (1):  "<< tester.compare2Vectors(testVec21, testVec20) << std::endl;
		std::cout << "2 - 4:   testing compare 2 elements, 1.0, 1.0 and 1.0, 1.0 (0):  "<< tester.compare2Vectors(testVec23, testVec23) << std::endl;
		std::cout << "2 - 5:   testing compare 2 elements, 1.0, 1.0 and 0.0, 1.0 (1):  "<< tester.compare2Vectors(testVec23, testVec22) << std::endl;
		std::cout << std::endl;
		std::cout << "3 - 1:   testing compare 4 elements, 0.0, 0.0, 0.0, 0.0 and 1.0, 1.0, 1.0, 1.0 (1):  "<< tester.compare4Vectors(testVec40, testVec415) << std::endl;
		std::cout << "3 - 2:   testing compare 4 elements, 0.0, 1.0, 0.0, 1.0 and 0.0, 1.0, 0.0, 1.0 (0):  "<< tester.compare4Vectors(testVec45, testVec45) << std::endl;
		std::cout << "3 - 3:   testing compare 4 elements, 1.0, 0.0, 0.0, 1.0 and 1.0, 0.0, 0.0, 0.0 (1):  "<< tester.compare4Vectors(testVec49, testVec48) << std::endl;
		std::cout << "3 - 4:   testing compare 4 elements, 1.0, 1.0, 1.0, 1.0 and 1.0, 1.0, 1.0, 1.0 (0):  "<< tester.compare4Vectors(testVec415, testVec415) << std::endl;
		std::cout << "3 - 5:   testing compare 4 elements, 0.0, 0.0, 0.0, 0.0 and 0.0, 0.0, 0.0, 0.0 (0):  "<< tester.compare4Vectors(testVec40, testVec40) << std::endl;
		std::cout << std::endl;
		std::cout << "4 - 1:  testing compare 6 elements, 0,0,0,0,0,0 and 0,0,0,0,0,0 (0):  " << tester.compare6Vectors(testVec30, testVec30) << std::endl;
		std::cout << "4 - 2:  testing compare 6 elements, 1,0,0,0,0,0 and 0,0,0,0,0,0 (1):  " << tester.compare6Vectors(testVec31, testVec30) << std::endl;
		std::cout << "4 - 3:  testing compare 6 elements, 0,1,0,0,0,0 and 0,1,0,0,0,0 (0):  " << tester.compare6Vectors(testVec32, testVec32) << std::endl;
		std::cout << "4 - 4:  testing compare 6 elements, 0,1,0,0,0,0 and 0,1,0,0,1,0 (1):  " << tester.compare6Vectors(testVec32, testVec310) << std::endl;
		std::cout << "4 - 5:  testing compare 6 elements, 1,1,0,0,0,0 and 1,1,0,0,0,0 (0):  " << tester.compare6Vectors(testVec33, testVec33) << std::endl;
		std::cout << "4 - 6:  testing compare 6 elements, 1,1,0,0,0,0 and 1,1,1,0,0,1 (1):  " << tester.compare6Vectors(testVec33, testVec315) << std::endl;
		std::cout << "4 - 7:  testing compare 6 elements, 1,1,1,0,0,1 and 0,0,0,0,0,0 (1):  " << tester.compare6Vectors(testVec315, testVec30) << std::endl;
		std::cout << "4 - 8:  testing compare 6 elements, 0,0,1,0,0,0 and 0,1,1,1,0,0 (1):  " << tester.compare6Vectors(testVec36, testVec313) << std::endl;
		std::cout << "4 - 9:  testing compare 6 elements, 0,1,1,0,0,0 and 0,0,1,0,0,0 (1):  " << tester.compare6Vectors(testVec35, testVec36) << std::endl;
		std::cout << std::endl;
		std::cout << "5 - 1:  testing compare 10 elements, 0,0,0,0,0,0,0,0,0,0 and 0,0,0,0,0,0,0,0,0,0 (0):  " << tester.compare10Vectors(testVec101, testVec101) << std::endl;
		std::cout << "5 - 2:  testing compare 10 elements, 1,1,1,1,1,1,1,1,1,1 and 1,1,1,1,1,1,1,1,1,1 (0):  " << tester.compare10Vectors(testVec1015, testVec1015) << std::endl;
		std::cout << "5 - 3:  testing compare 10 elements, 1,0,0,0,0,0,0,0,0,0 and 0,0,0,0,0,0,0,0,0,0 (1):  " << tester.compare10Vectors(testVec102, testVec101) << std::endl;
		std::cout << "5 - 4:  testing compare 10 elements, 1,0,0,1,1,1,1,1,0,1 and 1,1,1,1,1,1,1,1,1,1 (1):  " << tester.compare10Vectors(testVec1013, testVec1015) << std::endl;
		std::cout << "5 - 5:  testing compare 10 elements, 0,0,0,1,0,1,0,1,0,0 and 0,0,0,1,0,1,0,1,0,0 (1):  " << tester.compare10Vectors(testVec105, testVec106) << std::endl;
		std::cout << "5 - 6:  testing compare 10 elements, 1,1,0,0,0,0,0,0,0,0 and 0,0,1,0,0,0,0,0,0,0 (1):  " << tester.compare10Vectors(testVec103, testVec104) << std::endl;
		std::cout << "5 - 7:  testing compare 10 elements, 0,0,1,1,0,0,0,1,1,1 and 1,0,0,0,0,0,0,0,0,1 (1):  " << tester.compare10Vectors(testVec109, testVec107) << std::endl;
		std::cout << "5 - 8:  testing compare 10 elements, 0,0,0,0,1,1,1,0,0,0 and 1,1,0,1,1,0,1,1,0,1 (1):  " << tester.compare10Vectors(testVec1010, testVec1014) << std::endl;
		std::cout << "5 - 9:  testing compare 10 elements, 0,1,1,0,0,0,0,0,1,0 and 1,0,0,1,1,1,1,1,0,1 (1):  " << tester.compare10Vectors(testVec1012, testVec1013) << std::endl;
		std::cout << "5 - 10:  testing compare 10 elements, 0,0,0,0,0,0,0,0,0,0 and 1,1,1,1,1,1,1,1,1,1 (1):  " << tester.compare10Vectors(testVec101, testVec1015) << std::endl;
		std::cout << "5 - 11:  testing compare 10 elements, 0,0,0,1,0,1,0,1,0,0 and 0,0,0,1,0,1,0,1,0,0 (0):  " << tester.compare10Vectors(testVec105, testVec105) << std::endl;
		std::cout << std::endl;
		
		Eigen::Matrix<float, 5, 1> adderTest(0.0, 0.0, 0.0, 0.0, 0.0);
		std::cout << "6 - 1:   testing add 4 elements starting at: " << adderTest.transpose() << std::endl; 
		adderTest = tester.add4Vectors(adderTest.block<4, 1>(1, 0), testVec41);
		std::cout << "6 - 1.0:  add 1 : " << adderTest.transpose() << std::endl; 
		for (int i = 0; i < 15; i++)  {
					adderTest = tester.add4Vectors(adderTest.block<4, 1>(1, 0), testVec41);
					std::cout << "6 - 1." << i+1 << ":  add 1 : " << adderTest.transpose() << std::endl; 
		}
		
		// Now do an arbitrary look up 
		// The output should equal the input, remember to change both the output and actual function call if you want to test a different value
		std::cout << std::endl;
		std::cout << "7 - 1: Lookup for value: " << testVec44.transpose() << " returns:  " << (tester.lookup4Vector(testVec44)).transpose() << std::endl;
		
		return 0;
	}




