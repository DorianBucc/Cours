var VueTp1 = /** @class */ (function () {
    function VueTp1() {
    }
    VueTp1.prototype.init = function (form) {
        this._form = form;
        this.form.edtHt.onkeydown = function () { vueTp1.viderTTC(); };
        this.form.edtTtc.onkeydown = function () { vueTp1.viderHT(); };
        this.form.btnCalculer.onclick = function () { vueTp1.calculer(); };
    };
    Object.defineProperty(VueTp1.prototype, "form", {
        get: function () { return this._form; },
        enumerable: false,
        configurable: true
    });
    VueTp1.prototype.viderHT = function () {
        this.form.edtHt.value = "";
    };
    VueTp1.prototype.viderTTC = function () {
        this.form.edtTtc.value = "";
    };
    VueTp1.prototype.calculer = function () {
        var taux1 = this.form.radioTaux1;
        var taux2 = this.form.radioTaux2;
        var taux3 = this.form.radioTaux3;
        var edtHt = this.form.edtHt;
        var edtTtc = this.form.edtTtc;
        var taux = "";
        if (taux1.checked) {
            taux = taux1.value;
        }
        else if (taux2.checked) {
            taux = taux2.value;
        }
        else if (taux3.checked) {
            taux = taux3.value;
        }
        if (taux !== "") {
            var tauxTva = Number(taux) / 100;
            var ht = edtHt.value.trim();
            if (ht !== "") {
                var nb = Number(ht);
                if (isNaN(nb)) {
                    alert("Erreur - calcul impossible : le montant HT " + ht + " est invalide.");
                }
                else {
                    edtTtc.value = this.calculHtVersTtc(nb, tauxTva).toFixed(2);
                }
            }
            else {
                var ttc = edtTtc.value.trim();
                if (ttc !== "") {
                    var nb = Number(ttc);
                    if (isNaN(nb)) {
                        alert("Erreur - calcul impossible : le montant TTC " + ttc + " est invalide.");
                    }
                    else {
                        edtHt.value = this.calculTtcVersHt(nb, tauxTva).toFixed(2);
                    }
                }
            }
        }
        else {
            alert("Erreur - calcul impossible : le Taux de TVA n'est pas renseigné.");
        }
    };
    VueTp1.prototype.calculHtVersTtc = function (ht, taux) {
        return ht * (1 + taux);
    };
    VueTp1.prototype.calculTtcVersHt = function (ttc, taux) {
        return ttc / (1 + taux);
    };
    return VueTp1;
}());
var vueTp1 = new VueTp1;
export { vueTp1 };
//# sourceMappingURL=class_tp1.js.map