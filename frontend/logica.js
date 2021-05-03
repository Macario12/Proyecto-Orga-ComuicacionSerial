let casilla = "";

function select(pos) {
    if (casilla  !== "") {
        document.getElementById(casilla).className = "ladrillo"
    }
    casilla = pos
    document.getElementById(pos).className = "fa fa-bomb"
}

function confirmar() {
    opcion  =""
    document.getElementById(casilla).className = "ladrillo"
    data = document.getElementById("modo").value + casilla

    //hacer peticion a node con data
    fetch('http://localhost:3000/enviar',{
	    method: 'POST',
	    body: JSON.stringify({"data": data})
    }).then(res => res.json()).then(function(dataR) { 
	    if(document.getElementById("modo").value == 1) {
		    console.log(dataR.resultado == '11111');
		    if(dataR.resultado == '11111'){
			    //JUEGO CONTINUA
			    document.getElementById(casilla).innerHTML = "&#9989;";
		    }else{
			    //JUEGO PERDIDO
			    document.getElementById(casilla).innerHTML = "&#128163";
		    }
	    } else {
		    alert("Bomba colocada");
	    }
	    casilla  = ""
	    return "";
    });
}
