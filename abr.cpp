#include "abr.h"

Noeud::Noeud(int x) : info(x), fg(nullptr), fd(nullptr) {}

bool est_vide(const ABR& A) { return (A == nullptr); }

bool est_feuille(const ABR& A) {
	if (est_vide(A)) return false;
	return (A->fg == nullptr && A->fd == nullptr);
}

bool est_noeud_interne(const ABR& A) {
	if (est_vide(A)) return false;
	return (A->fg != nullptr || A->fd != nullptr);
}


ABR rechercher_ABR(ABR A, int x) {

	while (A) {
		if (A->info == x) return A;
		else if (x < A->info) A = A->fg;
		else A = A->fd;
	}
	return A;
}

bool inserer_ABR(ABR& A, int x) {

	ABR nouveau = new Noeud(x);
	if (!nouveau) return false;

	if (est_vide(A)) {
		A = nouveau;
		return true;
	}

	ABR q = A, pere;

	while (q) {
		pere = q;
		if (x < q->info) {
			q = q->fg;
			if (!q) pere->fg = nouveau;
		}
		else {
			q = q->fd;
			if (!q) pere->fd = nouveau;
		}
	}
	return true;
}

ABR rechercher_ABR_rec(ABR A, int x) {
	if (est_vide(A)) return nullptr;
	if (A->info == x) return A;
	if (x < A->info) return rechercher_ABR_rec(A->fg, x);
	return rechercher_ABR_rec(A->fd, x);
}

bool inserer_ABR_rec(ABR& A, int x) {
	if (est_vide(A)) {
		ABR nouveau = new Noeud(x);
		if (!nouveau) return false;
		A = nouveau;
		return true;
	}

	if (x < A->info) return inserer_ABR_rec(A->fg, x);
	return inserer_ABR_rec(A->fd, x);
}

ABR retirer_min_ABR(ABR& A) {
	if (est_vide(A)) return nullptr;

	if (A->fg == nullptr) {
		ABR p = A;
		A = A->fd;

		p->fg = nullptr;
		p->fd = nullptr;
		return p;
	}

	return retirer_min_ABR(A->fg);
}

ABR supprimer_ABR(ABR& A, int x) {
	if (!A) return nullptr;

	if (x < A->info) A->fg = supprimer_ABR(A->fg, x);
	else if (x > A->info) A->fd = supprimer_ABR(A->fd, x);
	else {
		ABR p = A;
		if (A->fg == nullptr) A = A->fd;
		else if (A->fd == nullptr) A = A->fg;
		else {
			ABR tmp = retirer_min_ABR(A->fd);
			tmp->fg = A->fg;
			tmp->fd = A->fd;
			A = tmp;
		}
		delete p;
	}

	return A;
}


void prefixe_ABR(const ABR& A) {
	if (!A) return;
	cout << A->info << " ";
	prefixe_ABR(A->fg);
	prefixe_ABR(A->fd);
}

void infixe_ABR(const ABR& A) {
	if (!A) return;
	infixe_ABR(A->fg);
	cout << A->info << " ";
	infixe_ABR(A->fd);
}

void postfixe_ABR(const ABR& A) {
	if (!A) return;
	postfixe_ABR(A->fg);
	postfixe_ABR(A->fd);
	cout << A->info << " ";
}

void parcours_niveau_ABR(const ABR& A) {
	if (!A) return;
	queue<ABR> file;
	file.push(A);
	ABR q;
	while (!file.empty()) {
		q = file.front();
		file.pop();
		cout << q->info << " ";
		if (q->fg != nullptr) file.push(q->fg);
		if (q->fd != nullptr) file.push(q->fd);
	}
}

void prefixe_ABR_iter(const ABR& A) {
	if (!A) return;
	stack<ABR> pile;
	pile.push(A);
	ABR q;
	while (!pile.empty()) {
		q = pile.top();
		pile.pop();
		cout << q->info << " ";
		if (q->fg != nullptr) pile.push(q->fg);
		if (q->fd != nullptr) pile.push(q->fd);
	}
}

int taille_ABR(const ABR& A) {
	if (est_vide(A)) return 0;
	return 1 + max(taille_ABR(A->fg), taille_ABR(A->fd));
}

void liberer_ABR(ABR& A) {
	if (!A) return;
	liberer_ABR(A->fg);
	liberer_ABR(A->fd);
	delete A;
	A = nullptr;
}

// Verifier si un Arbre est un ABR
// 1- Utilisant le parcours infixe
bool est_ABR(const ABR& A, int& n) {
	int prcd = -1;
	return __est_ABR(A, prcd, n);
}
// helper
bool __est_ABR(const ABR& A, int& prcd, int& n) {
	n++;
	if (!A) return true;

	bool fg_est_ABR = __est_ABR(A->fg, prcd, n);
	
	if (A->info <= prcd) return false;
	prcd = A->info;
	
	bool fd_est_ABR = __est_ABR(A->fd, prcd, n);

	return (fg_est_ABR && fd_est_ABR);
}

// Avec le min et le max des fils
int max_ABR(const ABR& A, int& n) {
	n++;
	if (!A) return -1;
	return max(max_ABR(A->fg, n), max(A->info, max_ABR(A->fd, n)));
}
int min_ABR(const ABR& A, int& n) {
	n++;
	if (!A) return 999;
	return min(min_ABR(A->fg, n), min(A->info, min_ABR(A->fd, n)));
}

bool est_ABR_bis(const ABR& A, int& n) {
	n++;
	if (!A) return true;

	if (!(A->info > max_ABR(A->fg, n) && A->info < min_ABR(A->fd, n)))
		return false;

	return est_ABR_bis(A->fg, n) && est_ABR_bis(A->fd, n);
}


// tri d'un tableau par un ABR

void tri_par_ABR(int T[], int premier, int dernier) {

	ABR A = nullptr;
	for (int i = premier; i <= dernier; i++)
		inserer_ABR(A, T[i]);

	int _premier = premier;
	ABR_vers_tableau(A, T, _premier, dernier);
	
	liberer_ABR(A);
}
void ABR_vers_tableau(ABR A, int T[], int& premier, int dernier) {
	
	if (premier > dernier || !A) return;
	
	ABR_vers_tableau(A->fg, T, premier, dernier);

	T[premier] = A->info;
	premier++;
	
	ABR_vers_tableau(A->fd, T, premier, dernier);

}
