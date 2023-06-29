import * as APIsql from "../modele/sqlWeb.js";
APIsql.sqlWeb.init("https://devweb.iutmetz.univ-lorraine.fr/~toto3u/ihm/dossier_application/vue/", "https://devweb.iutmetz.univ-lorraine.fr/~nitschke5/ihm/IHM_API/");
var Connexion = /** @class */ (function () {
    function Connexion() {
        this.init();
    }
    Connexion.prototype.init = function () {
        // à adapter avec voter nom de base et vos identifiants de connexion
        APIsql.sqlWeb.bdOpen('devbdd.iutmetz.univ-lorraine.fr', '3306', 'toto3u_nombase', 'toto3u_appli', 'motdepasse', 'utf8');
    };
    return Connexion;
}());
var connexion = new Connexion;
export { connexion, APIsql };
//# sourceMappingURL=connexion.js.map