/*----------------------------------------*- C++ -*------------------------------------------------------------------*\
| O pen         | OpenSea: The Open Source Seakeeping Suite                                                           |
| S eakeeping	| Web:     www.opensea.dmsonline.us                                                                   |
| E valuation   |                                                                                                     |
| A nalysis     |                                                                                                     |
\*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*\
 *Revision History
 *---------------------------------------------------------------------------------------------------------------------
 *Date          Author				Description
 *---------------------------------------------------------------------------------------------------------------------
 *May 15, 2013  Shane Honanie       Initially created.
 *Aug 04, 2013  Nicholas Barczak    Rewrote to use private variables.
 *
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



//######################################### Class Separator ###########################################################
#ifndef FORCEEQUATION_H
#define FORCEEQUATION_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../global_objects/ofreqcore.h"

//######################################### Class Separator ###########################################################
//Namespace declarations

//==========================================Section Separator =========================================================
/**
 * The namespace for all code created under the OpenSEA project.  There are also several sub-namespaces, one
 * associated with each primary program under osea.
 * 1.)  ohydro:  Code associated with the program ohydro.
 * 2.)  ofreq:   Code associated with the program ofreq.
 * 3.)  otime:   Code associated with the program otime.
 * 4.)  ofourier:  Code associated with the program ofourier.
 * 5.)  obatch:    Code associated with the program obatch.
 * 6.)  guisea:    Code assocaited with the GUI that interacts with all OpenSEA programs.
 * Any code that may have common utility amongst all programs, such as file reading objects, goes under the generic
 * osea namespace.  Any code that is only useful within the specific program it serves, goes under the specific
 * namespace.  When in doubt, default to just the osea namespace.
 *
 * The namespaces are not intended to create an organizational structure.  They are only intended to prevent
 * name conflicts.
 */
namespace osea
{

//==========================================Section Separator =========================================================
/**
 * The namespace of all code specifically associated with ofreq.
 */
namespace ofreq
{

//######################################### Class Separator ###########################################################
/**
 * This class holds data for an equation.
 */

class Equation : public osea::ofreq::oFreqCore
{
//==========================================Section Separator =========================================================
public:
    //------------------------------------------Function Separator ----------------------------------------------------
	Equation(); /**< This default constructor. */

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief Constructor with setting the data index.
     *
     * Constructor with setting the data index.
     * @param IndexIn The integer specifying the data index number.
     */
    Equation(int IndexIn);

    //------------------------------------------Function Separator ----------------------------------------------------
	~Equation(); /**< The default destructor, nothing happens here. */

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief Direct access to the list of coefficients.
     * @return Pointer to the list of coefficients.
     */
    std::vector<double> &listCoefficients();

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief Provides direct access to a coefficient from the list of coefficients.
     *
     * Returns a value from the list of coefficents.  Which value to return is specified by the input index.
     * @param index Unsigned integer.  Specifies which value to return from the list of coefficients.
     * @return Returns a double.  Returned variable is a value from the list of coefficients.  Returned variable is
     * passed by reference.
     */
    double &listCoefficients(unsigned int index);

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief Get the coefficient at the specified number.
     * @param number The index number of the coefficient to retrieve.
     * @return Returns a double precision floating point number of the coefficient at the index specified by number.
     */
    double getCoefficient(int number);

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief Set the coefficient value at the specified index number.
     *
     * Set the coefficient value at the specified index number.
     * @param number Integer.  The index number of the coefficient to set.
     * @param coeffIn Double precision floating number.  The value of the coefficient to set at the specified index.
     */
    void setCoefficient(int number, double coeffIn);

    //------------------------------------------Function Separator ----------------------------------------------------
	/**
	 * Retrieve the size of the coefficient list.
	 * @return The size of the coefficient list.
	 */
    unsigned int getCoefficientListSize();

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief Set the index number of any equation data that should be retrieved.
     *
     * Set the index number of any equation data that should be retrieved.  Because the first six values in the
     * index are reserved for 6DOF, it is necessary that equation objects should be able to specify their index
     * as something other than their place in a containing vector.  The default initialization value for this is
     * -1, which indicates the index is not set.  Any number less than zero indicates the index is not set.
     * @param index The index number that should be set.  Any number less than zero indicates the index is not set.
     */
    void setDataIndex(int index);

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief Get the index number of any equation data that should be retrieved.
     *
     * Get the index number of any equation data that should be retrieved.  Because the first six values in the
     * index are reserved for 6DOF, it is necessary that equation objects should be able to specify their index
     * as something other than their place in a containing vector.  The default initialization value for this is
     * -1, which indicates the index is not set.  Any number less than zero indicates the index is not set.
     * @param index Integer.  The index number that should be retrieved.  Any number less than zero indicates the
     * index is not set.
     */
    int getDataIndex();

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief Exposed access to the data access variable.
     * @return Returns the data access variable.  Return passed by reference.
     */
    int &refDataIndex();

//==========================================Section Separator =========================================================
protected:

//==========================================Section Separator =========================================================
private:
    //------------------------------------------Function Separator ----------------------------------------------------
	void initCoeff(); /**< Initialize all coefficients to default values. */

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief The list of coefficients.
     *
     * The list of coefficients.
     */
    std::vector<double> pcoeffs;

    //------------------------------------------Function Separator ----------------------------------------------------
    /**
     * @brief The index number of any equation data that should be retrieved.
     *
     * The index number of any equation data that should be retrieved.  Because the first six values in the
     * index are reserved for 6DOF, it is necessary that equation objects should be able to specify their index
     * as something other than their place in a containing vector.  The default initialization value for this is
     * -1, which indicates the index is not set.  Any number less than zero indicates the index is not set.
     */
    int pDataIndex;

};

}   //Namespace ofreq
}   //Namespace osea

#endif
