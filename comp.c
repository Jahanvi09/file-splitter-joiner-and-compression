#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Function to compress the file*/
void Compress(unsigned char *szOut, const char *szMessage) {
	/*Data nBuffer to store the details of the file*/
    unsigned long long nBuffer = 0; 
	char nBitsInBuffer = 0;
	while (*szMessage != 0) {
		nBuffer |= (unsigned long long)(*szMessage++ & 0x7F) << nBitsInBuffer;
		nBitsInBuffer += 7;
		if (nBitsInBuffer == 7 * 8) { 
            /*Removing the bits after use*/
			while (nBitsInBuffer > 0) {
				*szOut++ = nBuffer & 0xFF;
				nBuffer >>= 8;
				nBitsInBuffer -= 8;
			}
			
			nBitsInBuffer = 0;
			nBuffer = 0;
		}
	}
	/*Storing the results*/
	while (nBitsInBuffer > 0) {
		*szOut++ = nBuffer & 0xFF;
		nBuffer >>= 8;
		nBitsInBuffer -= 8;
	}
}


int main() {

    int  i=0;

	/* Character Array for the Project */
    char szMessage[100];  
    
	/* Creating the file pointer */
    FILE *file;  
	/*Opening the file to be compressed*/
    file = fopen("file.txt", "r"); 
    
	/*Reading the contents of the file*/
    while(fgets(szMessage, sizeof szMessage, file)!=NULL) {      
      continue; 
    }
    fclose(file);
    
	//char szMessage[] = "This file will be first compressed and then decompressed again";
	static const unsigned nCompressedSize = sizeof(szMessage) * 7 / 8; 
	unsigned char pCompressedBytes[nCompressedSize];
	char szUncompressed[sizeof(szMessage)];
	printf("\n------------------------File Compression Project------------------------");
	printf("\n");
	printf("\nOriginal File Message: %s\n", szMessage);
	Compress(pCompressedBytes, szMessage);
	printf("----------------File Compression-----------------------------------");
	
	printf("\n");
	printf("File has been compressed to compressed.out file!");
	
	FILE *f = fopen("compressed.out", "wb");
	fwrite(pCompressedBytes, sizeof(char), sizeof(pCompressedBytes), f);
	fclose(f);
	
	
		
	return 0;
}	
