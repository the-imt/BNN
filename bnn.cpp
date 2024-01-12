/**********************************************************************
 * bnn.cpp
 * 
 * Entry point and main space for testing BNNs
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
 
#include "bnn.h"

BNN::BNN()  {

	// This is for our friend XOR, or comparing 2 values
	W0 << 	1.0,1.0,
			0.5,0.5;
	W1 << 	1.0, -1.0;
	
	// Let the growing begin
	
	compare2First << 	1.0, 0.0, 1.0, 0.0,
						0.5, 0.0, 0.5, 0.0,
						0.0, 1.0, 0.0, 1.0,
						0.0, 0.5, 0.0, 0.5;
	
	compare2Second << 	1.0, -1.0, 1.0, -1.0;
	
	compare4First << 	1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
						0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0,
						0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
						0.0, 0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0,
						0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
						0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5, 0.0,
						0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0,
						0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5;
	
	compare4Second << 	1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0;
			
	compare6First << 	1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5,
			
	compare6Second << 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0;

	//This shit just keeps eating space
	compare10First << 	1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
						0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5,
			
	compare10Second << 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0;
	
	// The lookup matrix, the values here need not be constrained to 1 or 0 and the result from the lookup need not be activated
	// providing some additional capability/flexibility
	
	lookup4Vectors << 	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
						0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0,
						0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
						0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0;
	
	// Set up for the lookup piece, conveniently demonstrates using the tools developed to create vectors and matrices
	// for additional functionality
	currentVal << 0.0, 0.0, 0.0, 0.0, 0.0;
	add14 << 0.0, 0.0, 0.0, 1.0;
	index4.push_back(currentVal.block<4, 1>(1, 0));
	for (int i = 1; i < 16; i++)  {
			currentVal = add4Vectors(currentVal.block<4, 1>(1, 0), add14);
			index4.push_back(currentVal.block<4, 1>(1, 0));
	}
	
}

BNN::~BNN()  {
	
}

float BNN::activate(float prompt)  {
	float retval;
	// The simplest possible virtual neuron that is still a classifier
	prompt > 0.5 ? retval = 1.0 : retval = 0.0;
	return retval;
}

float BNN::invertF(float starter)  {
	// Simplifies doing lookups, as the output for a compare is inverted to what we actually want here
	float retval;
	starter == 1.0 ? retval = 0.0: retval = 1.0;
	return retval;
}
 
float BNN::testEqual(float a, float b)  {
	
	Eigen::Vector2f u; 
	Eigen::Matrix<float, 2, 1> tmp1;
	Eigen::Matrix<float, 2, 1> tmp2;
	float tempResult;
	 
	u << a,b;	
	tmp1 = W0 * u;
	// unwind the iterator loop because seriously...
	tmp2(0,0) = activate(tmp1(0,0));
	tmp2(1,0) = activate(tmp1(1,0));
	tempResult = W1 * tmp2;
	result = activate(tempResult); 
	
	return result;
 }

float BNN::compare2Vectors(Eigen::Matrix<float, 2, 1> leftVec, Eigen::Matrix<float, 2, 1> rightVec)  {
	// This compares 2 vectors of 2 elements each
	
	Eigen::VectorXf testVec(4);
	Eigen::VectorXf tmpVec(4);
	Eigen::VectorXf intVec(4);
	
	testVec << leftVec, rightVec;
	intVec = compare2First * testVec;
	for (int i = 0; i < 4; i++)  {
		tmpVec(i, 0) = activate(intVec(i, 0));
	}
	
	interimResult = compare2Second * tmpVec;
	result = activate(interimResult);
	return result;
}

float BNN::compare4Vectors(Eigen::Matrix<float, 4, 1> leftVec, Eigen::Matrix<float, 4, 1> rightVec)  {
	Eigen::VectorXf testVec(8);
	Eigen::VectorXf tmpVec(8);
	Eigen::VectorXf intVec(8);
	testVec << leftVec, rightVec;
	intVec = compare4First * testVec;
	for (int i = 0; i < 8; i++) {
		tmpVec(i, 0) = activate(intVec(i, 0));
	}
	interimResult = compare4Second * tmpVec;
	result = activate(interimResult);
	
	return result;
}

 
float BNN::compare6Vectors(Eigen::Matrix<float, 6, 1> leftVec, Eigen::Matrix<float, 6, 1> rightVec)  {

		Eigen::VectorXf testVec(12);
		Eigen::VectorXf tmpVec(12);
		Eigen::VectorXf intVec(12);
		testVec << leftVec, rightVec;
		intVec = compare6First * testVec;
		for (int i = 0; i < 12; i++)  {
			tmpVec(i,0) = activate(intVec(i, 0));
		}
		interimResult = compare6Second * tmpVec;
		result = activate(interimResult);
		
		return result;
}

float BNN::compare10Vectors(Eigen::Matrix<float, 10, 1> leftVec, Eigen::Matrix<float, 10, 1> rightVec)  {
	
	Eigen::VectorXf testVec(20);
	Eigen::VectorXf tmpVec(20);
	Eigen::VectorXf intVec(20);
	
	testVec << leftVec, rightVec;
	intVec = compare10First * testVec;
	for (int i = 0; i < 20; i++)  {
		tmpVec(i, 0) = activate(intVec(i, 0));
	}
	interimResult = compare10Second * tmpVec;
	result = activate(interimResult);
	
	return result;
}

Eigen::Matrix<float, 5, 1> BNN::add4Vectors(Eigen::Matrix<float, 4, 1> leftVec, Eigen::Matrix<float, 4, 1> rightVec)  {
	
	//Implements a simple 4-bit binary adder with overflow
	Eigen::Matrix<float, 5, 1> localRet(0.0, 0.0, 0.0, 0.0, 0.0);
	Eigen::VectorXf testVec(8);
	Eigen::VectorXf tmpVec(8);
	Eigen::VectorXf intVec(8);
	Eigen::Vector4f lvl2Vec;
	Eigen::Matrix<float, 5, 1> carry(0.0, 0.0, 0.0, 0.0, 0.0);
	Eigen::Vector2f int2Vec;
	float c1, c2;
	
	testVec << leftVec, rightVec;
	intVec = compare4First * testVec;
	for (int i = 0; i < 8; i++)  {
		tmpVec(i, 0) = activate(intVec(i, 0));
	}
	// do the pair-wise NOT-ANDs
	int k = 0;
	for (int j = 0; j < 8; j+=2)  {
		int2Vec = tmpVec.block<2, 1>(j, 0);
		lvl2Vec(k, 0) = activate(W1 * int2Vec);
		k++;
	}
	
	// Now add the carry and determine subsequent carry for each bit of the sum, have to go backwards because LSD is at the end	
	for (int m = 3; m >= 0; m--)  {
		localRet(m+1) = testEqual(lvl2Vec(m, 0), carry(m+1, 0));			// this is simply an XOR
		c1 = activate((lvl2Vec(m, 0) * 0.5) + (carry(m+1, 0) * 0.5));		//compactify a simple AND
		c2 = activate((leftVec(m, 0) * 0.5) + (rightVec(m, 0) * 0.5));	
		carry(m, 0) = activate(c1 + c2);									//compactify a simple OR 
	}
	// The leftmost position in the carry vector is the overflow
	localRet(0) = carry(0);
	return localRet; 	
}

Eigen::Matrix<float, 4, 1> BNN::lookup4Vector(Eigen::Matrix<float, 4, 1> findVec)  {
	
	Eigen::Matrix<float, 4, 1> retVal;
	Eigen::Matrix<float, 16, 1> indexUnwound;
	
	// The list of vectors to be compared against, index4, was created by sequentially adding 1 to each position, see constructor
	// this makes the vector index and vector value (interpreted) the same thing, so it looks up itself by position
	// Also, don't get stuck on a C++ vector of Eigen vectors, it's a common construct if you go beyond what's shown here
	
	for (int i = 0; i < 16; i++)  {
		indexUnwound[i] = invertF(compare4Vectors(index4[i], findVec));
	}
	retVal = lookup4Vectors * indexUnwound;
	
	// At this point, the output vector matches what's in the lookup matrix's chosen column, it can be any value you want there 
	// and need not be activated unless that makes sense in context.
	return retVal;
}



