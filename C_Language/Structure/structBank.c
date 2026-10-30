#include <stdio.h>
#include <string.h>
struct bank{
	char accNo[13];
	char accHolder[30];
	int balance;
};
struct bank b[3];

void displayacc(struct bank *);
void funds(struct bank *, char *, int, int);
void displaymsg();

int main(){
	int i;
	for(i = 0; i<3; i++){
		printf("Format:- Account_Number(12-digits Only)\t Account Holder\t Opening Balance\n");
		printf("Enter Account Details of Account %d: ", i+1);
		scanf(" %s %s %d", b[i].accNo, b[i].accHolder, &b[i].balance);
		if(strlen(b[i].accNo) != 12){
			printf("Invalid length of account Number!");
			return 0;
		}
	}

	int choice, flag = 1;
	while(flag){
	printf("\nPress 1 to display Accounts with balance less than 1000.\nPress 2 for Withdrawal/Deposit.\nPress any other to exit\n");
	printf("Enter your Choice : ");
	scanf("%d", &choice);

	switch(choice){
		case 1:
			displayacc(b);
			break;
		case 2:
			int op, amount;
			char acc[14];

			printf("Press 1 for Depositing Funds\t Press 0 for Withdrawing Funds\n");
			printf("Enter your choice: ");
			scanf("%d", &op);
			if(op < 0 || op > 1){
				printf("Invalid operation!\n");
				continue;
			}
			printf("Enter your Account number: ");
			scanf(" %s", acc);
			if(strlen(acc) != 12){
				printf("Invalid account number!\n");
				continue;
			}
			printf("Enter a amount: ");
			scanf("%d", &amount);
			funds(b, acc, amount, op);
			break;
		default:
			printf("Program exitted!\n");
			flag = 0;
			break;
		}
	}

	return 0;

}

void displayacc(struct bank *bp){
	struct bank *hp;
	int found = 0;
	for(hp = bp; hp <= bp+2; hp++){
		if(hp->balance <= 1000){
			printf("Account Number: %s\t Account Holder: %s\t Current Balance: %d\n", hp->accNo, hp->accHolder, hp->balance);
			found = 1;
		}
	}
	if(!found)
		printf("No Match Found!\n");

	printf("\n");
}

void funds(struct bank *bp, char *a, int sum, int c){
	struct bank *tp = bp;
	if(sum <= 0){
		printf("Invalid amount!\n");
		return;
	}
	while(tp <= bp+2){
		if(strcmp(tp->accNo,a) == 0){
			if(c == 0){
				if(1000 > (tp->balance - sum)){
					displaymsg();
					printf("Current Balance: %d\n", tp->balance);
					break;
				}
				else{
					tp->balance = tp->balance - sum;
					printf("Updated Balance: %d\n", tp->balance);
					break;
				}
			}
			else{
				tp->balance = tp->balance + sum;
				printf("Updated Balance: %d\n", tp->balance);
				break;
			}
		}
		tp++;
	}
}

void displaymsg(){
	printf("The balance is insufficient for the specified withdrawal\n");
}



