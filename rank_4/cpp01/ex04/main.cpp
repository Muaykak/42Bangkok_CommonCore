/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:11:54 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 20:37:57 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

// Read the whole given file. return std::string that has content of the file
bool readFile(std::string &filename, std::string &readString){
	// Just for sure
	if (filename.empty()){
		std::cerr << "Error\n: readFile() filename cannot be empty string" << std::endl;
		return (false);
	}

	// open file using fstream
	// need to convert to char *. the std::ifstream constructor cannot take std::string
	// use c_str() will return const char *
	std::ifstream inFile(filename.c_str());
	// if not open, some errors may occur, cannot open, or not found.
	if (!inFile.is_open()){
		std::cerr << "Error\n: Cannot open the given filename >> " << filename << std::endl;
		return (false);
	}

	std::string buffer;
	// good() is to quick check 
	// if read fail or reach EOF or something wrong it should return false
	while (inFile.good()){
		// We've already use std::getline() to handle user input from CPP00
		std::getline(inFile, buffer);
		readString += buffer;
		// only append with "\n" when it's still readable
		if (inFile.good())
			readString += "\n";
	}
	
	// fail() will return true if cannot read anymore (EOF or other thing)
	// in normal case we should read until EOF so eof() and fail()
	// should both return true. If it fails but nor reach EOF. then it has error
	if (!inFile.eof() && inFile.fail()){
		std::cerr << "Error occurred" << std::endl;
		inFile.close();
		return (false);
	}
	inFile.close();
	return (true);
}

void replaceString(const std::string &toFind, const std::string &toReplace, std::string &reString){
	// Just making sure
	if (toFind.empty())
		return ;
	
	// find() will return the index of
	// the string where we found the passed string 
	// If not found it will return npos value
	size_t currentPos = reString.find(toFind);
	while (currentPos != reString.npos){
		// remove characters in the string
		// need to specify the start index and size
		reString.erase(currentPos, toFind.size());
		// insert characters into string
		// specify the index to insert and the string we want to insert
		reString.insert(currentPos, toReplace);
		// find next string to replace
		// h e l l o
		// 0 1 2 3 4
		// ^        
		// h e r o - -
		//         ^  find() start index here
		currentPos = reString.find(toFind, currentPos + toReplace.size());
	}
}

bool writeFile(std::string &stringToWrite, const std::string &filename){
	// discard all the contents of the file if it already existed
	std::ofstream	outFile(filename.c_str(), std::ios_base::trunc);
	if (!outFile.is_open())
	{
		std::cerr << "Error\n: Cannot open the given filename >> " << filename << std::endl;
		return (false);
	}
	if (!outFile.write(stringToWrite.c_str(), stringToWrite.size())){
		std::cerr << "Error\n: Write to a file failed" << std::endl;
		outFile.close();
		return (false);
	}
	outFile.close();
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 4){
		std::cerr << "Error\n: This program takes 3 parameters: filename, stringToFind, stringToReplace" << std::endl;
		return (1);
	}

	// convert char * to std::string
	std::string filename = argv[1];
	std::string toFind = argv[2];
	std::string toReplace = argv[3];

	// Should not find with empty string
	if (toFind.empty())
	{
		std::cerr << "Error\n: cannot use empty string to find. Why would you ;-;??" << std::endl;
		return (1);
	}

	std::string readString;
	if (!readFile(filename, readString))
		return (1);
	replaceString(toFind, toReplace, readString);
	if (!writeFile(readString, filename + ".replace"))
		return (1);
	return (0);
}

// Honestly, I think i want to use rdbuf() to stringstream then turn to string
// easily. But i don't fully know the string stream So i don't wanna use that
