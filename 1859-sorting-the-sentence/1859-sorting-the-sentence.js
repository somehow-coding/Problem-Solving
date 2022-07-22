var sortSentence = function(s) {
    let i = 0, arr = [], temp;
    while(i<s.length){
        temp = "";
        while(!('1'<=s[i] && s[i]<='9')){
            temp += s[i];
            i++;
        }
        arr.push([s[i],temp]);
        i+=2;
    }
    arr.sort();
    let ret = "";
    for(i=0; i<arr.length; i++){
        ret += arr[i][1];
        if(i!=arr.length-1) ret+=' ';
    }
    return ret;
};