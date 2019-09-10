/*Program to display and add two polynomials using arrays*/

#include <stdio.h>
#include <conio.h>
#define MAX 10

struct term {
	int coeff;
	int exp;
};

struct poly {
	struct term t[10];
	int totalTerms;
};

//Prototypes

void initPoly(struct poly *);
void polyCreate(struct poly *, int c, int e);
struct poly addPoly(struct poly, struct poly);
struct poly mulPoly(struct poly, struct poly);
void display(struct poly);

int main() {
	struct poly p1,p2,p3;
	
	initPoly(&p1);
	initPoly(&p2);
	initPoly(&p3);
	
	polyCreate(&p1,1,7);
	polyCreate(&p1,2,6);
	polyCreate(&p1,3,5);
	polyCreate(&p1,4,4);
	polyCreate(&p1,5,2);
	
	polyCreate(&p2,1,4);
	polyCreate(&p2,1,3);
	polyCreate(&p2,1,2);
	polyCreate(&p2,1,1);
	polyCreate(&p2,2,0);
	
	p3 = addPoly(p1,p2);
	
	printf("First polynomial: ");
	display(p1);
	
	printf("\nSecond polynomail: ");
	display(p2);
	
	printf("\nResultant polynomial: ");
	display(p3);
	getch();
}

/*Initializes elements of struct poly*/
void initPoly(struct poly *p){
	int i;
	p->totalTerms = 0;
	
	for(i=0; i<MAX; i++){
		p->t[i].coeff = 0;
		p->t[i].exp = 0;
	}
}

/*Adds the term of polynomial to the array t*/
void polyCreate(struct poly *p, int c, int e){
	p->t[p->totalTerms].coeff = c;
	p->t[p->totalTerms].exp = e;
	(p->totalTerms)++;
}

/*Display the polynomial equation*/
void display(struct poly p){
	int flag = 0, i;
	for(i=0; i<p.totalTerms; i++){
		if(p.t[i].exp != 0){
			printf("%dx^%d + ",p.t[i].coeff,p.t[i].exp);
		}
		else {
			printf("%d",p.t[i].coeff);
			flag = 1;
		}
	}
	if(!flag){
		printf("\b\b");
	}
}

/*Adds two polynomials p1 and p2*/
struct poly addPoly(struct poly p1, struct poly p2){
	int i,j,c;
	struct poly p3;
	initPoly(&p3);
	
	if(p1.totalTerms > p2.totalTerms){
		c = p1.totalTerms;
	}
	else{
		c = p2.totalTerms;
	}
	
	for(i=0,j=0; i<=c; p3.totalTerms++){
		if(p1.t[i].coeff == 0 && p2.t[j].coeff == 0){
			break;
		}
		if(p1.t[i].exp >= p2.t[j].exp){
			if(p1.t[i].exp == p2.t[j].exp){
				p3.t[p3.totalTerms].coeff = p1.t[i].coeff + p2.t[j].coeff;
				p3.t[p3.totalTerms].exp = p1.t[i].exp;
				i++;
				j++;
			}
			else{
				p3.t[p3.totalTerms].coeff = p1.t[i].coeff;
				p3.t[p3.totalTerms].exp = p1.t[i].exp;
			}
		}
		else{
			p3.t[p3.totalTerms].coeff = p2.t[j].coeff;
			p3.t[p3.totalTerms].exp = p2.t[j].exp;
		}
	}
	return p3;
}

/*Multiples two polynomials p1 and p2*/
struct poly mulPoly(struct poly p1, struct poly p2){
	int coeff, exp;
	struct poly temp, p3;
	
	initPoly(&temp);
	initPoly(&p3);
	
	if(p1.totalTerms != 0 && p2.totalTerms != 0){
		for(int i=0; i<p1.totalTerms; i++){
			struct poly p;
			initPoly(&p);
			for(int j=0; j<p2.totalTerms; j++){
				coeff = p1.t[i].coeff * p2.t[j].coeff;
				exp = p1.t[i].exp + p2.t[j].exp;
				polyCreate(&p,coeff,exp);
			}
			if(i != 0){
				p3 = addPoly(temp,p);
				temp = p3;
			}
			else{
				temp = p;
			}
		}
	}
	return p3;
}
