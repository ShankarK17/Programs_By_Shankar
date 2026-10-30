#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void incr_cnt(){
	for(int i = 0; i<1000; i++){
	FILE *fp = fopen("counter.txt", "r+");
	if(!fp){
		fp = fopen("counter.txt", "w");
		fprintf(fp, "%d", 0);
		rewind(fp);
	}

	int count = 0;
	fscanf(fp, "%d", &count);

	count++;

	rewind(fp);
	fprintf(fp, "%d", count);
	fclose(fp);
	}
}

int main(){
	pid_t pid;
	switch(pid = fork()){
		case -1:
			printf("Fork Fail");
			return 1;
		case 0:
			incr_cnt();
			exit(0);
		default:
			wait(NULL);
			incr_cnt();
			//wait(NULL);
			
			int final_count = 0;
			FILE *file = fopen("counter.txt", "r");
			if(!file){
				printf("Couldn't allocate\n");
				return 1;
			}
			fscanf(file, "%d", &final_count);
			fclose(file);

			printf("Expected Output: 2000\n");
			printf("Actual Output: %d\n", final_count);

	}

	return 0;
}

