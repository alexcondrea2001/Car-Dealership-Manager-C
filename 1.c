/*
 * 1.c
 *
 *  Created on: Apr 16, 2021
 *      Author: CONDREA
 */

#include<stdio.h>
#include <windows.h>
#include <GL/glut.h>

struct masina
	{
	char marca[100];
	char model[100];
	int an;
	char stare[100];
	int putere;
	int kilometraj;
	int pret;
	};
struct masina v[100], aux;

void display()
{
  char string[]="MAGAZIN-MASINI-AUTO";
  char text[30];
  int len, i, j;

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 1.0f);
  len = (int)strlen(string);
  glRasterPos2f(-0.15f,0.9f);

  for(i = 0; i < len; i++)
	  {
	  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	  }

  for(i = 0; i < 15; i++)
  {
  	   glBegin(GL_QUADS);
  	   glColor3f(0.0f, i/5.0f, 1.0f);
  	   glVertex2f(-0.93+i*0.13, -0.5);
  	   glVertex2f(-0.93+i*0.13+0.07, -0.5);
  	   glVertex2f(-0.93+i*0.13+0.07, -0.5+v[i].putere/1000.0);
  	   glVertex2f(-0.93+i*0.13, -0.5+v[i].putere/1000.0 );
  	   glEnd();
  	   glRasterPos2f(-1.0+i*0.13+0.08,-0.5+v[i].putere/1000.0+0.05);
  	   sprintf(text, "%d HP", v[i].putere);

  	   for(j=0;j<strlen(text);j++)
  	   {
  		   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, text[j]);
  	   }

  	   glRasterPos2f(-1.0 + i * 0.13 +0.07, -0.6);

  	   for(j=0;j<strlen(v[i].marca);j++)
  	   {
  		   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, v[i].marca[j]);
  	   }

  	   glRasterPos2f(-1.0 + i * 0.13 +0.07, -0.65);

  	   for(j=0;j<strlen(v[i].model);j++)
  		 {
  		 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, v[i].model[j]);
  		 }
      }

  glFlush();
}


float medie (int, int);

void errorbuget(int);

int main(int argc, char** argv)
{
	FILE *fisier;
	FILE *fisier2;
	FILE *fisier3;
	int n;
	int i,j,k;
	int S,S2;
	int max;
	int nr1;
	int buget;
	int ok;
	int m;
	float medie_ani;


	fisier = fopen("fisier.txt", "r");

	fscanf(fisier,"%d",&n);
	printf("NUMARUL DE MASINI: %d\n\n", n);
	fflush(stdout);

	for(i=0;i<n;i++)
	{
		fscanf(fisier,"%s",v[i].marca);
		fscanf(fisier,"%s",v[i].model);
		fscanf(fisier,"%d",&v[i].an);
		fscanf(fisier,"%s",v[i].stare);
		fscanf(fisier,"%d",&v[i].putere);
		fscanf(fisier,"%d",&v[i].kilometraj);
		fscanf(fisier,"%d",&v[i].pret);

		printf("MARCA MASINII: %s\n", v[i].marca);
		fflush(stdout);
		printf("MODELUL MASINII: %s\n", v[i].model);
		fflush(stdout);
		printf("ANUL FABRICATIEI: %d\n", v[i].an);
		fflush(stdout);
		printf("STAREA MASINII: %s\n", v[i].stare);
		fflush(stdout);
		printf("PUTEREA MASINII: %d HP\n", v[i].putere);
		fflush(stdout);
		printf("KILOMETRAJUL MASINII: %d KM\n", v[i].kilometraj);
		fflush(stdout);
		printf("PRETUL MASINII: %d EURO\n\n", v[i].pret);
		fflush(stdout);

	}

	fisier2 = fopen("fisier2.txt", "w");

	fprintf(fisier2,"ORDONAREA DESCRESCATOARE IN FUNCTIE DE ANUL FABRICARII:\n\n");

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(v[i].an < v[j].an)
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	for(i=0;i<n;i++)
			{
				fprintf(fisier2,"%s ",v[i].marca);
				fprintf(fisier2,"%s ",v[i].model);
				fprintf(fisier2,"%d ",v[i].an);
				fprintf(fisier2,"%s ",v[i].stare);
				fprintf(fisier2,"%d hp ",v[i].putere);
				fprintf(fisier2,"%d ",v[i].kilometraj);
				fprintf(fisier2,"%d \n",v[i].pret);
			}

	fclose(fisier2);

	fisier3 = fopen("fisier3.txt", "w");

	fprintf(fisier3,"ORDONAREA ALFABETICA A MASINILOR:\n\n");

	for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(v[i].marca[0] > v[j].marca[0])
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
			}
		}

	for(i=0;i<n;i++)
		{
			fprintf(fisier3,"%s ",v[i].marca);
			fprintf(fisier3,"%s ",v[i].model);
			fprintf(fisier3,"%d ",v[i].an);
			fprintf(fisier3,"%s ",v[i].stare);
			fprintf(fisier3,"%d hp ",v[i].putere);
			fprintf(fisier3,"%d ",v[i].kilometraj);
			fprintf(fisier3,"%d \n",v[i].pret);

		}

	fclose(fisier3);

	for(i=0;i<n;i++)
	{
		S = S + v[i].putere;
		S2 = S2 + v[i].an;
	}

	printf("MEDIA ARITMETICA A CAILOR PUTERE ESTE: %.2f HP\n\n", (float)S/n);
	fflush(stdout);

	max = v[0].putere;

	for(i=1;i<n;i++)
	{
		if(max < v[i].putere)
		{
			max = v[i].putere;
			k=i;
		}
	}

	printf("MASINA CU CEI MAI MULTI HP ESTE: %s %s(%d HP)\n\n", v[k].marca, v[k].model, max);
	fflush(stdout);

	i=0;
	while(i<n)
	{
		if(v[i].an>=2015)
		{
			nr1++;
		}
		i++;
	}

	printf("NUMARUL DE MASINI NOI(>=2015): %d\n\n", nr1);
	fflush(stdout);

	medie_ani = medie(S2,n);

	printf("MEDIA ANILOR ESTE: %.2f\n\n", medie_ani);
	fflush(stdout);

	printf("BUGETUL DVS ESTE(EURO):");
	fflush(stdout);
	scanf("%d",&buget);
	errorbuget(buget);

	ok=0;
	printf("\nMASINI DISPONIBILE:\n\n");
	fflush(stdout);
	for(i=0;i<n;i++)
	{
		if(v[i].pret<=buget)
		{
			printf("%d.%s %s\n",i+1,v[i].marca,v[i].model);
			fflush(stdout);
			ok=1;
		}
	}

	if(ok==0)
	{
		printf("NU SUNT MASINI DISPONIBILE!");
		fflush(stdout);
	}
	else
	{
	printf("\nPUTETI SA VA SELECTATI MASINA!");
	fflush(stdout);

	printf("\n\nINTRODUCETI CIFRA REPREZENTATIVA MASINII:");
	fflush(stdout);
	scanf("%d",&m);

	while(v[m-1].pret>buget)
	{
		printf("\nVA RUGAM SA SELECTATI DIN NOU MASINA!\n");
		fflush(stdout);
		printf("\nINTRODUCETI CIFRA REPREZENTATIVA MASINII:");
		fflush(stdout);
		scanf("%d",&m);
	}

	printf("\nMASINA DVS ESTE: %s %s", v[m-1].marca,v[m-1].model);
	fflush(stdout);
	}

	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("PUTERE MASINI");
	glutDisplayFunc(display);
	glutMainLoop();



	return 0;
}

float medie (int S, int n)
{
	float m;
	m = (float)S/n;
	return m;
}
void errorbuget(int x)
{
	while(x<=0)
	{
		printf("\nVA RUGAM SA INTRODUCETI DIN NOU BUGETUL DVS!(>=0)\n\nBUGETUL DVS ESTE(EURO):");
		fflush(stdout);
		scanf("%d",&x);
	}
}
