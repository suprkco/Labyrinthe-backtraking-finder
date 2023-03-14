#include<stdio.h>
#include<string.h>
#include<unistd.h>

char labyrint[10000];

#define XMIN 0
#define YMIN 0
#define XMAX 50
#define YMAX 21

void init() {
	FILE* file = fopen("labyr2.txt","r");
	char labLigne[1024];
	int remplissage = 0;
	if (file == NULL) perror ("le fichier txt est introuvable");
	while (fgets (labLigne , 1024 , file) != NULL ) {
		if (labLigne[strlen(labLigne)-1]=='\n') {
			labLigne[strlen(labLigne)-1] = '\0';
			strcpy(&labyrint[remplissage],labLigne);
			remplissage = remplissage + XMAX;
		}
	}
	fclose (file);
}

void affichage() {
	
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif

	for (int ligne=0 ; ligne<YMAX ; ligne++) {
		for (int colonne=0 ; colonne<XMAX ; colonne++) {
			printf("%c",labyrint[ligne*XMAX+colonne]);
		}
		printf("\n");
	}
	printf("\n");
}

void path1() {
	int x1 = XMIN+1;
	int y1 = YMIN+1;
	int x2 = XMAX-1;
	int y2 = YMAX-1;
	for (x1=1 ; x1<x2 ; x1++) {
		labyrint[y1*XMAX+x1]='-';
	}
	for (y1=1 ; y1<y2 ; y1++) {
		labyrint[y1*XMAX+x1]='-';
	}
}

void path2() {
	int x1 = XMIN+1;
	int y1 = YMIN+1;
	int x2 = XMAX-1;
	int y2 = YMAX-1;
	while ((x1!=x2) || (y1!=y2)) {
		if (x1<x2) x1++;
		labyrint[y1*XMAX+x1]='-';
		if (x1>x2) x1--;
		labyrint[y1*XMAX+x1]='-';
		if (y1<y2) y1++;
		labyrint[y1*XMAX+x1]='-';
		if (y1>y2) y1--;
		labyrint[y1*XMAX+x1]='-';
	}
}
int valid3(int x1,int y1,int direction) {
		if ((direction==1) && (labyrint[y1*XMAX+x1+1]=='B')) return 1;
		if ((direction==2) && (labyrint[(y1+1)*XMAX+x1]=='B')) return 1;
		if ((direction==3) && (labyrint[y1*XMAX+x1-1]=='B')) return 1;
		if ((direction==4) && (labyrint[(y1-1)*XMAX+x1]=='B')) return 1;

		if ((direction==1) && (labyrint[y1*XMAX+x1+1]==' ')) return 0;
		if ((direction==2) && (labyrint[(y1+1)*XMAX+x1]==' ')) return 0;
		if ((direction==3) && (labyrint[y1*XMAX+x1-1]==' ')) return 0;
		if ((direction==4) && (labyrint[(y1-1)*XMAX+x1]==' ')) return 0;
		return -1;
}
int path3(int x1,int y1) {
	int score;
	for (int direction=1 ; direction<5 ; direction++) {
		int test = valid3(x1,y1,direction);
		if (test==0) {
			if (direction==1) x1++;
			if (direction==2) y1++;
			if (direction==3) x1--;
			if (direction==4) y1--;
			labyrint[y1*XMAX+x1]='-';
			affichage();
			sleep(1);
			score = path3(x1,y1);
			if (score == 1) return 1;
			labyrint[y1*XMAX+x1]='.';
			affichage();
			sleep(1);
			if (direction==1) x1--;
			if (direction==2) y1--;
			if (direction==3) x1++;
			if (direction==4) y1++;
		}
		if (test==1) return 1;
	}
	return 0;
}

int path4 () {
	return 0;
}

int main() {
	int x1 = XMIN+1;
	int y1 = YMIN+1;
	init();
	affichage();
	path3(x1,y1);
	affichage();
	return 0;
}
