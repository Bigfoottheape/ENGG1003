#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<math.h>
 
void main()
{
// Setting variables for the code
	char message[100], ch, input1[100], input2[100];
	int i, key;
	
// Clear command window and takes a Menu Input
	system("@cls||clear");
	printf("====================================== \n");
	printf("Would you like to encrypt or decrypt: \n");
	printf("====================================== \n");
	printf(" \n");
	printf("Answer: ");
	scanf("%s", input1);
	
//Either Encrypt or Decrypt depending on user input
	
	if (strcmp(input1, "encrypt")== 0)
		{
	
	// Encryption	
	// Clears the command window for a cleaner UI
		system("@cls||clear");
	// User inputs a plain text string
		printf("Enter a message to encrypt: ");
		scanf(" %100[^\n]", message);
	// User inputs a key for rotations
		printf("Enter key: ");
		scanf(" %d", &key);
	
	// Takes every seperate character through [1] and rotates as per the key
	// Will repeat until ever character in the string has been rotated by the specified key
		for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
	// Checks to make sure that the string character for each value is a real ascii values
	// If not will move to the else if statement
		if(ch >= 0 && ch <= 255)
		{
		// New ascii value = old ascii value + key rotation
		// This will allow each character to be encrypted into another character through ascii
			ch = ch + key;

			message[i] = ch;
		}
		else
		{
			printf("Congratulations, youre superior");
		}
	}
	
	printf("Encrypted message: %s", message);
	}


	else if (strcmp(input1, "decrypt")== 0)
	{
		
	// Decryption
	// Clears the command window for a cleaner UI
		system("@cls||clear");
		printf("Enter a message to decrypt: ");
		scanf(" %100[^\n]", message);
		printf("Enter key: ");
		scanf(" %d", &key);
	
		for(i = 0; message[i] != '\0'; ++i){
			ch = message[i];
		
			if(ch >= 0 && ch <= 255)
			{
				ch = ch - key;

				message[i]=ch;
			}
			else
		{
			printf("Congratulations, youre superior");
		}
	}
	
	printf("Decrypted message: %s", message);
	
	}
}
