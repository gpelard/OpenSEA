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

#include "derivative.h"

using namespace std;
using namespace osea::ofreq;

//==========================================Section Separator =========================================================
//Public functions:

//------------------------------------------Function Separator --------------------------------------------------------
Derivative::Derivative()
{
}

//------------------------------------------Function Separator --------------------------------------------------------
Derivative::~Derivative()
{

}

//------------------------------------------Function Separator --------------------------------------------------------
vector<Equation> &Derivative::listEquation()
{
    //Return equation list pointer.
    return pEquationList;
}

//------------------------------------------Function Separator --------------------------------------------------------
Equation &Derivative::listEquation(unsigned int number)
{
    //Check to see if the equation is out of bounds.  If so, resize vector.
    if ((number > pEquationList.size() - 1) || (pEquationList.size() == 0))
    {
        pEquationList.resize(number + 1);
    }

    //Return pointer to the specified equation.
    return pEquationList[number];
}

//------------------------------------------Function Separator --------------------------------------------------------
int Derivative::getEquationListSize()
{
    return pEquationList.size();
}

//------------------------------------------Function Separator --------------------------------------------------------
Equation &Derivative::refIndexEquation(int indexIn)
{
    //Get equation by data index, returns pointer to object.
    int i;       //get the integer for the object.

    //Find the index integer.
    i = findIndex(indexIn);

    //Write output
    return pEquationList[i];
}

//------------------------------------------Function Separator --------------------------------------------------------
Equation Derivative::getIndexEquation(int indexIn)
{
    //Get equation by data index, returns value.
    int i;

    //Find the index integer.
    i = findIndex(indexIn);

    //Write output
    return pEquationList[i];
}

//==========================================Section Separator =========================================================
//Protected functions:

//==========================================Section Separator =========================================================
//Private functions:

//------------------------------------------Function Separator --------------------------------------------------------
int Derivative::findIndex(int indexIn)
{
    int output;         //integer to write as output.
    int check;          //The integer to check against.

    //Finds the integer of the equation object by data index.
    for (unsigned int i = 0 ; i < pEquationList.size() ; i++)
    {
        //Check the data index of the object.
        if (pEquationList[i].getDataIndex() < 0)
        {
            //No data index set.  Use the position in the list.
            check = i;
        }
        else
        {
            //Data index is used.  Use the position in the list.
            check = pEquationList[i].getDataIndex();
        }

        //Check for match
        if (check == indexIn)
        {
            output = check;
            break;
        }
    }
    return output;
}
