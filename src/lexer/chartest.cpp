namespace rocket {
	
	namespace lexer {
		
		// Checks if the char it gets is a number.
		bool isNumeric(char input) {
			
			if(input > 47 && input < 58) {
				
				return true;
			}
			
			return false;
		}
		
		// Checks if the char it gets is a letter of the alphabet.
		bool isAlphabet(char input) {
			
			if((input > 64 && input < 91 ) ||
			   (input > 96 && input < 123)) {
				
				return true;
			}
			
			return false;
		}
		
		// Checks if the char it gets is a special character.
		bool isSpecial(char character) {
			 
			if((character > 32  && character < 48) ||
			   (character > 57  && character < 65) ||
			   (character > 90  && character < 97) ||
			   (character > 122 && character < 127)) {
				
				return true;
			}
			 
			return false;
		}
			
	}
	
}

