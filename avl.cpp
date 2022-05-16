#include "avl.h"

NoeudAVL::NoeudAVL(int x) : info(x), hauteur(0), fg(nullptr), fd(nullptr) {}

int get_hauteur(const AVL& A) {
	if (A == nullptr) return -1;
	return A->hauteur;
}

void set_hauteur(AVL& A) {
	if (A == nullptr) return;
	A->hauteur = 1 + max(get_hauteur(A->fg), get_hauteur(A->fd));
}

int desequilibre(const AVL& A) {
	if (A == nullptr) return 0;
	return get_hauteur(A->fg) - get_hauteur(A->fd);
}

bool est_equilibre(const AVL& A) {
	if (A == nullptr) return true;
	int d = abs(desequilibre(A));
	if (d <= 1) return (est_equilibre(A->fg) && est_equilibre(A->fd));
	return false;
}

// Rotation des AVL
AVL rotation_droite(AVL& A) {
	if (A != nullptr)
	{
		if (A->fg == nullptr) return A;

		AVL B = A->fg;
		A->fg = B->fd;
		B->fd = A;
		set_hauteur(A);
		set_hauteur(B);
		return B;
	}
	return nullptr;
}

AVL rotation_gauche(AVL& A) {
	if (A != nullptr)
	{
		if (A->fd == nullptr) return A;

		AVL B = A->fd;
		A->fd = B->fg;
		B->fg = A;
		set_hauteur(A);
		set_hauteur(B);
		return B;
	}
	return nullptr;
}

AVL rotation_GD(AVL& A) {
	if (A != nullptr)
	{
		if (A->fg != nullptr) A->fg = rotation_gauche(A->fg);
		return rotation_droite(A);
	}
	return nullptr;
}

AVL rotation_DG(AVL& A) {
	if (A != nullptr)
	{
		if (A->fd != nullptr) A->fd = rotation_droite(A->fd);
		return rotation_gauche(A);
	}
	return nullptr;
}

void inserer_AVL(AVL& A, int x) {
	if (A == nullptr) A = new NoeudAVL(x);
	else if (x < A->info) {
		inserer_AVL(A->fg, x);
		set_hauteur(A);
		A = reequilibrer(A);
	}
	else if (x > A->info) {
		inserer_AVL(A->fd, x);
		set_hauteur(A);
		A = reequilibrer(A);
	}
	else return; // valeur déja trouvé
}

AVL reequilibrer(AVL& A) {
	int d1 = desequilibre(A);
	if (d1 == 2) {
		int d2 = desequilibre(A->fg);
		if (d2 >= 0) return rotation_droite(A);
		return rotation_GD(A);
	}
	else if (d1 == -2) {
		int d2 = desequilibre(A->fd);
		if (d2 <= 0) return rotation_gauche(A);
		return rotation_DG(A);
	}
	return A;
}

void parcours_niveau_AVL(const AVL& A) {
	if (!A) return;
	queue<AVL> file;
	file.push(A);
	AVL q;
	while (!file.empty()) {
		q = file.front();
		file.pop();
		cout << q->info << " ";
		if (q->fg != nullptr) file.push(q->fg);
		if (q->fd != nullptr) file.push(q->fd);
	}
}
