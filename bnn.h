/**********************************************************************
 * bnn.h
 * 
 * BNN, a test implementation of binary neural networks
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

#ifndef BNN_H_  //Wouldn't want to be included too many times
#define BNN_H_

#include <iostream>
#include <string>
#include <vector>
#include <eigen3/Eigen/Dense>


class BNN  {
    
public:

    BNN();
    ~BNN();
    float getResult() {return result;}
    //Eigen::Matrix<float, 10, 10> getBlock() {return tickBlock;}

    float activate(float);
    float testEqual(float, float);
    float compare2Vectors(Eigen::Matrix<float, 2, 1> leftVec, Eigen::Matrix<float, 2, 1> rightVec);
    float compare4Vectors(Eigen::Matrix<float, 4, 1> leftVec, Eigen::Matrix<float, 4, 1> rightVec);
    float compare6Vectors(Eigen::Matrix<float, 6, 1> leftVec, Eigen::Matrix<float, 6, 1> rightVec);
    float compare10Vectors(Eigen::Matrix<float, 10, 1> leftVec, Eigen::Matrix<float, 10, 1> rightVec);
    float invertF(float);
	Eigen::Matrix<float, 5, 1> add4Vectors(Eigen::Matrix<float, 4, 1> leftVec, Eigen::Matrix<float, 4, 1> rightVec);
	Eigen::Matrix<float, 4, 1> lookup4Vector(Eigen::Matrix<float, 4, 1> findVec);
    
private:

	Eigen::Matrix<float, 2, 2> W0;
    Eigen::Matrix<float, 1, 2> W1;
    Eigen::Matrix<float, 4, 1> sendAct;
    Eigen::Matrix<float, 4, 4> compare2First;
    Eigen::Matrix<float, 1, 4> compare2Second;
    Eigen::Matrix<float, 8, 8> compare4First;
    Eigen::Matrix<float, 1, 8> compare4Second;
    Eigen::Matrix<float, 12, 8> add4First;
    Eigen::Matrix<float, 3, 2> add4Interior;
    Eigen::Matrix<float, 12, 12> compare6First;
    Eigen::Matrix<float, 1, 12> compare6Second;
    Eigen::Matrix<float, 20, 20> compare10First;
    Eigen::Matrix<float, 1, 20> compare10Second;
    Eigen::Matrix<float, 4, 16> lookup4Vectors;
    std::vector<Eigen::Matrix<float, 4, 1>> index4;
    Eigen::Matrix<float, 5, 1> currentVal;
	Eigen::Matrix<float, 4, 1> add14;
    float interimResult, result;
    
};


#endif //BNN_H_


