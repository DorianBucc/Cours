
type TtabAsso = {
	[key:string] : string;
}
type TdataSet  = TtabAsso[];


class SQLWeb {	
	spExec		: string;		 
	cheminHTML  : string;	
	http		: string;
	bd			: {host:string, port:string, bdname:string, user:string, pwd:string, charset:string, driver:string };

	init(cheminHTML : string, http : string) : void{
		this.spExec		 = http +'spExec.php';		 
		this.cheminHTML  = cheminHTML;	
		this.http		 = http;
	}
	
	
	getXhr(): XMLHttpRequest
	{
		let xhr = null;
		if (window.XMLHttpRequest)	// firefox et autres
		{	 xhr = new XMLHttpRequest;	}
		return xhr;	
	}

	SQLexec(sp : string, params : string[]):boolean {
		this.SQLloadData(sp, params, 'manipulation');
		return true;
	}
	
	SQLloadData(sp : string, params : string[], req ='interrogation'):TdataSet  {
	// fetch ne fonctionne pas en mode synchrone ==> mode synchrone obligatoire
		const xhr = this.getXhr();
		let resultat : TdataSet = [];
		if (xhr)
		{	// on définit ce qu'on va faire quand on aura la réponse
			xhr.onreadystatechange = function():void{
				if (xhr.readyState === 4 && xhr.status === 200)
				{	
					let src = JSON.parse(xhr.responseText);
					resultat = src['resultat'];	
				}
			}
			xhr.open ("POST", this.spExec, false);  // mode synchrone obligatoire
			xhr.setRequestHeader ('Content-Type', 'application/x-www-form-urlencoded');
			for (let i in params) {
				params[i] =encodeURIComponent(params[i]);
			}
			xhr.send('sp=' +encodeURIComponent(sp) +'&bd=' +JSON.stringify(this.bd) +'&params=' +JSON.stringify(params) +'&req=' +req);							
		}	
	
		return resultat;
	}
	
	bdOpen(host :string, port : string, bdname : string, user : string, pwd : string, charset ='utf8', driver ='mysql'):void {
		this.bd = {host:host, port:port, bdname:bdname, user:user, pwd:pwd, charset:charset, driver:driver };
		this.SQLloadData("",[]);
	}
	
}

let sqlWeb = new SQLWeb()
export { sqlWeb, TtabAsso, TdataSet }

