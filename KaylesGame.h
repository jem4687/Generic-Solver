/**
 * Name: KaylesGame.h
 *
 * Description:  Header file for a Kayles Game.
 *
 * $Id: KaylesGame.h,v 1.5 2012/11/07 19:10:46 jem4687 Exp jem4687 $
 *
 * Revisions:
 * $Log: KaylesGame.h,v $
 * Revision 1.10  2012/11/07 19:10:46  jem4687
 * Pretty up the comments
 *
 * Revision 1.9  2012/10/29 02:40:02  mal4012
 * Minor comment changes.
 *
 * Revision 1.8  2012/10/25 00:45:24  jem4687
 * Changed findsuccessors to receive a trip
 *
 * Revision 1.7  2012/10/21 18:16:29  mal4012
 * Changed comments.
 *
 * Revision 1.6  2012/10/21 03:04:07  mal4012
 * Redid comments.
 *
 * Revision 1.5  2012/10/18 03:22:10  p334-04e
 * works now
 *
 * Revision 1.4  2012/10/17 21:43:02  mal4012
 * Added play feature.
 *
 * Revision 1.3  2012/10/17 01:38:41  mal4012
 * Changed base cases.
 *
 * Revision 1.2  2012/10/16 02:29:08  jem4687
 * added functionality to print
 *
 * Revision 1.1  2012/10/16 02:25:21  jem4687
 * Initial revision
 *
 * @author:Jesse Martinez
 * @author:Michael Loper
 */

#ifndef KAYLES_H
#define KAYLES_H

#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include "Game.h"

typedef triple< int, int, std::vector< std::vector<int> > > trip;

class KaylesGame: public Game
{
	private:
		// Pair that holds player character and player type
		std::pair<std::string,std::string> p1;
		std::pair<std::string,std::string> p2;

	public:
		/**
		 * Constructor
		 *
		 * Description:  Creates a game of kayles between the user and
		 *		 the pc with the initial amount of pins and
		 * 		 board received.
		 *
		 * @param int    - A "dummy" int to differentiate the
		 *		   interactive mode from the solver mode.
		 *        pins   - The initial amount of pins in the row.
		 *        b      - A vector of strings representing the pins.
		 */
		KaylesGame( const int , int pins , std::vector<std::string> b );

		/**
		 * Constructor
		 *
		 * Description:  Creates a game of kayles to be ran in solver
		 * mode.
		 *
		 * @param pins   - The initial amount of pins in the row.
		 *        b      - A vector of strings representing the pins.
		 */
		KaylesGame( int pins , std::vector<std::string> b );

		/**
		 * Name:  generateBoard
		 *
		 * Description: Generates the board with 1's and 0's based off
		 * of the strings received from the command line arguments.
		 *
		 * @param b     - The board.
		 */
		void generateBoard( std::vector<std::string> b );

		/**
		 * Name: move
		 *
		 * Description:  Calls the proper move function based on the
		 *               received player number.  Removes the ammount
		 *               of pins the player chose.
		 *
		 * @param p      - The number representing whose turn it is.
		 */
		void move( const int p );

		/**
		 * Name: moveHuman
		 *
		 * Description: Asks for user input on how many pins to take
		 * away.
		 *
		 * @param p     - A string representing either player "X" or
		 *		  "O".
		 *
		 * @return      The number of pins chosen.
		 */
		int moveHuman( const std::string p );

		/**
		 * Name: movePC
		 *
		 * Description: Move for PC player calls the solver algorithim
		 *		to find the best possible move given for the
		 * 		current successor, and sets to board to the
		 *		best possible board.
		 *
		 * @param turn      - Integer to keep track of the turn.
		 *        successor - The current successor of a kayles
		 * 		      configuration.
		 *
		 * @return      A triple that holds the best score, the best
		 * 		move, and the best board.
		 */
		trip movePC( const int turn, std::vector< trip > successor );

		/**
		 * Name: findSuccessors
		 *
		 * Description: Generates all possible valid moves.
		 *
		 * @param b     - The current board, the number of pins to take
		 *		away, and the number of remaining pins.
		 *
		 * @return      A vector of all the successors.
		 */
		std::vector< trip > findSuccessors( trip b );

		/**
		 * Name: print
		 *
		 * Description: Prints an "X" for each pin left and "_" for
		 * missing pins.
 		 */
		void print();

		/**
		 * Name: getName
		 *
		 * Description: Returns the name of the player received.
		 *
		 * @param p     - An integer representing whose turn it is.
		 *
		 * @return      String representation of the current player.
		 */
		std::string getName( const int ) const;

		/**
		 * Name: checkBaseCase
		 *
		 * Description:  Determines if a base case as been reached.
		 *
		 * @param check  - A vector of the remaining moves.
		 *
		 * @return       True iff there are no remaining moves.
		 */
		bool checkBaseCase( const std::vector< trip > check ) const;

		/**
		 * Name: baseCase
		 *
		 * Description: Returns a standard base case representation
		 * for the kayles game.  For this game it is a score of -1 a
		 * move of 0 and an empty board.
		 *
		 * @return      A triple with a score, move, and board.
		 */
		trip baseCase() const;

		/**
		 * Name: invert
		 *
		 * Description: A dummy function to only be used in
		 * Connect3Game.
		 *
		 * @return      A board.
		 */
		std::vector< std::vector<int> > invert(
		std::vector< std::vector<int> > b );


};

#endif
