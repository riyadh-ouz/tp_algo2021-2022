#include "divers.h"


void tri_tri_couleur(int T[], int n) {

	int i = 0,
		i_rouge = 0,
		i_vert = n - 1;

	while (i <= i_vert) {
		if (T[i] == 1) {
			permuter<int>(T[i], T[i_rouge]);
			i_rouge++;
			i++;
		}
		else if (T[i] == 3) {
			permuter<int>(T[i], T[i_vert]);
			i_vert--;
		}
		else i++;
	}

}
