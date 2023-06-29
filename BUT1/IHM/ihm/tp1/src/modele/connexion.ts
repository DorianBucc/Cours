import * as APIsql from "../modele/sqlWeb.js"

APIsql.sqlWeb.init("https://devweb.iutmetz.univ-lorraine.fr/~toto3u/ihm/dossier_application/vue/","https://devweb.iutmetz.univ-lorraine.fr/~nitschke5/ihm/IHM_API/")

class Connexion {
	constructor() {
		this.init();
	}
	init():void {
		// à adapter avec voter nom de base et vos identifiants de connexion
		APIsql.sqlWeb.bdOpen('devbdd.iutmetz.univ-lorraine.fr','3306','toto3u_nombase', 'toto3u_appli','motdepasse', 'utf8');
	}
}
let connexion = new Connexion;

export {connexion, APIsql}

