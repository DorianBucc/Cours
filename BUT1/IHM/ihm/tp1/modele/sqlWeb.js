var SQLWeb = /** @class */ (function () {
    function SQLWeb() {
    }
    SQLWeb.prototype.init = function (cheminHTML, http) {
        this.spExec = http + 'spExec.php';
        this.cheminHTML = cheminHTML;
        this.http = http;
    };
    SQLWeb.prototype.getXhr = function () {
        var xhr = null;
        if (window.XMLHttpRequest) // firefox et autres
         {
            xhr = new XMLHttpRequest;
        }
        return xhr;
    };
    SQLWeb.prototype.SQLexec = function (sp, params) {
        this.SQLloadData(sp, params, 'manipulation');
        return true;
    };
    SQLWeb.prototype.SQLloadData = function (sp, params, req) {
        if (req === void 0) { req = 'interrogation'; }
        // fetch ne fonctionne pas en mode synchrone ==> mode synchrone obligatoire
        var xhr = this.getXhr();
        var resultat = [];
        if (xhr) { // on définit ce qu'on va faire quand on aura la réponse
            xhr.onreadystatechange = function () {
                if (xhr.readyState === 4 && xhr.status === 200) {
                    var src = JSON.parse(xhr.responseText);
                    resultat = src['resultat'];
                }
            };
            xhr.open("POST", this.spExec, false); // mode synchrone obligatoire
            xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
            for (var i in params) {
                params[i] = encodeURIComponent(params[i]);
            }
            xhr.send('sp=' + encodeURIComponent(sp) + '&bd=' + JSON.stringify(this.bd) + '&params=' + JSON.stringify(params) + '&req=' + req);
        }
        return resultat;
    };
    SQLWeb.prototype.bdOpen = function (host, port, bdname, user, pwd, charset, driver) {
        if (charset === void 0) { charset = 'utf8'; }
        if (driver === void 0) { driver = 'mysql'; }
        this.bd = { host: host, port: port, bdname: bdname, user: user, pwd: pwd, charset: charset, driver: driver };
        this.SQLloadData("", []);
    };
    return SQLWeb;
}());
var sqlWeb = new SQLWeb();
export { sqlWeb };
//# sourceMappingURL=sqlWeb.js.map