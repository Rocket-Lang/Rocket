#pragma once

#include <string>
#include <vector>

#include "lexeme.cpp"
#include "chartest.cpp"
#include "iskeyword.cpp"

namespace rocket {
	
	namespace lexer {
		
		// This function performs a lexical analysis on the code it gets.
		// It returns  a std::vector that is filled with Lexemes.
		std::vector<Lexeme> lexe(std::string code) {
			
			std::vector<Lexeme> lexemes;
			int charIndex = 0;
			
			while(charIndex < code.length()) {
				
				if(code[charIndex] == '\n') {
				
				Lexeme lexeme;
				lexeme.key = NEWLINE;
				
				lexemes.push_back(lexeme);
			}
			
			// Skipping all spaces and tabs
			if(code[charIndex] == ' ' || code[charIndex] == '\t') {
				
				
				while(charIndex < code.length()) {
					
					if(code[charIndex] != ' ' && code[charIndex] != '\t') {
						
						break;
					}
					
					charIndex++;
				}
				
				continue;
			}
			
			
			// Checking for a comment and skipping possible comments
			if(code[charIndex] == '/') {
				
				if(charIndex+1 < code.size()) {
					
					if(code[charIndex+1] == '/') {
						
						charIndex += 2;
						
						// Skipping the single-line comment (A backslash at
						// the end makes it affect the next line)
						while(charIndex < code.size()) {
							
							if(code[charIndex] == '\\') {
								
								charIndex += 2;
							}
							
							if(code[charIndex] == '\n') {
								
								Lexeme lexeme(NEWLINE, "");
								lexemes.push_back(lexeme);
								
								charIndex++;
								
								break;
							}
							
							charIndex++;
						}
						
					} else if(code[charIndex+1] == '*') {
						
						charIndex += 2;
						int bracketCount = 1;
						
						// Skipping the multi-line comment (Those can be nested)
						while(charIndex < code.size()) {
							
							// If there is a newline, notice it
							// (Otherwise, line-numbers in error-messages
							//  would be wrong and wouldn't be that helpful)
							if(code[charIndex] == '\n') {
								
								Lexeme lexeme(NEWLINE, "");
								lexemes.push_back(lexeme);
							}
							
							// Checking for a comment-closer
							if(code[charIndex] == '*') {
								
								if(charIndex+1 < code.size()) {
									
									if(code[charIndex+1] == '/') {
										
										charIndex += 2;
										bracketCount--;
									}
								}
							}
							
							// Checking for a comment-opener
							if(code[charIndex] == '/') {
								
								if(charIndex+1 < code.size()) {
									
									if(code[charIndex+1] == '*') {
										
										charIndex += 2;
										bracketCount++;
									}
								}
							}
							
							// If all comment-openers got closed
							if(bracketCount == 0) {
								
								break;
							}
							
							charIndex++;
						}
						
					}
					
				}
				
				continue;
			}
			
			
			// Checking for a string
			if(code[charIndex] == '"') {
				
				int lexemeStart = charIndex;
				charIndex++;
				
				while(charIndex < code.length()) {
					
					// The end of the string caused by a newline
					if(code[charIndex] == '\n') {
						
						charIndex++;
						
						break;
					}
					
					// The end of the string
					if(code[charIndex] == '"') {
						
						charIndex++;
						
						break;
					}
					
					// An escape-sequence
					if(code[charIndex] == '\\') {
						
						charIndex++;
					}
					
					charIndex++;
				}
				
				Lexeme lexeme(STRING, code.substr(lexemeStart, charIndex-lexemeStart));
				lexemes.push_back(lexeme);
				
				continue;
			}
			
			
			// If this is a number, cutting out all numbers after this
			if(isNumeric(code[charIndex])) {
				
				int lexemeStart = charIndex;
				bool isFloating = false;
				
				
				while(charIndex < code.length()) {
					
					if(code[charIndex] == '.') {
						
						isFloating = true;
						
						charIndex++;
					}
					
					if(!isNumeric(code[charIndex])) {
						
						break;
					}
					
					charIndex++;
				}
				
				
				Lexeme lexeme;
				
				std::string value = code.substr(lexemeStart, charIndex-lexemeStart);
				
				if(isFloating) {
					
					lexeme.key = FLOAT;
					lexeme.value = value;
					
				} else {
					
					lexeme.key = INTEGER;
					lexeme.value = value;
				}
				
				lexemes.push_back(lexeme);
				
				continue;
			}
				
				
			}
			
		}
		
	}
	
}

