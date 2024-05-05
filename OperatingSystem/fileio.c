#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 512

int main(int argc, char *argv[]){
	char *input_file = argv[1];
	char *output_file = argv[2];
	char buffer[BUF_SIZE];

	int input_fp = open(input_file, O_RDONLY);
	if(input_fp == -1){
		printf("Failed to open the file %s on line %d of file %s\n",argv[1],__LINE__,__FILE__);
		exit(-1);
	}

	int output_fp = open(output_file, O_WRONLY, 0200);
	if(output_fp == -1){
		printf("Failed to open the file %s on line %d of file %s\n",argv[2],__LINE__,__FILE__);
		exit(-1);
	}
	
	ssize_t read_bytes, write_bytes;
	while(1){
		read_bytes  = read(input_fp,buffer,BUF_SIZE);
		if(read_bytes == 0) break;
		write_bytes = write(output_fp,buffer,read_bytes);
		if(write_bytes == -1){
		printf("Failed to write bytes on file %s on line %d of file %s\n",argv[2],__LINE__,__FILE__);
			exit(-1);
		}
	}

	printf("Totally, %ld bytes were copied.\n",write_bytes);

	close(input_fp);
	close(output_fp);

	return 0;
}
