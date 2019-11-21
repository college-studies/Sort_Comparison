void selection_sort(int* vet, int n) {
	int pos, aux = 0, i;

	selection_c_cont++;
	while (aux < n) {
		selection_c_cont++;
		pos = aux;
		for (i = aux; i < n; i++) {
			selection_c_cont++;
			if (vet[i] < vet[pos]) {
				pos = i;
			}
		}
		swap(&vet[pos], &vet[aux]);
		selection_s_cont++;
		aux++;
	}

} 