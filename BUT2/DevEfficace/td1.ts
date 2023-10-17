function nombreAleatoire(n: number): number {
  return Math.floor(Math.random() * n) + 1;
}

class TableauTrie {
  private tab_: Array<number> = [];

  constructor(taille = 0) {
    for (let i = 0; i < taille; ++i) this.tab_.push(nombreAleatoire(taille * 10));
    this.tab_.sort((x, y) => x - y);
  }

  get taille(): number {
    return this.tab_.length;
  }

  private pushLeft(ind: number): void {
    let e = this.tab_[ind];

    while (ind > 0 && e < this.tab_[ind - 1]) {
      let aux = this.tab_[ind];
      this.tab_[ind] = this.tab_[ind - 1];
      this.tab_[ind - 1] = aux;

      ind -= 1;
    }
  }

  private pushRight(ind: number): void {
    let e = this.tab_[ind];

    while (ind < this.tab_.length - 1 && e > this.tab_[ind + 1]) {
      let aux = this.tab_[ind];
      this.tab_[ind] = this.tab_[ind + 1];
      this.tab_[ind + 1] = aux;

      ind += 1;
    }
  }

  push(e: number): void {
    this.tab_.push(e);
    this.pushLeft(this.tab_.length - 1);
  }

  afficher(): void {
    for (let valeur of this.tab_) console.log(valeur);
  }

  valeur(indice: number): number {
    if (indice < 0 || indice >= this.tab_.length) throw new Error("Indice incorrect");

    return this.tab_[indice];
  }

  retirer(indice: number): number {
    if (indice < 0 || indice >= this.tab_.length) throw new Error("Indice incorrect");

    let valeur = this.tab_[indice];

    for (let i = indice; i < this.tab_.length - 1; ++i) this.tab_[i] = this.tab_[i + 1];

    this.tab_.pop();

    return valeur;
  }

  modification(ind: number, valeur: number): void {
    if (ind < 0 || ind >= this.tab_.length) throw new Error("Indice incorrect");

    if (valeur < this.tab_[ind]) {
      this.tab_[ind] = valeur;
      this.pushLeft(ind);
    } else {
      this.tab_[ind] = valeur;
      this.pushRight(ind);
    }
  }

  rechercheDichotomiqueIt(e: number): number {
    let ind1 = 0;
    let ind2 = this.tab_.length;

    while (ind1 < ind2) {
      let m = Math.floor((ind1 + ind2 - 1) / 2);

      if (e === this.tab_[m]) return m;
      else if (e < this.tab_[m]) ind2 = m;
      else ind1 = m + 1;
    }

    return -1;
  }

  rechercheDichotomiqueAux(e: number, ind1: number, ind2: number): number {
    if (ind1 < ind2) {
      let m = Math.floor((ind1 + ind2 - 1) / 2);
      let v = this.tab_[m];

      if (e === v) return m;
      else if (e < v) return this.rechercheDichotomiqueAux(e, ind1, m);
      else return this.rechercheDichotomiqueAux(e, m + 1, ind2);
    }

    return -1;
  }

  rechercheDichotomiqueRec(e: number): number {
    return this.rechercheDichotomiqueAux(e, 0, this.tab_.length);
  }
}
