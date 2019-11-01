#include <stdio.h>
#include <stdlib.h>//Split ve double bet kaldý
int main() {
	int money=100, bet=10, var, change, deck[52], deck52, pc[5], player[5], pcc, sumpc, sumplayer, playerc, pcA, playerA;
	int i,j,k;
	char betc='y';
	//Giriþ ekranýný hazýrlayan blok.
	printf("Welcome to the blackjack game!\nPress a button for start the game...\n");
	getch();
	//Oyunun devam þartýný belirleyen blok.
	while(money>0){
		system("cls");
		pcA=0;
		playerA=0;
		deck52=52;
		//Deste tanýmlayan blok.
		for(i=0;i<=51;i++){
			deck[i]=i%13+1;
		}
		//Bet deðiþimi soran blok.
		if(bet>money){
			bet=money;
		}
		printf("\nBet: %d\t\tMoney: %d\nDo you want to change the bet?(y/n)\n", bet, money);
		var=0;
		while(var==0){
			betc=getch();
			if(betc=='Y'){
				var=1;
				change=1;
			}
			else if(betc=='y'){
				var=1;
				change=1;
			}
			else if(betc=='N'){
				var=1;
				change=0;
			}
			else if(betc=='n'){
				var=1;
				change=0;
			}
			else{
				var=0;
				printf("An error occured please repeat your choise...\nBet: %d\nDo you want to change the bet?\n", bet);
			}
		}
		var=1;
		if(change==1){
			while(var==1){
				printf("Enter new bet:");
				scanf("%d", &bet);
				if(bet<=money&&bet>0){
					var=0;
					system("cls");
					printf("\nBet: %d\t\tMoney: %d\n", bet, money);
				}
				else{
					printf("An error occured please repeat your choise...\n");
				}
			}
		}
		//Kart daðýtan blok.
		pcc=0;
		playerc=2;
		for(i=0;i<=4;i++){
			srand(time(NULL));
			j=rand()%deck52;
			pc[i]=deck[j];
			for(k=j;k<52-i;k++){
				deck[k]=deck[k+1];
			}
			deck52--;
		}
		for(i=0;i<=4;i++){
			srand(time(NULL));
			j=rand()%deck52;
			player[i]=deck[j];
			if(deck[j]==1){
				playerA++;
			}
			for(k=j;k<52-i;k++){
				deck[k]=deck[k+1];
			}
			deck52--;
		}
		//Desteleri yazdýran blok.
		printf("\nPc : X ");
		if(pc[1]>1&&pc[1]<=10){
			printf("%d", pc[1]);
		}
		else if(pc[1]==11){
			printf("J");
		}
		else if(pc[1]==12){
			printf("Q");
		}
		else if(pc[1]==13){
			printf("K");
		}
		else if(pc[1]==1){
			printf("A");
		}
		printf("\nPlayer :");
		for(i=0;i<=1;i++){
			if(player[i]>1&&player[i]<=10){
				printf(" %d", player[i]);
			}
			else if(player[i]==11){
				printf(" J");
			}
			else if(player[i]==12){
				printf(" Q");
			}
			else if(player[i]==13){
				printf(" K");
			}
			else if(player[i]==1){
				printf(" A");
			}	
		}
		//Oyuncuya kart veren blok.
		sumplayer=0;
		for(i=0;i<playerc;i++){
			if(player[i]<=10&&player[i]>1){
				sumplayer+=player[i];
			}
			else if(player[i]==1){
				sumplayer+=11;
			}
			else{
				sumplayer+=10;
			}
		}
		printf("\tTotal: %d", sumplayer);
		var=1;
		while(playerc<5&&sumplayer<21&&var==1){			
			printf("\nDo you want a new card?(y/n)");
			betc=getch();
			system("cls");
			printf("\nBet: %d\t\tMoney: %d\n\n", bet, money);
			if(betc=='Y'){
				var=1;
				playerc++;
				if(player[playerc-1]<=10&&player[playerc-1]>1){
					sumplayer+=player[playerc];
				}
				else if(player[playerc-1]==1){
					sumplayer+=11;
					playerA++;
				}
				else{
					sumplayer+=10;
				}
			}
			else if(betc=='y'){
				var=1;
				playerc++;
				if(player[playerc-1]<=10&&player[playerc-1]>1){
					sumplayer+=player[playerc-1];
				}
				else if(player[playerc-1]==1){
					sumplayer+=11;
				}
				else{
					sumplayer+=10;
				}
			}
			else if(betc=='N'){
				var=0;
			}
			else if(betc=='n'){
				var=0;		
			}
			else{
				var=1;
				printf("An error occured please repeat your choise...\nBet: %d\nDo you want a new card?\n", bet);
			}
			//Desteleri yazdýran blok.
			printf("\nPc : X ");
			if(pc[1]>1&&pc[1]<=10){
				printf("%d", pc[1]);
			}
			else if(pc[1]==11){
				printf("J");
			}
			else if(pc[1]==12){
				printf("Q");
			}
			else if(pc[1]==13){
				printf("K");
			}
			else if(pc[1]==1){
				printf("A");
			}
			printf("\nPlayer :");
			for(i=0;i<playerc;i++){
				if(player[i]>1&&player[i]<=10){
					printf(" %d", player[i]);
				}
				else if(player[i]==11){
					printf(" J");
				}
				else if(player[i]==12){
					printf(" Q");
				}
				else if(player[i]==13){
					printf(" K");
				}
				else if(player[i]==1){
					printf(" A");
				}	
			}
			while(playerA>0&&sumplayer>21){
				sumplayer-=10;
				playerA--;
			}
			printf("\tTotal: %d", sumplayer);
		}
		//Pc ye el tanýmlayan blok.
		sumpc=0;
		for(i=0;i<2;i++){
			pcc++;
			if(pc[pcc-1]<=10&&pc[pcc-1]>1){
				sumpc+=pc[pcc-1];
			}
			else if(pc[pcc-1]==1){
				sumpc+=11;
				pcA++;
			}
			else{
				sumpc+=10;
			}
		}
		while(sumplayer<=21&&sumpc<16){
			pcc++;
			if(pc[pcc-1]<=10&&pc[pcc-1]>1){
				sumpc+=pc[pcc-1];
			}
			else if(pc[pcc-1]==1){
				sumpc+=11;
				pcA++;
			}
			else{
				sumpc+=10;
			}
			while(pcA>0&&sumpc>21){
				sumpc-=10;
				pcA--;
			}	
		}
		//Desteleri yazdýran blok.
			printf("\n\nPc :");
			for(i=0;i<pcc;i++){
				if(pc[i]>1&&pc[i]<=10){
					printf(" %d", pc[i]);
				}
				else if(pc[i]==11){
					printf(" J");
				}
				else if(pc[i]==12){
					printf(" Q");
				}
				else if(pc[i]==13){
					printf(" K");
				}
				else if(pc[i]==1){
					printf(" A");
				}	
			}
			printf("\tTotal: %d", sumpc);
			printf("\nPlayer :");
			for(i=0;i<playerc;i++){
				if(player[i]>1&&player[i]<=10){
					printf(" %d", player[i]);
				}
				else if(player[i]==11){
					printf(" J");
				}
				else if(player[i]==12){
					printf(" Q");
				}
				else if(player[i]==13){
					printf(" K");
				}
				else if(player[i]==1){
					printf(" A");
				}	
			}
			printf("\tTotal: %d", sumplayer);
		//El sonucuna göre yapýlan iþlemler.
		if(sumplayer==21&&playerc==2){
			printf("\nBlackjack! You win");
			money+=bet*3/2;
		}
		else if(sumplayer==21||sumpc>21){
			printf("\nYou win");
			money+=bet;
		}
		else if(sumplayer>21||sumpc==21){
			printf("\nYou lose");
			money-=bet;
		}
		else if(sumplayer>sumpc){
			printf("\nYou win");
			money+=bet;
		}
		else if(sumplayer==sumpc){
			printf("\nDraw");
		}
		else{
			printf("\nYou lose");
			money-=bet;
		}
		printf("\t\t\t\tMoney: %d\n", money);
		system("pause");
	}
	printf("\n\tGAME OVER");
}
