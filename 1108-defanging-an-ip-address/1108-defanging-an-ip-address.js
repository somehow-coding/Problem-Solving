var defangIPaddr = function(s) {
    let x = "", y = "[.]";
    for(let i=0; i<s.length; i++){
        let c = s[i];
        if(c==='.'){
            x += y;
        }
        else{
            x += c;
        }
    }
    return x;
};