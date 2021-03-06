/**
 * Name: Connect3Game.h
 *
 * Description:  Header file for a Connect3 Game.
 *
 * $Id: Connect3Game.h,v 1.3 2012/11/07 19:10:46 jem4687 Exp jem4687 $
 *
 * Revisions:
 * $Log: Connect3Game.h,v $
 * Revision 1.5  2012/11/07 19:10:46  jem4687
 * Pretty up the comments
 *
 * Revision 1.4  2012/10/29 02:40:02  mal4012
 * Minor comment changes.
 *
 * Revision 1.3  2012/10/25 00:45:24  jem4687
 * Changed findsuccessors to receive a trip
 *
 * Revision 1.2  2012/10/21 22:10:25  mal4012
 * Changed constructors.
 *
 * Revision 1.1  2012/10/21 18:16:29  mal4012
 * Initial revision
 *
 *
 *
 * @author:Jesse Martinez
 * @author:Michael Loper
 */

#ifndef CONNECT3_H
#define CONNECT3_H

#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include "Game.h"

//Typedef for our created triple type.
typedef triple< int, int, std::vector< std::vector<int> > > trip;

class Connect3Game: public Game
{
        private:
                // Pair that holds player character and player type
                std::pair<std::string,std::string> p1;
                std::pair<std::string,std::string> p2;

		// Constant amount of how many in a row you need to win
		const int IN_A_ROW;

		// Column most recent move made
		int lastplaced;

		// Boolean keeping track of if Connect3 is in play mode
		bool playMode;

	public:
                /**
                 * Constructor
                 *
                 * Description: Creates a connect3 game based off the initial
		 * configuration to be ran in interactive mode.
                 *
                 * @param int    - A "dummy" int to differentiate the
                 *                 interactive mode from the solver mode.
                 *        spaces - The remaining spaces left on the board.
                 *        b      - A vector of strings representing the board.
                 */
                Connect3Game( const int, int spaces,
		std::vector<std::string> b );

                /**
                 * Constructor
                 *
                 * Description:  Creates a game of connect3 to be ran in solver
                 * mode.
                 *
                 * @param spaces - The remaining spaces left on the board.
                 *        b      - A vector of strings representing the board.
                 */
                Connect3Game( int spaces, std::vector<std::string> b );

                /**
                 * Name:  generateBoard
                 *
                 * Description: Generates a connect3 board of 0's, 1's, and 2's.
                 *
                 * @param b     - The board.
                 */
                void generateBoard( std::vector<std::string> b );

                /**
                 * Name: move
                 *
                 * Description:  Calls the proper move function based on the
                 *               received player number.
                 *
                 * @param p      - The number representing whose turn it is.
                 */
                void move( const int p );

                /**
                 * Name: moveHuman
                 *
                 * Description: Asks for user input on where they would like
		 *              to make a move.
                 *
                 * @param p     - A string representing either player "X" or
                 *                "O".
                 *
                 * @return
                 */
                int moveHuman( const std::string p );

                /**
                 * Name: movePC
                 *
                 * Description: Move for PC player calls the solver algorithim
                 *              to find the best possible move given for the
                 *              current successor, and sets to board to the
                 *              best possible board.
                 *
                 * @param turn      - Integer to keep track of the turn.
                 *        successor - The current successor of a connect3
                 *                    configuration.
                 *
                 * @return      A triple that holds the best score, the best
                 *              move, and the best board.
                 */
                trip movePC( const int turn, std::vector< trip > successor );

                /**
                 * Name: findSuccessors
                 *
                 * Description: Generates all possible valid moves.
                 *
                 * @param b     - A triple containing the current board, the
		 *		remaining spaces, and the last placed col.
                 *
                 * @return      A vector of all the successors.
                 */
                std::vector< trip > findSuccessors( trip b );

                /**
                 * Name: print
                 *
                 * Description: Prints out a connect3 rendition using X's
		 * and O's.
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
                 * Description: Returns the basecase move, score, and board.
                 *
                 * @return      A triple with a score, move, and board.
                 */
                trip baseCase() const;

		/**
		 * Name: checkWin
		 *
		 * Description: Given a column, checks for a win.
		 *
		 * @param b     - The column of the last played piece.
		 *
		 * @return      True iff the configuration is now a win.
		 */
		bool checkWin( trip b );

		/**
		 * Name: invert
		 *
		 * Description: Inverts the board by converting all the X's to O's and O's
		 *              to X's.
		 *
		 * @param b     - The board.
		 *
		 * @return      The inverted board.
		 */
		std::vector< std::vector<int> >
		invert( std::vector< std::vector<int> > b );
		
		/**
		 * Name: getLastPlace
		 *
		 * Description: Returns humans last move played
		 *
		 * @return	The column of humans last move
		 */
		int getLastPlaced();


};

#endif
