#include <stdio.h>
#include <stdlib.h>
#define LIMIT 50 // rozmiar kolejki

int queue[LIMIT]; 
int poczatek, koniec; 
int i,k; 
int wybor; 
void dodaj(); // funkcja dodająca elementy do kolejki
void usun(); // funkcja usuwająca element z kolejki
void wyswietl(); // funkcja wyświetlająca elementy kolejki
void zliczanie(); //funkcja zliczająca elementy kolejki
void szukanie(); //funkcja szukająca konkretnych elementów w kolejce

int main(){
	printf ("Kolejka FIFO\n\n");
	poczatek = koniec = -1;
	do{
		printf("1. Dodaj element\n2. Usun element\n3. Wypisz elementy\n4. Zlicz elementy\n5. Szukaj elementu\n6. Wyjdz\n");
		printf("Wybierz opcje:");
		scanf("%d",&wybor);
		printf("\n");
		switch(wybor){
			case 1:
			dodaj();
			break;
			case 2:
			usun();
			break;
			case 3:
			wyswietl();
			break;
			case 4:
			zliczanie();
			break;
			case 5:
			szukanie();
			break;
			case 6:
			exit(0);
			break;
			default:
			printf("wybor niemozliwy\n");
			break;
		}
	} while(wybor!=6);
	return 0;
}
	void dodaj(){
		int element;
		if (koniec == LIMIT - 1){ // zabezpieczenie zeby nie przekroczyc limitu miejsc w kolejce
		printf("NIE UDALO SIE, za duzo elementow w kolejce\n\n");
		}
		else{
			if (poczatek == - 1) poczatek = 0; //początek ma mieć wartość 0
			printf("Wpisz liczbe, ktora chcesz dodac do kolejki: ");
			scanf("%d", &element);
			printf("Dodano liczbe %d do kolejki\n\n", element);
			koniec++; //zwiększamy koniec kolejki o 1 i pod tym miejscem w kolejce zapamiętujemy wartość wprowadzonego elementu
			queue[koniec] = element;
			}
	}
	void usun(){
		if (poczatek == - 1 || poczatek > koniec){
			printf("Za malo elementow \n");
		}
		else{
			printf("usunieto element: %d\n", queue[poczatek]);//zgodnie z regułą FIFO usuwamy element znjadujący się na początku kolejki
			koniec=koniec-1; //koniec zmniejsza się o 1
			for(i=0;i<=koniec;i++){	
				queue[i]=queue[i+1]; //przepisujemy tablicę aby elementy przesunęły się w kolejce o 1 miejsce do przodu kolejki
			}
		}
	}
	void wyswietl(){
	int i;
	if (poczatek == - 1){
	printf("brak\n");
	}
	else
	{
	printf("Elementy kolejki to :\n POCZATEK\n");
	for (i = poczatek; i <= koniec; i++)
	printf("%d\n", queue[i]);
	}
	printf("KONIEC\n");
	}
	void zliczanie(){
		if(poczatek==-1) printf("0\n");
		else{
			int liczbael=koniec-poczatek+1;
			printf("liczba elementow to %d\n", liczbael);
		}
	}
	
	void szukanie()
	{	
		int p=0;
		printf("jakiego elemntu szukasz? ");
		scanf("%d", &k);
		for(i=poczatek;i<=koniec;i++){
			if(queue[i]==k){ //przeszukujemy kolejkę i jeśli znajdziemy szukany element to wypisujemy na którym miejscu w kolejce się znajduje 
				p++;
				printf("liczba %d znajduje sie w kolejce na %d miejscu\n",queue[i],i+1 );
			}		
		}
		if(p==0){			
				printf("brak tego elementu\n");
		}
	}
