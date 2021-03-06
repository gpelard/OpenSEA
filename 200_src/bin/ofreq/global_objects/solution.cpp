/*----------------------------------------*- C++ -*------------------------------------------------------------------*\
| O pen         | OpenSea: The Open Source Seakeeping Suite                                                           |
| S eakeeping	| Web:     www.opensea.dmsonline.us                                                                   |
| E valuation   |                                                                                                     |
| A nalysis     |                                                                                                     |
\*-------------------------------------------------------------------------------------------------------------------*/

//License
/*-------------------------------------------------------------------------------------------------------------------*\
 *Copyright Datawave Marine Solutions, 2013.
 *This file is part of OpenSEA.

 *OpenSEA is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.

 *OpenSEA is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.

 *You should have received a copy of the GNU General Public License
 *along with OpenSEA.  If not, see <http://www.gnu.org/licenses/>.
\*-------------------------------------------------------------------------------------------------------------------*/

#include "solution.h"

using namespace std;
using namespace arma;
using namespace osea::ofreq;

//------------------------------------------Function Separator --------------------------------------------------------
Solution::Solution()
{
    //Default constructor.
}

//------------------------------------------Function Separator --------------------------------------------------------
Solution::~Solution()
{
    //Default destructor.
}

//------------------------------------------Function Separator --------------------------------------------------------
cx_mat &Solution::refSolnMat()
{
    //Returns the solution object, by reference.
    return pSoln;
}

//------------------------------------------Function Separator --------------------------------------------------------
complex<double> Solution::getSolnMat(int index)
{
    //Returns single entry in the solution matrix.  By Value.
    return pSoln(index,1);
}

//------------------------------------------Function Separator --------------------------------------------------------
cx_mat Solution::getSolnMat()
{
    //Returns the solution object, by value.
    return pSoln;
}

//------------------------------------------Function Separator --------------------------------------------------------
void Solution::setSolnMat(cx_mat matIn)
{
    //Sets the solution object, by value.
    pSoln = matIn;
}

////------------------------------------------Function Separator --------------------------------------------------------
//Body Solution::getBody()
//{
//    //Gets the body object.
//    return *pBod;
//}

//------------------------------------------Function Separator --------------------------------------------------------
Body &Solution::refBody()
{
    //Retunrns the reference to the body object.
    return *pBod;
}
