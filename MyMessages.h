#include <string>
#include "intSLList.h"

#ifndef MYMESSAGES_H
#define MYMESSAGES_H


using namespace std;

class MyMessages {
public:
	string introMessage =
		
		"COMPUTER SYSTEM ENGINEERING     GROUP2      PROJECT\n"
		"\n\nWelcome to SimpleText 1.0!\n"
		"\n\nUse command to modify your text.\n"
		"\n\nHappy editing!\n";

	string infoOpenFile = "\n\nTo begin, open a Text File (ex : open Filename.txt)\n";
	string infoUndoComplete = "\n\nUndo completed for the action taken: ";
	string infoInseretLine = "\n\nYou Have Deleted All The Lines! Please Undo or Add New Lines.\n\n";
	string infoLastPage = "\n\nYou are already at the last page!\n";
	string infoFirstPage = "\n\nYou are already at the first page!\n";
	string infoEnterCommand = "\n\nEnter Your Command (to get command list, type help) :  ";
	string infoCommandListHelper =
		"\n\n-----------------------------------------------------------------------------------\n"
		"\n + Command List : \n"
		"\n-----------------------------------------------------------------------------------"
		"\n open                         - Open New File                 (ex : open filename.txt)"
		"\n next                         - Advance To Next Page "
		"\n prev                         - Return To Previous Page"
		"\n insert [line no] [new text]  - Insert A New Line             (ex : insert 1 NewText)"
		"\n delete [line no]             - Delete A Line                 (ex : delete 1)"
		"\n replace [line no] [new text] - Replace A Line                (ex : replace 1 NewText)"
		"\n move [line no1] [line no2]   - Move Target Line To New Line  (ex : move 1 2)"
		"\n save                         - Save Or Create A New File"
		"\n undo                         - Undo Last Action"
		"\n-----------------------------------------------------------------------------------"
		"\n\n";

	string errEmptyFile = "\nBlank File!!!\n\n";
	string errNoSuchFile = "\nNo Such File Found. Please Enter A Valid File Name!!!";
	string errNotValidCommand = "\nPlease Enter A Valid Command!!!\n\n";
	string errNotValidOpenCommand = "\nUser Needs To Enter A Valid 'Open File' Command, Example : open filename.txt\n";
	string errNotValidPosition = "\nPlease Enter Position Value(s) As Integer, Between 1 and ";
	string errNoUndoActionFound = "\n\nNo Action Found To Undo!!!\n";
};
#endif